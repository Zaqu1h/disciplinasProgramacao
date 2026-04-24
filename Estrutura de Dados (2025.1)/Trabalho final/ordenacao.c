/********************************************************************
 * @brief Este arquivo contém código para utilização de algoritmos
 *        de ordenação de vetores de inteiros.
 *
 * os Algoritmos de ordenação disponíveis são o Quick e o MergeSort, tais
 * quais os cabeçalhos estão definidos em um arquivo .h nomeado ordenacao.h.
 *
 * Obs: Merge é mais estável em velocidade, mas o Quick usa menos espaço
 * na memória, embora possa ser mais lento - O(n^2) - em casos mais ruins.
 */
 #include "ordenacao.h"

//-----------------------------------------------------------------------------

/**
 * @brief Particiona um vetor de inteiros para o QuickSort.
 *
 * @param vetor Vetor de inteiros a ser particionado.
 * @param inicio Índice inicial do subvetor.
 * @param fim Índice final do subvetor.
 * @return Índice do pivô após a partição.
 */
int particionar(int* vetor, int inicio, int fim){

    int pivo = vetor[fim];
    int i = inicio - 1; // começa em (inicio - 1) para que, ao encontrar o primeiro elemento <= pivo,
                        // ele seja colocado corretamente na posição 'inicio'

    int trans = 0;

    // Do inicio até o item anterior ao pivô
    for(int  j = inicio; j < fim; j++){

        if(vetor[j] <= pivo){

            i++; // Próxima posição válida pra troca
            trans = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = trans;
        }
    }

    pivo = i + 1; // Pos. final do pivô

    // Coloca o pivô na posição correta, depois dos menores que ele
    trans = vetor[pivo];
    vetor[pivo] = vetor[fim];
    vetor[fim] = trans;

    return pivo;
}

//-----------------------------------------------------------------------------

/**
 * @brief Algoritmo que ordena um vetor de inteiros recursivamente se baseando
 * em divisão e conquista.
 *
 * @param vetor Vetor de inteiros a ser ordenado.
 * @param inicio Índice inicial do vetor.
 * @param fim Índice final do vetor.
 */
void quickSort(int* vetor, int inicio, int fim){

    if(inicio < fim){

        int posPiv = particionar(vetor, inicio, fim);

        quickSort(vetor, posPiv + 1, fim);
        quickSort(vetor, inicio, posPiv - 1);
    }
}

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
void merge(int *v, int inicio, int meio, int fim) {

    int tamanho = fim - inicio + 1; // Quantidade de elementos para mesclar
    int *temp;

    temp = (int*)malloc(tamanho * sizeof(int));

    if (temp == NULL) {

        printf("Erro alocando mem.");
        exit(1);
    }

    int primeiraMetade = inicio;
    int segundaMetade = meio + 1;

    // 0 enquanto as metades não foram totalmente percorridas
    int fim1 = 0, fim2 = 0;

    int i;

    for(i = 0; i < tamanho; i++) { // Preenche o vetor temporário com os menores valores de cada metade

        if (fim1 != 1 && fim2 != 1){

            if (v[primeiraMetade] < v[segundaMetade]) { // Compara os elementos das duas metades e guarda o menor

                temp[i] = v[primeiraMetade++];
            }
            else {

                temp[i] = v[segundaMetade++];
            }

            if (primeiraMetade > meio) fim1 = 1;

            if (segundaMetade > fim) fim2 = 1;

        }
        else {
            if (fim1 != 1) {

                temp[i] = v[primeiraMetade++];
            }
            else {

                temp[i] = v[segundaMetade++];
            }
        }
    }

    int k = inicio; // Copia os elementos do vetor temporário de volta para o vetor original

    for (i = 0; i < tamanho; i++, k++) {

        v[k] = temp[i];
    }

    free(temp);
}

//-----------------------------------------------------------------------------

/**
 * @brief Ordena um vetor de inteiros dividindo os vetores em vários subvetores
 * e mesclando-os de forma ordenada.
 *
 * @param v Vetor de inteiros a ser ordenado.
 * @param inicio Índice inicial do vetor.
 * @param fim Índice final do vetor.
 */
void mergeSort(int *v, int inicio, int fim){

    if(inicio < fim) {

        int meio = ((inicio + fim)/2);

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}
