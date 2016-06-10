#include "ReverseEchoModule.h"
#include <algorithm> // for std::reverse

ReverseEchoModule::ReverseEchoModule(std::string _name)
  : Module(_name)
{}

ReverseEchoModule::~ReverseEchoModule()
{}

void ReverseEchoModule::run()
{
  if(messagesAvailable())
  {
    auto msg = nextMessage();
    std::reverse(msg.begin(),msg.end());
    
    getLog().log("\"" + getObjectName() + "\" Echo: \"" + msg + "\"");
  }
}
