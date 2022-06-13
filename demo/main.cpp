#include "BruteForce.hpp"
#include <thread>
#include "iostream"

int main()
{
  std::string name1 ="first thread";
  std::string name2 ="second thread";
  nlohmann::json array{};
  std::thread tre1(Hashing, std::ref(array), name1);
  std::thread tre2(Hashing, std::ref(array), name2);
  tre1.join();
  tre2.join();
  std::cout << "---------//---------//---------//---------" << std::endl;
  std::cout << array << std::endl;
  return 0;
}
