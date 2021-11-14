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
    } else if (strcmp(argv[1], "decryption") == 0) {
        get_data(str, key, argv[2]);
        align(str);
        result = decrypt(str, key);
        std::cout << result << std::endl;
    } else {
        help("Wrong mode", argv[0]);
        exit(-1);
    }


    return 0;
}
