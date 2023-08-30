#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "ui.h"

using namespace std;


void addMatrixes(vector<vector<double>> a, vector<vector<double>> b)
{
    /*
    Tomara como parametros 2 matrices y verificará que ambas sean de N*M.
    Si su tamaño es distinto se cortará la ejecucion con un mensaje y en caso afirmativo
    se generara una matriz nueva con la suma elemento a elemento de a y b.
    */
    vector<vector<double>> result;
    int aN = a.size(), aM = a[0].size();
    int bN = b.size(), bM = b[0].size();
    if (aN != bN || aM != bM)
    {
        cout << "Las matrices no son compatibles para la suma." << endl;
        system("pause");
    }
    else {
        for (int i = 0; i < aN; i++)
        {
            vector<double> row;
            for (int j = 0; j < aM; j++)
            {
                row.push_back(a[i][j] + b[i][j]);
            }
            result.push_back(row);
        }
        system("cls");
        cout << dye::colorize("La primera matriz ingresada fue: ", "aqua") << endl;
        printMatrix(a);
        cout << dye::colorize("La segunda matriz ingresada fue: ", "aqua") << endl;
        printMatrix(b);
        cout << dye::colorize("La matriz resultante es: ", "aqua") << endl;
        printMatrix(result);
        system("pause");
    }
}

void subtractMatrixes(vector<vector<double>> a, vector<vector<double>> b)
{
    /*
    Tomara como parametros 2 matrices y verificará que ambas sean de N*M.
    Si su tamaño es distinto se cortará la ejecucion con un mensaje y en caso afirmativo
    se generara una matriz nueva con la resta elemento a elemento de a y b.
    */
    vector<vector<double>> result;
    int aN = a.size(), aM = a[0].size();
    int bN = b.size(), bM = b[0].size();
    if (aN != bN || aM != bM)
    {
        cout << "Las matrices no son compatibles para la suma." << endl;
        system("pause");
    }
    else {
        for (int i = 0; i < aN; i++)
        {
            vector<double> row;
            for (int j = 0; j < aM; j++)
            {
                row.push_back(a[i][j] - b[i][j]);
            }
            result.push_back(row);
        }
        system("cls");
        cout << dye::colorize("La primera matriz ingresada fue: ", "aqua") << endl;
        printMatrix(a);
        cout << dye::colorize("La segunda matriz ingresada fue: ", "aqua") << endl;
        printMatrix(b);
        cout << dye::colorize("La matriz resultante es: ", "aqua") << endl;
        printMatrix(result);
        system("pause");
    }
}

void multiplyMatrixes(vector<vector<double>> a, vector<vector<double>> b)
{
    /*
    Tomara como parametros 2 matrices y verificará que ambas sean de N*M.
    Si su tamaño es distinto se cortará la ejecucion con un mensaje y en caso afirmativo
    se generara una matriz nueva con la multiplicación elemento a elemento de a y b.
    */
    vector<vector<double>> result;
    int aN = a.size(), aM = a[0].size();
    int bN = b.size(), bM = b[0].size();
    if (aN != bN || aM != bM)
    {
        cout << "Las matrices no son compatibles para la suma." << endl;
        system("pause");
    }
    else {
        for (int i = 0; i < aN; i++)
        {
            vector<double> row;
            for (int j = 0; j < aM; j++)
            {
                row.push_back(a[i][j] * b[i][j]);
            }
            result.push_back(row);
        }
        system("cls");
        cout << dye::colorize("La primera matriz ingresada fue: ", "aqua") << endl;
        printMatrix(a);
        cout << dye::colorize("La segunda matriz ingresada fue: ", "aqua") << endl;
        printMatrix(b);
        cout << dye::colorize("La matriz resultante es: ", "aqua") << endl;
        printMatrix(result);
        system("pause");
    }
}

void transpose(vector<vector<double>> matrix) {
    /*
    Tomara como paramentro una matriz la cual recorrerá verticalmente para generar
    una nueva matriz transpuesta a la original.
    */
    vector<vector<double>> result;
    vector<double> vec;
    for (int i = 0; i < matrix[0].size(); i++) {
        vector<double> vec;
        for (int k = 0; k < matrix.size(); k++) {
            vec.push_back(matrix[k][i]);   
        }
        result.push_back(vec);
    }
    system("cls");
    cout << dye::colorize("La matriz ingresada fue: ", "aqua") << endl;
    printMatrix(matrix);
    cout << dye::colorize("La transpuesta de la matriz ingresada es: ", "aqua") << endl;
    printMatrix(result);
    system("pause");
}


void determinant(vector<vector<double>> inputMatrix) {
    /*
    Tomara como parametro una matriz y revisara que la misma sea cuadrada.
    Realizara una reduccion por Gauss-Jordan a todos los elementos debajo de la diagonal, en caso
    de toparse con una division por 0, sustituíra el 0 por un numero muy cercano a 0 para que la cuenta sea valida.
    Una vez reducida, la multiplicacion de todos los elementos de la diagonal nos dara una aproximación al valor del
    determinante con un margen de error de 1 para matrices de longitud mayor que 10x10.
    */
    int n = inputMatrix.size();
    int n0 = inputMatrix[0].size();
    string action = "";
    if (n != n0) {
        system("cls");
        cout << dye::colorize("La matriz debe ser cuadrada para obtener su determinante!", "red") << endl;
        system("pause");
        return;
    }
    vector<vector<double>> matrix = inputMatrix;
    system("cls");
    cout << dye::colorize("La matrix ingresada fue:", "aqua") << endl;
    printMatrix(inputMatrix);
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (matrix[i][i] == 0) {
                matrix[i][i] = 0.000000000000001;
            }
            double ratio = matrix[k][i] / matrix[i][i];
            for (int j = 0; j < n; j++) {
                matrix[k][j] = matrix[k][j] - ratio * matrix[i][j];
            }
            action = "Fila " + to_string(k + 1) + " + " + "Fila " + to_string(i + 1) + " * " + to_string(-ratio);
            cout << dye::colorize(action, "aqua") << endl;
            printMatrix(matrix);
        }
    }
    double product = 1.0;
    for (int i = 0; i < n; i++) {
        product *= matrix[i][i];
    }
    cout << dye::colorize("Multiplicando los elementos de la diagonal, se obtiene...", "aqua") << endl;
    cout << "Det: " << product << endl;
    system("pause");
}