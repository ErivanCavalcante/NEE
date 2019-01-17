#include "CafeManha.h"

CafeManha::CafeManha(string nome) : Refeicao(nome)
{
    id = 0;
}

CafeManha::~CafeManha()
{
    //dtor
}

void CafeManha::calculaPorcentagens(float nee, float porCho, float porLip, float porPtn)
{
    kcal = nee * 0.2;

    cho = kcal * porCho / 4;
    lip = kcal * porLip / 9;
    ptn = kcal * porPtn / 4;
}
