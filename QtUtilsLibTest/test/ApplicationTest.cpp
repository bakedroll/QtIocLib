#include <gtest/gtest.h>

#include <QtUtilsLib/QtUtilsApplication.h>


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
  Implementation(utilsLib::StdInjector& injector)
  {
  }
};

std::shared_ptr<Interface> g_pObj;

class TestApplication : public QtUtilsLib::StdQtIocApplication
{
public:
  TestApplication(int& argc, char** argv)
    : QtUtilsLib::StdQtIocApplication(argc, argv)
  {
  }

  ~TestApplication() override = default;

protected:
  virtual void initialize(utilsLib::StdInjector& injector) override
  {
    g_pObj = injector.inject<Interface>();
  }

  virtual void registerComponents(utilsLib::StdInjectionContainer& container) override
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
  g_pObj.reset();

  app.reset(nullptr);
}
