# Materiales a utilizar

* 1 placa Nucleo F103RB
* 1 ESP32 (Bluetooth)
* 2 MCP23017 expansores i/o de 16 bits para entradas

    * https://www.mercadolibre.com.ar/modulo-mcp23017-16-bits-expansion-iic-i2c-spi/p/MLA2039732646

    * MVP 38 entradas de divisiones + 9 entradas de registros, sin contar nada más -> 3 chips. Son muchas entradas, vamos a perder más plata y tiempo comprando y soldando componentes que otra cosa
    
    * reducimos el MVP a dos notas por octava (do, sol) + nota superior en los manuales y tres notas (do, sol, do) para la pedalera, un registro por división, II/I y Super I, 1 boton de blower on/off, 1 boton de set y 2 botones de combinaciones libres + 2 botones de secuenciador (atras, adelante)

        + total 24 entradas -> 2 chips
    
    * organo real 152 entradas de divisiones (61 x 2 manuales y 30 pedalera) + 13 entradas de registros + 1 blower + X combinaciones libres, etc, etc

        + más de 8 chips, ver como implementar, maximo 8 i2c por bus (se verá al avanzar el proyecto qué conviene más)

* 3 74HC595 serial/parallel output shift register

    * https://www.mercadolibre.com.ar/20-unidades-74hc595-smd-circuitointegrado-lc-74-hc-595-sop16/up/MLAU126355654

    * MVP (5x2 man + 3 ped) + 3 reg + 2 acop + 2 CL + 1 blower + 8 (display)
    
        + 29 salidas -> 4 chips

    * organo real x salidas
    
        + x/8 chips (se verá al avanzar el proyecto qué conviene más)

## Comprar

* 24 botones
* 2 expansores MCP23017
* 21 leds
* 4 chips 74HC59

## Ya comprado

* 1 Nucleo F103RB
* 1 ESP32
* 1 servomotor SG90
* 1 potenciómetro 10K lineal
* 1 display 7 segmentos
