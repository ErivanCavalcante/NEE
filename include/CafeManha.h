#ifndef CAFEMANHA_H
#define CAFEMANHA_H

#include"Refeicao.h"

class CafeManha : public Refeicao
{
    public:
    CafeManha(string nome);
    virtual ~CafeManha();

    virtual void calculaPorcentagens(float nee, float porCho, float porLip, float porPtn);
};

#endif // CAFEMANHA_H
