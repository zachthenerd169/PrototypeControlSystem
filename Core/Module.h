#ifndef MODULE_H
#define MODULE_H

#include <queue>
#include <vector>
#include <thread>

#include "Object.h"

class Module : public Object
{
public:
  // Standard Typedefs
  typedef Module                        Self;
  typedef std::shared_ptr<Module>       Pointer;
  typedef std::shared_ptr<const Module> ConstPointer;

  Module(std::string _name="");
  virtual ~Module();
  void newMessage(std::string _msg);
protected:
  virtual void run()=0;
  bool messagesAvailable();
  std::string nextMessage();
private:
  void execute();
  std::thread th_work_thread;
  bool stop;

  std::queue<std::string> q_incoming_messages;
  std::vector<Module> v_outputs;
};

#endif //MODULE_H
