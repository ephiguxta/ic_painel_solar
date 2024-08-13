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
  ndispositivos = sensor.getDeviceCount(); //metodo da biblioteca
  Serial.print(ndispositivos, DEC);
  Serial.println(" dispositivos.");
  Serial.println("");
}
 
void loop() { 
  sensor.requestTemperatures(); 
 
  for (int i = 0;  i < ndispositivos;  i++) { //percorre o barramento até achar o nº de disp
    Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(": ");
    tempC = sensor.getTempCByIndex(i); 
    Serial.print(tempC);
    Serial.println("ºC");
  }
  
  Serial.println("");
  delay(1000);
}
