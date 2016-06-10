#include "Logger.h"

Logger::Logger()
{
  std::lock_guard<std::mutex> print_lock(m_print_lock);

  start_time = std::chrono::system_clock::now();
  /* Duplicate _log() functionality to avoid weird runtime erros */
  std::cout << "[DEBUG] "
            << "(at: " << get_time_str() << ") "
            << "Logger Created" << std::endl;
}
 
unsigned long Logger::get_time_millis()
{
  auto now = std::chrono::system_clock::now();
  //return std::chrono::system_clock::to_time_t(temp_time);
  return std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
}
  
std::string Logger::get_time_str()
{
  unsigned long millis = get_time_millis();

  int hr = millis/(1000*60*60);
  int mn = millis/(1000*60) % 60;
  int sc = millis/(1000) % 60;
  int ms = millis % 1000;

  std::string hr_str = std::to_string(hr); 
  std::string mn_str = std::string(2,'0') + std::to_string(mn); 
  std::string sc_str = std::string(2,'0') + std::to_string(sc);
  std::string ms_str = std::string(3,'0') + std::to_string(ms); 

  if(hr_str.length() < 2) { hr_str = std::string(1,'0') + hr_str; }
  mn_str = mn_str.substr(mn_str.length()-2);
  sc_str = sc_str.substr(sc_str.length()-2);
  ms_str = ms_str.substr(ms_str.length()-3);

  std::string out = hr_str + ":"
                  + mn_str + ":"
                  + sc_str + ":"
                  + ms_str;
  return out;
}
