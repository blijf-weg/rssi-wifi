#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;
int teller=1;
unsigned long tijd1=0;
unsigned long tijd2=0;
unsigned long tijd3=0;
unsigned long tijd4=0;
unsigned long tijd=0;

void setup(){
    Serial.begin(115200);
    wifiMulti.addAP("ESP32-Access-Point-1", "123456789");
    wifiMulti.addAP("ESP32-Access-Point-2", "987654321");
    Serial.println("Connecting Wifi...");
    if(wifiMulti.run() == WL_CONNECTED) {
      Serial.print("WiFi connected: ");
      Serial.println(WiFi.SSID());
      Serial.println(WiFi.localIP());
    }    
}

void loop() {
  // Maintain WiFi connection
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
  Serial.println(teller);
  if(teller==0){
    tijd3=millis();
    Serial.println("Hier");
  }
  teller++;
  if(teller==100){
    tijd4=millis();
    teller=0;
    tijd = tijd4-tijd3;
    Serial.println("Tijd teller=100: ");
    Serial.println(tijd);
    tijd1 = millis();
    if (wifiMulti.run() == WL_CONNECTED) {
      Serial.print("WiFi connected: ");
      Serial.println(WiFi.SSID());  
      Serial.println(WiFi.localIP());
    } else {
      Serial.println("WiFi not connected!");
    }
    tijd2 = millis();
    tijd=tijd2-tijd1; 
    Serial.println("Tijd connecteren");
    Serial.println(tijd);
  }
}