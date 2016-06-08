#include "EchoModule.h"

EchoModule::EchoModule(std::string _name)
  : Module(_name)
{}

EchoModule::~EchoModule()
{}

void EchoModule::run()
{
  if(messagesAvailable())
  {
    getLog().log("\"" + getObjectName() + "\" Echo: \"" + nextMessage() + "\"");
  }
}
