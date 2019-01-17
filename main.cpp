#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include "CafeManha.h"
#include "LancheManha.h"
#include "Almoco.h"
#include "LancheTarde.h"
#include "Jantar.h"

using namespace std;

//Globais
float nee, cho, lip, ptn = 0;
vector<Refeicao*> listaRefeicao;
bool sairPrograma, sairLoop = false;
int refeicao = 0;
int opcao = 0;
Refeicao *refer = 0;
//usado na soma
float somaKcal, somaCho, somaLip, somaPtn, sCa, sFe, sNa, sK, sZn, sVitc = 0;

bool salvaDieta()
{
    ofstream file;
    file.open("saveDieta.dta");

    if(!file.is_open())
        return false;

    //int numRefeicoes, numAlimentos = 0;
    file << nee << " ";
    file << cho << " ";
    file << lip << " ";
    file << ptn << " ";
    //Numero de refeicoes
    file << listaRefeicao.size() << " ";

    //Salva as refeicoes
    for(int i = 0; i < listaRefeicao.size(); ++i)
    {
        listaRefeicao[i]->salvaRefeicao(file);
    }

    file.close();

    return true;
}

bool carregaDieta()
{
    ifstream file;
    file.open("saveDieta.dta");

    if(!file.is_open())
        return false;

    //int numRefeicoes, numAlimentos = 0;
    file >> nee;
    file >> cho;
    file >> lip;
    file >> ptn;

    //Numero de refeicoes
    int tamLista = 0;
    file >> tamLista;

    int id = 0;
    //Salva as refeicoes
    for(int i = 0; i < tamLista; ++i)
    {
        Refeicao *r;

        file >> id;

        switch(id)
        {
            case 0:
                r = new CafeManha("");
                break;
            case 1:
                r = new LancheManha("");
                break;
            case 2:
                r = new Almoco("");
                break;
            case 3:
                r = new LancheTarde("");
                break;
            case 4:
                r = new Jantar("");
                break;
        }

        r->carregaRefeicao(file);

        listaRefeicao.push_back(r);
    }

    file.close();

    return true;
}

void criaRefeicoes()
{
    CafeManha *cafe = new CafeManha("CafeDaManha");
    LancheManha *lancheManha = new LancheManha("LancheDaManha");
    Almoco *almoco = new Almoco("Almoco");
    LancheTarde *lancheTarde = new LancheTarde("LancheDaTarde");
    Jantar *jantar = new Jantar("Jantar");
    //Refeicao cafe("Cafe");

    listaRefeicao.push_back(cafe);
    listaRefeicao.push_back(lancheManha);
    listaRefeicao.push_back(almoco);
    listaRefeicao.push_back(lancheTarde);
    listaRefeicao.push_back(jantar);
}

void calculaPorcentagemRefeicao()
{
    system("cls");
    cout << endl << "Calculo porcentagem para adequar as refeicao" << endl << endl;

    for(int i = 0; i < listaRefeicao.size(); ++i)
    {
        cout << "Nome = " << listaRefeicao[i]->nome << endl;

        listaRefeicao[i]->calculaPorcentagens(nee, cho, lip, ptn);

        cout << "Cho = " << listaRefeicao[i]->cho << "(g) Lip = "
            << listaRefeicao[i]->lip << "(g) Ptn = " << listaRefeicao[i]->ptn << "(g)" << endl;
    }
}

void adicionaAlimento()
{
    AlimentoTaco *alim = new AlimentoTaco();

    cout << "Digite os dados do alimento da taco" << endl << endl;

    cout << "Nome Alimento" << endl;
    cin >> alim->nome;
    cout << "Kcal(kcal)" << endl;
    cin >> alim->kcal;
    cout << "Carboidrato(g)" << endl;
    cin >> alim->cho;
    cout << "Lipidio(g)" << endl;
    cin >> alim->lip;
    cout << "Proteina(g)" << endl;
    cin >> alim->ptn;
    cout << "Calcio(mg)" << endl;
    cin >> alim->ca;
    cout << "Ferro(mg)" << endl;
    cin >> alim->fe;
    cout << "Sodio(mg)" << endl;
    cin >> alim->na;
    cout << "Potassio(mg)" << endl;
    cin >> alim->k;
    cout << "Zinco(mg)" << endl;
    cin >> alim->zn;
    cout << "Vitamina C(mg)" << endl;
    cin >> alim->vitc;

    cout << "Digite a quantidade do alimento utilizado(g)" << endl;
    cin >> alim->qtd;

    //ajusta a qtd
    alim->ajustaQtd();

    refer->listaAlimentos.push_back(alim);
}

