#ifndef TIPOS_H
#define TIPOS_H

#include <vector>

using namespace std;

class Professor
{
  public:
    int id;
    int habilitacoes;
    vector<int> preferencias;
    int prefAtual;
    bool emparelhado;
    int parAlvo;
    int parPeso;
    //Conexao conexao;
    Professor();
    Professor(int id, int habilitacoes, vector<int> preferencias);
};

class Escola
{
  public:
    int id;
    int habilitacoes;
    int vagasTotal;
    int vagasDiponiveis;
    vector <int> idProfessor;
    Escola();
    Escola(int id, int habilitacoes, int vagas, vector <int> idProfessor);
};

#endif