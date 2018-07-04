#include "mapplannerconfiguration.h"
#include <iostream>

MapPlannerConfiguration::MapPlannerConfiguration( const MapPlannerConfiguration & other){
    for(const auto& kv:other.m_configurations){
        auto * config = kv.second->copy();
        m_configurations.insert(std::make_pair(config->getName(),config));
    }
}

MapPlannerConfiguration & MapPlannerConfiguration::operator=( const MapPlannerConfiguration & other){
    for(const auto& kv:other.m_configurations){
        auto * config = kv.second->copy();
        m_configurations.insert({config->getName(),config});
        m_configurations[config->getName()]->setValue(config->getValue());
    }
    return *this;
}

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
