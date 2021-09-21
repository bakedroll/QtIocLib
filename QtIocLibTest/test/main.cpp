#include <gtest/gtest.h>

extern int    g_argc = 0;
extern char** g_argv = nullptr;

int main(int argc, char** argv)
{
  g_argc = argc;
  g_argv = argv;

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
