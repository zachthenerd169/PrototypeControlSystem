#ifndef ECHOMODULE_H
#define ECHOMODULE_H

#include "Module.h"

class EchoModule : public Module
{
public:
  EchoModule(std::string _name="");
  virtual ~EchoModule();
protected:
  void run();
};

#endif //ECHOMODULE_H
