#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "leitor.hpp"

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
}

//---------------------------------------------
//  Escola

Escola::Escola(){
    this->id = 0;
    this->habilitacoes = 0;
    this->vagas = 0;
}

Escola::Escola(int id, int habilitacoes, int vagas){
    this->id = id;
    this->habilitacoes = habilitacoes;
    this->vagas = vagas;
}

//---------------------------------------------
//  Leitor
void Leitor::trataLinha(string linha){
    string l1 = linha.substr(0, 2);
    //Linhas que representam professores
    if(l1 == "(P"){
        Professor prof;
        int pos, virg;
        //faz um "split" em ':'
        pos = linha.find(':',0);
        l1 = linha.substr(0, pos);
        //cout << l1 << endl;
        virg = l1.find(',',0);
        //Pega o id "antes da virgula"
        prof.id = stoi(l1.substr(2,virg),nullptr,10);
        //cout << prof.id << endl;
        //Pega as habilitacoes "depois da virgula"
        prof.habilitacoes = stoi(l1.substr(virg+1, l1.size()), nullptr, 10);
        //cout << prof.habilitacoes << endl;
        //vai pra segunda metade da string
        l1 = linha.substr(pos+2, linha.size());
        //cout << l1 << endl;
        virg=0;
        //pega as preferencias
        //o maior vai ser o 'front' e o menor vai ser o 'back'
        for(int i=0;i<5;i++){
            prof.preferencias.push_back(stoi(l1.substr(virg+2,l1.find(',',virg))));
            virg = l1.find(',', virg)+1;
        }
        //cout << prof.preferencias.front() << endl;
        professores.push_back(prof);
    }
    else{
        //Linhas que representam escolas
        if (l1 == "(E"){
            Escola colegio;
            int pos, pos1;
            pos = linha.find(':',0);
            l1 = linha.substr(2,pos-2);
            l1.pop_back();
            colegio.id = stoi(l1, nullptr, 10);
            
            pos1 = linha.find(':', pos+1);
            pos1 = pos1 - pos;
            l1 = linha.substr(pos+2, pos1-3);
            colegio.habilitacoes = stoi(l1, nullptr, 10);

            l1 = linha.substr(pos1+pos+2, 1);
            colegio.vagas = stoi(l1, nullptr, 10);
            
            escolas.push_back(colegio);
        }
    }
    
}

int Leitor::leitura(string nomearquivo){
    ifstream arquivo;

    arquivo.open(nomearquivo);
    if (arquivo.is_open()){
        cout << "Arquivo aberto!" << endl;
        string linha;
        while(arquivo.good()){
            getline(arquivo, linha);
            trataLinha(linha);
        }
        
        
        cout << "Fechando o arquivo..." << endl;
        arquivo.close();
        cout << "Arquivo fechado!" << endl;
        cout << "numero de professores -- " << professores.size() << endl;
        cout << "numero de escolas     -- " << escolas.size() << endl;
    }
    else{
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    return 0;
}