#include <WiFi.h>

const char* ssid = "RENOX";
const char* password = "12345678";

WiFiServer server(80);

const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client.");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();
    
    if (request.indexOf("/LED=ON") != -1) {
      digitalWrite(ledPin, HIGH);
    } 
    if (request.indexOf("/LED=OFF") != -1) {
      digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<h1>ESP32 LED Control</h1>");
    client.println("<p><a href=\"/LED=ON\"><button>ON</button></a></p>");
    client.println("<p><a href=\"/LED=OFF\"><button>OFF</button></a></p>");
    client.println("</html>");
    
    delay(1);
    Serial.println("Client disonnected");
  }
}
