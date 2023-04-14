#pragma once

#include <QObject>

#include <functional>

namespace QtUtilsLib
{

class MultithreadedObject : public QObject
{
  Q_OBJECT

public:
  ~MultithreadedObject() override;

  static MultithreadedObject& getInstance();

Q_SIGNALS:
  void executeFunctionAsync(std::function<void()> func);
  void executeFunctionBlocking(std::function<void()> func);

public Q_SLOTS:
  void executeFunction(std::function<void()> func) const;

private:
  MultithreadedObject();

};

}
