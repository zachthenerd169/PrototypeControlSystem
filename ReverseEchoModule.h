#ifndef REVERSEECHOMODULE_H
#define REVERSEECHOMODULE_H

#include "Module.h"

class ReverseEchoModule : public Module
{
public:
  // Standard Typedefs
  typedef ReverseEchoModule                        Self;
  typedef std::shared_ptr<ReverseEchoModule>       Pointer;
  typedef std::shared_ptr<const ReverseEchoModule> ConstPointer;

  ReverseEchoModule(std::string _name="");
  virtual ~ReverseEchoModule();
protected:
  void run();
};

#endif //REVERSEECHOMODULE_H
