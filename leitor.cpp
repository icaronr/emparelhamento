#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "leitor.hpp"
#include "processador.hpp"

using namespace std;

//---------------------------------------------
//  Leitor
void Leitor::trataLinha(string linha){
    string l1 = linha.substr(0, 2);
    //Linhas que representam professores
    if(l1 == "(P"){
        //cout << "TIPO : PROFESSOR!" << endl;
        Professor prof;
        //cout << "setou professor" << endl;
        int pos, virg;
        int id, habilitacoes;
        vector <int> preferencias;
        //cout << "setou variaveis" << endl;
        //faz um "split" em ':'
        pos = linha.find(':',0);
       // cout << "achou : " << endl;
        l1 = linha.substr(0, pos);
        //cout << "separou" << endl;
        //cout << l1 << endl;
        virg = l1.find(',',0);
       // cout << "achou a , " << endl;
        //Pega o id "antes da virgula"
        //cout << stoi(l1.substr(2, virg), nullptr, 10) << endl;

        id = stoi(l1.substr(2, virg), nullptr, 10);
       // cout << "id = " << id << endl;
       // cout << "\n  id  ";
        //cout << prof.id << endl;
        //Pega as habilitacoes "depois da virgula"
        //cout << linha.substr(pos + 2, linha.size());
        habilitacoes = stoi(l1.substr(virg+1, l1.size()), nullptr, 10);
        //cout << "  Habilitacao = " << habilitacoes << endl;
        //cout << prof.habilitacoes << endl;
        //vai pra segunda metade da string
        l1 = linha.substr(pos+2, linha.size());
        //cout << l1 << endl;
        virg=0;
        //pega as preferencias
        //o maior vai ser o 'front' e o menor vai ser o 'back'
        for(int i=0;i<5;i++){
            preferencias.push_back(stoi(l1.substr(virg+2,l1.find(',',virg))));
            virg = l1.find(',', virg)+1;
           // cout << "  preferencia " << i << " = " << preferencias.back() << "  ";
        }
        //cout << prof.preferencias.front() << endl;
        prof = Professor(id, habilitacoes, preferencias);
        professores.push_back(prof);
       // cout << endl;
    }
    else{
        //Linhas que representam escolas
        if (l1 == "(E"){
           // cout << "ecola" << endl;
            Escola colegio;
            int pos, pos1;
            int id, habilitacoes, vagas;
            vector <int> idProfessor;
            pos = linha.find(':',0);
            l1 = linha.substr(2,pos-2);
            l1.pop_back();
            id = stoi(l1, nullptr, 10);
            
            pos1 = linha.find(':', pos+1);
            pos1 = pos1 - pos;
            l1 = linha.substr(pos+2, pos1-3);
            habilitacoes = stoi(l1, nullptr, 10);

            l1 = linha.substr(pos1+pos+2, 1);
            vagas = stoi(l1, nullptr, 10);
            for(int i=0; i<colegio.vagasTotal; i++){
                idProfessor.push_back(0);
            }
            colegio = Escola(id, habilitacoes, vagas, idProfessor);
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
        cout << "Iniciando a leitura do arquivo.." << endl;
        while(arquivo.good()){
            //cout << "LINHA ACESSIVEL!" << endl;
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

int Leitor::chamaProcesso(){
    Processador* proc = new Processador(professores, escolas);
    cout << "Iniciando o Emparelhamento.." << endl;
    proc->emparelhar();
    cout << "\n Emparelhado" << endl;
    proc->mostrador();
    return 0;
}