void task1(){

enum class Task1States{
        INIT,
        WAIT_FOR_TIMEOUT
    };

    static Task1States task1State = Task1States::INIT;
    static uint32_t lastTime;
    static constexpr uint32_t INTERVAL = 1000;

    switch(task1State){
        case Task1States::INIT:{
            Serial.begin(115200);
            lastTime = millis();
            task1State = Task1States::WAIT_FOR_TIMEOUT;
            break;
        }

        case Task1States::WAIT_FOR_TIMEOUT:{
            uint32_t currentTime = millis();
            if( (currentTime - lastTime) >= INTERVAL ){
                lastTime = currentTime;
                Serial.print("mensaje a 1Hz\n");
            }
            break;
        }

        default:{
            break;
        }
    }

}

void task2(){

}

void task3(){

}

void setup()
{
    task1();
    task2();
    task3();
}

void loop()
{
    task1();
    task2();
    task3();
}
