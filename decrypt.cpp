// Copyright 2021 <keyow>

#include <vector>
#include <string>
#include <iostream>


std::string decrypt(const std::string ciphertext, const size_t key) {

    srand(key);

    std::string dec_result;
    std::vector<uint16_t> _16word_vector;
    size_t length = ciphertext.length();
    uint16_t _16word = 0;

    for (size_t i = 0; i < length; ++i) {
        _16word = (_16word << 8) | (0xff & ciphertext[i]);
        if (i % 2 == 1) {
            _16word_vector.push_back(_16word);
            _16word = 0;
        }
    }

    for (uint16_t& el : _16word_vector) {
        el ^= rand();
        el = (el << 3) | ((el & 0xe000) >> 13);
        el = ((el & 0xff) << 8) | ((el & 0xff00) >> 8);
        dec_result += ((char) ((el & 0xff00) >> 8));
        dec_result += ((char) (el & 0xff));
    }

    return dec_result;
}