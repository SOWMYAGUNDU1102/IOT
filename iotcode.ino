#define BLYNK_TEMPLATE_ID "TMPL3OlHLLmko"
#define BLYNK_TEMPLATE_NAME "vehicle monitoring"
#define BLYNK_AUTH_TOKEN "0VS_TySgFCokTElccLkuZZDc4aOUF3dW"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
// -------- WIFI --------
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "TezooA55";
char pass[] = "Divi12345";

// -------- PINS --------
#define ACS712_PIN 34
#define LM35_PIN   35
#define BUZZER_PIN 2   // optional

// -------- VARIABLES --------
float sensitivity = 0.185;   // adjust based on ACS712 model
float offsetVoltage = 0;

float prevTemp = 0;
float prevCurrent = 0;

BlynkTimer timer;

// -------- SETUP --------
void setup() {
  Serial.begin(115200);
  analogReadResolution(12);

  pinMode(BUZZER_PIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);

  Serial.println("Calibrating... Keep motor OFF");

  long sum = 0;
  for (int i = 0; i < 200; i++) {
    sum += analogRead(ACS712_PIN);
    delay(5);
  }

  float avg = sum / 200.0;
  offsetVoltage = (avg * 3.3) / 4095.0;

  Serial.print("Offset Voltage: ");
  Serial.println(offsetVoltage);

  timer.setInterval(1000L, sendData);
}

// -------- MAIN FUNCTION --------
void sendData() {

  // ===== CURRENT =====
  long sumCurrent = 0;
  for (int i = 0; i < 50; i++) {
    sumCurrent += analogRead(ACS712_PIN);
  }

  float avgADC = sumCurrent / 50.0;
  float voltageCurrent = (avgADC * 3.3) / 4095.0;
  float current = (voltageCurrent - offsetVoltage) / sensitivity;
  current = abs(current);

  // ===== TEMPERATURE =====
  int adcTemp = analogRead(LM35_PIN);
  float voltageTemp = adcTemp * (3.3 / 4095.0);
  float temperature = voltageTemp * 100;

  // ===== FILTER =====
  temperature = (temperature + prevTemp) / 2;
  current = (current + prevCurrent) / 2;

  prevTemp = temperature;
  prevCurrent = current;

  // ===== STATUS =====
  String status;

  if (temperature < 20 && current < 0.5) {
    status = "NORMAL";
  }
  else if (temperature < 30 && current < 1.5) {
    status = "WARNING";
  }
  else {
    status = "CRITICAL";
  }

  // ===== FAULT + BUZZER =====
  if (temperature > 35 || current > 1.5) {
    Serial.println("⚠️ FAULT: MOTOR OVERLOAD");
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // ===== SEND TO BLYNK =====
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, status);

  // ===== SERIAL MONITOR =====
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C  |  ");

  Serial.print("Current: ");
  Serial.print(current);
  Serial.print(" A  |  ");

  Serial.print("Status: ");
  Serial.println(status);
}

// -------- LOOP --------
void loop() {
  Blynk.run();
  timer.run();
}