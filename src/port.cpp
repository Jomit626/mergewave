#include "port.hpp"

namespace mergewave
{

static Port::Direction dirConvert(ArgumentDirection dir) {
  if (dir == ArgumentDirection::In)
    return Port::Direction::Input;
  else if (dir == ArgumentDirection::Out)
    return Port::Direction::Output;
  else if (dir == ArgumentDirection::InOut)
    return Port::Direction::InOut;
  else
    return Port::Direction::InOut;
}

Port::Port(const PortSymbol* p) {
  name = p->name;
  dir = dirConvert(p->direction);
}

}

