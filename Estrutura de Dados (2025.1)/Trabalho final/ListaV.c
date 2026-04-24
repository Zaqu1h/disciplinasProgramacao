/********************************************************************
 * @brief Este arquivo código para manipular uma lista com vetor.
 *
 * Uma listaV é representada pela estrutura "tpListaV" definida em listaV.h.
 * Uma listaV guarda:
 *
 * a) Um ponteiro "dado" para um vetor de inteiros;
 * b) Um inteiro "capacidade" que define o tamanho máximo da fila;
 * c) Um inteiro "qte" que representa quantos elementos estão inseridos.
 *
 */
 #include "ListaV.h"

//-----------------------------------------------------------------------------

/**
 * @brief Cria uma nova lista com vetor e capacidade definida pelo usuário.
 *
 * @param capacidade Capacidade máxima da lista.
 * @return lista Estrutura da lista inicializada.
 */
tpListaV criarListaV(int capacidade) {

    tpListaV lista;
    lista.dado = (int*)calloc(capacidade, sizeof(int));

    if (lista.dado == NULL) exit(1);  // Falha na alocação

    lista.qte = 0;
    lista.capacidade = capacidade;

    return lista;
}

//-----------------------------------------------------------------------------

/**
 * @brief Libera a memória alocada para o vetor interno da lista.
 *
 * @param lista Ponteiro para a lista.
 */
void liberarListaV(tpListaV *lista) {
    if (lista != NULL) {
        free(lista->dado);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Verifica se a lista está cheia.
 *
 * @param lista Ponteiro para a lista.
 * @return 1 se estiver cheia, 0 caso contrário.
 */
int confCheiaLV(tpListaV *lista) {
    return lista->qte == lista->capacidade;
}

//-----------------------------------------------------------------------------

/**
 * @brief Verifica se a lista está vazia.
 *
 * @param lista Ponteiro para a lista.
 * @return 1 se estiver vazia, 0 caso contrário.
 */
int confVaziaLV(tpListaV *lista) {
    return lista->qte == 0;
}

//-----------------------------------------------------------------------------

/**
 * @brief Retorna a quantidade atual de elementos na lista.
 *
 * @param lista Ponteiro para a lista.
 * @return Quantidade de elementos.
 */
int tamListaV(tpListaV *lista) {
    return lista->qte;
}

//-----------------------------------------------------------------------------

/**
 * @brief Insere um elemento em uma posição específica da lista.
 *
 * @param lista Ponteiro para a lista.
 * @param pos Posição onde o elemento será inserido.
 * @param dado Elemento a ser inserido.
 * @return Nova quantidade de elementos, 0 se posição inválida, -1 se lista cheia.
 */
int inserirNaPosLV(tpListaV *lista, int pos, int dado) {

    if (confCheiaLV(lista)) return -1;

    if (pos < 0 || pos > lista->qte) return 0;

    for (int i = lista->qte; i > pos; i--) {

        lista->dado[i] = lista->dado[i - 1];
    }

    lista->dado[pos] = dado;
    lista->qte++;

    return lista->qte;
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove a primeira ocorrência de um elemento da lista.
 *
 * @param lista Ponteiro para a lista.
 * @param dado Elemento a ser removido.
 * @return Nova quantidade de elementos se removido, -1 se não encontrado ou lista vazia.
 */
int removerDadoLV(tpListaV *lista, int dado) {

    if (confVaziaLV(lista)) return -1;

    int i = 0;

    while (i < lista->qte && lista->dado[i] != dado) {

        i++;
    }

    if (i == lista->qte) return -1;

    for (int j = i; j < lista->qte - 1; j++) {

        lista->dado[j] = lista->dado[j + 1];
    }

    lista->qte--;
    return lista->qte;
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove o elemento na posição indicada da lista.
 *
 * @param lista Ponteiro para a lista.
 * @param indice Índice do elemento a ser removido.
 * @return Nova quantidade de elementos se removido, -1 se índice inválido.
 */
int removerIndiceLV(tpListaV *lista, int indice) {

    if (confVaziaLV(lista)) return -1;

    if (indice < 0 || indice >= lista->qte) return -1;

    for (int i = indice; i < lista->qte - 1; i++) {

        lista->dado[i] = lista->dado[i + 1];
    }

    lista->qte--;
    return lista->qte;
}

/**
 * @brief Busca por um elemento na lista.
 *
 * @param lista Ponteiro para a lista.
 * @param item Elemento a ser buscado.
 * @return Índice do elemento se encontrado, -1 caso contrário.
 */
int buscarDadoLV(tpListaV *lista, int item) {

    for (int i = 0; i < lista->qte; i++) {

        if (lista->dado[i] == item) return i;
    }
    return -1;
}

//-----------------------------------------------------------------------------

/**
 * @brief Imprime os elementos da lista.
 *
 * @param lista Ponteiro para a lista.
 */
void imprimirListaV(tpListaV *lista) {

    printf("[");

    for (int i = 0; i < lista->qte; i++) {

        printf("%d", lista->dado[i]);

        if (i < lista->qte - 1) printf(", ");
    }
    printf("]\n");
}
