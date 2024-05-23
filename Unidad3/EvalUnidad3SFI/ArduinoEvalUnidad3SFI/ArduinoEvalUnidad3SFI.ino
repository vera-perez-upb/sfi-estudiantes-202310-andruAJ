void task(){
  enum class TaskStates
    {
        INIT,
        WAIT_COMMANDS
    };
    static TaskStates taskState = TaskStates::INIT;

    switch (taskState)
    {
        case TaskStates::INIT:
        {
            Serial.begin(115200);
            taskState = TaskStates::WAIT_COMMANDS;
            break;
        }
        case TaskStates::WAIT_COMMANDS:
        {
            if (Serial.available() > 0)
            {
                String command = Serial.readStringUntil('\n');
                if (command == "A")
                {
                    Serial.println("Desde arduino recibimos la letra A");
                }
                else if (command == "S")
                {
                    Serial.println("Desde arduino recibimos la letra S");
                }
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
  task();
}

void loop() {
  task();
}
