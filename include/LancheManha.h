#ifndef LANCHEMANHA_H
#define LANCHEMANHA_H

#include"Refeicao.h"

class LancheManha : public Refeicao
{
    public:
    LancheManha(string nome);
    virtual ~LancheManha();

    virtual void calculaPorcentagens(float nee, float porCho, float porLip, float porPtn);
};

#endif // LANCHEMANHA_H
