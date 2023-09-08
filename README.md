# Parcial Arquitectura

### Por: Juan Estebas Castaño y Camilo Valencia
---
## Metodo Principal
```c++
int main() {
    cout << "Elija una opción (solo el número) y seguido presione * para aceptar el valor" << endl;
    cout
        << "1. Aplicación calcule pendiente e intercepto mediante dos puntos.\n"
        << endl;
    cout << "2. Calcular promedio y desviación estándar de un conjunto de "
            "temperaturas.\n"
         << endl;
    cout << "3. Generar colores en un LED RGB: \n" << endl;
```
Se muestra por consola las instrucciones para el usuario y los diferentes casos de uso para el programa, para garantizar que solo se pueda digitar 1,2 o 3 se hace un ciclo while con las respectivas condiciones de parada.


```c++
while (opcion < 1 || opcion > 3) {
      cout << "Ingrese una opcion valida" << endl;
      opcion = stoi(leerNum());
    }
```
Mediante switch-case se llama a las diferentes funciones que cumple el programa.
```c++
switch(opcion) {
        case 1:
            pend_inter();
            break;
        case 2:
            temperatura();
            break;
        case 3:
            leds();
            break;
    }
```

---
##Teclado Membrana

Para mayor facilidad definimos una matriz que representa el teclado de membrana fisico:
```c++
string keyMap[4][3] = {
   {"1", "2", "3"},
   {"4", "5", "6"},
   {"7", "8", "9"},
   {"*", "0", "#"}
};
```

Se define y se inicializa arreglos que se comunicaran con la tarjeta de desarrolo, los seran los que se leen mediante el teclado de membrana.

