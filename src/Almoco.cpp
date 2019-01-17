#include "Almoco.h"

Almoco::Almoco(string nome) : Refeicao(nome)
{
    id = 2;
}

Almoco::~Almoco()
{
    //dtor
}

void Almoco::calculaPorcentagens(float nee, float porCho, float porLip, float porPtn)
{
    kcal = nee * 0.3;

    cho = kcal * porCho / 4;
    lip = kcal * porLip / 9;
    ptn = kcal * porPtn / 4;
}
