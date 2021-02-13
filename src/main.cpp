#include <WiFi.h>
#include <Arduino.h>
#include <circ-buffer.h>
 
const char* ssid = "NETGEAR68";
const char* password =  "excitedtuba713";
 
CircBuffer buffer;
int teller=0;
float * avg;

CircBufferStatus_t initBuffers(uint8_t size){
  CircBufferStatus_t status = buffer.init(size);
  if(status != CB_SUCCESS){
  return status;
}
  return CB_SUCCESS;
}

void connectToNetwork() {
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Establishing connection to WiFi..");
  }
 
  Serial.println("Connected to network");
 
}
 
void setup() {
 
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  connectToNetwork();
  initBuffers(10);
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());
 

 
}
 
void loop() {
  delay(100);
  long rssi = WiFi.RSSI();
  buffer.put(rssi);
  teller++;
  if(teller%10==0){
    Serial.printf("Gemiddelde: %f\n", buffer.getAverage());
    if(buffer.getAverage()>-40){
      digitalWrite(2,HIGH);
    }
    else{
      if(buffer.getAverage()<-45){
        digitalWrite(2,LOW);
      }
    }
  }
  if(teller%20==0){
    WiFi.disconnect(true);
    if(strcmp(ssid,ssid1) == 0){
      ssid=ssid2;
      password=password2;
    }else{
      ssid=ssid1;
      password=password1;
    }
    connectToNetwork();
  }

}