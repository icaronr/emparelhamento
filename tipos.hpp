#ifndef TIPOS_H
#define TIPOS_H

#include <vector>

using namespace std;

class Vagas
{
  public:
    int total;
    int disponiveis;
    Vagas();
    Vagas(int vagas);
};

class Conexao
{
  public:
    // Conexao.feita, true se houver conexao estabelecida
    bool feita;
    // alvo da conexao
    int alvo;
    // peso da conexao
    int peso;
    Conexao();
};

class Professor
{
  public:
    int id;
    int habilitacoes;
    vector<int> preferencias;
    Conexao conexao;
    Professor();
    Professor(int id, int habilitacoes, vector<int> preferencias);
};

class Escola
{
  public:
    int id;
    int habilitacoes;
    Vagas vagas;
    Escola();
    Escola(int id, int habilitacoes, int vagas);
};

#endif