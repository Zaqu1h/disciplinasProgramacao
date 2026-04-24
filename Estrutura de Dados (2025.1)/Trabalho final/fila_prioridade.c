/********************************************************************
 * @brief Este arquivo contem funções para manipular uma fila de prioridade
 *        baseada em Heap Binário (Max-Heap).
 *
 * A fila é representada pela estrutura "tpFilaP" definida em fila_prioridade.h.
 * Cada fila guarda:
 *
 * a) Um ponteiro "fila" para um vetor de inteiros;
 * b) Um inteiro "capacidade" que define o tamanho máximo da fila;
 * c) Um inteiro "tamanho" que representa quantos elementos estão inseridos.
 */
 #include "fila_prioridade.h"

//-----------------------------------------------------------------------------

/**
 * @brief Cria e inicializa uma nova fila de prioridade.
 *
 * @param maximo Capacidade máxima da fila.
 * @return nova A nova fila criada.
 */
tpFilaP criaFilaPrioridade(int maximo){

    tpFilaP nova;

    nova.fila = (int*)calloc(maximo, sizeof(int));

    if(nova.fila == NULL){

        exit(1);
    }

    nova.capacidade = maximo;
    nova.tamanho = 0;
    return nova;
}

//-----------------------------------------------------------------------------

/**
 * @brief Libera a memória da fila e a invalida.
 *
 * @param heap Ponteiro para a fila.
 */
void destroiHeap(tpFilaP* heap){

    if (heap == NULL) return;

    if (heap->fila != NULL){

        free(heap->fila);

        heap->fila = NULL;
    }

    heap->tamanho = 0;
    heap->capacidade = 0;
}

//-----------------------------------------------------------------------------

/**
 * @brief Retorna a capacidade máxima da fila.
 *
 * @param heap A fila de prioridade.
 * @return Capacidade total da fila.
 */
int getCapacidadeHeap(tpFilaP heap){

    return heap.capacidade;
}

//-----------------------------------------------------------------------------

/**
 * @brief Retorna a quantidade de elementos atualmente na fila.
 *
 * @param heap A fila de prioridade.
 * @return Tamanho atual da fila.
 */
int getTamanhoHeap(tpFilaP heap){

    return heap.tamanho;
}

//-----------------------------------------------------------------------------

/**
 * @brief Retorna o elemento no índice especificado.
 *
 * @param heap A fila de prioridade.
 * @param i Índice desejado.
 * @return Elemento no índice ou -1 se estiver fora dos limites.
 */
int getElementoHeap(tpFilaP heap, unsigned int i){

    if(i >= heap.tamanho){

        printf("Ind. fora do limite.\n");
        return -1;
    }

    return heap.fila[i];
}

//-----------------------------------------------------------------------------

/**
 * @brief Reorganiza a heap de cima para baixo a partir do índice i (desce heapando).
 *
 * @param heap Ponteiro para a fila.
 * @param i Índice inicial para "descer" o valor.
 */
void desceHeap(tpFilaP *heap, int i) {

    int esquerdo = (2 * i) + 1;
    int direito = (2 * i) + 2;
    int maior = i; // Maior no início está, supostamente, no índice i

    if (esquerdo < heap->tamanho && heap->fila[esquerdo] > heap->fila[maior]) {

        maior = esquerdo;
    }
    if (direito < heap->tamanho && heap->fila[direito] > heap->fila[maior]) {

        maior = direito;
    }

    if (maior != i) { // Só precisa trocar se o maior achado for diferente do atribuído no início

        int trans = heap->fila[i];
        heap->fila[i] = heap->fila[maior];
        heap->fila[maior] = trans;

        desceHeap(heap, maior);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Reorganiza a heap de baixo para cima a partir do índice i (sobe heapando).
 *
 * @param heap Ponteiro para a fila.
 * @param i Índice inicial para "subir" o valor.
 */
void sobeHeap(tpFilaP *heap, int i) {

    if (i == 0) return;

    int pai = (i - 1) / 2;

    if (heap->fila[pai] < heap->fila[i]){

        int temp = heap->fila[pai];
        heap->fila[pai] = heap->fila[i];
        heap->fila[i] = temp;

        sobeHeap(heap, pai);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Constrói uma heap a partir dos elementos da fila.
 *
 * @param heap Ponteiro para a fila.
 */
void fazHeap(tpFilaP *heap){

    if(heap->tamanho < 2)
        return;

    for (int i = (heap->tamanho / 2) - 1; i >= 0; i--) {

        desceHeap(heap, i);
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Ordena um max-heap crescentemente.
 *
 * @param heap Ponteiro para a fila.
 */
void heapSort(tpFilaP *heap){

    fazHeap(heap);
    int tamanhoAntigo = heap->tamanho;

    for (int i = (heap->tamanho - 1); i > 0; i--) {

        int trans = heap->fila[0];
        heap->fila[0] = heap->fila[i];
        heap->fila[i] = trans;

        // Trocou o último com o primeiro e reorganiza a prioridade
        heap->tamanho--;
        desceHeap(heap, 0);
    }

    heap->tamanho = tamanhoAntigo;
}

//-----------------------------------------------------------------------------

/**
 * @brief Remove o elemento de maior prioridade.
 *
 * @param heap Ponteiro para a fila.
 */
void removeTopoHeap(tpFilaP *heap){

    if(heap->tamanho == 0) return;

    heap->fila[0] = heap->fila[heap->tamanho-1];
    heap->tamanho--;
    desceHeap(heap, 0);
}

//-----------------------------------------------------------------------------

/**
 * @brief Insere um novo valor na heap, mantendo a propriedade da Max-Heap.
 *
 * @param heap Ponteiro para a fila.
 * @param num Valor a ser inserido.
 */
void insereHeap(tpFilaP *heap, int num) {

    if(heap->tamanho < heap->capacidade){

        heap->fila[heap->tamanho] = num;

        sobeHeap(heap, heap->tamanho);

        heap->tamanho += 1;
    }
    else{

        printf("Fila lotada, impossivel inserir %i.\n", num);
        return;
    }
}

//-----------------------------------------------------------------------------

/**
 * @brief Imprime todos os elementos da heap na ordem do vetor.
 *
 * @param heap A fila de prioridade.
 */
void printaHeap(tpFilaP heap) {
    for (int i = 0; i < heap.tamanho; i++) {
        printf("%d ", heap.fila[i]);
    }
    printf("\n");
}
