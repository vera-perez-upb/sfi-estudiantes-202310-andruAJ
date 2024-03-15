Ejecuta la aplicación en Unity. Verás un número cambiar rápidamente en pantalla. Ahora presiona la tecla A (no olvides dar click en la pantalla Game). ¿Qué pasa? ¿Por qué crees que ocurra esto?

Al presionar A, el número que aparece en la pantalla se detiene por un corto periodo de tiempo y luego continua. Mi hipótesis es que al mandarle el key, el buffer mantiene recibiendo este caracter y se recibe de vuelta el número de bytes que se han recibido, y ya que el buffer sigue recibiendo "A", no para de subir el número de bytes recibidos (que se muestran en la pantalla), pero al escribir otra vez el A, el programa se detiene un momento al recibir una nueva isntrucción y sigue con su funcionamiento

¿Qué pasaría si al momento de ejecutar la instrucción int numData = 
_serialPort.Read(buffer, 0, 20); solo han llegado 10 de los 16 bytes del mensaje? 

Si al momento de leer el puerto seria, el buffer sólo ha recibido 10 bytes, estos serán guardados en el buffer, sin necesidad de que no sean 16 y el valor de vuelto por numData será 10

¿Cómo puede hacer tu programa para saber que ya tiene el mensaje completo?

Para saber si el mensaje está completo, se necesitan marcardor (como /n) para decirle al sistema que ese es todo el mensaje, pero aquí no hay, entonces no se puede saber con certeza.

¿Cómo se podría garantizar que antes de hacer la operación Read tenga los 16 bytes listos para ser leídos?

Para lograr esto, se puede hacer una línea de código con un if con la condición para que sólo funcione cuando estén los 16 bytes. Otra opción es con un temporizador para esperar a que lleguen los bytes.

Además, ¿si los mensajes que envía el controlador tienen tamaños diferentes?

Si los mensajes tienen diferentes tamaños, el programa tendrá complicaciones al recibirlos y puede terminar leyendo caracteres vacio y gastando tiempo leyendo bytes inexistentes. Para evitar esto se NECESITA lógica entre el sistema y el controlador para decirle que lea la información recibida en el buffer de los mensajes, sin pasarse ni un byte más de los que el mensaje tiene.

¿Cómo haces para saber que el mensaje enviado está completo o faltan bytes por recibir?

Se necesita un marcador para el final del mensaje para que el buffer sepa cuando se recibe el último byte.