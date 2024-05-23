El primero que envia datos entre el computador y el procesador es este último, sin embargo, no manda nada al inicio, sólo espera a que el usuario mande la información.

Este código está pendiente del buffer, esperando que el usuario envie información a través de él, y en el caso , en que aquella información fuese el caracter 1, el sistema devolverá un mensaje diciendo "Hello from Raspberry Pi Pico".

¿Por qué es importante considerar las propiedades PortName y BaudRate?
Esto es importante porque es como le contamos al sistema las configuraciones para trabajar con nuestro procesador. El Portname le dirá en que puerto se encuentra el procesador y BaudRate le dirá la velocidad de comunicación con el procesador, así como lo haciamos en arduino con la linea "serial.begin(115200)"

¿Qué relación tienen las propiedades anteriores con el controlador?

La primera propiedad, el Portname, es el nombre del puerto donde está conectado el procesador, mientras que la segunda se trata de la velocidad de comunicación del procesador con el sistema.
