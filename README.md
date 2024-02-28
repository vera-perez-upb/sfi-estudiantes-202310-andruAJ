Equipo: Team Rocket

Integrantes: 
Andrés Juan Giraldo Vargas 393367

Emmanuel Quintero 462240

Karen Correa 484613

///////

3a. Al hacer el cambio de 100 a 500, estamos haciendo que el LED parpadeé con intervalos más grandes. Esto se debe a que el código es un contador y al usar millis() estamos diciéndole al raspberry que cuente el tiempo desde que inicia el programa y que al restar el previoustime, parpadee cada 0.5 segundos 


5. El Raspberry Pi Pico W tiene un módulo que permite la conexión a bueltooth e internet que brinda grandes posibilidades para usar esta computadora en muchos tipos de aplicaciones y soluciones, pero el Raspberry que usamos tiene  como gran diferencia que no tiene esta función implementada.

   El Raspberry Pi te permite usarlo sin problema con múltiples plataformas (como Mac and Windows) y no sólo en Linux como otras opciones.
   
6. Cada cierto tiempo (el intervalo) la maquina nos mandará el mensaje de su tiempo actual. Al inicio nos mandará el mensaje "wait timeout" ya que este es su estado inicial, por lo que esta programado para mandar el mensaje apenas inicia el programa (solo se manda una vez).

7. La función Millis() sirve para que el sistema lleve una cuenta en milisegundos del tiempo que ha pasado desde que inició el programa. Esta función NO sirve sola para cambiar de estados, ya que el sistema no puede leer de millis el tiempo para activar un evento, por esto, creamos variables como "currenttiem", "previoustime", "lasttime"... Para llenarlas con valores de millis() y restarla entre ellas para crear intervalos que podran ser leidos por el código. En resumén millis() es una función, NO una variable, por lo que hay que crear variables para usar sus valores.
   
8. El programa tiene 2 estados, el inicial y cuando está esperando por los intervalos.
   Nuestro programa tiene 3 eventos, los cuales son al pasar cada segundo que nos dice el ejercicio (1,2 y 3)
   Las acciones en el programa son 3, son los mensajes que manda el sistema al detectar cada evento.
   
11. 

   1. El evento que verifica si algo ha llegado al puerto serial es el "if (Serial.available() > 0)"
   3. El número al lado de las letras en la tabla es la dirección de memoria donde se guarda el caracter
   4. Éstos números son la dirección de memoria de los caracteres y son necesarios para el computador para poder leer, manipular y devolver mensajes escritos, ya que en el código a nivel de maquina se    maneja con direcciones y no con los caracteres como tal.
   5. El programa tiene el 0a ya que esa es la manera que tiene el computador que ahí acaba el mensaje, y que el vacìo que està leyendo no es un caracter nulo ni un "espacio" pero que hasta ahì llega el mensaje y el espacio de memoria que debe guardar.

