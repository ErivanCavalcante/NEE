#ifndef ALIMENTOTACO_H
#define ALIMENTOTACO_H

#include<string>
#include <fstream>
//#include <iostream>

using namespace std;

class AlimentoTaco
{
    public:
    AlimentoTaco();
    virtual ~AlimentoTaco();

    string nome;
    float kcal, cho, lip, ptn, ca, fe, na, k, zn, vitc;
    float qtd;

    void ajustaQtd();

    void salvaAlimento(ofstream &file);
    void carregaAlimento(ifstream &file);
};

#endif // ALIMENTOTACO_H
