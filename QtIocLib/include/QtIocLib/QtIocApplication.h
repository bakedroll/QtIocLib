#pragma once

#include <QtIocLib/MultithreadedApplication.h>

#include <iocLib/Injector.h>
#include <iocLib/InjectionContainer.h>

namespace QtIocLib
{

template <typename TPtr>
class QtIocApplication : public MultithreadedApplication
{
public:
  QtIocApplication(int& argc, char** argv)
    : MultithreadedApplication(argc, argv)
  {
  }

  ~QtIocApplication() override
  {
    // TODO: Remove function fron injector and use InjectionContainer::clear()
    m_injector->clearContainer();
  }

  void setupIOC()
  {
    m_injector = std::make_unique<iocLib::Injector<TPtr>>(m_container);

    registerComponents(m_container);
    initialize(*m_injector);
  }

protected:
  virtual void initialize(iocLib::Injector<TPtr>& injector) {}
  virtual void registerComponents(iocLib::InjectionContainer<TPtr>& container) {}

private:
  iocLib::InjectionContainer<TPtr>        m_container;
  std::unique_ptr<iocLib::Injector<TPtr>> m_injector;

};

using StdQtIocApplication = QtIocApplication<std::shared_ptr<void>>;

}
