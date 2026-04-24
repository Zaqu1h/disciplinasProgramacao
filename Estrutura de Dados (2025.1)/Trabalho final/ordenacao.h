// Essas diretivas são postas para evitar que um arquivo .h seja incluído
// mais que uma vez num mesmo projeto.
#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

// Biblioteca que serve para a manipulação da memória (alocações, liberações,
// etc).
#include <stdlib.h>

// Biblioteca padrão para trabalhar com entradas e saídas.
#include <stdio.h>

//-----------------------------------------------------------------------------

/**
 * @brief Particiona um vetor de inteiros para o QuickSort.
 *
 * @param vetor Vetor de inteiros a ser particionado.
 * @param inicio Índice inicial do subvetor.
 * @param fim Índice final do subvetor.
 * @return Índice do pivô após a partição.
 */
int particionar(int* vetor, int inicio, int fim);

//-----------------------------------------------------------------------------

/**
 * @brief Algoritmo que ordena um vetor de inteiros recursivamente se baseando
 * em divisão e conquista.
 *
 * @param vetor Vetor de inteiros a ser ordenado.
 * @param inicio Índice inicial do vetor.
 * @param fim Índice final do vetor.
 */
void quickSort(int* vetor, int inicio, int fim);

//-----------------------------------------------------------------------------

/**
 * @brief Combina dois subvetores ordenados em um único vetor ordenado para o
 * MergeSort.
 *
 * @param v Vetor de inteiros a ser combinado.
 * @param inicio Índice inicial do primeiro subvetor.
 * @param meio Índice final do primeiro subvetor.
 * @param fim Índice final do segundo subvetor.
 */
void merge(int* v, int inicio, int meio, int fim);

//-----------------------------------------------------------------------------

/**
 * @brief Ordena um vetor de inteiros dividindo os vetores em vários subvetores
 * e mesclando-os de forma ordenada.
 *
 * @param v Vetor de inteiros a ser ordenado.
 * @param inicio Índice inicial do vetor.
 * @param fim Índice final do vetor.
 */
void mergeSort(int* v, int inicio, int fim);

//-----------------------------------------------------------------------------

#endif // ORDENACAO_H_INCLUDEDD
