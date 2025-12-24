<p align="center">
  <img src="https://raw.githubusercontent.com/mpdcfiuba/tdse-tf_3-4/refs/heads/main/img/Logo-FIUBA.svg" alt="image1">
</p>

# Sistema de gestión de órganos de tubos con microcontroladores

<table align="center">
  <tr>
    <th>Autor</th>
    <th>Padrón</th>
    <th>Mail</th>
  </tr>
  <tr>
    <td>Costantini, Martín</td>
    <td>104171</td>
    <td>mcostantini@fi.uba.ar</td>
  </tr>
  <tr>
    <td>Díaz, Mateo Fermín</td>
    <td>110629</td>
    <td>mfdiaz@fi.uba.ar</td>
  </tr>
</table>

<p align="center">
  2025 | 2do Cuatrimestre
</p>

<p align="center">
  Taller de Sistemas Embebidos (TA134)
</p>

# 1. Selección del proyecto a implementar

## 1.1. Objetivo del proyecto

El objetivo de este proyecto es implementar un sistema completo y moderno de control de órganos de tubos que permita al usuario ejecutarlo desde la consola, el celular, provea recursos para facilitar la ejecución del mismo y herramientas para mejorar la eficiencia a la hora de realizarle mantenimiento. Una vez logrado un MVP, el proyecto será escalado e implementado en un órgano de tubos real.

## 1.2. Funcionamiento básico de un órgano de tubos

Los órganos de tubos consisten básicamente en cuatro partes. Ventilador o compresor de aire, válvulas, sistema de accionamiento de válvulas y tubos.

El ventilador centrífugo presuriza el aire, el cual llega hasta la secreta, en donde se encuentran las válvulas que pueden permitir el paso de dicho aire presurizado hacia las distintas filas de tubos o columnas de notas.

El primer bloque que se realiza para conceptualizarlos, es el de las divisiones. Por cada manual (teclado para dedos) que tenga el órgano, se considera una división. Salvo contadas excepciones, los órganos poseen además la divisón que se llama pedalera, donde se encuentran notas que se tocan con los pies, organizadas de la misma manera que los manuales, en 12 notas por octava.
El siguiente bloque son los registros, donde cada registro consiste en una cantidad igual de tubos que de notas tenga la división (ya sea cantidad de teclas por manual o de pedales en la pedalera). Por ejemplo, si el teclado tiene 61 teclas (5 octavas + nota superior), un registro consistirá en 61 tubos. Un órgano suele tener varios registros por división, donde cada registro le pertenece a cada división.

En la figura 1 se puede observar una vista ilustrativa en corte de un órgano de tubos en donde se aprecian las hileras de tubos, siendo cada una, un registro diferente.

<p align="center">
  <img src="https://raw.githubusercontent.com/mpdcfiuba/tdse-tf_3-4/refs/heads/main/img/2.png" alt="image1">
</p>

<p align="center">
  <em>Figura 1: Vista esquemática de un órgano de tubos</em>
</p>

Cada división posee una válvula por nota. Para hacer sonar individualmente cada registro, existe una válvula por registro, donde dicha válvula permite o no, el ingreso del aire presurizado al compartimento de cada registro. Combinando la valvula de una nota en particular de una división y la válvula de activación del registro particular, se logra hacer sonar cada tubo individualmente. De abrir simultáneamente varias válvulas, se puede hacer sonar la misma nota en distintos registros seleccionados al mismo tiempo, también distintas notas en el mismo registro, o la combinación de ambas. En órganos antiguos se realizaba todo de forma mecánica con varillaje, modernamente se utilizan soluciones electroneumáticas o directamente eléctricas (hubo un paso histórico muy oscuro y caótico por máquinas puramente neumáticas).

En la figura 2 se puede observar la conexión que posee el teclado con las válvulas de apertura de notas (Keyboard -> Mechanical link -> Valve). Por otro lado, para el caso de los registros (Stop kob -> Mechanical link -> Slider), el accionamiento es lateral. Se puede ver que la combinación de ambos se puede esquematizar como un sistema filas-columnas. En este tipo de órganos, se realiza a través de un slider aunque existien nuevas tecnologías con válvulas electroneumáticas que reemplazan los sliders, conservando la funcionalidad.

