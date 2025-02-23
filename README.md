> [!IMPORTANT]  
> Migrate to external component pls. E.g. https://github.com/alexi-t/esphome-cg-anem

## Description

ESPHome custom component sensor for Climateguard thermoanemometer CG-Anem.

## Deployment

First of all get the code:
```bash
git clone https://github.com/maaad/CG-Anem /usr/share/hassio/homeassistant/esphome/CG-Anem
```
Add to device config for climateguard/CG-Anem
```yaml
esphome:
  ...
 libraries:
   - Wire
   - "climateguard/ClimateGuard CG Anem"
 includes:
   - CG-Anem/_cgAnem.h

 i2c:

...

sensor:
  - platform: custom
    lambda: |-
      auto cg_anem = new MyCgAnem();
      App.register_component(cg_anem);
      return {cg_anem->Temperature_Sensor, cg_anem->AirFlowRate_Sensor, cg_anem->AirConsumption_Sensor, cg_anem->MaxAirFlowRate_Sensor, cg_anem->MinAirFlowRate_Sensor};
    sensors:
      - name: "Temperature"
        id: temperature
        unit_of_measurement: °C
        state_class: measurement
        accuracy_decimals: 1
      - name: "AirFlow Rate"
        unit_of_measurement: m/s
        state_class: measurement
        accuracy_decimals: 1
      - name: "Air Consumption"
        unit_of_measurement: m^3/hour
        state_class: measurement
        accuracy_decimals: 1
      - name: "Max AirFlow Rate"
        unit_of_measurement: m/s
        state_class: measurement
        accuracy_decimals: 1
      - name: "Min AirFlow Rate"
        unit_of_measurement: m/s
        state_class: measurement
        accuracy_decimals: 1
```

## References

[External_component for cg-anem](https://github.com/alexi-t/esphome-cg-anem/tree/cg_anem) 

[Official CG-Anem library by ClimateGuard](https://github.com/climateguard/CG-Anem)

[ESPHome Documentation](https://esphome.io/index.html)


