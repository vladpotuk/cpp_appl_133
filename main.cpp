#include <iostream>
#include "html_validator.h"

int main() {
    std::string filePath;
    std::cout << "Enter the path to the HTML file: ";
    std::cin >> filePath;

    HTMLValidator validator(filePath);
    if (validator.validate()) {
        std::cout << "The HTML file is valid." << std::endl;
    }
    else {
        std::cout << "The HTML file is invalid." << std::endl;
    }

    return 0;
}
