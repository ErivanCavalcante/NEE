#include "AlimentoTaco.h"

AlimentoTaco::AlimentoTaco()
{
    kcal = cho = lip = ptn = ca = fe = na = k = zn = vitc = 0;
    qtd = 0;
}

AlimentoTaco::~AlimentoTaco()
{
    //dtor
}


void AlimentoTaco::ajustaQtd()
{
    float por = qtd / 100;

    kcal *= por;
    cho *= por;
    lip *= por;
    ptn *= por;
    ca *= por;
    fe *= por;
    na *= por;
    k *= por;
    zn *= por;
    vitc *= por;
}

void AlimentoTaco::salvaAlimento(ofstream &file)
{
    file << nome << " ";
    file << kcal << " ";
    file << cho << " ";
    file << lip << " ";
    file << ptn << " ";
    file << ca << " ";
    file << fe << " ";
    file << na << " ";
    file << k << " ";
    file << zn << " ";
    file << vitc << " ";

    file << qtd << " ";
}

void AlimentoTaco::carregaAlimento(ifstream &file)
{
    file >> nome;
    file >> kcal;
    file >> cho;
    file >> lip;
    file >> ptn;
    file >> ca;
    file >> fe;
    file >> na;
    file >> k;
    file >> zn;
    file >> vitc;

    file >> qtd;
}
