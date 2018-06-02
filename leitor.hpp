#ifndef LEITOR_H
#define LEITOR_H

#include <vector>
#include <string>
#include "tipos.hpp"

using namespace std;

class Leitor{        
    public:
        vector<Professor> professores;
        vector<Escola> escolas;
        int leitura(string nomearquivo);
        void trataLinha(string linha);
        int chamaProcesso();
};

#endif