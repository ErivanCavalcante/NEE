#include "Refeicao.h"

Refeicao::Refeicao(string nome)
{
    this->nome = nome;

    kcal = cho = lip = ptn = 0;
    refKcal = refCho = refLip = refPtn = 0;
}

Refeicao::~Refeicao()
{
    for(int i = 0; i < listaAlimentos.size(); ++i)
    {
        delete listaAlimentos[i];
        listaAlimentos[i] = 0;
    }
}

void Refeicao::salvaRefeicao(ofstream &file)
{
    file << id << " ";
    file << nome << " ";
    file << kcal << " ";
    file << cho << " ";
    file << lip << " ";
    file << ptn << " ";

    //Alimentos
    file << listaAlimentos.size() << " ";

    //Loop nos alimentos
    for(int i = 0; i < listaAlimentos.size(); ++i)
    {
        listaAlimentos[i]->salvaAlimento(file);
    }
}

void Refeicao::carregaRefeicao(ifstream &file)
{
    file >> nome;
    file >> kcal;
    file >> cho;
    file >> lip;
    file >> ptn;

    //Alimentos
    int tamAlimentos = 0;
    file >> tamAlimentos;

    //Loop nos alimentos
    for(int i = 0; i < tamAlimentos; ++i)
    {
        AlimentoTaco *al = new AlimentoTaco();

        al->carregaAlimento(file);

        listaAlimentos.push_back(al);
    }
}

