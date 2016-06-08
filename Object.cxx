#include "Object.h"

Object::Object(std::string _name)
{
  if(_name == "")
  {
    getLog().log<Logger::WARN>("Object created with no name");
    s_name = "";
  } else {
    getLog().log<Logger::DEBUG>("Object \"" + _name + "\" created");
    s_name = _name;
  }
}

Object::~Object()
{}

Logger& Object::getLog() { return l_logger; }

std::string Object::getObjectName() { return s_name; }

Logger Object::l_logger;
