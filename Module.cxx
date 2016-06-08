#include "Module.h"

Module::Module(std::string _name)
  : Object(_name)
{
  stop = false;
  th_work_thread = std::thread(&Module::execute,this);
}

Module::~Module()
{
  stop = true;
  th_work_thread.join();
}

bool Module::messagesAvailable()
{
  return !q_incoming_messages.empty();
}

std::string Module::nextMessage()
{
  if(!messagesAvailable())
  {
    return std::string("");
  }

  std::string tmp = q_incoming_messages.front();
  q_incoming_messages.pop();
  
  return tmp;
}

void Module::newMessage(std::string _msg)
{
  getLog().log("new message for \"" + getObjectName() + "\": \"" + _msg + "\"");
  q_incoming_messages.push(_msg);
}

void Module::execute()
{
  getLog().log("Executing \"" + getObjectName() + "\"");
  while(!stop)
  {
    run();
  }
}
