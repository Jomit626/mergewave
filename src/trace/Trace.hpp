#include <string>
#include <vector>
#include <map>

namespace mergewave {
  using namespace std;

  class Trace {
    public:
    typedef vector<string> ScopedNames;
    typedef map<string, string> ScopedName2Hash;

    ScopedName2Hash name2hash;
    ScopedNames names;

    public:
      Trace(const char *file);
  };
}
