#ifndef ALMOCO_H
#define ALMOCO_H

#include"Refeicao.h"

class Almoco : public Refeicao
{
    public:
    Almoco(string nome);
    virtual ~Almoco();

    virtual void calculaPorcentagens(float nee, float porCho, float porLip, float porPtn);
};

#endif // ALMOCO_H
