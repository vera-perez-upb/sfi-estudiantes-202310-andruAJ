void setup() {
  Serial.begin(115200);

}

void loop() {
  float temperatura26 = (float)analogRead(26) * (3.3 / 1024.0) * 100.0;
    
    Serial.print("Temperatura 26: ");
    Serial.print(temperatura26);
    Serial.println(" °C");

  float temperatura27 = (float)analogRead(27) * (3.3 / 1024.0) * 100.0;
    
    Serial.print("Temperatura 27: ");
    Serial.print(temperatura27);
    Serial.println(" °C");

  float temperatura28 = (float)analogRead(28) * (3.3 / 1024.0) * 100.0;
    
    Serial.print("Temperatura 28: ");
    Serial.print(temperatura28);
    Serial.println(" °C");
    
    delay(1000);
}
