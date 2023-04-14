#pragma once

#include <functional>

namespace QtUtilsLib
{

class Multithreading
{
public:
  Multithreading() = delete;

  /*!
  *  Executes a function in UI thread. Blocks the current thread until the execution
  *  of the function is finished
  *  \param func The function to execute
  */
  static void executeInUiBlocking(std::function<void()> func);

  /*!
  *  Executes a function in UI thread. The function is executed asynchronously
  *  This function should not be called from UI thread
  *  \param func              The function to execute
  *  \param executeInUIThread true if this function in executed in UI thread
  */
  static void executeInUiAsync(std::function<void()> func, bool executeInUIThread = false);

  //! \returns true if this function is called from UI thread
  static bool isInUIThread();

};

}