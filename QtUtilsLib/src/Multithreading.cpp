#include <QtUtilsLib/Multithreading.h>

#include <QtUtilsLib/MultithreadedObject.h>

#include <QCoreApplication>
#include <QObject>
#include <QThread>

namespace QtUtilsLib
{
void Multithreading::executeInUiBlocking(std::function<void()> func)
{
  if (isInUIThread())
  {
    func();
    return;
  }

  Q_EMIT MultithreadedObject::getInstance().executeFunctionBlocking(func);
}

void Multithreading::executeInUiAsync(std::function<void()> func, bool executeInUIThread)
{
  if (isInUIThread())
  {
    func();
    return;
  }

  Q_EMIT MultithreadedObject::getInstance().executeFunctionAsync(func);
}

bool Multithreading::isInUIThread()
{
  return (!qApp || (QThread::currentThread() == qApp->thread()));
}

}
