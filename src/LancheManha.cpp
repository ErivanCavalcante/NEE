#include "LancheManha.h"

LancheManha::LancheManha(string nome) : Refeicao(nome)
{
    id = 1;
}

LancheManha::~LancheManha()
{
    //dtor
}

void LancheManha::calculaPorcentagens(float nee, float porCho, float porLip, float porPtn)
{
    kcal = nee * 0.1;

    cho = kcal * porCho / 4;
    lip = kcal * porLip / 9;
    ptn = kcal * porPtn / 4;
}
