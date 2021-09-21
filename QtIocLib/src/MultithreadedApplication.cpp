#include "QtIocLib/MultithreadedApplication.h"

#include <QThread>

namespace QtIocLib
{

MultithreadedApplication::MultithreadedApplication(int& argc, char** argv)
  : QApplication(argc, argv)
{
  qRegisterMetaType<std::function<void()>>("std::function<void()>");

  connect(this, &MultithreadedApplication::executeFunctionAsync, this, &MultithreadedApplication::executeFunction, Qt::QueuedConnection);

  connect(this, &MultithreadedApplication::executeFunctionBlocking, this, &MultithreadedApplication::executeFunction,
    Qt::BlockingQueuedConnection);
}

MultithreadedApplication::~MultithreadedApplication() = default;

void MultithreadedApplication::executeInUiBlocking(std::function<void()> func)
{
  if (isInUIThread())
  {
    func();
    return;
  }

  Q_EMIT static_cast<MultithreadedApplication*>(qApp)->executeFunctionBlocking(func);
}

void MultithreadedApplication::executeInUiAsync(std::function<void()> func, bool executeInUIThread)
{
  if (isInUIThread())
  {
    func();
    return;
  }

  Q_EMIT static_cast<MultithreadedApplication*>(qApp)->executeFunctionAsync(func);
}

bool MultithreadedApplication::isInUIThread()
{
  return (!qApp || (QThread::currentThread() == qApp->thread()));
}

void MultithreadedApplication::executeFunction(std::function<void()> func) const
{
  func();
}

}
