#ifndef OBJECT_H
#define OBJECT_H

#include "Logger.h"
#include <string>
#include <memory>

class Object
{
public:
  // Standard Typedefs
  typedef Object                        Self;
  typedef std::shared_ptr<Object>       Pointer;
  typedef std::shared_ptr<const Object> ConstPointer;

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
