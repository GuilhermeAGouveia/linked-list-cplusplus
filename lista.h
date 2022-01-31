/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: Guilherme Gouveia
 *
 * Created on January 26, 2021, 11:32 AM
 */

#ifndef LISTA_H
#define LISTA_H

typedef struct no_{
	//critério de busca da ordenação
	int chave;

	//'carga útil' do nó
	//num cenario real, poderia ser, por exemplo: nome, endereco...
	int valor;

	struct no_ * prox;
} no;

typedef struct {
    int tam;
    no * lista;
} Tlista;

Tlista* inicia_lista();
Tlista * encerra_lista(Tlista * ptlista);
bool busca_enc(Tlista * ptlista, int chave, no ** ant);
bool insere_enc(Tlista * ptlista, int chave, int valor);
no * remove_enc(Tlista * ptlista, int chave);
void imprime(Tlista * ptlista);

#endif /* LISTA_H */

