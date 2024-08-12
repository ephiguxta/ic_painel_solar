#include <OneWire.h>
#include <DallasTemperature.h>

OneWire pin(23);
DallasTemperature bus(&pin);
DeviceAddress sensor;

void setup(void) {
	Serial.begin(115200);
	bus.begin();
	bus.getAddress(sensor, 0);
}

void loop() {
	bus.requestTemperatures();

	float temp = bus.getTempC(sensor);
	Serial.println(temp);

	delay(100);
}
