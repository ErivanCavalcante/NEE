#include "LancheTarde.h"

LancheTarde::LancheTarde(string nome) : Refeicao(nome)
{
    id = 3;
}

LancheTarde::~LancheTarde()
{
    //dtor
}

void LancheTarde::calculaPorcentagens(float nee, float porCho, float porLip, float porPtn)
{
    kcal = nee * 0.1;

    cho = kcal * porCho / 4;
    lip = kcal * porLip / 9;
    ptn = kcal * porPtn / 4;
}
