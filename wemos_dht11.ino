#include "thingProperties.h"
#include "DHT.h"
#define DHT_TYPE DHT11
int DHT_PIN = D1;
int relPin = D2;

DHT dht(DHT_PIN, DHT_TYPE);
unsigned long lastReadTime = 0;
unsigned long lastReadTime2 = 0;
void setup() {
  Serial.begin(9600);
  delay(1500); 
  dht.begin();
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relPin, OUTPUT);
}

void loop() {
  ArduinoCloud.update();
  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (millis() - lastReadTime >= 2000) {  
  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C, Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
    
    suhu = temperature;
    kelembaban = humidity;
    
  } else {
    Serial.println("DHT11 reading error!");
  }
}

  if (led==true) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
if (millis() - lastReadTime2 >= 1000) {
  if (timer.isActive()) {
    digitalWrite(relPin, LOW);
  } else {
    digitalWrite(relPin, HIGH);
  }
}
  
    
  if (suhu>=30) {
    digitalWrite(relPin, LOW);
  } 
  else if (relay==true) {
    digitalWrite(relPin, LOW);
  }
  else {
    digitalWrite(relPin, HIGH);
  }
    
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
/*
  Since Waktu is READ_WRITE variable, onWaktuChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onWaktuChange()  {
  // Add your code here to act upon Waktu change
}
/*
  Since Relay is READ_WRITE variable, onRelayChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onRelayChange()  {
  
}
/*
  Since Timer is READ_WRITE variable, onTimerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTimerChange()  {
  // Add your code here to act upon Timer change
}
