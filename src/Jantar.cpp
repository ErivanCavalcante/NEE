#include "Jantar.h"

Jantar::Jantar(string nome) : Refeicao(nome)
{
    id = 4;
}

Jantar::~Jantar()
{
    //dtor
}

void Jantar::calculaPorcentagens(float nee, float porCho, float porLip, float porPtn)
{
    kcal = nee * 0.3;

    cho = kcal * porCho / 4;
    lip = kcal * porLip / 9;
    ptn = kcal * porPtn / 4;
}
