#include <gtest/gtest.h>

#include <QtIocLib/QtIocApplication.h>

extern int    g_argc;
extern char** g_argv;

class Interface
{
public:
  virtual ~Interface() = default;
};

class Implementation : public Interface
{
public:
  Implementation(iocLib::StdInjector& injector)
  {
  }
};

std::shared_ptr<Interface> g_pObj;

class TestApplication : public QtIocLib::StdQtIocApplication
{
public:
  TestApplication(int& argc, char** argv)
    : QtIocLib::StdQtIocApplication(argc, argv)
  {
  }

  ~TestApplication() override
  {
    printf("bla");
  }

protected:
  virtual void initialize(iocLib::StdInjector& injector) override
  {
    g_pObj = injector.inject<Interface>();
  }

  virtual void registerComponents(iocLib::StdInjectionContainer& container) override
  {
    container.registerSingletonInterfaceType<Interface, Implementation>();
  }
};

TEST(ApplicationTest, Bootstrap)
{
  auto app = std::make_unique<TestApplication>(g_argc, g_argv);

  EXPECT_EQ(g_pObj, nullptr);

  app->setupIOC();

  EXPECT_NE(g_pObj, nullptr);

  app.reset(nullptr);
}
