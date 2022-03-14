#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "CGA2121_LSqeC2T";
const char* password = "hiddenpassword";

const char *host = "http://httpbin.org/post";
//const char *host = "http://access-control-umg.herokuapp.com/api/test";
 
void setup() {
  Serial.begin(115200);
  Serial.println("\nWiFi station setting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting ");
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
    delay(500);
    Serial.println(".");
  }
  Serial.println("\nWiFi ready");
  Serial.println("My ip adress: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  WiFiClient client;
  HTTPClient http;

  String userID = "mario";
  String timeXD = "02:55";

  String postData, link;
  postData = "userID=" + userID + "&time=" + timeXD;

  Serial.print("Request Link");
  Serial.print(host);

  Serial.print("Post Data:");
  Serial.println(postData);

  http.begin(client, host);
  http.addHeader("Content-type","application/json");
  
  int httpCode = http.POST(postData);

  String payload = http.getString();

  Serial.print("Response Code:");
  Serial.println(httpCode);
  Serial.print("Returned data from Server: ");
  Serial.println(payload);

  http.end();
  delay(5000);  //Send a request every 5 seconds
 
}
