// Copyright 2021 <keyow>

#include <iostream>
#include <string>
#include <fstream>

void help(const std::string error, const std::string program_name) {
    std::cerr << "Error: " << error << std::endl;
    std::cout << std::endl;
    std::cout << program_name << " usage:" << std::endl;
    std::cout << "./[program_name] [mode] [filename with extension]" << std::endl;
    std::cout << "Modes:" << std::endl;
    std::cout << "- encryption (encrypt a file)" << std::endl;
    std::cout << "- decryption (decrypt a file)" << std::endl;
}


void align(std::string& line) {
    if (line.length() % 2 == 1) {
        line += '\x00';
    }
}


void get_data(std::string& text, int& key) {
    std::cout << "Enter text: " << std::endl;
    std::getline(std::cin, text);
    if(text.empty()) {
        std::cerr << "Error: line is empty" << std::endl;
        exit(-1);
    }

    std::string key_str;
    std::cout << "Enter key (integer): " <<std::endl;
    std::cin >> key_str;
    for (const char& c : key_str) {
        key = (key + static_cast<int> (c)) % 65536;
    }
}


void get_data(std::string& text, int& key, const std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::getline(file, text);
    } else {
        std::cerr << "Error: can't open file";
        exit(-1);
    }

    std::string key_str;
    std::cout << "Enter key (integer): " <<std::endl;
    std::cin >> key_str;
    for (const char& c : key_str) {
        key = (key + static_cast<int> (c)) % 65536;
    }
}
