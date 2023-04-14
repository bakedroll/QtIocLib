#pragma once

#include <utilsLib/DependencyInjectionBase.h>
#include <utilsLib/LoggingManager.h>

namespace QtUtilsLib
{

template <typename TPtr>
class QtUtilsApplication : public utilsLib::DependencyInjectionBase<TPtr>
{
public:
  QtUtilsApplication() :
    utilsLib::DependencyInjectionBase<TPtr>()
  {
    utilsLib::ILoggingManager::create<utilsLib::LoggingManager>();
  }

  ~QtUtilsApplication() override
  {
    utilsLib::ILoggingManager::destroy();
  }

  virtual int execApp() = 0;
  virtual void quitApp() = 0;

  int run()
  {
    utilsLib::DependencyInjectionBase<TPtr>::setupIOC();
    return execApp();
  }
};

using StdQtUtilsApplication = QtUtilsApplication<std::shared_ptr<void>>;

}
