#include <WiFi.h>
#include <Deneyap_OLED.h>

OLED OLED;
const char* ssid = ""; //Wi-Fi adiniz
const char* password = ""; //Wi-Fi sifreniz

// LED pinleri
const int LED_YESIL = D14;
const int LED_KIRMIZI = D15;

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(LED_YESIL, OUTPUT);
  pinMode(LED_KIRMIZI, OUTPUT);
  digitalWrite(LED_YESIL, LOW);
  digitalWrite(LED_KIRMIZI, LOW);

  OLED.begin(0x7A);
  OLED.clearDisplay();
  OLED.setTextXY(0, 0);
  OLED.putString("Baglaniyor...");

  WiFi.begin(ssid, password);
  Serial.print("WiFi baglaniyor");
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println();

  String ip = WiFi.localIP().toString();

  Serial.println("=====================");
  Serial.print("KART IP: ");
  Serial.println(ip);
  Serial.println("=====================");

  OLED.clearDisplay();
  OLED.setTextXY(0, 0);
  OLED.putString("Kart IP:");
  OLED.setTextXY(2, 0);
  OLED.putString(ip.c_str());
}

void loop() {
  // IP ogrenildigini belirtmek icin iki LED de surekli yanip soner
  digitalWrite(LED_YESIL, HIGH);
  digitalWrite(LED_KIRMIZI, HIGH);
  delay(400);
  digitalWrite(LED_YESIL, LOW);
  digitalWrite(LED_KIRMIZI, LOW);
  delay(400);
}