#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

struct Coeficient
{
    double value;
    string var;
};

Coeficient lookupComponent(vector<Coeficient> eq, string correctVar) {
    /*
    Busca una variable dentro de un vector de coeficientes.
    Si no la encuentra, retorna un coeficiente con valor 0.
    */
    for (int i = 0; i < (int)eq.size(); i++) {
        if (eq[i].var == correctVar) {
            return eq[i];
        }
    }
    Coeficient notFound;
    notFound.value = 0;
    notFound.var = correctVar;
    return notFound;
}

vector<vector<Coeficient>> orderCoeficients(vector<vector<Coeficient>> eq) {
    /*
    Ordena los coeficientes de cada ecuacion segun el orden de la primera.
    */
    vector<vector<Coeficient>> equation = eq;
    vector<string> varOrder;
    for (int i = 0; i < (int)eq[0].size(); i++) {
        varOrder.push_back(eq[0][i].var);
    }
    for (int i = 0; i < (int)eq.size(); i++) {
        for (int j = 0; j < (int)eq[i].size(); j++) {
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
    Convierte strings de coeficientes a estructuras Coeficient con valor (double) y variable.
    */
    vector<Coeficient> result;
    for (int i = 0; i < (int)coeficients.size(); i++)
    {
        Coeficient coef;
        if (isdigit(coeficients[i].back()))
        {
            // Es el termino independiente (lado derecho del =)
            if (coeficients[i].front() == '-')
            {
                coef.value = -1 * stod(coeficients[i].substr(1, coeficients[i].size() - 1));
            }
            else
            {
                coef.value = stod(coeficients[i].substr(1, coeficients[i].size() - 1));
            }
            coef.var = "X" + to_string(1);
            result.push_back(coef);
            break;
        }
        if (coeficients[i].front() == '-')
        {
            coef.var = string(1, coeficients[i].back());
            coef.value = -1 * stod(coeficients[i].substr(1, coeficients[i].size() - 2));
        }
        else
        {
            coef.var = string(1, coeficients[i].back());
            coef.value = stod(coeficients[i].substr(1, coeficients[i].size() - 2));
        }
        result.push_back(coef);
    }
    return result;
}

vector<Coeficient> parseEqCoeficients(string equation)
{
    /*
    Separa una ecuacion en sus coeficientes.
    Formato esperado: 4x+1y=-3  o  -1x+2y=5

    Ejemplo: -1x+2y=0
    > "-1x", "+2y", "+0"
    */
    int lastIndex = 0;
    vector<string> coeficients;
    for (int i = 0; i < (int)equation.length(); i++)
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
