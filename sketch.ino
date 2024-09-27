#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Rede Wi-Fi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configurações do MQTT
const char* mqttServer = "mqtt3.thingspeak.com";
const int mqttPort = 1883;
const char* mqttclient = "MQUpDh0qFAsTNi8mNBgmGyE";
const char* mqttUser = "MQUpDh0qFAsTNi8mNBgmGyE"; // Substitua
const char* mqttPassword = "UZ4vQFGWdp+Lrl2eGCA1At04"; // Substitua
const char* mqttTopic = "channels/2664977/publish"; // Substitua

// Definições do DHT
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Inicialização do cliente MQTT
WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup() {
  Serial.begin(115200);
  dht.begin();
  connectWiFi();
  client.setServer(mqttServer, mqttPort);
}

void connectWiFi() {
  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Conectado ao WiFi!");
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect(mqttclient, mqttUser, mqttPassword)) {
      Serial.println(" Conectado ao MQTT!");
    } else {
      Serial.print("Falha na conexão, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  String payload = "field1=" + String(t) + "&field2=" + String(h);
  client.publish(mqttTopic, payload.c_str());

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C, Umidade: ");
  Serial.print(h);
  Serial.println(" %");

  delay(2000);
}
