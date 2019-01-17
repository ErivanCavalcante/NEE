#ifndef LANCHETARDE_H
#define LANCHETARDE_H

#include"Refeicao.h"

class LancheTarde : public Refeicao
{
    public:
    LancheTarde(string nome);
    virtual ~LancheTarde();

    virtual void calculaPorcentagens(float nee, float porCho, float porLip, float porPtn);

};

#endif // LANCHETARDE_H
