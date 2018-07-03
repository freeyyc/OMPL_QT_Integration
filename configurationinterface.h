#ifndef CONFIGURATIONINTERFACE_H
#define CONFIGURATIONINTERFACE_H

#include <string>

class ConfigurationInterface{
public:
    virtual std::string getName() const = 0;
    virtual std::string getValue() const = 0;
    virtual void setValue(std::string value) = 0;
};

#endif // CONFIGURATIONINTERFACE_H
