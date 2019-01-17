#ifndef CAFE_H
#define CAFE_H

#include <vector>
#include <string>
//#include <iostream>
#include <fstream>
#include "AlimentoTaco.h"

using namespace std;

class Refeicao
{
    public:
    Refeicao(string nome);
    virtual ~Refeicao();

    int id;

    string nome;

    float kcal, cho, lip, ptn;
    float refKcal, refCho, refLip, refPtn;

    vector<AlimentoTaco*> listaAlimentos;

    virtual void calculaPorcentagens(float nee, float porCho, float porLip, float porPtn) = 0;

    void salvaRefeicao(ofstream &file);
    void carregaRefeicao(ifstream &file);
};

#endif // CAFE_H
