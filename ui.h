#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "color.hpp"

using namespace std;

void printMenu()
{
    /*
    Funcion encargada de imprimir el menu principal del progrmama.
    */
    cout << dye::colorize("  _____         __  __ _____      ______ _    _  ____  ", "red") << endl;
    cout << dye::colorize(" / ____|  /\\   |  \\/  |  __ \\/\\  /  ____| |  | |/ __ \\ ", "red") << endl;
    cout << dye::colorize("| (___   /  \\  | \\  / | |__)/  \\ | |    | |__| | |  | |", "red") << endl;
    cout << dye::colorize(" \\___ \\ / /\\ \\ | |\\/| | ___/ /\\ \\| |    |  __  | |  | |", "red") << endl;
    cout << dye::colorize(" ____) / ____ \\| |  | | | / ____ \\ |____| |  | | |__| |", "red") << endl;
    cout << dye::colorize("|_____/_/    \\_| |  |_|_|/_/    \\_\\_____|_|  |_|\\____/ ", "red") << endl << endl;

    cout << dye::aqua("Selecciona la opcion deseada: ") << endl;
    cout << "(1) Resolver sistema de ecuaciones." << endl;
    cout << "(2) Resolver matriz NxN." << endl;
    cout << "(3) Realizar suma de matrices." << endl;
    cout << "(4) Realizar resta de matrices." << endl;
    cout << "(5) Realizar multiplicacion de matrices." << endl;
    cout << "(6) Transponer una matriz." << endl;
    cout << "(7) Determinante una matriz." << endl;
    cout << "(8) Como funciona este sistema? " << endl;
    cout << "(9) Terminar Programa." << endl;
}

void help() {
    /*
    Funcion encargada de imprimir ayuda e informacion de como funciona el sistema.
    */
    cout << dye::colorize("AYUDA", "aqua").invert() << endl;
    cout << dye::colorize("1)", "aqua").invert() << " Resolver sistema de ecuaciones. Como funciona esta opcion? " << endl;
    cout << " Dentro de esta opcion tendras la posibilidad de resolver algun sistema ecuacion. Para ello deberas introducir el numero de ecuaciones que conforman el sistema y sus ecuaciones. " << endl;
    cout << " Ej. : " << endl;
    cout << " 1)	4x + 1y = -3 " << endl;
    cout << " 2)	2y - 1x = 2 " << endl;
    cout << " Los coeficientes pueden ser puestos en distinto orden y toda variable debe estar acompañada de su valor. 2y - x = 2 NO seria un ejemplo valido. " << endl;
    cout << " - Aclaracion: solo funciona con sistemas NxN. " << endl;
    cout << endl;
    cout << dye::colorize("2)", "aqua").invert() << " Resolver matriz NxN. Como funciona esta opcion? " << endl;
    cout << "En esta opcion se debera introducir una matriz aumentada y este arrojara la solución de la misma mostrando paso por paso. " << endl;
    cout << endl;
    cout << dye::colorize("3)", "aqua").invert() << " Realizar suma de matrices. " << endl;
    cout << " Para utilizar esta opcion, el usuario ingresara la cantidad de filas y columnas de las dos matrices que quiere sumar y los valores de la matriz. " << endl;
    cout << " NOTA: Lo mismo ocurre con la resta, multiplicacion y transponer de una matriz. " << endl;
    cout << endl;
    cout << dye::colorize("4)", "aqua").invert() << " Determinante de una matriz. " << endl;
    cout << " Se ingresa una matriz cuadrada y este arrojara el determinante de esta. " << endl;
}

void printMatrix(vector<vector<double>> matrix)
{
    /*
    Funcion encargada de imprimir matrices.
    */
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (j == matrix[i].size() - 1)
            {
                cout << matrix[i][j] << "]";
                continue;
            }
            else
            {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void printAugmentedMatrix(vector<vector<double>> matrix)
{
    /*
    Funcion encargada de imprimir matrices aumentadas.
    */
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (j == matrix[i].size() - 1)
            {
                cout << "|   " << matrix[i][j] << "]";
                continue;
            }
            else if (j == matrix[i].size() - 2)
            {
                cout << matrix[i][j] << "   ";
            }
            else
            {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
}



vector<vector<double>> reqMatrix()
{
    /*
    Generara una matriz de tamaño N*M, siendo N y M valores ingresados por el usuario, luego
    en base a N y M solicitara cada uno de los elementos de la matriz y retornara la matriz generada.
    */
    int n, m;
    cout << "Ingrese el número de filas: ";
    cin >> n;
    cout << "Ingrese el número de columnas: ";
    cin >> m;
    vector<vector<double>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<double> row;
        for (int j = 0; j < m; j++)
        {
            double value;
            cout << "Ingrese el valor de la posición [" << i << "][" << j << "]: ";
            cin >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    return matrix;
}