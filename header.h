#ifndef ENC_HOMEWORK_1_HEADER_H
#define ENC_HOMEWORK_1_HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

std::string encrypt(const std::string, size_t);
std::string decrypt(const std::string, size_t);
void help(const std::string, const std::string);
void align(std::string&);
bool isnumber(const std::string);
void get_data(std::string&, int&);
void get_data(std::string&, int&, const std::string);

#endif //ENC_HOMEWORK_1_HEADER_H
