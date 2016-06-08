#ifndef OBJECT_H
#define OBJECT_H

#include "Logger.h"
#include <string>

class Object
{
public:
  Object(std::string _name="");
  virtual ~Object();
protected:
  Logger& getLog();
  std::string getObjectName();
private:
  static Logger l_logger;

  std::string s_name;
};


#endif //OBJECT_H
