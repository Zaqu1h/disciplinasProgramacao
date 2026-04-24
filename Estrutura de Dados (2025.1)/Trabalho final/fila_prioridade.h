// Essas diretivas são postas para evitar que um arquivo .h seja incluído
// mais que uma vez num mesmo projeto.
#ifndef FILA_PRIORIDADE_H_INCLUDED
#define FILA_PRIORIDADE_H_INCLUDED

// Biblioteca padrão para trabalhar com entradas e saídas.
#include <stdio.h>

// Biblioteca que serve para a manipulação da memória (alocações, liberações,
// etc).
#include <stdlib.h>

//-----------------------------------------------------------------------------

/**
 * @brief Estrutura de uma fila de prioridade.
 */
typedef struct filaPrioridade{

    int capacidade;
    int tamanho;
    int* fila;
}tpFilaP;

//-----------------------------------------------------------------------------

/**
 * @brief Cria e inicializa uma nova fila de prioridade.
 *
 * @param maximo Capacidade máxima da fila.
 * @return nova A nova fila criada.
 */
tpFilaP criaFilaPrioridade(int maximo);

//-----------------------------------------------------------------------------

/**
 * @brief Libera a memória da fila e a invalida.
 *
 * @param heap Ponteiro para a fila.
 */
void destroiHeap(tpFilaP* heap);

//-----------------------------------------------------------------------------

/**
 * @brief Retorna a capacidade máxima da fila.
 *
 * @param heap A fila de prioridade.
 * @return Capacidade total da fila.
 */
int getCapacidadeHeap(tpFilaP heap);

//-----------------------------------------------------------------------------

/**
 * @brief Retorna a quantidade de elementos atualmente na fila.
 *
 * @param heap A fila de prioridade.
 * @return Tamanho atual da fila.
 */
int getTamanhoHeap(tpFilaP heap);

//-----------------------------------------------------------------------------

/**
 * @brief Retorna o elemento no índice especificado.
 *
 * @param heap A fila de prioridade.
 * @param i Índice desejado.
 * @return Elemento no índice ou -1 se estiver fora dos limites.
 */
int getElementoHeap(tpFilaP heap, unsigned int i);

//-----------------------------------------------------------------------------

/**
 * @brief Reorganiza a heap de cima para baixo a partir do índice i (desce heapando).
 *
 * @param heap Ponteiro para a fila.
 * @param i Índice inicial para "descer" o valor.
 */
void desceHeap(tpFilaP *heap, int i);

//-----------------------------------------------------------------------------

/**
 * @brief Reorganiza a heap de baixo para cima a partir do índice i (sobe heapando).
 *
 * @param heap Ponteiro para a fila.
 * @param i Índice inicial para "subir" o valor.
 */
void sobeHeap(tpFilaP *heap, int i);

//-----------------------------------------------------------------------------

/**
 * @brief Constrói uma heap a partir dos elementos da fila.
 *
 * @param heap Ponteiro para a fila.
 */
void fazHeap(tpFilaP *heap);

//-----------------------------------------------------------------------------

/**
 * @brief Ordena um max-heap crescentemente.
 *
 * @param heap Ponteiro para a fila.
 */
void heapSort(tpFilaP *heap);

//-----------------------------------------------------------------------------

/**
 * @brief Remove o elemento de maior prioridade (topo da heap).
 *
 * @param heap Ponteiro para a fila.
 */
void removeTopoHeap(tpFilaP *heap);

//-----------------------------------------------------------------------------

/**
 * @brief Insere um novo valor na heap, mantendo a propriedade da Max-Heap.
 *
 * @param heap Ponteiro para a fila.
 * @param num Valor a ser inserido.
 */
void insereHeap(tpFilaP *heap, int num);

//-----------------------------------------------------------------------------

/**
 * @brief Imprime todos os elementos da heap na ordem do vetor.
 *
 * @param heap A fila de prioridade.
 */
void printaHeap(tpFilaP heap);

#endif // FILA_PRIORIDADE_H_INCLUDED
