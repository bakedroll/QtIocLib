#pragma once

#include <QtUtilsLib/MultithreadedObject.h>

#include <QCoreApplication>
#include <QPointer>
#include <QThread>

#include <functional>

namespace QtUtilsLib
{

/*!
*  \class MultithreadedApplication
*  This class provides static functions that ensure that code is executed in the UI thread
*  The Qt application has to inherit this class to work properly
*/
template <typename TApp>
class MultithreadedApplication : public TApp
{
public:
  /*!
  *  The constructor
  *  \param argc The number of arguments
  *  \param argv The command line arguments
  */
  MultithreadedApplication(int& argc, char** argv) :
    TApp(argc, argv)
  {
    qRegisterMetaType<std::function<void()>>("std::function<void()>");

    QObject::connect(&MultithreadedObject::getInstance(), &MultithreadedObject::executeFunctionAsync,
      &MultithreadedObject::getInstance(), &MultithreadedObject::executeFunction, Qt::QueuedConnection);

    QObject::connect(&MultithreadedObject::getInstance(), &MultithreadedObject::executeFunctionBlocking,
      &MultithreadedObject::getInstance(), &MultithreadedObject::executeFunction, Qt::BlockingQueuedConnection);
  }

  ~MultithreadedApplication() override = default;

};

}
