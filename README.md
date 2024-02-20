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
   
8. El programa tiene 4 estados, el inicial, cuando pasa 1 segundo, cuando pasan 2 y cuando pasan 3.
   Nuestro programa tiene 3 eventos, los cuales son al pasar cada segundo que nos dice el ejercicio (1,2 y 3)
   Las acciones en el programa son 3, son los mensajes que manda el sistema al detectar cada evento.
   
