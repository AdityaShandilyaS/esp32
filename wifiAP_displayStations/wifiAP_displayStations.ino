#include "WiFi.h"
#include "esp_wifi.h"
 
const char *ssid = "MyESP32AP";
const char *password = "testpassword";

#include <WiFi.h>
#include "esp_wifi.h"
 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.softAP(ssid, password);
 
}
 
void loop() {
 
  wifi_sta_list_t wifi_sta_list;
  tcpip_adapter_sta_list_t adapter_sta_list;
 
  memset(&wifi_sta_list, 0, sizeof(wifi_sta_list));
  memset(&adapter_sta_list, 0, sizeof(adapter_sta_list));
 
  esp_wifi_ap_get_sta_list(&wifi_sta_list);
  tcpip_adapter_get_sta_list(&wifi_sta_list, &adapter_sta_list);
 
  for (int i = 0; i < adapter_sta_list.num; i++) {
 
    tcpip_adapter_sta_info_t station = adapter_sta_list.sta[i];
 
    Serial.print("station nr ");
    Serial.println(i);
 
    Serial.print("MAC: ");
 
    for(int i = 0; i< 6; i++){
      
      Serial.printf("%02X", station.mac[i]);  
      if(i<5)Serial.print(":");
    }
 
    Serial.print("\nIP: ");  
    Serial.println(ip4addr_ntoa(&(station.ip)));    
  }
 
  Serial.println("-----------");
  delay(5000);
}

 