void removeAlimento()
{
    int retOpcao = -1;

    cout << "-1)Voltar" << endl;

    for(int i = 0; i < refer->listaAlimentos.size(); ++i)
    {
        cout << i << ")" << refer->listaAlimentos[i]->nome << endl;
    }

    cin >> retOpcao;

    if(retOpcao >= 0)
    {
        if(retOpcao < refer->listaAlimentos.size())
        {
            AlimentoTaco *al = refer->listaAlimentos[retOpcao];

            delete al;
            al = 0;

            refer->listaAlimentos.erase( refer->listaAlimentos.begin() + retOpcao );

            cout << endl << "Alimento Removido com Sucesso!!" << endl << endl;
        }
        else
        {
            cout << endl << "Erro ao Reomover o Alimento! Id nao Existe!" << endl << endl;
            return;
        }

    }
}

void mostraAdequacao()
{
    system("cls");

    somaKcal = somaCho = somaLip = somaPtn = sCa = sFe = sNa = sK = sZn = sVitc = 0;

    cout << "Adequacao..." << endl << endl << endl;

    cout << "nee = " << nee << "kcal" << endl;
    cout << "%cho = " << cho << " %lip = " << lip << " %ptn = " << ptn << endl;

    cout << "Lista de Refeicoes e Alimentos" << endl << endl;

    for(int i = 0; i < listaRefeicao.size(); ++i)
    {
        Refeicao *r = listaRefeicao[i];

        cout << "Refeicao" << endl;

        cout << r->nome << " Kcal = " << r->kcal << " Cho = " << r->cho << "(g) Lip = "
            << r->lip << "(g) Ptn = " << r->ptn << "(g)" << endl << endl;

        r->refKcal = r->refCho = r->refLip = r->refPtn = 0;

        if(listaRefeicao[i]->listaAlimentos.empty() )
            continue;

        cout << "Alimento" << endl;

        for(int j = 0; j < listaRefeicao[i]->listaAlimentos.size(); ++j)
        {
            AlimentoTaco *al = listaRefeicao[i]->listaAlimentos[j];

            //Total por refeicao
            r->refKcal += al->kcal;
            r->refCho += al->cho;
            r->refLip += al->lip;
            r->refPtn += al->ptn;

            //Total com tds os alimentos
            somaKcal += al->kcal;
            somaLip += al->lip;
            somaCho += al->cho;
            somaPtn += al->ptn;
            sCa += al->ca;
            sFe += al->fe;
            sNa += al->na;
            sK += al->k;
            sZn += al->zn;
            sVitc += al->vitc;

            cout << al->nome << " kcal = " << al->kcal << "(kcal) cho = " << al->cho << "(g) lip = " << al->lip << "(g) ptn = " << al->ptn
                << "(g) Ca = " << al->ca <<
            "(mg) Fe = " << al->fe << "(mg) Na = " << al->na << "(mg) K = " << al->k
            << "(mg) Zn = " << al->zn << "(mg) VitC = " << al->vitc << "(mg)" << endl << endl;
        }
    }

    cout << "Total por Refeicao" << endl << endl;
    for(int i = 0; i < listaRefeicao.size(); ++i)
    {
        Refeicao *r = listaRefeicao[i];

        //nao tem nada
        if(r->refKcal == 0)
            continue;

        cout << "Nome = " << r->nome << endl << endl;

        cout << "Valor em gramas(g)" << endl;
        cout << "Soma Kcal = " << r->refKcal << "(kcal) Soma Cho = " << r->refCho << "(g) Soma Lip = " << r->refLip
            << "(g) Soma Ptn = " << r->refPtn << "(g)" << endl << endl;

        cout << "Valor em porcentagem(%)" << endl;
        cout << "%Kcal = " << (r->refKcal * 100) / r->kcal << " %Cho = " << (r->refCho * 100) / r->cho
            << " %Lip = " << (r->refLip * 100) / r->lip << " %Ptn = " << (r->refPtn * 100) / r->ptn << endl << endl;

    }

    cout << "Total por Completo" << endl << endl;

    cout << "Valor em gramas(g)" << endl;
    cout << "Soma Kcal = " << somaKcal << "(kcal) Soma Cho = " << somaCho << "(g) Soma Lip = " << somaLip
        << "(g) Soma Ptn = " << somaPtn << "(g)" << endl << endl;

    cout << "Valor em miligramas(mg)" << endl;
    cout << "Soma Calcio = " << sCa << "(mg) Soma Ferro = " << sFe << "(mg) Soma Sodio = " << sNa
        << "(mg) Soma Potassio = " << sK << "(mg) Soma Zinco = " << sZn << "(mg) Soma Vitamina C = "
        << sVitc << "(mg)" << endl << endl;

    cout << "Valor em porcentagem(%)" << endl;
    cout << "%Kcal = " << (somaKcal / nee) * 100  << " %Cho = " << (somaCho * 100) / (nee * cho)
        << " %Lip = " << (somaLip * 100) / (nee * lip) << " %Ptn = " << (somaPtn * 100) / (nee * ptn) << endl << endl;

}