<p align="center">
  <img src="https://raw.githubusercontent.com/mpdcfiuba/tdse-tf_3-4/refs/heads/main/img/1.png" alt="image1">
</p>

<p align="center">
  <em>Figura 2: Vista esquemática detallada por funciones</em>
</p>

Como es de suponer, existen diversos mecanismos para facilitar la ejecución del instrumento llamados acoples.Tracción o enclavamiento se llama al caso de conectar las notas de dos divisiones distintas. Super al de conectar una nota con la misma nota de la octava superior. Sub, mismo caso en la octava inferior. Super II/I, combinando ambos efectos, conectando una nota del manual I con la nota de la octava superior, pero del manual II.

También existen presets de registros, que consisten en memorias de activación de ciertos registros de acceso rápido llamadas combinaciones libres. Dichas combinaciones se setean eligiendo los registros a guardar desde sus tiradores individuales, apretando un botón de set y luego el botón de la combinación libre en donde guardar dicho set. En órganos modernos, existen perfiles de usuario para poder guardar distintas combinaciones sin tener que modificarlas nuevamente cada vez que otro usuario guarde combinaciones distintas en el instrumento para utilizarlo.

Por último, existen divisiones enteras que se encuentran encerradas en cajas de madera con persianas. Se las llama expresivas, enclosed, swell, etc. Dichas persianas se operan desde un pedal de expresión que, al cambiar su ángulo, abre o cierra dichas persianas de madera. De esta forma se logra aumentar o disminuir el volumen y tener un efecto de presencia del sonido en una habitación contigua, de forma progresiva. En órganos mecánicos se realizaba con varillaje y pesas, modernamente se utilizan motores eléctricos.

Para tener una idea cómo se pueden controlar las funcionalidades anteriormente mencionadas, puede apreciarse en la figura 3 la consola del órgano de tubos de la Catedral de Notre Dame de Paris, el más icónico y conocido de todo el mundo. En el centro se encuentran los manuales, sobre el piso la pedalera. En los costados, tanto a izquierda como a derecha, los registros (tiradores), separados en columnas por maunales. En el centro, por encima de los manuales (plaquitas negras), los acopladores, super, sub y funcionalidades extras que posee éste órgano en particular. Tanto los botones blancos debajo de los manuales (pistons), como los botones redondos por encima de la pedalera, activan las combinaciones libres. Los dos pedales expresivos que se encuentran por encima de la pedalera, son los encargados de abrir y cerrar las persianas de las cajas expresivas. Por último, a la izquierda de plaquitas negras anteriormente mencionadas, se puede observar una pantalla en donde se muestra el usuario seleccionado (y más funcionalidades que no se incluyen en el presente trabajo).

<p align="center">
  <img src="https://raw.githubusercontent.com/mpdcfiuba/tdse-tf_3-4/refs/heads/main/img/3.jpg" alt="image1">
</p>

<p align="center">
  <em>Figura 3: Consola del órgano de tubos de la Catedral Notre Dame de Paris</em>
</p>

