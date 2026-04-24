/********************************************************************
 * @brief Este arquivo contém código para manipular uma árvore binária AVL.
 *
 * Um nó é uma estrutura do tipo tpNo definida pelo usuário em um arquivo .h nomeado de arvoreAVL.h.
 * Cada nó da árvore é representado por um *tpNo, que guarda:
 *
 * a) Um *tpNo "esq" que aponta para seu filho esquerdo;
 * b) Um *tpNo "dir" que aponta para seu filho direito;
 * c) Um número inteiro "valor"
 *
 * Obs: Se um *tpNo apontar para NULL, é porque aquele filho não existe.
 */
 #include "arvoreAVL.h"

//-----------------------------------------------------------------------------

/**
 * @brief Calcula a altura de uma árvore binária de busca (AVL).
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @return Altura da árvore (-1 se vazia).
 */
int calculaAltura(tpNo* raiz) {

    int altEsq, altDir;

    if (raiz == NULL) return -1;

    altEsq = calculaAltura(raiz->esq);
    altDir = calculaAltura(raiz->dir);

    return (altEsq >  altDir) ? (altEsq + 1) : (altDir + 1);
}

//-----------------------------------------------------------------------------

/**
 * @brief Calcula o fator de balanceamento de um nó.
 *
 * @param no Ponteiro para o nó.
 * @return Diferença entre altura da subárvore esquerda e direita.
 */
int fatorBalanceamento(tpNo* no){

    if (no == NULL) return 0;

    return calculaAltura(no->esq) - calculaAltura(no->dir);
}

//-----------------------------------------------------------------------------

/**
 * @brief Cria um novo nó da árvore AVL.
 *
 * @param valor Valor inteiro a ser armazenado no nó.
 * @return Ponteiro para o novo nó alocado.
 */
tpNo* criarNo(int valor){

    tpNo *novoNo = (tpNo*)malloc(sizeof(tpNo));

    if (novoNo != NULL){

        novoNo->valor = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
    }

    return novoNo;
}

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação simples à direita.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após a rotação.
 */
tpNo* rotacionarDir(tpNo* avre){

//           (30) = avre
//          /
//       (20)
//      /
//   (10)

    if (avre == NULL || avre->esq == NULL)
        return avre;

    tpNo* raizNova = avre->esq; // = 20
    tpNo* avreDir = raizNova->dir; // = NULL

    raizNova->dir = avre; // = 30
    avre->esq = avreDir; // = NULL

    return raizNova; // = 20
}

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação simples à esquerda.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após a rotação.
 */
tpNo* rotacionarEsq(tpNo* avre){

    if (avre == NULL || avre->dir == NULL)
        return avre;

    tpNo* raizNova = avre->dir;
    tpNo* avreEsq = raizNova->esq;

    raizNova->esq = avre;
    avre->dir = avreEsq;

    return raizNova;
}

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação dupla esquerda-direita.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após as rotações.
 */
tpNo* esquerdaDireita(tpNo* avre){

//           (30) = avre
//          /
//       (10) = avre->esq
//          \
//           (20)

    avre->esq = rotacionarEsq(avre->esq);

//           (30) = avre
//          /
//       (20)
//      /
//   (10)

    return rotacionarDir(avre);
}

//-----------------------------------------------------------------------------

/**
 * @brief Executa rotação dupla direita-esquerda.
 *
 * @param avre Ponteiro para o nó desbalanceado.
 * @return Nova raiz após as rotações.
 */
tpNo* direitaEsquerda(tpNo* avre){

    avre->dir = rotacionarDir(avre->dir);
    return rotacionarEsq(avre);
}

//-----------------------------------------------------------------------------

/**
 * @brief Rebalanceia a árvore a partir de um nó e valor inserido/removido.
 *
 * @param raiz Ponteiro para o nó em específico.
 * @param valor Valor inserido ou removido.
 * @return Ponteiro para a nova raiz da subárvore.
 */
tpNo* balanceaArvore(tpNo* raiz, int valor){

    int FB = fatorBalanceamento(raiz);

    if (FB > 1){

        if(valor < raiz->esq->valor){

            return rotacionarDir(raiz);
        }
        else{

            return esquerdaDireita(raiz);
        }
    }


    if (FB < -1){

        if(valor > raiz->dir->valor){

            return rotacionarEsq(raiz);
        }
        else{

            return direitaEsquerda(raiz);
        }
    }

    return raiz;
}

//-----------------------------------------------------------------------------

/**
 * @brief Insere um valor na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param valor Valor a ser inserido.
 * @return Nova raiz da subárvore após inserção e rebalanceamento.
 */
tpNo* inserirNo(tpNo* raiz, int valor){

    if (raiz == NULL){

        return criarNo(valor);
    }
    if (valor > raiz->valor){

        raiz->dir = inserirNo(raiz->dir, valor);
    }
    else if (valor < raiz->valor){

        raiz->esq = inserirNo(raiz->esq, valor);
    }
    else return raiz;

    return balanceaArvore(raiz, valor);
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove um valor da árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param valor Valor a ser removido.
 * @return Nova raiz da subárvore após remoção e rebalanceamento.
 */
tpNo* removerNo(tpNo* raiz, int valor){

    if (raiz == NULL) return NULL;

    if (valor > raiz->valor){

        raiz->dir = removerNo(raiz->dir, valor);
    }
    else if (valor < raiz->valor){

        raiz->esq = removerNo(raiz->esq, valor);
    }
    else {

        if (raiz->dir == NULL){

            tpNo* aux = raiz->esq;
            free(raiz);
            return aux;
        }
        if (raiz->esq == NULL){

            tpNo* aux = raiz->dir;
            free(raiz);
            return aux;
        }
        tpNo* sucessor = raiz->dir;

        while (sucessor->esq != NULL)
            sucessor = sucessor->esq;

        raiz->valor = sucessor->valor;
        raiz->dir = removerNo(raiz->dir, sucessor->valor);
    }

    return balanceaArvore(raiz, valor);
}

//-----------------------------------------------------------------------------

/**
 * @brief Busca um valor na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore.
 * @param num Valor a ser buscado.
 * @return Ponteiro para o nó com o valor, ou NULL se não existir.
 */
tpNo* buscaArvore(tpNo* raiz, int num){

    if (raiz == NULL) return NULL;

    if (raiz->valor < num) return buscaArvore(raiz->dir, num);

    if (raiz->valor > num) return buscaArvore(raiz->esq, num);

    return raiz;
}

//-----------------------------------------------------------------------------

/**
 * @brief Imprime a árvore AVL em percurso pré-ordem.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void preOrdem(tpNo* avre){

    if (avre != NULL){

        printf("%i\t", avre->valor);
        preOrdem(avre->esq);
        preOrdem(avre->dir);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Imprime a árvore AVL em percurso em-ordem.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void emOrdem(tpNo* avre){

    if (avre != NULL){

        emOrdem(avre->esq);
        printf("%i\t", avre->valor);
        emOrdem(avre->dir);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Imprime a árvore AVL em percurso pós-ordem.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void posOrdem(tpNo* avre){

    if (avre != NULL){

        posOrdem(avre->esq);
        posOrdem(avre->dir);
        printf("%i\t", avre->valor);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Libera toda a memória alocada pela árvore AVL.
 *
 * @param avre Ponteiro para a raiz da árvore.
 */
void lenhador(tpNo* avre){

    if (avre != NULL){

        lenhador(avre->esq);
        lenhador(avre->dir);
        free(avre);
    }
}
