#include <vector>

#include "tipos.hpp"

using namespace std;

//---------------------------------------------
//  Professor

Professor::Professor(){
    this->id = 0;
    this->habilitacoes = 0;
}

Professor::Professor(int id, int habilitacoes, vector<int> preferencias){
    this->id = id;
    this->habilitacoes = habilitacoes;
    this->preferencias = preferencias;
    this->prefAtual = 0;
    this->emparelhado = false;
    this->parAlvo = 0;
    this->parPeso = 0;
}

//---------------------------------------------
//  Escola

Escola::Escola(){
    this->id = 0;
    this->habilitacoes = 0;
    this->vagasTotal = 0;
    this->vagasDiponiveis = 0;
}

Escola::Escola(int id, int habilitacoes, int vagas, vector<int> idProfessor){
    this->id = id;
    this->habilitacoes = habilitacoes;
    this->vagasTotal = vagas;
    this->vagasDiponiveis = vagas;
    this->idProfessor = idProfessor;
}