int main()
{
    cout << "OBS: Sempre use ponto no lugar da virgula! " << endl <<
            "Verifique suas respostas antes de dar enter!" << endl <<
            "Nao use ESPACOS nos nomes!" << endl << endl;

    cout << "Deseja carregar uma dieta!" << endl << endl;
    cout << "1)Sim" << endl;
    cout << "0)Nao" << endl;

    cin >> opcao;

    if(opcao == 1)
    {
        if(carregaDieta())
        {
            cout << endl << "Carregao com Sucesso!!" << endl << endl;
        }
        else
        {
            cout << endl << "Erro ao Carregar Dieta!!" << endl << endl;
            return 0;
        }
    }
    else if(opcao == 0)
    {
        criaRefeicoes();
        //Pega as variaveis
        cout << "Informe o nee(kcal)" << endl;
        cin >> nee;

        cout << "Informe as porcentagens de Cho( em decimal )" << endl;
        cin >> cho;

        cout << "Informe as porcentagens de Lip( em decimal )" << endl;
        cin >> lip;

        cout << "Informe as porcentagens de Ptn( em decimal )" << endl;
        cin >> ptn;

        calculaPorcentagemRefeicao();
    }

    opcao = 0;

    while(!sairPrograma)
    {
        cout << endl << "Escolha uma Opcao" << endl << endl;
        cout << "-3)Salvar" << endl;
        cout << "-2)Mostrar Adequacao" << endl;
        cout << "-1) Sair" << endl;
        cout << "0) Cafe" << endl;
        cout << "1) Lanche Manha" << endl;
        cout << "2) Almoco" << endl;
        cout << "3) Lanche Tarde" << endl;
        cout << "4) Janta" << endl;

        //Pega a opcao
        cin >> refeicao;

        //Fecha o programa
        if(refeicao == -1)
        {
            sairPrograma = true;
            break;
        }
        //Mostra a adequação
        else if(refeicao == -2)
        {
            mostraAdequacao();
            continue;
        }
        else if(refeicao == -3)
        {
            if(!salvaDieta())
            {
                cout << endl << "Erro ao Salvar Dieta!!!" << endl << endl;
            }
            else
            {
                cout << endl << "Salvo com Sucesso!!!" << endl << endl;
            }

            continue;
        }

        //Refeicao
        refer = listaRefeicao[refeicao];

        sairLoop = false;

        do
        {
            system("cls");

            cout << endl << "Escolha uma opcao" << endl << endl;
            cout << "0) Add alimento" << endl;
            cout << "1) Remove alimento" << endl;
            cout << "-1) Voltar" << endl;

            //Pega a opcao
            cin >> opcao;

            if(opcao == -1)
            {
                sairLoop = true;
                break;
            }
            //adiciona o alimento
            else if(opcao == 0)
            {
                system("cls");

                adicionaAlimento();

                continue;
            }
            else if(opcao == 1)
            {
                system("cls");

                removeAlimento();

                continue;
            }
        }while(!sairLoop);
    }

    //Deleta tudo
    for(int i = 0; i < listaRefeicao.size(); ++i)
    {
        delete listaRefeicao[i];
    }

    return 0;
}
