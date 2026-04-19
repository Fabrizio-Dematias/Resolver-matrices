#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "ui.h"
#include "color.hpp"
#include "eqparser.h"

using namespace std;

void solve(vector<vector<double>> matrix, int n)
{
    /*
    Resuelve un sistema NxN usando Gauss-Jordan con pivoteo parcial.
    Muestra cada paso hasta obtener la matriz identidad aumentada.
    */
    for (int i = 0; i < n; i++)
    {
        // Pivoteo parcial: buscar la fila con mayor valor absoluto en la columna i
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i]))
                maxRow = k;
        }
        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
            string swapAction = "Intercambio Fila " + to_string(i + 1) + " <-> Fila " + to_string(maxRow + 1);
            cout << dye::colorize(swapAction, "yellow") << endl;
            printAugmentedMatrix(matrix);
            cout << endl;
        }

        if (fabs(matrix[i][i]) < 1e-12)
        {
            cout << dye::colorize("El sistema no tiene solucion unica (pivote nulo en columna " + to_string(i + 1) + ").", "red") << endl;
            pauseScreen();
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k <= n; k++)
                {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
                string action = "Fila " + to_string(j + 1) + " + Fila " + to_string(i + 1) + " * " + to_string(-ratio);
                cout << dye::colorize(action, "aqua") << endl;
                printAugmentedMatrix(matrix);
                cout << endl;
            }
        }
    }

    // Normalizar cada fila dividiendo por el pivote
    for (int i = 0; i < n; i++)
    {
        double pivot = matrix[i][i];
        for (int j = 0; j <= n; j++)
        {
            matrix[i][j] = matrix[i][j] / pivot;
        }
    }

    printAugmentedMatrix(matrix);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        string result = "X" + to_string(i + 1) + " = " + to_string(matrix[i][n]);
        cout << dye::colorize(result, "aqua").invert() << endl;
    }
    pauseScreen();
}

void fillMatrix()
{
    /*
    Solicita N y construye una matriz aumentada NxN+1.
    Acepta valores decimales (double).
    */
    int n;
    cout << "Introduce N para realizar la matriz NxN: ";
    cin >> n;
    vector<vector<double>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(vector<double>());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            double val;
            cout << "Introduce el valor de la posicion [" << i << "][" << j << "]: ";
            cin >> val;
            vec[i].push_back(val);
        }
    }
    system("clear");
    cout << "La matriz ingresada fue: " << endl;
    printAugmentedMatrix(vec);
    solve(vec, n);
}

void fillMatrixFromParsedEquation(vector<vector<Coeficient>> equation) {
    /*
    Convierte un sistema de ecuaciones parseado en una matriz aumentada y lo resuelve.
    */
    vector<vector<double>> vec;
    equation = orderCoeficients(equation);
    int n = equation[0].size();

    for (int i = 0; i < (int)equation.size(); i++)
    {
        vec.push_back(vector<double>());
    }
    for (int i = 0; i < (int)equation.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            vec[i].push_back(equation[i][j].value);
        }
    }
    system("clear");
    cout << "La matriz ingresada fue:" << endl;
    printAugmentedMatrix(vec);
    solve(vec, equation.size());
}
