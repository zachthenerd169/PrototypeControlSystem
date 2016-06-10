#include "EchoModule.h"
#include <thread>

int main()
{
  // Create an EchoModule object
  auto mod = std::make_shared<EchoModule>("Echo Module");

  // Delay for a short amount of time
  std::this_thread::sleep_for(std::chrono::milliseconds(600));

  // Send a message to the EchoModule
  mod->newMessage("First Message");

  // Delay for a short amount of time
  std::this_thread::sleep_for(std::chrono::milliseconds(600));

  // Send a message to the EchoModule
  mod->newMessage("Second Message");

  return 0;
}
