#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <string>


using namespace std;


struct Coeficient
{
    int value;
    string var;
};

Coeficient lookupComponent(vector<Coeficient> eq, string correctVar) {
    /*
    Tomara como paramentro un vector de coeficientes, el cual representa una ecuacion, y la variable
    de la ecuacion a buscar, una vez encontrada la retornara.
    */
    for (int i = 0; i < eq.size(); i++) {
        if (eq[i].var == correctVar) {
            return eq[i];
        }
    }
}

vector<vector<Coeficient>> orderCoeficients(vector<vector<Coeficient>> eq) {
    /*
    Tomara como parametro un vector de vectores formados con Coefiecientes, los cuales
    representan una ecuacion.
    En base a la primera ecuacion se definira el orden el cual los elementos deben utilizar y luego
    se corroborara que los coeficientes lo cumplan, en caso de no hacerlo se intercambiaran de posicion
    los coeficientes afectados.
    */
    vector<vector<Coeficient>> equation = eq;
    vector<string> varOrder;
    for (int i = 0; i < eq[0].size(); i++) {
        varOrder.push_back(eq[0][i].var);
    }
    for (int i = 0; i < eq.size(); i++) {
        for (int j = 0; j < eq[i].size(); j++) {
            if (eq[i][j].var != varOrder[j]) {
                Coeficient correctedCoef = lookupComponent(eq[i], varOrder[j]);
                equation[i][j].var = correctedCoef.var;
                equation[i][j].value = correctedCoef.value;
            }
        }
    }
    return equation;
}

vector<Coeficient> cleanCoeficients(vector<string> coeficients)
{
    /*
    Toma como parametro un vector de strings correspondientes a coeficientes
    de una ecuacion y combierte a cada elemento a una estructura Coeficiente,
    a la cual se le asigna un valor y su variable. Cada uno de estos elementos
    se los agrega al vector que será retornado.
    */
    vector<Coeficient> result;
    for (int i = 0; i < coeficients.size(); i++)
    {
        Coeficient coef;
        if (isdigit(coeficients[i].back()))
        {
            if (coeficients[i].front() == '-')
            {
                coef.value = -1 * stoi(coeficients[i].substr(1, coeficients[i].size() - 1));
            }
            else
            {
                coef.value = stoi(coeficients[i].substr(1, coeficients[i].size() - 1));
            }
            coef.var = "X" + to_string(1);
            result.push_back(coef);
            break;
        }
        if (coeficients[i].front() == '-')
        {
            coef.var = coeficients[i].back();
            coef.value = -1 * stoi(coeficients[i].substr(1, coeficients[i].size() - 2));
        }
        else
        {
            coef.var = coeficients[i].back();
            coef.value = stoi(coeficients[i].substr(1, coeficients[i].size() - 2));
        }
        result.push_back(coef);
    }
    return result;
}

vector<Coeficient> parseEqCoeficients(string equation)
{
    /*
    Funcion que separa la ecuacion en sus distintos coeficientes.
    Toma como parametro un string que representa a una ecuacion y luego
    en base a los signos reconoce los coeficientes de la ecuacion y los guarda
    en un vector de strings. Una vez guardados se limpiaran y se retornara
    un vector de Struct::Coeficientes.

    --> -1x+2y=0
    > -1x lastIndex=3
    > +2y lastIndex=6
    > 0

    {"-1x", "+2y", 0}
    */
    int lastIndex = 0;
    vector<string> coeficients;
    for (int i = 0; i < equation.length(); i++)
    {
        if (equation[i] == '+' || equation[i] == '-')
        {
            if (i == 0)
            {
                continue;
            }
            if (lastIndex == 0)
            {
                if (isdigit(equation[0]))
                {
                    coeficients.push_back("+" + equation.substr(lastIndex, i - lastIndex));
                    lastIndex = i + 1;
                    continue;
                }
                else
                {
                    coeficients.push_back(equation.substr(lastIndex, i - lastIndex));
                    lastIndex = i + 1;
                    continue;
                }
            }
            coeficients.push_back(equation[lastIndex - 1] + equation.substr(lastIndex, i - lastIndex));
            lastIndex = i + 1;
        }
        if (equation[i] == '=')
        {
            coeficients.push_back(equation.substr(lastIndex - 1, i - lastIndex + 1));
            if (isdigit(equation[i + 1]))
            {
                coeficients.push_back("+" + equation.substr(i + 1, equation.length() - i));
            }
            else
            {
                coeficients.push_back(equation.substr(i + 1, equation.length() - i));
            }
            break;
        }
    }
    vector<Coeficient> result = cleanCoeficients(coeficients);
    return result;
}