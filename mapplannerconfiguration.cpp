#include "mapplannerconfiguration.h"

void MapPlannerConfiguration::addConfiguration(ConfigurationInterface * config){
    if(config){
        m_configurations.insert(std::make_pair(config->getName(),config));
    }
}

std::vector<std::string> MapPlannerConfiguration::getConfigurationsNames() const{
    std::vector<std::string> configurations_names;
    for(const auto & kv:m_configurations){
        configurations_names.push_back(kv.first);
    }
    return configurations_names;
}

ConfigurationInterface* MapPlannerConfiguration::getConfiguration(std::string name){
    if(m_configurations.count(name)){
        return m_configurations[name];
    }
    return nullptr;
}

std::vector<ConfigurationInterface*> MapPlannerConfiguration::getConfigurations(){
    std::vector<ConfigurationInterface*> configurations;
    for(const auto & kv:m_configurations){
        if(kv.second){
            configurations.push_back(kv.second);
        }
    }
    return configurations;
}
