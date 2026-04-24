// Essas diretivas são postas para evitar que um arquivo .h seja incluído
// mais que uma vez num mesmo projeto.
#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED

// Biblioteca padrão para trabalhar com entradas e saídas.
#include <stdio.h>

// Biblioteca que serve para a manipulação da memória (alocações, liberações,
// etc).
#include <stdlib.h>

//-----------------------------------------------------------------------------

/**
 * @brief Estrutura de um elemento da lista duplamente encadeada.
 */
typedef struct tpElemento {

    int dado;
    struct tpElemento *proximo;
    struct tpElemento *anterior;
} tpElemento;

//-----------------------------------------------------------------------------

/**
 * @brief Estrutura da lista duplamente encadeada.
 */
typedef struct {

    tpElemento *primeiro;
    tpElemento *ultimo;
    int tamanho;
} tpLista;

//-----------------------------------------------------------------------------

/**
 * @brief Cria e retorna uma lista vazia.
 * @return lista Lista duplamente encadeada inicializada.
 */
tpLista criarListaDE();

//-----------------------------------------------------------------------------

/**
 * @brief Libera toda a memória da lista e a esvazia.
 * @param lista Ponteiro para a lista a ser liberada.
 */
void liberarListaDE(tpLista *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento no início da lista.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser inserido.
 */
void inserirNoInicioLDE(tpLista *lista, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento no fim da lista.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser inserido.
 */
void inserirNoFimLDE(tpLista *lista, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento em uma posição específica da lista.
 * @param lista Ponteiro para a lista.
 * @param pos Posição onde o novo valor será inserido (começa de 0).
 * @param dado Valor a ser inserido.
 */
void inserirNaPosicaoLDE(tpLista *lista, int pos, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Remove o primeiro elemento da lista.
 * @param lista Ponteiro para a lista.
 */
void removerNoInicioLDE(tpLista *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Remove o último elemento da lista.
 * @param lista Ponteiro para a lista.
 */
void removerNoFimLDE(tpLista *lista);

//-----------------------------------------------------------------------------

/**
 * @brief Remove o primeiro elemento com o valor especificado.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser removido.
 */
void removerElementoLDE(tpLista *lista, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Busca o primeiro elemento com o valor informado.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser buscado.
 * @return Ponteiro para o elemento encontrado ou NULL se não existir.
 */
tpElemento* buscarElementoLDE(tpLista *lista, int dado);

//-----------------------------------------------------------------------------

/**
 * @brief Imprime os elementos da lista no formato [a, b, c].
 * @param lista Ponteiro para a lista.
 */
void imprimirListaDE(tpLista *lista);

#endif // LISTADE_H_INCLUDED
