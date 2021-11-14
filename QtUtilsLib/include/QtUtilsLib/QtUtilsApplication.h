#pragma once

#include <QtUtilsLib/MultithreadedApplication.h>

#include <utilsLib/Injector.h>
#include <utilsLib/InjectionContainer.h>
#include <utilsLib/DependencyInjectionBase.h>
#include <utilsLib/ILoggingManager.h>
#include <utilsLib/LoggingManager.h>

namespace QtUtilsLib
{

template <typename TPtr>
class QtUtilsApplication : public MultithreadedApplication,
                           public utilsLib::DependencyInjectionBase<TPtr>
{
public:
  QtUtilsApplication(int& argc, char** argv)
    : MultithreadedApplication(argc, argv)
    , utilsLib::DependencyInjectionBase<TPtr>()
  {
    utilsLib::ILoggingManager::create<utilsLib::LoggingManager>();
  }

  ~QtUtilsApplication() override
  {
    utilsLib::ILoggingManager::destroy();
  }

  int run()
  {
    utilsLib::DependencyInjectionBase<TPtr>::setupIOC();
    return exec();
  }
};

using StdQtUtilsApplication = QtUtilsApplication<std::shared_ptr<void>>;

}
