<p align="center">
  <img src="./img/Logo-FIUBA.svg" alt="image1">
</p>

# Reporte de progreso: [Sistema de gestión de órganos de tubos con microcontroladores]

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

<p align="center">
  Universidad de Buenos Aires | Facultad de Ingeniería
</p>

## 📊 Status actual
**Progreso general:** 100% : Todo lo planificado se logró llevar a cabo.

## ✅ Tareas completadas
- [x] Presentación de la idea y requisitos.
- [x] Setup inicial y concretización de la idea.
- [x] Programación del firmware del Cortex-M/NUCLEO-F103RB.
- [x] Programación del firmware del ESP32 C3 RISC-V.
- [x] Programación de la aplicación.
- [x] Debugging por módulos y por conjuntos de módulos.
- [x] Testing intensivo.
- [x] Soldado de los componentes a la placa.
- [x] Debugging final con el sistema completo terminado.

## 🔀 Cambios en lo planificado
- Se cambió el módulo expansor de entradas MCP23017 por el shift register 74HC165 debido a un replanteamiento del costo/beneficio de usar cada uno de dichos módulos.
- Se realizó la placa sin el 74HC165 utilizando a cambio, teclas de un teclado MIDI, el cual envía por UART los comandos que activan las funciones de cada uno de los botones configurados.

## 🛑 Dificultades para llevar adelante el trabajo
- Falta de práctica inicial de programación en C.
- Falta de familiarización inicial completa con la forma de trabajo.
- Envergadura del trabajo grande.
- Complicaciones del funcionamiento sobre BLE en distintas plataformas.
- Inexperiencia en soldado de componentes SMD.
- Cantidad excesiva de botones y luces en la misma placa para presentar funcionalidades similares.

## 🔍 Reporte por ID en específico
<table align="center">
  <tr>
    <th>Estado</th>
    <th>Descripción</th>
  </tr>
  <tr>
    <td align="center">🟢</td>
    <td>Implementado</td>
  </tr>
  <tr>
    <td align="center">🟡</td>
    <td>En proceso</td>
  </tr>
  <tr>
    <td align="center">🔴</td>
    <td>No será implementado</td>
  </tr>
</table>

| Grupo | ID | Descripción | Estado |
| :---- | :---- | :---- | :---- |
| Interruptores/ Botones / Sensores | 1.1 | El sistema contará con 5 botones en cada uno de los dos manuales, donde cada uno representa una nota musical | 🟢 |
|  | 1.2 | El sistema contará con 3 botones en la pedalera, donde cada uno representa una nota musical | 🟢 |
| Continuaba (...) | X.X | (...) La lista completa incluía todos los requisitos (...)|  🟢 |

## 📝 Comentarios adicionales
Para llevar adelante el trabajo se utilizaron todas las herramientas disponibles, desde feedback a usuarios habituales (distintos del programador, para tener más perspectivas) de este tipo de instrumentos, observación de modelos reales y su funcionamiento, hasta consultas a las distintas IA sobre consejos para agilizar cada uno de los módulos, especialmente en los que no se contaba con experiencia previa.

Lo que más se utilizó fue la capacidad para pensar, razonar y discernir, especialmente al momento de plantear cuándo es necesario valerse de una herramienta externa para aprender más y/o trabajar de forma más eficiente, cuándo es necesario mandar un mail y cuándo estar horas para solucionar el problema sin información externa que realentice el proceso y bloquee la capacidad de aprender de cada una de las situaciones problemáticas encontradas en el transcurso del trabajo.