/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>


UnbufferedSerial pc(USBTX,USBRX,9600);
using namespace std;
const int numRows = 4;
const int numCols = 3;

char keyMap[numRows][numCols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

DigitalOut rowPins[numRows] = {DigitalOut(D2), DigitalOut(D3), DigitalOut(D4), DigitalOut(D5)};
DigitalIn colPins[numCols] = {DigitalIn(D6), DigitalIn(D7), DigitalIn(D8)};

int leerNum(){
        char num;
        for (int i = 0; i < numRows; i++) {
            rowPins[i] = 0;
            
            for (int j = 0; j < numCols; j++) {
                if (!colPins[j]) {
                    if(keyMap[i][j]!='*'){
                        num+=keyMap[i][j];
                        printf("Tecla presionada: %c\n", num);
                    }else {
                        break;
                    }
                
                    ThisThread::sleep_for(500ms);  // Evita lecturas múltiples mientras la tecla está presionada
                }
            }

            rowPins[i] = 1;
        }
        return num-'0';
        
    }

int main() {
    int num;
        
    cout << "Elija una opción (solo el número):\n" << endl;
    cout << "1. Aplicación calcule pendiente e intercepto mediante dos puntos.\n" <<endl;
    cout << "2. Calcular promedio y desviación estándar de un conjunto de temperaturas.\n" << endl;
    cout << "3. Generar colores en un LED RGB: \n"  <<endl;
    
    
    int numero;

    while (true) {
        numero = leerNum();
        cout<<numero;

        if(numero==1){
            cout<< "Digite la coordenada x del primer punto\n";
            int x1=leerNum();
            cout<< "Digite la coordenada y del primer punto";
            int y1=leerNum();
            cout<< "Digite la coordenada x del segundo punto";
            int x2=leerNum();
            cout<< "Digite la coordenada y del segundo punto";
            int y2=leerNum();

            int m=y2-y1/(x2-x1);
            int intercepto= -1*x1*m+y1;
            cout << "La pendiente es: ", m;
            cout << "El intercepto es: " ,intercepto;



        }else if(numero==2){
            cout <<"Digite el numero de temperaturas a introducir: ";
            int n=leerNum();
            int temp[n];
            for (int i = 0; i < n; i++) {
                cout<<"Ingrese la ", i," temperatura: \n";
                temp[i]=leerNumero();

            }
            
        }

    }
}
