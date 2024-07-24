#include "Array.hpp"

int main() {
    Array<int>  arr(5);

    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = static_cast<int>(i) + 1;
    }

    std::cout << "Array arr values: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << arr[5] << std::endl; // This will throw an exception
    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Array<int>  brr;
    try {
        std::cout << brr[0] << std::endl; // This will throw an exception
    } catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    brr = arr;
    std::cout << "Array brr values: ";
    for (size_t i = 0; i < brr.size(); ++i) {
        std::cout << brr[i] << " ";
    }
    std::cout << std::endl;

    Array<int>  crr(brr);
    std::cout << "Array crr values: ";
    for (size_t i = 0; i < crr.size(); ++i) {
        std::cout << crr[i] << " ";
    }
    std::cout << std::endl;

    Array<float>   frr(3);
    frr[0] = 0.2;
    frr[1] = 1.4;
    frr[2] = 2.7;
    std::cout << "Array frr values: ";
    for (size_t i = 0; i < frr.size(); ++i) {
        std::cout << frr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
