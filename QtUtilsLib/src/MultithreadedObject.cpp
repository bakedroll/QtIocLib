#include <QtUtilsLib/MultithreadedObject.h>

namespace QtUtilsLib
{

MultithreadedObject::~MultithreadedObject() = default;

MultithreadedObject& MultithreadedObject::getInstance()
{
  static MultithreadedObject obj;
  return obj;
}

void MultithreadedObject::executeFunction(std::function<void()> func) const
{
  func();
}

MultithreadedObject::MultithreadedObject() = default;

}
