Juan Estebas Castaño y Camilo Valencia

En la clase propuesta para trabajar con la memabrana de teclado se realizó un codigo el cual recorre por medio de ciclos for recorre la matriz y se ve cual fila y columna estan iguales para luego mostrar esta misma interseccion en consola. Este codigo estaba dentro del while(true) en el main.

Para mayor facilidad y como se pedia al usuario ingresar varios valores multiples veces, decidimos poner este codigo dentro que una funcion que retornara el numero entero convirtiendo la cedana de caracteres asi: 
```c++
string cadena = "123";
int numero = cadena - "0";
```
Ademas de este cambio se añadio la condicional
```c++
if(keyMap[i][j]!='*'){
}
```
Esto con el fin de que guardara en la cadena todos los characteres presionados hasta que se oprimiera la tecla '*'.

Sin embargo solo funcionaba si se mantenia oprimida la tecla desde el momento que se iniciaba el programa, se intento arreglar por multiples caminos, poniendo banderas para que detectara la parada, forzando la parada con un break, pero nada funcionó.

Al ver que esto no nos funciono decidimos, entonces, continuar con las aplicaciones que se pedian.
1. Para el primer punto se hizo uso de la formula de una recta teniendo dos puntos
   
   m=y<sub>2</sub> - y<sub>1</sub>/(x<sub>2</sub> - x<sub>1</sub>)
   
   y-y<sub>1</sub> = m ( x - x<sub>1</sub>)
   Teniendo en cuenta que se pedia el intercepto con el eje y, es decir cuando la x=0, se despejo la x:
   ```c++
   int intercepto= -1*x1*m+y1;
   ```

2. Para el segundo punto solo se alcanzo a hacer que se pidiera el numero de temperaturas a digitar, y por medio de un ciclo for se piden ese numero de temperaturas.
   ```c++
   cout <<"Digite el numero de temperaturas a introducir: ";
            int n=leerNum();
            int temp[n];
            for (int i = 0; i < n; i++) {
                cout<<"Ingrese la ", i," temperatura: \n";
                temp[i]=leerNumero();
            }
   ```

Teniendo en cuenta el problema del teclado de membrana y comenzando a las 4:20 pm eso fue lo maximo que pudimos hacer.
.
.
.
.
.
.
.
![](./resources/official_armmbed_example_badge.png)
# Blinky Mbed OS example

The example project is part of the [Arm Mbed OS Official Examples](https://os.mbed.com/code/) and is the [getting started example for Mbed OS](https://os.mbed.com/docs/mbed-os/latest/quick-start/index.html). It contains an application that repeatedly blinks an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

You can build the project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).
(Note: To see a rendered example you can import into the Arm Online Compiler, please see our [import quick start](https://os.mbed.com/docs/mbed-os/latest/quick-start/online-with-the-online-compiler.html#importing-the-code).)

## Mbed OS build tools

### Mbed CLI 2
Starting with version 6.5, Mbed OS uses Mbed CLI 2. It uses Ninja as a build system, and CMake to generate the build environment and manage the build process in a compiler-independent manner. If you are working with Mbed OS version prior to 6.5 then check the section [Mbed CLI 1](#mbed-cli-1).
1. [Install Mbed CLI 2](https://os.mbed.com/docs/mbed-os/latest/build-tools/install-or-upgrade.html).
1. From the command-line, import the example: `mbed-tools import mbed-os-example-blinky`
1. Change the current directory to where the project was imported.

### Mbed CLI 1
1. [Install Mbed CLI 1](https://os.mbed.com/docs/mbed-os/latest/quick-start/offline-with-mbed-cli.html).
1. From the command-line, import the example: `mbed import mbed-os-example-blinky`
1. Change the current directory to where the project was imported.

## Application functionality

The `main()` function is the single thread in the application. It toggles the state of a digital output connected to an LED on the board.

**Note**: This example requires a target with RTOS support, i.e. one with `rtos` declared in `supported_application_profiles` in `targets/targets.json` in [mbed-os](https://github.com/ARMmbed/mbed-os). For non-RTOS targets (usually with small memory sizes), please use [mbed-os-example-blinky-baremetal](https://github.com/ARMmbed/mbed-os-example-blinky-baremetal) instead.

## Building and running

1. Connect a USB cable between the USB port on the board and the host computer.
1. Run the following command to build the example project and program the microcontroller flash memory:

    * Mbed CLI 2

    ```bash
    $ mbed-tools compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

    * Mbed CLI 1

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash
    ```

Your PC may take a few minutes to compile your code.

The binary is located at:
* **Mbed CLI 2** - `./cmake_build/mbed-os-example-blinky.bin`</br>
* **Mbed CLI 1** - `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-blinky.bin`

Alternatively, you can manually copy the binary to the board, which you mount on the host computer over USB.

## Expected output
The LED on your target turns on and off every 500 milliseconds.


## Troubleshooting
If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related Links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html).
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see [CONTRIBUTING.md](./CONTRIBUTING.md) for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
