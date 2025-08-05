#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    // 提高I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::string bin_str;
    std::cin >> n >> bin_str;

    // 建立二进制到十六进制的映射
    std::map<std::string, char> bin_to_hex_map;
    bin_to_hex_map["0000"] = '0';
    bin_to_hex_map["0001"] = '1';
    bin_to_hex_map["0010"] = '2';
    bin_to_hex_map["0011"] = '3';
    bin_to_hex_map["0100"] = '4';
    bin_to_hex_map["0101"] = '5';
    bin_to_hex_map["0110"] = '6';
    bin_to_hex_map["0111"] = '7';
    bin_to_hex_map["1000"] = '8';
    bin_to_hex_map["1001"] = '9';
    bin_to_hex_map["1010"] = 'A';
    bin_to_hex_map["1011"] = 'B';
    bin_to_hex_map["1100"] = 'C';
    bin_to_hex_map["1101"] = 'D';
    bin_to_hex_map["1110"] = 'E';
    bin_to_hex_map["1111"] = 'F';

    // 在左边补0，使长度成为4的倍数
    int padding = (4 - bin_str.length() % 4) % 4;
    if (padding != 0) {
        bin_str = std::string(padding, '0') + bin_str;
    }

    std::string hex_str = "";
    for (size_t i = 0; i < bin_str.length(); i += 4) {
        std::string group = bin_str.substr(i, 4);
        hex_str += bin_to_hex_map[group];
    }

    std::cout << hex_str << std::endl;

    return 0;
}
