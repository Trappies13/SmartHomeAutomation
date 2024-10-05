#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

class LegacyThermostat {
private:
    int temperature;
public:
    LegacyThermostat(int initialTemp);
    int getLegacyTemperature() const;
    void setLegacyTemperature(int temp);
};

#endif
