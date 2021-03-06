# Cuestionario Teórico

============================

#### 1. Mencione al menos 3 ejemplos donde pueda encontrarse concurrencia
#### (que no estén mencionados en las transparencias de la clase)

* Una pc que está renderizando un video, reproduciendo música y a la vez
  navegando por inernet.
* SmartPhone 

#### 2. Escriba una definición de concurrencia. Diferencie procesamiento
#### secuencial, concurrente y paralelo.

* La concurrencia es la capacidad que tienen las computadoras de
  ejecutar multiples tareas de forma simultaena.

* Secuencial: Un flujo de control que ejecuta de a una instruccion a la vez.

* Concurrente: Procesamiento lógico y simultaneo de un set de instrucciones.

* Paralelo: Procesamiento físico y simultaneo de un set de instrucciones.

#### 3. ¿Cuáles son las 3 grandes clases de aplicaciones concurrentes que podemos
#### encontrar? Ejemplifique

* Multithread: Maneja simultaneamente tareas independientes, asignando los
  procesadores de a cuerdo a alguna politica.
    * Por ejemplo: sistema de ventanas en PC, Sistemas Operativos time-shared.

* Sistemas de computo distribuido: Vincula procesadores distintos sobre los que
  ejecuta instrucciones que se comunican entre sí por mensajes.
    * Por ejemplo: Sistemas web distribuidos, Bases de Datos de bancos.

* Sistemas de computo paralelo: Resuolver un problema en menor tiempo, utilizando
  una arquitectura multiprocesador en la que se puede dividir la taera globar el
  tareas que puedan ejecutarse en distintos procesadores.
    * Por ejemplo: Calculo científico, Procesamientode imágenes.

#### 4. Describa el concepto de deadlock y qué condiciones deben darse para que ocurra.

* El deadlock es una situación en la que dos o mas procesos que comparten un
  recurso se quedan esperando a que el otro lo libere, impidiendo que ambos avancen.

* Las propiedades para que ocurran son:
  * Recursos reusables serialmente
  * Adquisición incremental: Losprocesos mantienen los recursos que poseen
    mientras esperar adquirir recursos adicionales
  * No-preemption: Lo recursos solo pueden ser liberados de forma voluntaria.
  * Espera cíclica: Existe una cadena circular de procesos que dónde cada uno
    tiene un recurso que su sucesor esta esperando adquirir.

#### 5. Defina inanición. Ejemplifique.

* La inanición es cuando un proceso no logra acceder a un recurso compartido.
  por ejemplo, cuando varios procesos compiten por un recurso, y hay uno que no
  logra acceder en ningún momento.

#### 6. ¿Qué entiende por no determinismo? ¿Cómo se aplica este concepto a la ejecución concurrente?

* Se entiende que la salida puede ser distinta segun el orden de ejecucion de
  los procesos que comparten un recurso.
* por ejemplo se tienen los siguientes algoritmos

        x = 2

        p1{
            x = x+1;
        }

        p2{
            x = x*2;
        }

  Si se ejecuta primero la instruccion de p1 y luego la de p2, al finalizar la
  ejecución, x tendrá el valor 6, mientras que si se ejecuta de la forma p2 y
  luego p1, al finalizar la ejecucion x tendrá el valor 5

#### 7. Defina comunicación. Explique los mecanismos de comunicación que conozca

* La comunicacion es la forma en que se organiza y se transmiten datos entre
  tareas concurrentes.
* Hay dos protocolos:
  * Memoria compartida: los procesos intercambian informacion sobre la memoria
    compartida o actúan coordinadamente sobre datos residentes en ella.
  * Por pasaje de mensajes: se establece un canal(logico o fisico) para
    transmitir informacion entre procesos.

#### 8.
  * A)_ Defina sincronización. Explique los mecanismos de sincronización que conozca.
    * Se entiende por sincronizar al ajuste temporal de procesos para lograr la
      coordinacion entre ellos.
    * Sincronizacion por exclusion mutua: asegurar que solo un proceso tenga
       acceso al recurso compartido por un espacio de tiempo
    * Sincronizacion por condicion: bloquear la ejecucion de un proceso hasta
          que se cumpla una condicion dada.
* B)_  ¿En un programa concurrente pueden estar presentes más de un mecanismo
        de sincronización? En caso afirmativo, ejemplifique
  * En el problema de productores y consumidores se utilizan dos mecanismos:
    * Por condición el proceso de consumir se bloquea hasta que se de que se
      pueda consumir.
    * Po exclusion mutua el consumidor consumira lo que produjo el productor,
      pero nunca ambos intentaran usar un mismo recurso a la vez.

#### 9.
* A)_ Analice en qué tipo de problemas son más adecuados cada uno de los 5
    paradigmas de resolución de problemas concurrentes descriptos en clase.
  * Paralelismo iterativo: Resolución de sistemas de ecuaciones, calculos con matrices
  * Paralelismo recursivo: Sort by merge, cálculo de raíces en funciones continuas,
    problema del viajante.
  * Productor-consumidor:el pipe en GNU/Linux, esquema productor-consumidor.
  * Cliente-servidor: mecanismo de invocacion de tipo RPC o rendezvous.
  * Pares que interactuan: transferencias de archivos.

* B)_ ¿Qué relación encuentra entre el paralelismo recursivo y la estrategia de
      “dividir y conquistar”? ¿Cómo aplicaría este  concepto a un problema de
      ordenación de un arreglo (por ejemplo usando un algoritmo de tipo “quicksort”
      o uno de tipo “sorting by merging”).?
  * Lo que se hace es dividir  al arreglo en bloques de datos y ordenar cada bloque paralelamente para luego hacer un merge.

* C)_ Mencione algún sistema de tipo cliente/servidor que conozca
  * Los sistemas de los cajeros automáticos.


