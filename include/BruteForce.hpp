// Copyright 2022 Lonskiy Yuriy yuralong.skiy@mail.ru

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include <iostream>
#include "picosha2.h"
#include <boost/log/trivial.hpp>
#include <nlohmann/json.hpp>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <signal.h>
using namespace std;
bool marker = true;

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
  cout << "Caught signal " << signum << endl;
  // Terminate program
marker = false;
}

std::string wordbook = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/*std::string Text(){
  std::string text = "";
  for (int i = 0; i <= std::rand()%(21); i++ ){
      text += wordbook[std::rand()%(wordbook.length() + 1)];
  }
  return text;
}*/

void Hashing(nlohmann::json &array, std::string name) {
  signal(SIGINT, signal_callback_handler);

  nlohmann::json j{};
  unsigned int start_time =  clock();
  while (marker) {
    std::string text = "";
    for (int i = 0; i <= std::rand() % (21); i++) {
      text += wordbook[std::rand() % (wordbook.length())];
    }
    std::string hash_hex_str;
    picosha2::hash256_hex_string(text, hash_hex_str);
    // std::ifstream path("/Users/itsumaden/C++/PartyOne/lab-06-multithreads/include/package.json");
    // nlohmann::json j = nlohmann::json::parse(path);
    if (hash_hex_str[63] == 48 and hash_hex_str[62] == 48 and
        hash_hex_str[61] == 48 and hash_hex_str[60] == 48) {
      unsigned int end_time = clock();
      j["timestamp"] = end_time - start_time;
      j["data"] = text;
      j["hash"] = hash_hex_str;
      j["THREAD"] = name;
      array.push_back(j);
      start_time = clock();
    }
    std::cout << "SHA256(" << text << ") = \"" << hash_hex_str << "\""
              << std::endl;
    // std::cout << hash_hex_str << std::endl;
    // BOOST_LOG_TRIVIAL(trace) << "A trace severity message" << text << hash_hex_str;
  }
}
#endif // INCLUDE_EXAMPLE_HPP_
