void task1()
{
    enum class Task1States    {
        INIT,
        WAIT_DATA
    };

    static Task1States task1State = Task1States::INIT;
    static uint32_t value;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
       if (Serial.available() > 0)
        {
            value = value + Serial.available();
            //static uint32_t bufferRecepcion[value];
            Serial.print("Se han recibido");
            Serial.print(value);
            Serial.print('\n');
        }
        break;
    }

    default:
    {
        break;
    }
    }
}

void setup() {
  task1();
}

void loop() {
}
