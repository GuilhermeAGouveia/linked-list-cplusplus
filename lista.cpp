/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>

#include "lista.h"

using namespace std;

/*typedef struct no_ {
	int chave;  //critério de busca da ordenação
	int valor;  //'carga útil' do nó
                    //num cenario real, poderia ser: nome, endereco...
	struct no_ * prox;  // ponteiro para o próximo nó da lista encadeada
} no;
*/
/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
Tlista* inicia_lista() {
	Tlista* tmp = new (Tlista);
        tmp->tam = 0;
        tmp->lista = NULL;
        cout << "-A lista foi iniciada."<<endl;
	return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
Tlista * encerra_lista(Tlista * ptlista) {
	no * ant = ptlista->lista;
	no * pont = ant->prox;
	
	while(pont != NULL){
		delete(ant);
		ant = pont;
		pont = pont->prox;
	}
	delete(ant);
        cout << "-A lista foi removida."<<endl;
	
        return NULL;
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
bool busca_enc(Tlista * ptlista, int chave,  no** ant) {
   
	*ant = ptlista->lista;
	no * ptr = *ant;
	while (ptr != NULL && ptr->chave < chave) {
            *ant = ptr;
            ptr = ptr->prox;
        }
	return ptr != NULL && ptr->chave == chave;
}

/**
 * Realiza a insercao na lista encadeada ordenada (sem repeticoes).
 * @param chave a ser inserida.
 * @param valor a ser inserido.
 * @return verdadeiro se o elemento foi inserido.
 */
bool insere_enc(Tlista * ptlista, int chave, int valor){
	no* ant;
	if(busca_enc(ptlista, chave, &ant))
            return false;
        no * ptr = new(no);
        ptr->chave = chave;
        ptr->valor = valor;
        if (!ptlista->lista || chave < ptlista->lista->chave){
            ptr->prox = ptlista->lista;
            ptlista->lista = ptr;
        } else {
            ptr->prox = ant->prox;
            ant->prox = ptr;
        }
        
        ++ptlista->tam;
        return true;
}

/**
 * Realiza a remocao do elemento passado caso o mesmo esteja na lista encadeada.
 * @param chave do elemento a ser removido.
 * @return nulo em caso de lista vazia ou elemento inexistente,
 * e o no removido caso contrario.
 */
no * remove_enc(Tlista * ptlista, int chave){
	no* ant, *ptr;

	if(!busca_enc(ptlista, chave, &ant))
            return NULL;
        ptr = ant->prox;
        ant->prox = ptr->prox;
        ptr->prox = NULL;
        --ptlista->tam;
	return ptr;
}

/**
 * Imprime a lista encadeada.
 */
void imprime(Tlista * ptlista){
	no * ptr = ptlista->lista;
        cout << "---Estado atual da lista:";
	while(ptr != NULL){
            cout << "-> ("<<ptr->chave<<","<<ptr->valor<<") ";
            ptr = ptr->prox;
	}
        cout << endl;
}

