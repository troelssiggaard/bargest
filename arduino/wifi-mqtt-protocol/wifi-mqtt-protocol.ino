/**
 * \file
 *       ESP8266 MQTT Bridge example
 * \author
 *       Tuan PM <tuanpm@live.com>
 */

#include <espduino.h>
#include <mqtt.h>

//Serial debugPort; // RX, TX
ESP esp(&Serial1, &Serial, 4);
MQTT mqtt(&esp);
boolean wifiConnected = false;

void wifiCb(void* response) {
  uint32_t status;
  RESPONSE res(response);

  if(res.getArgc() == 1) {
    
    res.popArgs((uint8_t*)&status, 4);
    
    if(status == STATION_GOT_IP) {
      Serial.println("WIFI CONNECTED");
      mqtt.connect("192.168.1.41", 1883);
      wifiConnected = true;
      //or mqtt.connect("host", 1883); /*without security ssl*/
      
    } else {
      
      wifiConnected = false;
      mqtt.disconnect();
    
    }
    
  }
}

// IMPORTANT: SETUP PUBLISH AND SUBSCRIBE CHANNELS HERE.
void mqttConnected(void* response) {
  Serial.println("Connected");
  mqtt.subscribe("topic/barrobot/motor1/#");  // EXAMPLE TOPIC SUBSCRIBED TO.  //or mqtt.subscribe("topic",0); /* QoS default = 0*/
  Serial.println("Subscribe");
  //mqtt.publish("/topic/0", "data123");
  //Serial.println("Publish");
}

void mqttDisconnected(void* response) {   }

// HANDLING THE DATA AND WRITING THEM TO SERIAL MONITOR
void mqttData(void* response) {
  RESPONSE res(response);

  Serial.print("Received: topic=");
  String topic = res.popString();
  Serial.println(topic);

  Serial.print("data=");
  String data = res.popString();
  Serial.println(data);
  
  if(data == "hej"){
    Serial.println("HEJ MED DIG!");  
  }
}

void mqttPublished(void* response) {   }

void setup() {
  Serial1.begin(19200);
  Serial.begin(19200);
  esp.enable();
  delay(500);
  esp.reset();
  delay(500);
  while(!esp.ready());

  Serial.println("ARDUINO: setup mqtt client");
  if(!mqtt.begin("DVES_duino", "admin", "Isb_C4OGD4c3", 120, 1)) {
    Serial.println("ARDUINO: fail to setup mqtt");
    while(1);
  }

  Serial.println("ARDUINO: setup mqtt lwt");
  mqtt.lwt("/lwt", "offline", 0, 0); //or mqtt.lwt("/lwt", "offline");

  /*setup mqtt events */
  mqtt.connectedCb.attach(&mqttConnected);
  mqtt.disconnectedCb.attach(&mqttDisconnected);
  mqtt.publishedCb.attach(&mqttPublished);
  mqtt.dataCb.attach(&mqttData);

  /*setup wifi*/
  Serial.println("ARDUINO: setup wifi");
  esp.wifiCb.attach(&wifiCb);
  esp.wifiConnect("Scan","Hej-for-dig!"); // Setup SSID, PASSWORD = esp.wifiConnect("SSIDNAME","PASSWORD");

  Serial.println("ARDUINO: system started");
}

void loop() {
  esp.process();
  
  //if(wifiConnected) {
     // mqtt.publish("/topic/0", (const char*) "Skippelippe");
     // Serial.println("WiFi Connected :D");

  //}
 // delay(2000);
}
