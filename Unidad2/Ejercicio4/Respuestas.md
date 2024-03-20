Código microcontrolador:

Tenemos un método que recibe a la variable btnState que carga el estado del boton con sus opciones "HIGH" o "LOW". En esta función, dependiendo del estado del botón, se regresa "OFF" u "ON".

Luego esta la maquina de estados, con los estados INIT y WAIT_COMMANDS, inicializando en el primer mencionado y luego se nos muestran variables buttonXPin, con X = 1,2,3,4 en los pines 12, 13, 32, 33.

Luego se inicia el led en modo de salida y se le dice que empiece apagado. Luego, a cada uno de los pines ya mencionados los ponemos en modo INPUT_PULLUP, para que los botones estén constantemente en el estado 1 a menos que uno lo cambiara manualmente, para después cambiar al estado WAIT_COMMANDS.

En el estado WAIT_COMMANDS se tiene un evento con un condicional para verificar si el Serialport ha recibido algo. En caso de que sí, se usa la variable command para guardar el mensaje y se tienen 3 eventos "ledON", "ledOFF" y "readBUTTONS" a los cuales se ingresa si command recibio uno de esos mensajes. En el primer evento, se prende el led, en el segundo se apaga y en el tercero se imprime el estado de todos los botones.

Codigo aplicación Unity:

Tenemos una maquina de estados con los estados: INIT y WAIT_COMMANDS

