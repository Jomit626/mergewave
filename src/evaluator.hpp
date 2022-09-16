#include <vector>

#include "port.hpp"

namespace mergewave
{

using namespace std;

class Evaluator {
protected:
  PortList port_list;
public:
  const PortList* get_top_port();
};

class SVEvaluator: public Evaluator {
public:
  SVEvaluator(const char* svfile);
  SVEvaluator(vector<const char*> svfiles);
};

class PrintEvaluator: public Evaluator {

};

}
