static void saveVar1(uint32_t *pdata1, uint32_t *pdata2)
{
    uint32_t cambio1 = *pdata1;
    uint32_t cambio2 = *pdata2;
    *pdata1 = cambio2;
    *pdata2 = cambio1;
}

static void printVar(uint32_t var1, uint32_t var2)
{
    Serial.print("var1 content: ");
    Serial.print(var1);
    Serial.print('\n');
    Serial.print("var2 content: ");
    Serial.print(var2);
    Serial.print('\n');
}

void task1()
{
    enum class Task1States    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

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
            uint32_t var1 = 1;
            uint32_t *pvar1 = &var1;
            uint32_t var2 = 2;
            uint32_t *pvar2 = &var2;
            printVar(*pvar1,*pvar2);
            saveVar1(pvar1, pvar2);
            printVar(*pvar1, *pvar2);
        }
        break;
    }

    default:
    {
        break;
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
