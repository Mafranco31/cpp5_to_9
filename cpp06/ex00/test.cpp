#include <iostream>
#include <iomanip>

int main() {
    int intValue = 1.2;
    float floatValue = static_cast<float>(intValue);

    std::cout << "intValue: " << intValue << std::endl;
    std::cout << "floatValue: " << std::fixed << std::setprecision(1) << floatValue << std::endl;

    return 0;
}