De esta manera, un organista sin ayudantes es capaz de manejar por completo un órgano de tubos gracias al sistema electrónico de gestión. En el [siguiente link](https://www.youtube.com/watch?v=9HskcJlixGs), se puede observar un ejemplo de ejecución en el instrumento mencionado.

## 1.3. Desarrollo de las funcionalidades en el microcontrolador

Se implementará un gestor cíclico de tareas con WCET para evitar retrasos, asegurar un tiempo medible, predecible y estable de ejecución. De encontrar contratiempos en la ejecución de las tareas, se buscará dividirlas y organizarlas para lograr la mínima latencia posible.

Se establecerán dos modos de funcionamiento, config y exec. En el primer modo, config, se permitirá el cambio de perfiles de usuario, seteo de combinaciones libres, seteo de modos de apertura de persianas (lectura analógica lineal del pedal de expresión, ejecución lineal, logarítmica u otras), ejecución por Bluetooth de notas (para afinación del instrumento sin necesidad de ayudantes) o canciones según teclado en app o vía MIDI (escucharse a uno mismo tocando desde otro punto del recinto acústico a partir de una grabación MIDI), prendido o apagado del ventilador centrífugo (en el TP, un led), etc. En el segundo modo, exec (ejecución del instrumento), se permitirá unicamente la apertura y cierre de válvulas (en el TP, leds) o persianas (en el TP, motor paso a paso).

Por el lado del funcionamiento electrónico externo, tanto para leer las notas/botones presionados como para controlar los leds, se utilizarán módulos expansores i/o, que funcionan por $i^2c$, los cuales registran con filp flops las entradas o salidas, permitiendo así multiplexar y demultiplexar con métodos y tecnología moderna. Para el caso del motor paso a paso, se controlará vía salida PWM. Para el Bluetooth se utilizará el módulo comercial ESP32 de envío y recepción de datos con el microcontrolador vía UART. Se diseñará una app para celular, para poder manejar los modos de funcionamiento remotamente.

Para realizar el trabajo, se implementarán dos manuales de 15 notas (solo las blancas o naturales) y pedalera de 8 notas. Cada división contará con 3 registros propios.

## 1.4. Diagrama en bloques de periféricos

En la figura 4, se presenta el diagrama en bloques de los periféricos utilizados en el proyecto y su tipo de conexión a la placa NUCLEO-F103RB.

```mermaid
flowchart TD
    A[NUCLEO-F103RB]

    A <-->|I2C| B["1. Módulos expansores
    I/O para
    entradas de teclas o
    tiradores de registros"]

    A <-->|I2C| C["2. Módulos expansores
    I/O para salidas de
    LEDs de notas y registros"]

    A -->|UART| D["3. Módulo
    Bluetooth ESP32"]

    A -->|GPIO PWM| E["4. Servo SG90"]

    A -->|GPIO DIGITAL| F["5. LED ventilador centrífugo"]
```

<p align="center">
  <em>Figura 4: Diagrama en bloques del sistema</em>
</p>

## 2. Elicitación de requisitos y casos de uso

En Argentina no existe competencia alguna para este tipo de sistemas de control de órganos de tubos. Existe mercado, pero es muy reducido debido a la falta de recursos monetarios de las instituciones que albergan este tipo de instrumentos. Tiene mucho potencial de exportación a otros países como Alemania, Estados Unidos, Francia, en donde donde es muy común encontrar este tipo de instrumentos, se los aprecia, se los mantiene con regularidad y las soluciones electrónicas (sistema central de control) tienen un costo mayor a USD 5.000, sin contar los periféricos externos como electroimanes. Por tanto, como MVP, es muy viable para producción a baja escala con altos grados de personalización ya que el mercado no altamente competitivo y no trabaja con métricas de ganancia por volumen en donde el centavo de reducción marca la diferencia. Mas bién destacaría el producto por la calidad de materiales, terminación, fiabilidad, configurabilidad y facilidad de mantenimiento.

En la tabla 1, se describen las distintas funcionalidades a codificar agrupadas por módulos, para tener trazabilidad a la hora de realizar el despliegue del código y asegurar el funcionamiento correcto de cada uno de dichos módulos.

| Grupo | ID | Descripción |
| :---- | :---- | :---- |
| Configuración | 1.1 | El sistema permitirá el encendido  y apagado del ventilador centrífugo |
|  | 1.2 | El sistema permitirá la modificación de presets |
|  | 1.3 | El sistema permitirá la modificación de función de respuesta al pedal expresivo |
| Indicadores | 2.1 | El sistema contará con indicadores luminosos para mostrar registros seleccionados |
|  | 2.2 | El sistema contará con indicadores luminosos para mostrar acoplamientos seleccionados |
|  | 2.3 | El sistema contará con indicadores luminosos que marquen preset seleccionado |
|  | 2.4 | El sistema contará con indicadores luminosos que marquen perfil seleccionado |
|  | 2.5 | El sistema contará con un indicador luminoso que marque entrada vía Bluetooth |
| Motor | 3.1  | El sistema contará con un servo motor para abrir y cerrar las persianas el cual debe ser inicialmente calibrado |
| Comunicación Bluetooth | 4.1 | El sistema se comunicará mediante Bluetooth con la aplicación de celular |
|  | 4.2 | La aplicación permitirá cambiar de modos de operación y perfiles de usuario |
|  | 4.3 | El sistema tendrá dos modos de operación, config y exec |
|  | 4.4 | El sistema tendrá cinco perfiles de usuario diferentes para configurar |
|  | 4.5 | El sistema deberá enviar en tiempo real a la aplicación las notas en formato MIDI que se estén ejecutando, de habilitar la opción desde el celular |
|  | 4.6 | El sistema deberá recibir en formato MIDI y ejecutar en tiempo real las notas que se envíen desde el celular, de habilitar la opción desde el celular |
| Aplicación | 5.1 | La aplicación actualizará al conectar la base de datos de los perfiles guardados |
|  | 5.2 | La aplicación deberá permitirle al usuario configurar el modo de trabajo |
|  | 5.3 | La aplicación deberá poder recibir notas MIDI y mostrarlas en tiempo real en un teclado virtual |
|  | 5.4 | La aplicación deberá poder enviar notas MIDI desde un teclado virtual |
|  | 5.5 | La aplicación deberá permitirle al usuario modificar los presets guardados en los perfiles |
| Interruptores/ Botones | 6.1 | El sistema contará con 15 botones en cada uno de los dos manuales, donde cada uno representa una nota musical |
|  | 6.2 | El sistema contará con 8 botones en la pedalera, donde cada uno representa una nota musical |
|  | 6.3 | El sistema contará con 9 botones, donde cada uno representa un registro |
|  | 6.4 | El sistema contará con 3 botones, donde cada uno representa una combinación libre |
|  | 6.5 | El sistema contará con 1 boton, que representa el seteador de combinaciones libres |

<p align="center">
  <em>Tabla 1: Requisitos del proyecto</em>
</p>

Los casos de uso para este tipo de proyecto son tantos como combinaciones de teclas quiera apretar el usuario. Cada uno de ellos representa un flujo de ejecución muy simple en donde se presiona una tecla, se modifica un registro, o se cambia un perfil de usuario. A continuación, se presentan tres casos de uso a modo de ejemplo.

| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere ejecutar una nota en el manual I |
| Precondiciones | El sistema se encuentra encendido, se encuentran dos registros seleccionados del manual I, se encuentra un registro en el manual II, se encuentra activado el acoplamiento II/I |
| Flujo principal | El sistema enciende los pines de salida de ambos manuales de la nota presionada |

<p align="center">
  <em>Tabla 2: Caso de uso 1</em>
</p>

| Elemento | Definición|
| :---- | :---- |
| Disparador | Se quiere setear una combinación libre |
| Precondiciones | El sistema se encuentra encendido, se encuentran dos registros seleccionados del manual I, se encuentra un registro en el manual II, se encuentra activado el acoplamiento II/I |
| Flujo principal | Al presionar el boton de set, el sistema lee el pin de set presionado, pasa a modo config, realiza cambios en las estructuras cfg de cada combinación libre guardando tanto registros como acoplamientos seleccionados al momento de setear (estructura dta) y vuelve al modo exec |

<p align="center">
  <em>Tabla 3: Caso de uso 2</em>
</p>

| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere seleccionar una combinación libre |
| Precondiciones | El sistema está encendido, se encuentra seleccionada cualquier combinación de registros y acomplamientos |
| Flujo principal | Al presionar el botón de la combinación libre, el sistema lee el pin presionado, revisa cual estructura cfg se seleccionó y copia su contenido a la estructura dta, seleccionando de esa manera la combinación de registros y acoplamientos de dicha combinación libre |

<p align="center">
  <em>Tabla 4: Caso de uso 3</em>
</p>
