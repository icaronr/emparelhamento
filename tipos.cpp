#include <vector>

#include "tipos.hpp"

using namespace std;

//---------------------------------------------
//  Professor

Professor::Professor(){
    this->id = 0;
    this->habilitacoes = 0;
    this->conexao = Conexao();
}

Professor::Professor(int id, int habilitacoes, vector<int> preferencias){
    this->id = id;
    this->habilitacoes = habilitacoes;
    this->preferencias = preferencias;
    this->conexao = Conexao();
}

//---------------------------------------------
//  Escola

Escola::Escola(){
    this->id = 0;
    this->habilitacoes = 0;
    this->vagas = Vagas();
}

Escola::Escola(int id, int habilitacoes, int vagas){
    this->id = id;
    this->habilitacoes = habilitacoes;
    this->vagas = Vagas(vagas);
}

//---------------------------------------------
//  Conexao

Conexao::Conexao(){
    this->feita = false;
    this->alvo = 0;
    this->peso = 0;
}

//---------------------------------------------
//  Vagas

Vagas::Vagas(){
    this->total = 0;
    this->disponiveis = 0;
}

Vagas::Vagas(int vagas){
    this->total = vagas;
    this->disponiveis = vagas;
}