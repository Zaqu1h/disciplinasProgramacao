#ifndef LISTAV_H_INCLUDED
#define LISTAV_H_INCLUDED

#include "ListaV.h"

// Biblioteca padrão para trabalhar com entradas e saídas.
#include <stdio.h>

// Biblioteca que serve para a manipulação da memória (alocações, liberações,
// etc).
#include <stdlib.h>

//-----------------------------------------------------------------------------

/**
 * @brief Estrutura de uma lista com vetor.
 */
struct listaV{

  int capacidade;
  int qte;
  int *dado;
};

typedef struct listaV tpListaV;

//-----------------------------------------------------------------------------

/**
 * @brief Cria uma nova lista com vetor e capacidade definida pelo usuário.
 *
 * @param capacidade Capacidade máxima da lista.
 * @return lista Estrutura da lista inicializada.
 */
tpListaV criarListaV(int capacidade);

//-----------------------------------------------------------------------------

/**
 * @brief Libera a memória alocada para o vetor interno da lista.
 *
 * @param lista Ponteiro para a lista.
 */
void liberarListaV(tpListaV *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Verifica se a lista está cheia.
 *
 * @param lista Ponteiro para a lista.
 * @return 1 se estiver cheia, 0 caso contrário.
 */
int confCheiaLV(tpListaV *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Verifica se a lista está vazia.
 *
 * @param lista Ponteiro para a lista.
 * @return 1 se estiver vazia, 0 caso contrário.
 */
int confVaziaLV(tpListaV *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Retorna a quantidade atual de elementos na lista.
 *
 * @param lista Ponteiro para a lista.
 * @return Quantidade de elementos.
 */
int tamListaV(tpListaV *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento em uma posição específica da lista.
 *
 * @param lista Ponteiro para a lista.
 * @param pos Posição onde o elemento será inserido.
 * @param dado Elemento a ser inserido.
 * @return Nova quantidade de elementos, 0 se posição inválida, -1 se lista cheia.
 */
int inserirNaPosLV(tpListaV *lista, int pos, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Remove a primeira ocorrência de um elemento da lista.
 *
 * @param lista Ponteiro para a lista.
 * @param dado Elemento a ser removido.
 * @return Nova quantidade de elementos se removido, -1 se não encontrado ou lista vazia.
 */
int removerDadoLV(tpListaV *lista, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Remove o elemento na posição indicada da lista.
 *
 * @param lista Ponteiro para a lista.
 * @param indice Índice do elemento a ser removido.
 * @return Nova quantidade de elementos se removido, -1 se índice inválido.
 */
int removerIndiceLV(tpListaV *lista, int indice);

/**
 * @brief Busca por um elemento na lista.
 *
 * @param lista Ponteiro para a lista.
 * @param item Elemento a ser buscado.
 * @return Índice do elemento se encontrado, -1 caso contrário.
 */
int buscarDadoLV(tpListaV *lista, int item);

//-----------------------------------------------------------------------------

/**
 * @brief Imprime os elementos da lista.
 *
 * @param lista Ponteiro para a lista.
 */
void imprimirListaV(tpListaV *lista);

#endif // LISTAV_H_INCLUDED
