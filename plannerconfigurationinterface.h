#ifndef PLANNERCONFIGURATIONINTERFACE_H
#define PLANNERCONFIGURATIONINTERFACE_H

#include <configurationinterface.h>
#include <vector>

class PlannerConfigurationInterface{
public:
    virtual void addConfiguration(ConfigurationInterface * config) = 0;
    virtual std::vector<std::string> getConfigurationsNames() const = 0;
    virtual ConfigurationInterface* getConfiguration(std::string name) = 0;
    virtual std::vector<ConfigurationInterface*> getConfigurations() = 0;
};

#endif // PLANNERCONFIGURATIONINTERFACE_H
