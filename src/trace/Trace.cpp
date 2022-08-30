#include "Trace.hpp"
#include "VCDFileParser.hpp"

namespace mergewave {
  static void contruct_full_scoped_name(VCDScope* scope,
      string prefix, Trace::ScopedName2Hash *n2h, Trace::ScopedNames *names) {
    for(VCDSignal *s: scope->signals) {
      string scoped_name = prefix + s->reference;
      names->push_back(scoped_name);
      n2h->emplace(make_pair(scoped_name, s->hash));
    }

    prefix = prefix + scope->name + '.';

    for(VCDScope *s: scope->children) {
      contruct_full_scoped_name(s, prefix, n2h, names);
    }
  }

  Trace::Trace(const char *file) {
    VCDFileParser parser;
    VCDFile *vcd_file = parser.parse_file(file);
    VCDScope *root = vcd_file->root_scope;

    contruct_full_scoped_name(root, "root", &name2hash, &names);
  }
}

