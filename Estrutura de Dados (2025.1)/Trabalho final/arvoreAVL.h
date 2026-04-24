// Essas diretivas são postas para evitar que um arquivo .h seja incluído
// mais que uma vez num mesmo projeto.
#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

// Biblioteca padrão para trabalhar com entradas e saídas.
#include <stdio.h>

// Biblioteca que serve para a manipulação da memória (alocações, liberações,
// etc).
#include <stdlib.h>

//-----------------------------------------------------------------------------

/**
 * @brief Estrutura de um nó de uma árvore binária
 */
typedef struct tpNo{

    struct tpNo* esq;
    struct tpNo* dir;
    int valor;
} tpNo;

//-----------------------------------------------------------------------------

/**
 * @brief Calcula a altura de uma árvore binária de busca (AVL).
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @return Altura da árvore (-1 se vazia).
 */
int calculaAltura(tpNo* raiz);

//-----------------------------------------------------------------------------

/**
 * @brief Calcula o fator de balanceamento de um nó.
 *
 * @param no Ponteiro para o nó.
 * @return Diferença entre altura da subárvore esquerda e direita.
 */
int fatorBalanceamento(tpNo* no);

//-----------------------------------------------------------------------------

/**
 * @brief Cria um novo nó da árvore AVL.
 *
 * @param valor Valor inteiro a ser armazenado no nó.
 * @return Ponteiro para o novo nó alocado.
 */
tpNo* criarNo(int valor);

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação simples à direita.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após a rotação.
 */
tpNo* rotacionarDir(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação simples à esquerda.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após a rotação.
 */
tpNo* rotacionarEsq(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação dupla esquerda-direita.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após as rotações.
 */
tpNo* esquerdaDireita(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação dupla direita-esquerda.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após as rotações.
 */
tpNo* direitaEsquerda(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Rebalanceia a árvore a partir de um nó e valor inserido/removido.
 *
 * @param raiz Ponteiro para o nó em específico.
 * @param valor Valor inserido ou removido.
 * @return Ponteiro para a nova raiz da subárvore.
 */
tpNo* balanceaArvore(tpNo* raiz, int valor);

//-----------------------------------------------------------------------------

/**
 * @brief Insere um valor na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param valor Valor a ser inserido.
 * @return Nova raiz da subárvore após inserção e rebalanceamento.
 */
tpNo* inserirNo(tpNo* raiz, int valor);

//-----------------------------------------------------------------------------

/**
 * @brief Remove um valor da árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param valor Valor a ser removido.
 * @return Nova raiz da subárvore após remoção e rebalanceamento.
 */
tpNo* removerNo(tpNo* raiz, int valor);

//-----------------------------------------------------------------------------

/**
 * @brief Busca um valor na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param num Valor a ser buscado.
 * @return Ponteiro para o nó com o valor, ou NULL se não existir.
 */
tpNo* buscaArvore(tpNo* raiz, int num);

//-----------------------------------------------------------------------------

/**
 * @brief Imprime a árvore AVL em percurso pré-ordem.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void preOrdem(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Imprime a árvore AVL em percurso em-ordem.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void emOrdem(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Imprime a árvore AVL em percurso pós-ordem.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void posOrdem(tpNo* avre);

//-----------------------------------------------------------------------------

/**
 * @brief Libera toda a memória alocada pela árvore AVL.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void lenhador(tpNo* avre);

#endif // ARVOREAVL_H_INCLUDED
