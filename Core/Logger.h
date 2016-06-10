#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <chrono>
#include <mutex>

class Logger
{
public:
  // Standard Typedefs
  typedef Logger                        Self;
  typedef std::shared_ptr<Logger>       Pointer;
  typedef std::shared_ptr<const Logger> ConstPointer;

  static constexpr int INFO  =0;
  static constexpr int DEBUG =1;
  static constexpr int WARN  =2;
  static constexpr int ERROR =3;
  
  Logger();
 
  template<int log_type=INFO>
  void log(std::string msg)
  {
    std::lock_guard<std::mutex> print_lock(m_print_lock);

    std::string type_strings[] = {"INFO","DEBUG","WARN","ERROR"};
    std::string type = "UNKNOWN";
    if(log_type>=0 && log_type<=3) { type=type_strings[log_type]; }
    std::cout << "[" << type  << "] "
              << "(at: " << get_time_str() << ") "
              << msg << std::endl;
  }

  Logger(Logger const&) = delete;
  void operator=(Logger const&) = delete;

private:
  std::chrono::system_clock::time_point start_time;

private:
  unsigned long get_time_millis();

  std::string get_time_str();
  
  std::mutex m_print_lock;
};

#endif // LOGGER_H
