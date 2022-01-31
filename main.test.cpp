/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavio, paulo
 *
 * Created on January 26, 2021, 11:00 AM
 */

#include <iostream>
#include <stdlib.h>
#include "lista.h"

using namespace std;

Tlista * lista1;

/*
 * 
 */
int main() {
    no * p;
    lista1 = inicia_lista();

    cout<<"valor retornado: "<<insere_enc(lista1, 4, 5)<<endl;
    imprime(lista1);

    cout<<"valor retornado: "<<insere_enc(lista1, 2, 10)<<endl;
    imprime(lista1);

    cout<<"valor retornado: "<<insere_enc(lista1, 5, 15)<<endl;
    imprime(lista1);

    cout<<"valor retornado: "<<insere_enc(lista1, 3, 12)<<endl;
    imprime(lista1);

    cout<<"valor retornado: "<<insere_enc(lista1, 0, 12)<<endl;
    imprime(lista1);

    cout<<"valor retornado: "<< (p = remove_enc(lista1, 3))<<endl;
    delete (p);
    imprime(lista1);

    cout<<"valor retornado: "<<remove_enc(lista1, 9)<<endl;
    imprime(lista1);

    lista1 = encerra_lista(lista1);

    return (EXIT_SUCCESS);
}
