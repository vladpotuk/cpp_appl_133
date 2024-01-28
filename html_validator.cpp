#include "html_validator.h"
#include <fstream>
#include <iostream>

HTMLValidator::HTMLValidator(const std::string& filePath) : fileContent(std::make_unique<std::string>()) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            *fileContent += line + "\n";
        }
        file.close();
    }
}

bool HTMLValidator::validate() {
    std::string& content = *fileContent;
    size_t pos = 0;
    int openTagCount = 0;
    while ((pos = content.find('<', pos)) != std::string::npos) {
        size_t endPos = content.find('>', pos);
        if (endPos == std::string::npos) {
            std::cerr << "Invalid tag: " << content.substr(pos) << std::endl;
            return false;
        }

        std::string tag = content.substr(pos + 1, endPos - pos - 1);
        if (tag[0] == '/') { 
            openTagCount--;
            if (openTagCount < 0) {
                std::cerr << "Unexpected closing tag: " << tag << std::endl;
                return false;
            }
        }
        else { 
            openTagCount++;
        }

        pos = endPos + 1;
    }

    if (openTagCount > 0) {
        std::cerr << "Unclosed tags found." << std::endl;
        return false;
    }

    return true;
}
