#include "EchoModule.h"
#include "ReverseEchoModule.h"
#include <thread>

int main()
{
  // Create an EchoModule object
  auto echo = std::make_shared<EchoModule>("Echo Module");

  // Create a ReverseEchoModule object
  auto reverse_echo = std::make_shared<ReverseEchoModule>("Reverse Echo Module");

  // Delay for a short amount of time
  std::this_thread::sleep_for(std::chrono::milliseconds(600));

  // Send a message to both modules
  echo->newMessage("First Message");
  reverse_echo->newMessage("First Message");

  // Delay for a short amount of time
  std::this_thread::sleep_for(std::chrono::milliseconds(600));

  // Send a message to both modules
  echo->newMessage("Second Message");
  reverse_echo->newMessage("Second Message");

  return 0;
}
