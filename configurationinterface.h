#ifndef CONFIGURATIONINTERFACE_H
#define CONFIGURATIONINTERFACE_H

#include <string>
#include <iostream>

class ConfigurationInterface{
public:
    ConfigurationInterface() = default;
    ConfigurationInterface( const ConfigurationInterface & other) = default;
    virtual ConfigurationInterface & operator=( const ConfigurationInterface & other) = default;
    virtual std::string getName() const = 0;
    virtual std::string getValue() const = 0;
    virtual void setValue(std::string value) = 0;
    virtual ConfigurationInterface* copy() const = 0;
};

#endif // CONFIGURATIONINTERFACE_H
