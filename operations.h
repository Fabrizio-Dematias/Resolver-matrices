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
    Suma elemento a elemento. Requiere matrices del mismo tamanio.
    */
    int aN = a.size(), aM = a[0].size();
    int bN = b.size(), bM = b[0].size();
    if (aN != bN || aM != bM)
    {
        cout << "Las matrices no son compatibles para la suma (deben tener las mismas dimensiones)." << endl;
        pauseScreen();
        return;
    }
    vector<vector<double>> result;
    for (int i = 0; i < aN; i++)
    {
        vector<double> row;
        for (int j = 0; j < aM; j++)
        {
            row.push_back(a[i][j] + b[i][j]);
        }
        result.push_back(row);
    }
    system("clear");
    cout << dye::colorize("La primera matriz ingresada fue: ", "aqua") << endl;
    printMatrix(a);
    cout << dye::colorize("La segunda matriz ingresada fue: ", "aqua") << endl;
    printMatrix(b);
    cout << dye::colorize("La matriz resultante es: ", "aqua") << endl;
    printMatrix(result);
    pauseScreen();
}

void subtractMatrixes(vector<vector<double>> a, vector<vector<double>> b)
{
    /*
    Resta elemento a elemento. Requiere matrices del mismo tamanio.
    */
    int aN = a.size(), aM = a[0].size();
    int bN = b.size(), bM = b[0].size();
    if (aN != bN || aM != bM)
    {
        cout << "Las matrices no son compatibles para la resta (deben tener las mismas dimensiones)." << endl;
        pauseScreen();
        return;
    }
    vector<vector<double>> result;
    for (int i = 0; i < aN; i++)
    {
        vector<double> row;
        for (int j = 0; j < aM; j++)
        {
            row.push_back(a[i][j] - b[i][j]);
        }
        result.push_back(row);
    }
    system("clear");
    cout << dye::colorize("La primera matriz ingresada fue: ", "aqua") << endl;
    printMatrix(a);
    cout << dye::colorize("La segunda matriz ingresada fue: ", "aqua") << endl;
    printMatrix(b);
    cout << dye::colorize("La matriz resultante es: ", "aqua") << endl;
    printMatrix(result);
    pauseScreen();
}

void multiplyMatrixes(vector<vector<double>> a, vector<vector<double>> b)
{
    /*
    Multiplicacion matricial real: A(aN x aM) * B(bN x bM) requiere aM == bN.
    El resultado es una matriz de aN x bM.
    */
    int aN = a.size(), aM = a[0].size();
    int bN = b.size(), bM = b[0].size();
    if (aM != bN)
    {
        cout << "Las matrices no son compatibles para la multiplicacion." << endl;
        cout << "(Las columnas de la primera deben ser iguales a las filas de la segunda)" << endl;
        pauseScreen();
        return;
    }
    vector<vector<double>> result(aN, vector<double>(bM, 0.0));
    for (int i = 0; i < aN; i++)
        for (int j = 0; j < bM; j++)
            for (int k = 0; k < aM; k++)
                result[i][j] += a[i][k] * b[k][j];

    system("clear");
    cout << dye::colorize("La primera matriz ingresada fue: ", "aqua") << endl;
    printMatrix(a);
    cout << dye::colorize("La segunda matriz ingresada fue: ", "aqua") << endl;
    printMatrix(b);
    cout << dye::colorize("La matriz resultante es: ", "aqua") << endl;
    printMatrix(result);
    pauseScreen();
}

void transpose(vector<vector<double>> matrix) {
    /*
    Genera la transpuesta intercambiando filas por columnas.
    */
    vector<vector<double>> result;
    for (int i = 0; i < (int)matrix[0].size(); i++) {
        vector<double> row;
        for (int k = 0; k < (int)matrix.size(); k++) {
            row.push_back(matrix[k][i]);
        }
        result.push_back(row);
    }
    system("clear");
    cout << dye::colorize("La matriz ingresada fue: ", "aqua") << endl;
    printMatrix(matrix);
    cout << dye::colorize("La transpuesta de la matriz ingresada es: ", "aqua") << endl;
    printMatrix(result);
    pauseScreen();
}

void determinant(vector<vector<double>> inputMatrix) {
    /*
    Calcula el determinante por eliminacion de Gauss con pivoteo parcial.
    Multiplica los elementos de la diagonal de la matriz triangular superior.
    Cada intercambio de filas cambia el signo del determinante.
    */
    int n = inputMatrix.size();
    int n0 = inputMatrix[0].size();
    if (n != n0) {
        system("clear");
        cout << dye::colorize("La matriz debe ser cuadrada para obtener su determinante!", "red") << endl;
        pauseScreen();
        return;
    }
    vector<vector<double>> matrix = inputMatrix;
    system("clear");
    cout << dye::colorize("La matriz ingresada fue:", "aqua") << endl;
    printMatrix(inputMatrix);

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        // Pivoteo parcial
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i]))
                maxRow = k;
        }
        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
            swaps++;
            string swapAction = "Intercambio Fila " + to_string(i + 1) + " <-> Fila " + to_string(maxRow + 1);
            cout << dye::colorize(swapAction, "yellow") << endl;
            printMatrix(matrix);
        }

        if (fabs(matrix[i][i]) < 1e-12) {
            cout << dye::colorize("Det: 0 (matriz singular)", "red") << endl;
            pauseScreen();
            return;
        }

        for (int k = i + 1; k < n; k++) {
            double ratio = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; j++) {
                matrix[k][j] -= ratio * matrix[i][j];
            }
            string action = "Fila " + to_string(k + 1) + " + Fila " + to_string(i + 1) + " * " + to_string(-ratio);
            cout << dye::colorize(action, "aqua") << endl;
            printMatrix(matrix);
        }
    }
    double product = (swaps % 2 == 0) ? 1.0 : -1.0;
    for (int i = 0; i < n; i++) {
        product *= matrix[i][i];
    }
    cout << dye::colorize("Multiplicando los elementos de la diagonal...", "aqua") << endl;
    cout << dye::colorize("Det: " + to_string(product), "aqua").invert() << endl;
    pauseScreen();
}
