#include <iostream>
#include "leitor.hpp"

using namespace std;

int main(){
    cout << "Vamos começar." << endl;
    Leitor* ledor = new Leitor;

    ledor->leitura("entradaProj3TAG.txt");

    delete ledor;
return 0;
}