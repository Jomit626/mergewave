#pragma once

#include <string>

#include "slang/symbols/PortSymbols.h"

namespace mergewave
{
  using namespace std;
  using namespace slang;

  class Port {
  public:
    enum Direction {
      Input,
      Output,
      InOut
    } dir;
    string name;
    int width;

    Port(Direction dir, const string& name, int width);
    Port(const PortSymbol* p);
  };

  typedef vector<Port> PortList;
}

