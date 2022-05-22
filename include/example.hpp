// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include <iostream>

#include "picosha2.h"
#include <boost/log/trivial.hpp>

std::string wordbook = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/*std::string Text(){
  std::string text = "";
  for (int i = 0; i <= std::rand()%(21); i++ ){
      text += wordbook[std::rand()%(wordbook.length() + 1)];
  }
  return text;
}*/

std::string Hashing(){
  std::string text = "";
  for (int i = 0; i <= std::rand()%(21); i++ ){
    text += wordbook[std::rand()%(wordbook.length() + 1)];
  }
  std::string hash_hex_str;
  picosha2::hash256_hex_string(text, hash_hex_str);
  std::cout << text << std::endl;
  std::cout << hash_hex_str << std::endl;
  BOOST_LOG_TRIVIAL(trace) << "A trace severity message" << text << hash_hex_str;
  return hash_hex_str;
}

#endif // INCLUDE_EXAMPLE_HPP_
