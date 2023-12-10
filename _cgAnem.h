#include "esphome.h"

#include "cgAnem.h"

#define SECONDS_PER_INTERVAL 5
#define AREA 100

#ifdef ANEM_I2C_ADDR 
#undef ANEM_I2C_ADDR
#define ANEM_I2C_ADDR 0x11
#endif 


using namespace esphome;

class MyCgAnem: public PollingComponent, public CustomAPIDevice {
  public: Sensor * Temperature_Sensor = new Sensor();
  Sensor * AirFlowRate_Sensor = new Sensor();
  Sensor * AirConsumption_Sensor = new Sensor();
  Sensor * Duct_Area_Sensor = new Sensor();
  Sensor * MaxAirFlowRate_Sensor = new Sensor();
  Sensor * MinAirFlowRate_Sensor = new Sensor();
  CG_Anem myself {
    ANEM_I2C_ADDR
  };
  MyCgAnem(): PollingComponent(SECONDS_PER_INTERVAL * 1000) {}

  void setup() override {
    myself.init();
    myself.set_duct_area(AREA);
  }

  void update() override {
    float Temperature = myself.getTemperature();
    float AirFlowRate = myself.getAirflowRate();
    float AirConsumption = myself.calculateAirConsumption();
    float MaxAirFlowRate = myself.getMaxAirFlowRate();
    float MinAirFlowRate = myself.getMinAirFlowRate();
    if (myself.data_update()) {
      Temperature_Sensor -> publish_state(Temperature);
      AirFlowRate_Sensor -> publish_state(AirFlowRate);
      AirConsumption_Sensor -> publish_state(AirConsumption);
      MaxAirFlowRate_Sensor -> publish_state(MaxAirFlowRate);
      MinAirFlowRate_Sensor -> publish_state(MinAirFlowRate);
    }
  }
};
