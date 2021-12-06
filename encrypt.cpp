// Copyright 2021 <keyow>

#include <vector>
#include <string>
#include <iostream>

std::string encrypt(const std::string& text, const size_t key) {
    srand(key);

    std::string enc_result;
    uint16_t _16word = 0;
    for (size_t i = 0; i < text.length(); ++i) {
        _16word = (_16word << 8) | (0xff & text[i]);
        if (i % 2 == 1) {
            _16word = (_16word >> 3) | ((_16word & 0x0007) << 13);
            int tmp = rand();
            _16word ^= tmp;
            enc_result += static_cast<char>((_16word & 0xff00) >> 8);
            enc_result += static_cast<char>(_16word & 0xff);
            _16word = 0;
        }
    }

    return enc_result;
}