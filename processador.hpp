#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include <vector>
#include "tipos.hpp"


class Processador{
public:
  vector<Professor> professoress;
  vector<Escola> escolass;
  Processador(vector<Professor> professores, vector<Escola> escolas);
  void emparelhar();
  void mostrador();

  struct sortByHabs
  {
    //  overload () operator
    bool operator()(const Escola &a, const Escola &b){
      if(a.habilitacoes != b.habilitacoes)
        return a.habilitacoes > b.habilitacoes;
      return a.vagasDiponiveis > b.vagasDiponiveis;
    }
  };
};

#endif