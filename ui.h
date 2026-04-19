#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
#include "color.hpp"

using namespace std;

void pauseScreen() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printMenu()
{
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
    cout << dye::colorize("AYUDA", "aqua").invert() << endl;
    cout << dye::colorize("1)", "aqua").invert() << " Resolver sistema de ecuaciones." << endl;
    cout << " Introduce el numero de ecuaciones y cada una en formato: 4x+1y=-3" << endl;
    cout << " Toda variable debe tener su coeficiente. Ej: 1x-2y=5 (no 'x-2y=5')" << endl;
    cout << " Solo funciona con sistemas NxN." << endl;
    cout << endl;
    cout << dye::colorize("2)", "aqua").invert() << " Resolver matriz NxN aumentada." << endl;
    cout << " Introduce N y luego los valores de la matriz aumentada (N columnas + resultado)." << endl;
    cout << endl;
    cout << dye::colorize("3)", "aqua").invert() << " Suma de matrices." << endl;
    cout << " Ambas matrices deben tener las mismas dimensiones." << endl;
    cout << endl;
    cout << dye::colorize("4)", "aqua").invert() << " Resta de matrices." << endl;
    cout << " Ambas matrices deben tener las mismas dimensiones." << endl;
    cout << endl;
    cout << dye::colorize("5)", "aqua").invert() << " Multiplicacion de matrices." << endl;
    cout << " Las columnas de la primera deben ser iguales a las filas de la segunda." << endl;
    cout << endl;
    cout << dye::colorize("6)", "aqua").invert() << " Transponer una matriz." << endl;
    cout << endl;
    cout << dye::colorize("7)", "aqua").invert() << " Determinante de una matriz cuadrada." << endl;
}

void printMatrix(vector<vector<double>> matrix)
{
    for (int i = 0; i < (int)matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < (int)matrix[i].size(); j++)
        {
            if (j == (int)matrix[i].size() - 1)
            {
                cout << matrix[i][j] << "]";
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
    for (int i = 0; i < (int)matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < (int)matrix[i].size(); j++)
        {
            if (j == (int)matrix[i].size() - 1)
            {
                cout << "|   " << matrix[i][j] << "]";
            }
            else if (j == (int)matrix[i].size() - 2)
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
    int n, m;
    cout << "Ingrese el numero de filas: ";
    cin >> n;
    cout << "Ingrese el numero de columnas: ";
    cin >> m;
    vector<vector<double>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<double> row;
        for (int j = 0; j < m; j++)
        {
            double value;
            cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";
            cin >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    return matrix;
}
