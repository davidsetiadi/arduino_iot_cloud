#include "arduino_secrets.h"
#include "thingProperties.h"
#include "DHT.h"

#define DHT_PIN 5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  delay(1500); 
  dht.begin();
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  ArduinoCloud.update();
  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C, Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
    
    // Update cloud variables
    suhu = temperature;
    kelembaban = humidity;
    
  } else {
    Serial.println("DHT11 reading error!");
  }
  if (led==false) {
digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(2000);
}

void onSuhuChange() {
  // Add your code here to act upon Suhu change
}

void onKelembabanChange() {
  // Add your code here to act upon Kelembaban change
}

void onLedChange() {
  // Add your code here to act upon Led change
}
