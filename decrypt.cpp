// Copyright 2021 <keyow>

#include <vector>
#include <string>
#include <iostream>

std::string decrypt(const std::string& ciphertext, const size_t key) {
    srand(key);

    std::string dec_result;
    uint16_t _16word = 0;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        _16word = (_16word << 8) | (0xff & ciphertext[i]);
        if (i % 2 == 1) {
            _16word ^= rand();
            _16word = (_16word << 3) | ((_16word & 0xe000) >> 13);
            dec_result += static_cast<char>((_16word & 0xff00) >> 8);
            dec_result += static_cast<char>(_16word & 0xff);
            _16word = 0;
        }
    }

    return dec_result;
}