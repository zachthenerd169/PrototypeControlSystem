#ifndef ECHOMODULE_H
#define ECHOMODULE_H

#include "Module.h"

class EchoModule : public Module
{
public:
  // Standard Typedefs
  typedef EchoModule                        Self;
  typedef std::shared_ptr<EchoModule>       Pointer;
  typedef std::shared_ptr<const EchoModule> ConstPointer;

  EchoModule(std::string _name="");
  virtual ~EchoModule();
protected:
  void run();
};

#endif //ECHOMODULE_H
