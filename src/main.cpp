#include <iostream>

#include "VCDFileParser.hpp"
#include "slang/syntax/SyntaxTree.h"

int main(int argc, char *argv[]) {
  auto tree = slang::SyntaxTree::fromFile("asdfasdf");
  VCDFileParser parser;
  VCDFile * trace = parser.parse_file("a.vcd");
  for(VCDScope *scope: *trace->get_scopes()) {
    for(VCDSignal *signal: scope->signals) {
      VCDSignalValues* signalValue = trace->get_signal_values(signal->hash);
    }
  }
  return 0;
}
