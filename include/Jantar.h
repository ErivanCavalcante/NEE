#ifndef JANTAR_H
#define JANTAR_H

#include"Refeicao.h"

class Jantar : public Refeicao
{
    public:
    Jantar(string nome);
    virtual ~Jantar();

    virtual void calculaPorcentagens(float nee, float porCho, float porLip, float porPtn);
};

#endif // JANTAR_H
