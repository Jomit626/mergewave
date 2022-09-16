#include "slang/compilation/Compilation.h"
#include "slang/syntax/SyntaxTree.h"
#include "slang/symbols/CompilationUnitSymbols.h"
#include "slang/symbols/InstanceSymbols.h"
#include "slang/symbols/PortSymbols.h"
#include "slang/diagnostics/DiagnosticEngine.h"

#include "port.hpp"
#include "evaluator.hpp"
#include "spdlog/spdlog.h"

namespace mergewave
{

const PortList* Evaluator::get_top_port() {
  return &port_list;
}

SVEvaluator::SVEvaluator(const char* svfile) {
  auto syntax_tree = SyntaxTree::fromFile(svfile);

  Compilation compilation;
  compilation.addSyntaxTree(syntax_tree);

  const auto &diags = compilation.getAllDiagnostics();
  if (!diags.empty()) {
    auto str = DiagnosticEngine::reportAll(SyntaxTree::getDefaultSourceManager(), diags);
    spdlog::info("{}", str);
    return;
  }

  const RootSymbol &root = compilation.getRoot();
  auto tops = root.topInstances;
  auto top = tops.front();
  auto& body = top->as<slang::InstanceSymbol>().body;
  auto ports = body.getPortList();
  for (auto const& p : ports) {
    port_list.push_back(Port(&p->as<PortSymbol>()));
  }
}

}
