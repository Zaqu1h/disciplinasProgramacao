/********************************************************************
 * @brief Este arquivo contém código para manipular uma lista duplamente encadeada.
 *
 * As estruturas dos tipos "lista" e "elemento" são definidas pelo usuário em um arquivo .h nomeado de listaDE.h.
 * Cada elemento da lista é representado por um *tpElemento, que guarda:
 *
 * a) Um *tpElemento "proximo" que aponta para seu sucessor;
 * b) Um *tpElemento "anterior" que aponta para seu antecessor;
 * c) Um número inteiro "dado"
 *
 * Uma lista é representada por um tpLista, que guarda:
 *
 * a) Um *tpElemento "primeiro", que aponta para o primeiro elemento da lista;
 * b) Um *tpElemento "ultimo", que aponta para o ultimo elemento da lista;
 * c) Um número inteiro "tamanho", que guarda o número de elementos da lista.
 *
 */
 #include "listaDE.h"

//-----------------------------------------------------------------------------

/**
 * @brief Cria e retorna uma lista vazia.
 * @return lista Lista duplamente encadeada inicializada.
 */
tpLista criarListaDE() {

    tpLista lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;
    lista.tamanho = 0;

    return lista;
}

//-----------------------------------------------------------------------------

/**
 * @brief Libera toda a memória da lista e a esvazia.
 * @param lista Ponteiro para a lista a ser liberada.
 */
void liberarListaDE(tpLista *lista) {

    while (lista->primeiro != NULL) {

        tpElemento *removido = lista->primeiro;
        lista->primeiro = lista->primeiro->proximo;
        free(removido);
    }

    lista->ultimo = NULL;
    lista->tamanho = 0;
}

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento no início da lista.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser inserido.
 */
void inserirNoInicioLDE(tpLista *lista, int dado) {

    tpElemento *elementoNovo = (tpElemento*) malloc(sizeof(tpElemento));

    if (elementoNovo == NULL) return;

    elementoNovo->dado = dado;
    elementoNovo->proximo = lista->primeiro;
    elementoNovo->anterior = NULL;

    if (lista->tamanho != 0) {
        lista->primeiro->anterior = elementoNovo;
    }else {
        lista->ultimo = elementoNovo;
    }

    lista->primeiro = elementoNovo;
    lista->tamanho +=1;
}

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento no fim da lista.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser inserido.
 */
void inserirNoFimLDE(tpLista *lista, int dado) {

    tpElemento *elementoNovo = (tpElemento*)malloc(sizeof(tpElemento));

    if (elementoNovo == NULL) return;

    elementoNovo->proximo = NULL;
    elementoNovo->dado = dado;
    elementoNovo->anterior = lista->ultimo;

    if (lista->tamanho != 0)
        lista->ultimo->proximo = elementoNovo;
    else {
        lista->primeiro = elementoNovo;
    }

    lista->ultimo = elementoNovo;
    lista->tamanho += 1;

}

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento em uma posição específica da lista.
 * @param lista Ponteiro para a lista.
 * @param pos Posição onde o novo valor será inserido (começa de 0).
 * @param dado Valor a ser inserido.
 */
void inserirNaPosicaoLDE(tpLista *lista, int pos, int dado) {

    if (pos < 0 || pos > lista->tamanho) return;

    if (pos == 0) {

        inserirNoInicioLDE(lista, dado);
        return;
    }

    if (pos == lista->tamanho) {

        inserirNoFimLDE(lista, dado);
        return;
    }

    tpElemento *atual = lista->primeiro;

    for (int i = 0; i < pos - 1; i++){

        atual = atual->proximo;
    }

    tpElemento *elementoNovo = (tpElemento*)malloc(sizeof(tpElemento));

    if (elementoNovo == NULL) return;

    elementoNovo->dado = dado;
    elementoNovo->proximo = atual->proximo;
    elementoNovo->anterior = atual;

    atual->proximo->anterior = elementoNovo;
    atual->proximo = elementoNovo;

    lista->tamanho++;
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove o primeiro elemento da lista.
 * @param lista Ponteiro para a lista.
 */
void removerNoInicioLDE(tpLista *lista) {

    if (lista->tamanho == 0) return;

    if (lista->tamanho == 1) {

        free(lista->primeiro);

        lista->primeiro=NULL;
        lista->ultimo=NULL;
        lista->tamanho = 0;
        return;
    }

    tpElemento *segundoElemento = lista->primeiro->proximo;

    lista->primeiro = segundoElemento;

    free(segundoElemento->anterior);
    segundoElemento->anterior = NULL;

    lista->tamanho--;
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove o último elemento da lista.
 * @param lista Ponteiro para a lista.
 */
void removerNoFimLDE(tpLista *lista) {

    if (lista->tamanho == 0) return;

    if (lista->tamanho ==1) {

        free(lista->primeiro);

        lista->ultimo = NULL;
        lista->primeiro = NULL;
        lista->tamanho = 0;

        return;
    }

    tpElemento *penultimo = lista->ultimo->anterior;
    free(penultimo->proximo);
    penultimo->proximo = NULL;

    lista->ultimo = penultimo;
    lista->tamanho--;
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove o primeiro elemento com o valor especificado.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser removido.
 */
void removerElementoLDE(tpLista *lista, int dado) {

    if (lista->tamanho == 0) return;

    tpElemento *removido = lista->primeiro;

    while (removido != NULL && removido->dado != dado){

        removido = removido->proximo;
    }

    if (removido == NULL) return;

    if (removido == lista->primeiro) {

        removerNoInicioLDE(lista);
        return;
    }

    if (removido == lista->ultimo) {

        removerNoFimLDE(lista);
        return;
    }

    removido->anterior->proximo = removido->proximo;
    removido->proximo->anterior = removido->anterior;

    free(removido);
    lista->tamanho--;
}

//-----------------------------------------------------------------------------

/**
 * @brief Busca o primeiro elemento com o valor informado.
 * @param lista Ponteiro para a lista.
 * @param dado Valor a ser buscado.
 * @return Ponteiro para o elemento encontrado ou NULL se não existir.
 */
tpElemento *buscarElementoLDE(tpLista *lista, int dado) {

    tpElemento *atual = lista->primeiro;

    while (atual != NULL) {

        if (atual->dado == dado) return atual;

        atual = atual->proximo;
    }

    return NULL;
}

//-----------------------------------------------------------------------------

/**
 * @brief Imprime os elementos da lista no formato [a, b, c].
 * @param lista Ponteiro para a lista.
 */
void imprimirListaDE(tpLista *lista) {

    tpElemento *atual = lista->primeiro;

    if (atual == NULL) {

        printf("[]\n");
        return;
    }

    printf("[");

    while (atual->proximo != NULL) {

        printf("%i, ", atual->dado);
        atual = atual->proximo;
    }

    printf("%i]\n", atual->dado);
}
