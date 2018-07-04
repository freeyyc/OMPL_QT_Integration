#ifndef GOALBIASCONFIGURATION_H
#define GOALBIASCONFIGURATION_H

#include "configurationinterface.h"

class GoalBiasConfiguration : public ConfigurationInterface{
public:
    GoalBiasConfiguration(double goal_bias = 0.05):m_goal_bias{goal_bias}{}
    std::string getName() const override{
        return "Goal Bias";
    }
    std::string getValue() const override{
        return std::to_string(m_goal_bias);
    }
    void setValue(std::string value) override{
        setGoalBias(std::stod(value));
    }
    double getGoalBias(){
        return m_goal_bias;
    }
    void setGoalBias(double goal_bias){
        if(goal_bias < 0.0){
            goal_bias = 0.0;
        }
        if(goal_bias > 1.0){
            goal_bias = 1.0;
        }
        m_goal_bias = goal_bias;
    }
    ConfigurationInterface* copy() const override{
        return new GoalBiasConfiguration{m_goal_bias};
    }
private:
    double m_goal_bias;
};

#endif // GOALBIASCONFIGURATION_H
