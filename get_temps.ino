#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(23);
DallasTemperature sensor(&oneWire);

int ndispositivos = 0;
float tempC;

void setup()  {
	sensor.begin();

	Serial.begin(9600);

	delay(3000);

	Serial.println("Localizando Dispositivos ...");
	Serial.print("Encontrados ");

	ndispositivos = sensor.getDeviceCount();

	Serial.printf("%d dispostivios\n", ndispositivos);
}

void loop() { 
	sensor.requestTemperatures();

	// percore o barramento pegando a temperatura de cada sensor
	for (int i = 0;  i < ndispositivos;  i++) {
		// FIXME: tratar erro de quando o sensor não enviar a temperatura
		tempC = sensor.getTempCByIndex(i);

		Serial.printf("Sensor %d: %.2f ºC\n",i+1, tempC);
	}

	delay(1000);
}
