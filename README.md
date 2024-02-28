Equipo: Team Rocket

Integrantes: 
Andrés Juan Giraldo Vargas 393367

Emmanuel Quintero 462240

Karen Correa 484613

///////

*3a.* Al hacer el cambio de 100 a 500, estamos haciendo que el LED parpadeé con intervalos más grandes. Esto se debe a que el código es un contador y al usar millis() estamos diciéndole al raspberry que cuente el tiempo desde que inicia el programa y que al restar el previoustime, parpadee cada 0.5 segundos 


*5.* El Raspberry Pi Pico W tiene un módulo que permite la conexión a bueltooth e internet que brinda grandes posibilidades para usar esta computadora en muchos tipos de aplicaciones y soluciones, pero el Raspberry que usamos tiene  como gran diferencia que no tiene esta función implementada.

   El Raspberry Pi te permite usarlo sin problema con múltiples plataformas (como Mac and Windows) y no sólo en Linux como otras opciones.
   
*6.* Cada cierto tiempo (el intervalo) la maquina nos mandará el mensaje de su tiempo actual. Al inicio nos mandará el mensaje "wait timeout" ya que este es su estado inicial, por lo que esta programado para mandar el mensaje apenas inicia el programa (solo se manda una vez).

*7.* La función Millis() sirve para que el sistema lleve una cuenta en milisegundos del tiempo que ha pasado desde que inició el programa. Esta función NO sirve sola para cambiar de estados, ya que el sistema no puede leer de millis el tiempo para activar un evento, por esto, creamos variables como "currenttiem", "previoustime", "lasttime"... Para llenarlas con valores de millis() y restarla entre ellas para crear intervalos que podran ser leidos por el código. En resumén millis() es una función, NO una variable, por lo que hay que crear variables para usar sus valores.
   
*8.* El programa tiene 2 estados, el inicial y cuando está esperando por los intervalos.
   Nuestro programa tiene 3 eventos, los cuales son al pasar cada segundo que nos dice el ejercicio (1,2 y 3)
   Las acciones en el programa son 3, son los mensajes que manda el sistema al detectar cada evento.
   
*11.* 

   1. El evento que verifica si algo ha llegado al puerto serial es el "if (Serial.available() > 0)"
   3. El número al lado de las letras en la tabla es la dirección de memoria donde se guarda el caracter
   4. Éstos números son la dirección de memoria de los caracteres y son necesarios para el computador para poder leer, manipular y devolver mensajes escritos, ya que en el código a nivel de maquina se    maneja con direcciones y no con los caracteres como tal.
   5. El programa tiene el 0a ya que esa es la manera que tiene el computador que ahí acaba el mensaje, y que el vacìo que està leyendo no es un caracter nulo ni un "espacio" pero que hasta ahì llega el mensaje y el espacio de memoria que debe guardar.

*12.*
    Los punteros se definen y declaran como en el ejercicio con una línea similar a esta "uint32_t *pvar = &var;" donde se declara el tipo de variable (uint32_t) y se inicializa con la siguiente parte de la       línea, donde se le dice a que variable va a "apuntar"

   Para obtener la dirección de una variable, utilizamos el operador de dirección "&" para decirle al sistema que nos la devuelva al puntero que definimos.
      Con el * podemos leer el contenido de un puntero, usando otra variable e igualandola al puntero con el * antes del puntero para que se pueda leer (ejemplo: x = *pvar)
      Con el * también podemos cambiar el contenido de la variable a través del puntero, cambiando el valor casi como si fuese una variable (ejemplo: *pvar = 20)

*13.* 
   Hipotesis: En el task 1, en el estado WAIT_DATA, después de confirmar que ya le llegó información al serial port, se crea la variable "var" de tipo uint32 y se le da el valor 0, se procede a crear el puntero pvar y se le indica que guarde la dirección de la variable var y se manda este puntero a la función printVar. En esta función se imprime el valor de var con la variable value (específico de esta función), a través del puntero ya que se mando como un puntero. Luego se manda el puntero a la función changeVar y en esta función recibe un puntero que llama pdata, por lo que al pasar pvar sin el * igualmente se logra lo deseado ya que la función recibe un puntero y no una variable, por lo que es compatible. Después de que el valor de var fue cambiado a 10 con la dirección dada por pdata, nos vamos nuevamente a printVar, pero no mandamos el puntero pero la variable, que ya fue cambiada de 0 a 10.

Después de probarlo, estaba en lo correcto.

*15.*
   1. rxData se plantea como static porque queremos conservar su contenido y forma entre cada llamada a task1 y que no se mantenga reiniciando.
   2.dataCounter no se va a reiniciar a 0 cada vez que se entre al loop, ya que fue declarado en el task1 como una variable static, lo que la hace inmune a reinicios cada vez que entre a la función.
   3. la parte (pData[i] - 0x30) es necesaria porque de esta manera le decimos al sistema que transforme la variable de su forma en ASCII a su caracter correspondiente

*16.*
   1. Se verifica si el sistema detecta el serial port, de no hacerlo, no correrá ningún código (por el if que usamos siempre).
   2. Se lee cualquier mensaje que se manda desde la serial, pero nunca lo usamos en ninguno de los ejercicios que hemos hecho.
   3. La función va a devolver un "-1" indicandonos que no hay nada en el buffer de recepción.
   4. Aunque en el buffer de recepción hayan varios datos, serial.read() sólo va a devolver un byte de datos.
   5. Si se desea leer más datos, debemos de llamar a serial.read() múltiples veces para que este vaya leyendo los datos proporcionados, uno cada vez que pasa
   6. El sistema puede recibir los datos mandados por el buffer, pero si no tienes el serial.read() ni nada similar que pueda interactuar con el buffer, el sistema no hará nada con esos datos proporcionados.

*17.*
   Caso1 (datos en el buffer = 2): si tuvieramos dos datos en el buffer, el dataRx1 y dataRx2 los guardarían, mientras que el dataRx3 guardaría un -1, ya que no hay datos suficientes en el buffer
   
   Caso2 (datos en el buffer> 2): si mandamos 3 o más datos, el código guardará en las variables los primeros 3 datos del buffer, por lo que si hubiera más de 3, el resto no se guardaría.

   Caso3 (datos en el buffer <2): En este caso, no ocurriría el evento, el if no iniciaría con sus variables, por lo que no pasaría nada.
