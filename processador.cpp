#include <vector>
#include <algorithm>
#include <iostream>
#include "processador.hpp"

using namespace std;

#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

Processador::Processador(vector<Professor> professores, vector<Escola> escolas){
    this->professoress = professores;
    this->escolass = escolas;
    
}

void Processador::cobertura(){
    int quantidades[51];
    for(int i=0;i<52;i++){
        quantidades[i] = 0;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<100;j++){
            int p = professoress[j].preferencias[i];
            quantidades[p]++;
        }
    }
    /*for (int i = 0; i < 52; i++)
    {
        cout << i << " - " << quantidades[i] << endl;
    }*/
}

void Processador::emparelhar(){
//organiza o vetor de escolas pelo maior numero de habilitacoes
//sort(escolass.begin(), escolass.end(), sortByHabs());
//cout << "sorted" << endl;
int listasPercorridas = 0;
int alocados = 0;
//Corre 5 vezes, passando pelas 5 preferencias de cada professor
while((listasPercorridas+alocados < professoress.size())){
    // Corre para cada professor
    for(int pIndex=0;pIndex<professoress.size();pIndex++){
        //Se o professor nao esta emparelhado
        if(professoress[pIndex].emparelhado == false && professoress[pIndex].prefAtual < 5){
        cout << "professor " << professoress[pIndex].id << " /  prefatual  " << professoress[pIndex].prefAtual << endl;
            int eid = professoress[pIndex].preferencias[professoress[pIndex].prefAtual];
            // Se existe alguma vaga disponivel, matricula o professor
            if(escolass[eid-1].vagasDiponiveis>0){
                // Atendendo ao requerimento de habilitacoes
                if(professoress[pIndex].habilitacoes >= escolass[eid-1].habilitacoes){
                    // cada professor só tem 5 preferencias, se tentar acessar uma 6a, seg.fault.
                    if(professoress[pIndex].prefAtual < 5){
                        cout << "matriculando" << endl;

                        //parte do professor
                        professoress[pIndex].emparelhado = true;
                        professoress[pIndex].parAlvo = escolass[eid - 1].id;
                        // o '+1' é por conta dos indices começarem em '0', aí o '+1' serve de offset;
                        professoress[pIndex].parPeso = professoress[pIndex].prefAtual + 1;
                        professoress[pIndex].prefAtual++;
                        cout << "JOOOO    " << professoress[pIndex].prefAtual << endl;

                        //parte da escola
                        cout << "Tamanho antes -- " << escolass[eid - 1].idProfessor.size() << "  /  ";
                        escolass[eid - 1].idProfessor.push_back(professoress[pIndex].id);
                        cout << "Tamanho depois -- " << escolass[eid - 1].idProfessor.size() << endl;
                        escolass[eid - 1].vagasDiponiveis--;
                        alocados++;

                        if (professoress[pIndex].prefAtual > 4){
                            listasPercorridas++;
                        }
                    }//estourou as preferencias
                    else
                    {
                        if (professoress[pIndex].prefAtual > 4)
                        {
                            listasPercorridas++;
                        }
                    }
                    
                }//sem habilitacao
                else{
                    cout << "sem habs" << endl;
                    professoress[pIndex].prefAtual++;
                    if (professoress[pIndex].prefAtual > 4){
                        listasPercorridas++;
                    }
                }
                // Se não houver vaga disponível, compara o peso desse professor, com o(s) contratado(s)
               }else{
                    if(professoress[pIndex].habilitacoes >= escolass[eid-1].habilitacoes){

                        cout << "tentando realocar" << endl;
                   
                        int profAtual = escolass[eid-1].idProfessor.back();
                        // o '+1' é por conta dos indices começarem em '0', aí o '+1' serve de offset;
                        // Se o peso for menor que o peso do que esta atualmente, o atual sai e o novo entra
                        if(professoress[pIndex].prefAtual+1<professoress[profAtual-1].parPeso){
                            // id = index + 1 -- profAtual é ID.
                            //desmatricula
                            professoress[profAtual - 1].emparelhado = false;
                            professoress[profAtual - 1].parAlvo = 0;
                            professoress[profAtual - 1].parPeso = 0;

                            if (escolass[eid - 1].idProfessor.back() == professoress[profAtual - 1].id){
                                escolass[eid - 1].idProfessor.pop_back(); 
                            }else{
                                int aux = escolass[eid - 1].idProfessor.back();
                                escolass[eid - 1].idProfessor.pop_back();
                                escolass[eid - 1].idProfessor.pop_back();
                                escolass[eid - 1].idProfessor.push_back(aux);
                                escolass[eid - 1].vagasDiponiveis++;
                            }

                            //matricula o novo
                            //parte do professor
                            professoress[pIndex].emparelhado = true;
                            professoress[pIndex].parAlvo = escolass[eid - 1].id;
                            // o '+1' é por conta dos indices começarem em '0', aí o '+1' serve de offset;
                            professoress[pIndex].parPeso = professoress[pIndex].prefAtual + 1;
                            professoress[pIndex].prefAtual++;
                            cout << "JOOOO    " << professoress[pIndex].prefAtual << endl;

                            //parte da escola
                            cout << "Tamanho antes -- " << escolass[eid - 1].idProfessor.size() << "  /  ";
                            escolass[eid - 1].idProfessor.push_back(professoress[pIndex].id);
                            cout << "Tamanho depois -- " << escolass[eid - 1].idProfessor.size() << endl;
                            escolass[eid - 1].vagasDiponiveis--;
                            alocados++;

                            if (professoress[pIndex].prefAtual > 4){
                                listasPercorridas++;
                            }
                        }else{
                            //peso nao vale
                            professoress[pIndex].prefAtual++;
                            if (professoress[pIndex].prefAtual > 4){
                                listasPercorridas++;
                            }
                        }
                    }//sem habilitacoes
                    else{
                        cout << "sem habs" << endl;
                        professoress[pIndex].prefAtual++;
                        if (professoress[pIndex].prefAtual > 4)
                        {
                            listasPercorridas++;
                        }
                    }
                }
            }
        }//end-for(professores)
        cout << "\n\nlistas finalizadas -- " << listasPercorridas << " /  Alocados  " << alocados << endl;
       getchar();

   }

}

void Processador::mostrador(){

    for(Professor prof: professoress){
        if(prof.emparelhado){
            int target = prof.parAlvo;
        cout <<"Professor(" << prof.id << ")";
        cout << setw(15) << " - (";
        cout <<  prof.parAlvo <<")Escola //" << "  Hab(prof/escola) (" << prof.habilitacoes << "/" << escolass[target-1].habilitacoes << ")";
        cout << "  Pref.Prof(" << prof.parPeso << ")" << endl;
        }
    }
    cout << "Escolas com vagas disponiveis:" << endl;
    for(auto ex: escolass){
        if(ex.vagasDiponiveis>0)
            cout << "Escola - " << ex.id << "/hab." << ex.habilitacoes << "/  v.disp - " << ex.vagasDiponiveis << "/ v.total - " << ex.vagasTotal << endl;
    }
}