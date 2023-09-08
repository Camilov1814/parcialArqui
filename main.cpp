/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
#include <string>

// blinking rate en milisegundos
#define BLINKING_RATE 200ms
// conexion serial con el pc
UnbufferedSerial pc(USBTX, USBRX, 9600);
using namespace std;

PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);

void setRGBColor(float red, float green, float blue) {
  ledR = red;
  ledG = green;
  ledB = blue;
}

const int numRows = 4;
const int numCols = 3;

string keyMap[4][3] = {
    {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}, {"*", "0", "#"}};

DigitalIn rowPins[numRows] = {DigitalIn(D2), DigitalIn(D3), DigitalIn(D4),
                              DigitalIn(D5)};
DigitalOut colPins[numCols] = {DigitalOut(D6), DigitalOut(D7), DigitalOut(D8)};

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

float calcular_promedio(float arr[], int n) {
  float suma = 0;
  for (int i = 0; i < n; i++) {
    suma += arr[i];
  }
  return suma / n;
}

float calcular_desviacion_estandar(float arr[], int n, float promedio) {
  float suma_cuadrados = 0;
  for (int i = 0; i < n; i++) {
    suma_cuadrados += pow(arr[i] - promedio, 2);
  }
  return sqrt(suma_cuadrados / n);
}

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

int opcion;
int main() {
  

    cout << "Elija una opción (solo el número) y seguido presione * para aceptar el valor" << endl;
    cout
        << "1. Aplicación calcule pendiente e intercepto mediante dos puntos.\n"
        << endl;
    cout << "2. Calcular promedio y desviación estándar de un conjunto de "
            "temperaturas.\n"
         << endl;
    cout << "3. Generar colores en un LED RGB: \n" << endl;

    // Leer la elección del usuario desde el teclado de membrana
    while (opcion < 1 || opcion > 3) {
      cout << "Ingrese una opcion valida" << endl;
      opcion = stoi(leerNum());
    }

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

}

