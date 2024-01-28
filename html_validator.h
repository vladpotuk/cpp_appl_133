#ifndef HTML_VALIDATOR_H
#define HTML_VALIDATOR_H

#include <string>
#include <memory>

class HTMLValidator {
public:
    HTMLValidator(const std::string& filePath);
    bool validate();

private:
    std::unique_ptr<std::string> fileContent;
};

#endif 

