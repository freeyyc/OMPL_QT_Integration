#ifndef MAPPLANNERCONFIGURATION_H
#define MAPPLANNERCONFIGURATION_H
#include "plannerconfigurationinterface.h"
#include "unordered_map"

class MapPlannerConfiguration: public PlannerConfigurationInterface {
public:
    MapPlannerConfiguration(){}
    void addConfiguration(ConfigurationInterface * config) override;
    std::vector<std::string> getConfigurationsNames() const override;
    ConfigurationInterface* getConfiguration(std::string name) override;
    std::vector<ConfigurationInterface*> getConfigurations() override;

private:
    std::unordered_map<std::string,ConfigurationInterface*> m_configurations;
};

#endif // MAPPLANNERCONFIGURATION_H