```c++
DigitalIn rowPins[numRows] = {DigitalIn(D2), DigitalIn(D3), DigitalIn(D4), DigitalIn(D5)};
DigitalOut colPins[numCols] = {DigitalOut(D6), DigitalOut(D7), DigitalOut(D8)};
```
Las filas son entradas digitales mientras que las columnas son salidas digitales.
### Detectar tecla presionada
Mediante dos ciclos for ( uno para las columnas (poniendolas en 0) y otro para las filas, se recorre el teclado de membrana buscandose que la fila y la columna sea 0, esto para hallar el punto de intersección.

```c++
string membrana() {
  for (int i = 0; i < numCols; i++) {
    colPins[i] = 0;

    for (int j = 0; j < numRows; j++) {
      if (rowPins[j] == 0) {
        while (rowPins[j] == 0)
          ;
        colPins[i] = 1;
        return keyMap[j][i];
      }
    }

    colPins[i] = 1;
  }

  return "";
}
```

### Para leer una cadena de caracteres
Se realiza una funcion la cual contiene la tecla que se oprime y una cadena de las teclas, en este caso se elijio el "*" para hacer las veces de enter, es decir, para que se sepa cuando para la cadena y asi devolver ésta.
```c++
string leerNum() {
  string caracterPresionado = "";
  string cadena = "";

  while (caracterPresionado != "*") {
    caracterPresionado = membrana();

    if (caracterPresionado != "") {

      cadena += caracterPresionado;
      cout << caracterPresionado<<flush;
    }
  }

  cout << endl;

  return cadena;
}
```
### Pasar de String a Integer
Para esto se utilizo una funcion que hace parte de la libreria previamente importada <string>, teniendo en cuenta que la funcion leerNum() retorna una cadena de caracteres (String), entonces:
```c++
#include <string>
int numero = stoi(leerNum());
```

# Funciones del Programa
## Calcular Pendiente e Intercepto
Teniendo en cuenta la formula utilizada para encontrar la ecuacion de una recta que pasa por dos puntos:

m=y<sub>2</sub> - y<sub>1</sub>/(x<sub>2</sub> - x<sub>1</sub>)

y-y<sub>1</sub> = m ( x - x<sub>1</sub>)

ademas que toda recta esta dada por la forma y=mx + b, donde m es la pendiente y b (termino independiente) es el intercepto con el eje y, se hace x=0 y se despeja la y:
```c++
   int intercepto= -1*x1*m+y1;
```
Por ende la funcion para encontrar esto queda tal que asi:
```c++
void pend_inter() {
  float x1, x2, y1, y2;
  cout << "Teniendo en cuenta un punto P=(x,y)" << endl;
  cout << "Para el primer punto: " << endl;
  cout << "Digite la coordenada en x" << endl;
  x1 = stoi(leerNum());
  cout << "Digite la coordenada en y" << endl;
  y1 = stoi(leerNum());
  cout << "Para el segundo punto: " << endl;
  cout << "Digite la coordenada en x" << endl;
  x2 = stoi(leerNum());
  cout << "Digite la coordenada en y" << endl;
  y2 = stoi(leerNum());

  if (x1 == x2) {
    cout << "La pendiente es indefinida debido a que es una recta vertical y "
            "la division por 0 es indefinida"
         << endl;
  } else {
    float m = y2 - y1 / (x2 - x1);
    cout << "La pendiente de la recta es: " << m << endl;
    float inter = -1 * x1 * m + y1;
    cout << "El intercepto con el eje y es: " << inter << endl;
  }
}
```
*Se pide a el usuario digital las coordenadas tanto en x como en y de los dos puntos.
*Si las coordenadas en x coinciden, la recta es vertical y la division por 0 esta indefinida.
*se muestra por consola la pendiente previamente calculada y el intercepto.

## Temperaturas
### Promedio y desviacion estandar
Se realizó un metodo para calcular el promedio de los valores de un arreglo de n posiciones, este recorre cada posicion del arreglo y lo suma, despues se divide por la cantidad de elementos que contiene.
```c++
float calcular_promedio(float arr[], int n) {
  float suma = 0;
  for (int i = 0; i < n; i++) {
    suma += arr[i];
  }
  return suma / n;
}
```
Para la desviacion estandar se tiene en cuenta la sumatoria del cuadrado de el elemento en cuestion menos el promedio, despues se divide entre los n elementos y se saca raiz.
```c++
float calcular_desviacion_estandar(float arr[], int n, float promedio) {
  float suma_cuadrados = 0;
  for (int i = 0; i < n; i++) {
    suma_cuadrados += pow(arr[i] - promedio, 2);
  }
  return sqrt(suma_cuadrados / n);
}
```
### Funcion temperatura
```c++
void temperatura() {
  int n;
  cout << "Ingrese la cantidad de temperaturas a digitar: " << endl;
  n = stoi(leerNum());
  float temps[n];
  int i = 0;
  for (i = 0; i < n; i++) {
    cout << "Ingrese la temperatura " << i + 1 << endl;
    temps[i] = stoi(leerNum());
  }
  float promedio = calcular_promedio(temps, n);
  cout << "El promedio de temperaturas es: " << promedio << endl;
  float desviacionEst = calcular_desviacion_estandar(temps, n, promedio);
  cout << "La desviacion Estandar es: " << desviacionEst << endl;
}
```
Se le pide a el usuario el numero de temperaturas del conjunto y se almacena.
1. Se crea un arreglo con el numero introducido.
2. Mediante un ciclo for se le pide a el usuario las temperaturas una por una.
3. Teniendo el arreglo llenado, se llama a las funciones de calcular_promedio() y calcular_desviacion_estandar().
4. Se muestra por consola el resultado.


##Color RGB
Se le pide a el usuario el codigo RGB  restringiendo el input mediante ciclos while 8 de 0 a 255) y leyendo el input mediante la funcion ya utilizasa anteriormente leerNum()
```c++
void leds() {

  cout << "Digite el valor R: " << endl;
  float red = stoi(leerNum());

  while (red > 255) {
    cout << "Digite un valor dentro del rango [0-255]: " << endl;
    red = stoi(leerNum());
  }

  cout << "Digite el valor G: " << endl;
  float green = stoi(leerNum());

  while (green > 255) {
    cout << "Digite un valor dentro del rango [0-255]: " << endl;
    green = stoi(leerNum());
  }

  cout << "Digite valor de B" << endl;
  float blue = stoi(leerNum());

  while (blue > 255) {
    cout << "Digite un valor dentro del rango [0-255]: " << endl;
    blue = stoi(leerNum());
  }

  // Asignar valor de color a los leds
  float R = 1-((float)(red / 255.0f));
  float G = 1-((float)(green / 255.0f));
  float B = 1-((float)(blue / 255.0f));

  setRGBColor(R,G,B);

  
}
```

*Los valores digitados por el usuario son guardados en una variable la cual se tiene que pasar a float en un intervalo de [0,1] indicando la intensidad de la luz en cada LED, siendo 0 estado alto y 1 estado bajo debido a la conexion con el sistema embebido.
*mediante la funcion setRGBColor() se le asigna a los LEDS inicalizados su respectiva intensidad.
```c++
PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);

void setRGBColor(float red, float green, float blue) {
  ledR = red;
  ledG = green;
  ledB = blue;
}
```
