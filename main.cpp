#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "ui.h"
#include "eqparser.h"
#include "operations.h"
#include "solver.h"

using namespace std;

/*
   ESTRUCTURA DEL PROGRAMA
   -----------------------

-> Sampacho-Algebra
   |
   |-- main.cpp
   |   |
   |   |> Ciclo principal del programa.
   |
   |-- eqparser.h
   |   |
   |   |> Parseo de ecuaciones y ordenamiento de coeficientes.
   |
   |-- solver.h
   |   |
   |   |> Generación y resolución de matrices.
   |
   |-- operations.h
   |   |
   |   |> Operaciones matriciales y calculos.
   |
   |-- ui.h
   |   |
   |   |> Metodos relacionados con la interfaz del usuario.
*/


int main()
{
    /*
    Funcion principal del programa, se encargara de pedir infinitamente la opcion deseada
    y ejecutar las funciones acordes, si la opcion ingresada es "9" el programa finalizara.
    */
    vector<vector<Coeficient>> linearSystem;
    vector<vector<Coeficient>> emptyVector;
    vector<vector<double>> m1;
    vector<vector<double>> m2;
    while (true)
    {
        int option;
        system("cls");
        printMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            int amountOfEq;
            cout << "Introduce el numero de ecuaciones a ingresar: ";
            cin >> amountOfEq;
            for (int i = 0; i < amountOfEq; i++)
            {
                string equation;
                cout << "Introduce la ecuacion " << i + 1 << ": ";
                cin >> equation;
                vector<Coeficient> parsedEquation = parseEqCoeficients(equation);
                linearSystem.push_back(parsedEquation);
            }
            fillMatrixFromParsedEquation(linearSystem);
            linearSystem = emptyVector; // reset
            break;
        case 2:
            fillMatrix();
            break;
        case 3:
            m1 = reqMatrix();
            m2 = reqMatrix();
            addMatrixes(m1, m2);
            break;
        case 4:
            m1 = reqMatrix();
            m2 = reqMatrix();
            subtractMatrixes(m1, m2);
            break;
        case 5:
            m1 = reqMatrix();
            m2 = reqMatrix();
            multiplyMatrixes(m1, m2);
            break;
        case 6:
            m1 = reqMatrix();
            transpose(m1);
            break;
        case 7:
            m1 = reqMatrix();
            determinant(m1);
            break;
        case 8:
            system("cls");
            help();
            system("pause");
            break;
        case 9:
            exit(0);
            return 0;
        default:
            cout << "Opcion no valida." << endl;
            system("pause");
        }
    }
    return 0;
}