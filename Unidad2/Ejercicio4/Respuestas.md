Código microcontrolador:

Tenemos un método que recibe a la variable btnState que carga el estado del boton con sus opciones "HIGH" o "LOW". En esta función, dependiendo del estado del botón, se regresa "OFF" u "ON".

Luego esta la maquina de estados, con los estados INIT y WAIT_COMMANDS, inicializando en el primer mencionado y luego se nos muestran variables buttonXPin, con X = 1,2,3,4 en los pines 12, 13, 32, 33.

Luego se inicia el led en modo de salida y se le dice que empiece apagado. Luego, a cada uno de los pines ya mencionados los ponemos en modo INPUT_PULLUP, para que los botones estén constantemente en el estado 1 a menos que uno lo cambiara manualmente, para después cambiar al estado WAIT_COMMANDS.

En el estado WAIT_COMMANDS se tiene un evento con un condicional para verificar si el Serialport ha recibido algo. En caso de que sí, se usa la variable command para guardar el mensaje y se tienen 3 eventos "ledON", "ledOFF" y "readBUTTONS" a los cuales se ingresa si command recibio uno de esos mensajes. En el primer evento, se prende el led, en el segundo se apaga y en el tercero se imprime el estado de todos los botones.

Codigo aplicación Unity:

Tenemos una maquina de estados con los estados: INIT y WAIT_COMMANDS

Ya dentro de la clase classSerial, hacemos que inicie la maquina de estado en el estado INIT e inicializamos las variables: taskState(en el estado INIT), _serailPort (va a leer el puerto serial que le diremos después), buffer (un arreglo que guardara la info del buffer), myText (el cuadro de texto que daremos como referencia en unity), counter (inicializandolo en 0).

En el método Start() le damos la información del puerto serial a la variable _serialPort (le damos el nombre del puerto donde se encuentra el microcontrolador, la velocidad del puerto, lo iniciamos...). Mandamos el mensaje "open Serial Port" e inicializamos el arreglo buffer con 128 bytes disponibles.

En el método Update(), le diremos al codigo que la variable myText.text va a tomar el valor de counter converitdo en un string y subimos el valor del counter. 

En el switch tenemos los estados, en el INIT pasamos directamente al siguiente estado.

En WAIT_COMMANDS hay 4 eventos, si se recibe el boton A, S y R y un estado donde la variable de tipo string  "response" lee lo que recibio el puerto serial en caso de que hayan Bytes para leer en el puerto. 



