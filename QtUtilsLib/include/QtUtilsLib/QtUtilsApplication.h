#pragma once

#include <QtUtilsLib/MultithreadedApplication.h>

#include <utilsLib/Injector.h>
#include <utilsLib/InjectionContainer.h>
#include <utilsLib/ILoggingManager.h>
#include <utilsLib/LoggingManager.h>

namespace QtUtilsLib
{

template <typename TPtr>
class QtUtilsApplication : public MultithreadedApplication
{
public:
  QtUtilsApplication(int& argc, char** argv)
    : MultithreadedApplication(argc, argv)
  {
    utilsLib::ILoggingManager::create<utilsLib::LoggingManager>();
  }

  ~QtUtilsApplication() override
  {
    m_container.clear();
  }

  void setupIOC()
  {
    m_injector = std::make_unique<utilsLib::Injector<TPtr>>(m_container);

    registerComponents(m_container);
    initialize(*m_injector);
  }

protected:
  virtual void initialize(utilsLib::Injector<TPtr>& injector) {}
  virtual void registerComponents(utilsLib::InjectionContainer<TPtr>& container) {}

private:
  utilsLib::InjectionContainer<TPtr>        m_container;
  std::unique_ptr<utilsLib::Injector<TPtr>> m_injector;

};

using StdQtIocApplication = QtUtilsApplication<std::shared_ptr<void>>;

}
