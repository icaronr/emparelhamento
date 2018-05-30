#include <vector>
#include <string>

using namespace std;

class Professor{
    public:
        int id;
        int habilitacoes;
        vector<int> preferencias;
        Professor();
        Professor(int id, int habilitacoes, vector<int> preferencias);
};

class Escola{
    public:
        int id;
        int habilitacoes;
        int vagas;
        Escola();
        Escola(int id, int habilitacoes, int vagas);
};

class Leitor{        
    public:
        vector<Professor> professores;
        vector<Escola> escolas;
        int leitura(string nomearquivo);
        void trataLinha(string linha);

};