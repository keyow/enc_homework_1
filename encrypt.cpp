// Copyright 2021 <keyow>

#include <vector>
#include <string>
#include <iostream>


std::string encrypt(const std::string text, const size_t key) {

    srand(key);

    std::string enc_result;

    std::vector<uint16_t> _16word_vector;
    size_t length = text.length();
    uint16_t _16word = 0;

    for (size_t i = 0; i < length; ++i) {
        _16word = (_16word >> 8) | ((0x00 | text[i]) << 8);  // big endian
        if (i % 2 == 1) {
            _16word_vector.push_back(_16word);
            _16word = 0;
        }
    }

    for (uint16_t& el : _16word_vector) {
        el = (el >> 3) | ((el & 0x0007) << 13);
        el ^= rand();
        enc_result += static_cast<char>(((el & 0xff00) >> 8));
        enc_result += static_cast<char>(el & 0xff);
    }

    std::cout << enc_result << std::endl;
    return enc_result;
}