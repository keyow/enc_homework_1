#include "header.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        help("Need 2 arguments", argv[0]);
        exit(-1);
    }

    std::string result;
    std::string str;

    int key;

    if (strcmp(argv[1], "encryption") == 0) {
        get_data(str, key);
        align(str);
        result = encrypt(str, key);
        std::ofstream f(argv[2]);
        f << result;
        f.close();
    } else if (strcmp(argv[1], "decryption") == 0) {
        get_data(str, key, argv[2]);
        result = decrypt(str, key);
    } else {
        help("Wrong mode", argv[0]);
        exit(-1);
    }

    std::cout << result << std::endl;
    return 0;
}
