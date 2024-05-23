void setup() {
    Serial.begin(115200);
}

void loop() {
    float num1 = 123.456;
    float num2 = -789.012;

    
    Serial.write((uint8_t*)&num1, sizeof(float));
    Serial.write((uint8_t*)&num2, sizeof(float));

    
    byte* ptr_num1 = (byte*)&num1;
    byte* ptr_num2 = (byte*)&num2;

    for (int i = sizeof(float) - 1; i >= 0; i--) {
        Serial.write(ptr_num1[i]);
    }

    for (int i = sizeof(float) - 1; i >= 0; i--) {
        Serial.write(ptr_num2[i]);
    }

}
