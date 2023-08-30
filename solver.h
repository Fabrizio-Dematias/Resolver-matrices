#pragma once
#include <iostream>
#include <vector>
#include "ui.h"
#include "color.hpp"
#include "eqparser.h"

using namespace std;



void solve(vector<vector<double>> matrix, int n)
{
    /*
    Tomara como parametro un vector de vectores formados por doubles y un entero n.
    Luego resolovera la matriz utilizando el metodo de Gauss-Jordan e imprimira
    cada uno de los pasos realizados junto al resultado final.
    */
    vector<double> result(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0.0)
        {
            cout << "No puedes dividir por 0." << endl;
            break;
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
                string action = "Fila " + to_string(j + 1) + " + " + "Fila " + to_string(i + 1) + " * " + to_string(-ratio);
                cout << dye::colorize(action,"aqua") << endl;
                printAugmentedMatrix(matrix);
                cout << endl;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        double ratio = matrix[i][i];
        for (int j = 0; j <= n; j++)
        {
            matrix[i][j] = matrix[i][j] / ratio;
        }
    }
    printAugmentedMatrix(matrix);
    for (int i = 0; i < n; i++)
    {
        string result = "X" + to_string(i + 1) + " = " + to_string(matrix[i][n]);
        cout << dye::colorize(result, "aqua").invert() << endl;
    }
    system("pause");
}

void fillMatrix()
{
    /*
    Pedira ingresar un valor N para generar una matriz N*N+1, interpretando N+1 como
    el resultado de la matriz aumentada y luego en base a la matriz solicitada permitira al usuario
    ingresar los valores de la matriz.
    Luego llamara a la funcion encargada de resolver la matriz.
    */
    int n;
    int val;
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
            cout << "Introduce el valor de la posición [" << i << "][" << j << "]: ";
            cin >> val;
            vec[i].push_back(val);
        }
    }
    system("cls");
    cout << "La matriz ingresada fue: " << endl;
    printAugmentedMatrix(vec);
    solve(vec, n);
}

void fillMatrixFromParsedEquation(vector<vector<Coeficient>> equation) {
    /*
    Tomara como parametro un vector de vectores formados con Coefiecientes, los cuales
    representan una ecuacion y los ordenará para luego generar una matriz y llamar a
    la funcion solve, la cual se encargará de resolverla.
    */
    vector<vector<double>> vec;
    equation = orderCoeficients(equation);
    int n = equation[0].size();

    for (int i = 0; i < equation.size(); i++)
    {
        vec.push_back(vector<double>());
    }
    for (int i = 0; i < equation.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            vec[i].push_back(equation[i][j].value);
        }

    }
    system("cls");
    cout << "La matriz ingresada fue:" << endl;
    printAugmentedMatrix(vec);
    solve(vec, equation.size());
}