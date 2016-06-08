#include "EchoModule.h"
#include <thread>

int main()
{
  EchoModule mod("Echo Module");
  std::this_thread::sleep_for(std::chrono::milliseconds(600));
  mod.newMessage("First Message");
  std::this_thread::sleep_for(std::chrono::milliseconds(600));
  mod.newMessage("Second Message");

  return 0;
}
