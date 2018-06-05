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

void Processador::emparelhar(int entrada){
//organiza o vetor de escolas pelo maior numero de habilitacoes
//sort(escolass.begin(), escolass.end(), sortByHabs());
//cout << "sorted" << endl;
unsigned int listasPercorridas = 0;
unsigned int alocados = 0;
//Corre 5 vezes, passando pelas 5 preferencias de cada professor
while((listasPercorridas+alocados < professoress.size())){
    // Corre para cada professor
    for(unsigned int pIndex=0;pIndex<professoress.size();pIndex++){
        //Se o professor nao esta emparelhado
        if(professoress[pIndex].emparelhado == false && professoress[pIndex].prefAtual < 5){
        //cout << "professor " << professoress[pIndex].id << " /  prefatual  " << professoress[pIndex].prefAtual << endl;
            int eid = professoress[pIndex].preferencias[professoress[pIndex].prefAtual];
            // Se existe alguma vaga disponivel, matricula o professor
            if(escolass[eid-1].vagasDiponiveis>0){
                // Atendendo ao requerimento de habilitacoes
                if(professoress[pIndex].habilitacoes >= escolass[eid-1].habilitacoes){
                    // cada professor só tem 5 preferencias, se tentar acessar uma 6a, seg.fault.
                    if(professoress[pIndex].prefAtual < 5){
                    //    cout << "matriculando" << endl;

                        //parte do professor
                        professoress[pIndex].emparelhado = true;
                        professoress[pIndex].parAlvo = escolass[eid - 1].id;
                        // o '+1' é por conta dos indices começarem em '0', aí o '+1' serve de offset;
                        professoress[pIndex].parPeso = professoress[pIndex].prefAtual + 1;
                        professoress[pIndex].prefAtual++;
                      //  cout << "JOOOO    " << professoress[pIndex].prefAtual << endl;

                        //parte da escola
                        //cout << "Tamanho antes -- " << escolass[eid - 1].idProfessor.size() << "  /  ";
                        escolass[eid - 1].idProfessor.push_back(professoress[pIndex].id);
                        //cout << "Tamanho depois -- " << escolass[eid - 1].idProfessor.size() << endl;
                        escolass[eid - 1].vagasDiponiveis--;
                        

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
                   // cout << "sem habs" << endl;
                    professoress[pIndex].prefAtual++;
                    if (professoress[pIndex].prefAtual > 4){
                        listasPercorridas++;
                    }
                }
                // Se não houver vaga disponível, compara as habilitacoes.  
               }else{
                    if(professoress[pIndex].habilitacoes >= escolass[eid-1].habilitacoes){

                     //   cout << "tentando realocar" << endl;
                   
                        int profAtual = escolass[eid-1].idProfessor.back();
                        // o '+1' é por conta dos indices começarem em '0', aí o '+1' serve de offset;
                        // Se o candidato tiver mais habilitacoes, a escola troca.
                        bool deveTrocar=false;
                        if(entrada == 1){
                            deveTrocar = professoress[pIndex].habilitacoes > professoress[profAtual - 1].habilitacoes;
                        }else{
                            if ((professoress[profAtual - 1].habilitacoes != escolass[eid-1].habilitacoes)&&(professoress[pIndex].habilitacoes == escolass[eid - 1].habilitacoes)){
                                deveTrocar = true;
                            }
                            
                        }
                        if(deveTrocar){
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
                           // cout << "JOOOO    " << professoress[pIndex].prefAtual << endl;

                            //parte da escola
                            //cout << "Tamanho antes -- " << escolass[eid - 1].idProfessor.size() << "  /  ";
                            escolass[eid - 1].idProfessor.push_back(professoress[pIndex].id);
                            //cout << "Tamanho depois -- " << escolass[eid - 1].idProfessor.size() << endl;
                            escolass[eid - 1].vagasDiponiveis--;
                            

                            if (professoress[pIndex].prefAtual > 4){
                                listasPercorridas++;
                            }
                        }else{
                            //caso nao troque
                            professoress[pIndex].prefAtual++;
                            if (professoress[pIndex].prefAtual > 4){
                                listasPercorridas++;
                            }
                        }
                    }//sem habilitacoes
                    else{
                        //cout << "sem habs" << endl;
                        professoress[pIndex].prefAtual++;
                        if (professoress[pIndex].prefAtual > 4)
                        {
                            listasPercorridas++;
                        }
                    }
                }
            }
        }//end-for(professores)
        alocados = 0;
        for(auto profe : professoress){
            if(profe.emparelhado == true){
                alocados++;
            }
        }
        cout << "\n\nAlocados  " << alocados << endl;
    }

}

void Processador::mostrador(){

    for(Professor prof: professoress){
        if(prof.emparelhado){
            int target = prof.parAlvo;
        cout <<"Professor(" << prof.id << ")";
        cout << setw(3) << " - (";
        cout <<  prof.parAlvo <<")Escola //" << "  Hab(prof/escola) (" << prof.habilitacoes << "/" << escolass[target-1].habilitacoes << ")";
        cout << "  Pref.Prof(" << prof.parPeso << ")" << endl;
        }
    }
    cout << "\n\nEscolas com vagas disponiveis:" << endl;
    for(auto ex: escolass){
        if(ex.vagasDiponiveis>0)
            cout << "Escola - " << ex.id << "/hab." << ex.habilitacoes << "/  v.disp - " << ex.vagasDiponiveis << "/ v.total - " << ex.vagasTotal << endl;
    }
    cout << "\n\nProfessores livres:\n" << endl;
    for(auto pro: professoress){
        if(pro.emparelhado == false){
            cout << "Professor - " << pro.id <<  " /habs" << pro.habilitacoes << " /prefs : ";
            for(int i=0; i<5;i++){
                cout << " " << pro.preferencias[i];
            }
            cout << endl;
        }
    }
}