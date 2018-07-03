#ifndef RANGECONFIGURATION_H
#define RANGECONFIGURATION_H

#include "configurationinterface.h"

class RangeConfiguration : public ConfigurationInterface{
public:
    RangeConfiguration(double range = 0.0):m_range{range}{}
    std::string getName() const override{
        return "Range";
    }
    std::string getValue() const override{
        return std::to_string(m_range);
    }
    void setValue(std::string value) override{
        setRange(std::stod(value));
    }
    double getRange(){
        return m_range;
    }
    void setRange(double range){
        if(range < 0.0){
            range = 0.0;
        }
        m_range = range;
    }
private:
    double m_range;
};

#endif // RANGECONFIGURATION_H
