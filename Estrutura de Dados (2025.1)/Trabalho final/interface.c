/********************************************************************
 * @brief Arquivo principal que apresenta um menu interativo com múltiplas
 *        estruturas de dados, como Árvore AVL, Fila de Prioridade,
 *        Lista com Vetor e Lista Duplamente Encadeada. Conta com
 *        as 5 bibliotecas definidas em arquivos externos .h.
 *
 * Cada estrutura possui um submenu com funcionalidades como as de
 * inserção, remoção, busca, ordenação e impressão.
 *
 */

//-----------------------------------------------------------------------------

// Biblioteca para manipulação de árvores AVL
#include "arvoreAVL.h"

// Biblioteca para manipulação de filas de prioridades (max-heaps)
#include "fila_prioridade.h"

// Biblioteca para manipulação de listas duplamente encadeadas
#include "listaDE.h"

// Biblioteca de algoritmos de ordenação (QuickSort e MergeSort)
#include "ordenacao.h"

// Biblioteca para manipulação de listas com vetores
#include "ListaV.h"

// Biblioteca padrão para trabalhar com entradas e saídas.
#include <stdio.h>

// Biblioteca que serve para a manipulação da memória (alocações, liberações,
// ... etc).
#include <stdlib.h>

//-----------------------------------------------------------------------------

/**
 * @brief Exibe o menu principal, que direciona o usuário para a estrutura de dados desejada.
 */
void menuPrincipal();

//-----------------------------------------------------------------------------

/**
 * @brief Exibe o menu da árvore AVL com opções para inserir, remover, buscar e percorrer.
 */
void menuArvoreAVL();

//-----------------------------------------------------------------------------

/**
 * @brief Exibe o menu da fila de prioridade (heap) com opções de criação, inserção, remoção e ordenação.
 */
void menuFilaPrioridade();

//-----------------------------------------------------------------------------

/**
 * @brief Exibe o menu da lista duplamente encadeada com opções de inserção, remoção, busca, ordenação e exibição.
 */
void menuLDE();

//-----------------------------------------------------------------------------

/**
 * @brief Exibe o menu da lista implementada com vetor (array).
 */
void menuListaVetor();




// FUNÇÃO PRINCIPAL (MAIN) -----------------------------------------------------

/**
 * @brief Função principal do programa. Inicia o menu principal.
 *
 * @return int Retorna 0 ao final da execução.
 */
int main() {

    menuPrincipal();
    return 0;
}

//-----------------------------------------------------------------------------




void menuPrincipal() {

    int opcaoP;

    do {
        printf("_______________________________________________________________________________\n");

        printf("Menu Principal:\n\n");

        printf("1.\tArvore AVL;\n");
        printf("2.\tFila de Prioridade;\n");
        printf("3.\tLista com Vetor;\n");
        printf("4.\tLista Duplamente Encadeada;\n");
        printf("0.\tSair\n");

        printf("_______________________________________________________________________________\n\n > ");

        scanf("%i", &opcaoP);
        printf("\n");

            switch (opcaoP) {
                case 1:
                    menuArvoreAVL();
                    break;
                case 2:
                    menuFilaPrioridade();
                    break;
                case 3:
                    menuListaVetor();
                    break;
                case 4:
                    menuLDE();
                    break;
                case 0:
                    printf("Encerrando...");
                    break;
                default:
                    printf("Erro\n");
            }

        } while (opcaoP != 0);

    return;
}

//-----------------------------------------------------------------------------

void menuArvoreAVL() {

    int opcaoArv;
    int valor;
    tpNo* Arvore = NULL;

    do {

        printf("_______________________________________________________________________________\n");

        printf("Menu AVL:\n\n");

        printf("1.\tInserir nodo;\n");
        printf("2.\tRemover nodo;\n");
        printf("3.\tBuscar nodo;\n");
        printf("4.\tPre-Ordem;\n");
        printf("5.\tEm Ordem;\n");
        printf("6.\tPos-Ordem;\n");
        printf("7.\tLimpar AVL;\n");
        printf("0.\tVoltar\n");

        printf("_______________________________________________________________________________\n\n > ");

        scanf("%i", &opcaoArv);

        switch (opcaoArv) {

            case 1:

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                Arvore = inserirNo(Arvore, valor);

                if (Arvore != NULL) printf("\n'%i' foi inserido com sucesso.\n", valor);
                else printf("\nErro.\n");

                break;
            case 2:

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                tpNo* achado = buscaArvore(Arvore, valor);
                Arvore = removerNo(Arvore, achado->valor);

                if (achado != NULL && achado->valor == valor) printf("\n'%i' foi removido com sucesso.\n", valor);
                else printf("\n'%i' inexistente.\n", valor);

                break;
            case 3:

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                achado = buscaArvore(Arvore, valor);

                if (achado != NULL && achado->valor == valor) printf("'%i' foi achado com sucesso.\n", valor);
                else printf("'%i' inexistente.\n", valor);

                break;
            case 4:

                preOrdem(Arvore);
                printf("\n");
                break;
            case 5:

                emOrdem(Arvore);
                printf("\n");
                break;
            case 6:

                posOrdem(Arvore);
                printf("\n");
                break;
            case 7:

                lenhador(Arvore);
                break;
            case 0:

                lenhador(Arvore);
                break;
            default:
                printf("Erro\n");
        }
    }while(opcaoArv != 0);

    return;
}

//-----------------------------------------------------------------------------

void menuFilaPrioridade() {

    int opcaoFila;
    int valor;
    int filaCriada = 0;
    tpFilaP Fila;

    do {

        printf("_______________________________________________________________________________\n");

        printf("Menu Fila de Prioridade (Max-Heap):\n\n");

        printf("1.\tCriar fila;\n");
        printf("2.\tInserir na fila;\n");
        printf("3.\tRemover do topo da fila;\n");
        printf("4.\tOrdenar a fila;\n"); // Usa HeapSort
        printf("5.\tImprimir fila;\n");
        printf("6.\tLimpa Fila;\n");
        printf("0.\tVoltar\n");

        printf("_______________________________________________________________________________\n\n > ");

        scanf("%i", &opcaoFila);

        switch (opcaoFila) {

            case 1:

                if(filaCriada == 1) destroiHeap(&Fila);
                printf("Insira a capacidade max. da fila: \n\n > ");
                scanf("%i", &valor);

                Fila = criaFilaPrioridade(0X7FFFFFFF & valor);

                filaCriada = 1;

                printf("\nFila de capacidade '%i' criada com sucesso.\n", valor);

                break;
            case 2:

                if(filaCriada != 1){
                    printf("\nCrie uma fila antes disso!\n");
                    break;
                }

                int tamanhoAntigo = Fila.tamanho;
                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                insereHeap(&Fila, valor);
                if (Fila.tamanho - tamanhoAntigo == 1){
                    printf("\n'%i' inserido com sucesso.\n", valor);
                    fazHeap(&Fila);
                }
                else printf("\nImpossivel de inserir '%i.'\n", valor);

                break;
            case 3:

                if(filaCriada != 1){
                    printf("\nCrie uma fila antes disso!\n");
                    break;
                }

                if(Fila.tamanho == 0) printf("\nFila vazia.\n");
                else{

                tamanhoAntigo = Fila.tamanho;
                int topoAntigo = Fila.fila[0];
                removeTopoHeap(&Fila);

                if (Fila.tamanho - tamanhoAntigo == -1) printf("\nTopo ('%i') removido com sucesso.\n", topoAntigo);
                else printf("\nAlgo deu errado ao remover...'\n");
                }

                break;
            case 4:

                if(filaCriada != 1){
                    printf("\nCrie uma fila antes disso!\n");
                    break;
                }

                if(Fila.tamanho == 0) printf("\nFila vazia.\n");
                else{

                printf("Fila antes: ");
                printaHeap(Fila);
                printf("Fila depois de ordenar: ");
                heapSort(&Fila);
                printaHeap(Fila);
                }

                break;
            case 5:

                printaHeap(Fila);
                break;
            case 6:

                destroiHeap(&Fila);
                break;
            case 0:

                destroiHeap(&Fila);
                break;
            default:
                printf("Erro\n");
        }
    }while(opcaoFila != 0);

    return;
}

//-----------------------------------------------------------------------------

void menuLDE() {

    int opcaoLDE;
    int valor;
    tpLista Lista = criarListaDE();

    do {

        printf("_______________________________________________________________________________\n");

        printf("Menu Lista Duplamente Encadeada:\n\n");

        printf("1.\tInserir elemento;\n");
        printf("2.\tRemover elemento;\n");
        printf("3.\tBuscar elemento;\n");
        printf("4.\tImprimir lista;\n");
        printf("5.\tOrdenar lista;\n"); // Usa MergeSort
        printf("6.\tLimpar lista;\n");
        printf("0.\tVoltar\n");

        printf("_______________________________________________________________________________\n\n > ");

        scanf("%i", &opcaoLDE);

        switch (opcaoLDE) {

            case 1:

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                int onde = 0;
                int tamanhoAntigo = Lista.tamanho;

                printf("Tamanho da lista: %i\n", tamanhoAntigo);
                printf("Informe onde: \n\n > ");
                scanf("%i", &onde);

                if(onde == 0) inserirNoInicioLDE(&Lista, valor);
                else if (onde == tamanhoAntigo) inserirNoFimLDE(&Lista, valor);
                else if (onde > 0 && onde < tamanhoAntigo) inserirNaPosicaoLDE(&Lista, onde, valor);
                else printf("\nLocal inexistente.'\n");

                if (Lista.tamanho - tamanhoAntigo == 1){

                    printf("\n'%i' inserido com sucesso.\n", valor);
                }
                else printf("\nErro ao inserir '%i.'\n", valor);

                break;
            case 2:

                onde = 0;
                tamanhoAntigo = Lista.tamanho;

                printf("Tamanho da lista: %i\n", tamanhoAntigo);
                printf("1.\tRemover o primeiro;\n");
                printf("2.\tRemover o final;\n");
                printf("3.\tRemover por valor\n\n > ");
                scanf("%i", &onde);

                if(onde == 1) removerNoInicioLDE(&Lista);
                else if (onde == 2) removerNoFimLDE(&Lista);
                else if (onde == 3){

                    printf("Insira o valor que desejar: \n\n > ");
                    scanf("%i", &valor);

                    removerElementoLDE(&Lista, valor);
                }
                else {

                    printf("\nErro.'\n");
                    break;
                }

                if(Lista.tamanho - tamanhoAntigo == -1) printf("\nRemovido com sucesso.\n");
                else printf("\nItem inexistente.\n");

                break;
            case 3:

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                tpElemento* achadoDE = buscarElementoLDE(&Lista, valor);

                if (achadoDE != NULL && achadoDE->dado == valor) printf("'%i' foi achado com sucesso.\n", valor);
                else printf("'%i' inexistente.\n", valor);

                break;
            case 4:

                imprimirListaDE(&Lista);
                break;
            case 5:

                if (Lista.tamanho < 2) break;

                int *aux = (int*)malloc(sizeof(int) * Lista.tamanho);
                int i = 0;

                if(aux != NULL){

                    while(Lista.primeiro != NULL){

                        aux[i++] = Lista.primeiro->dado;
                        removerNoInicioLDE(&Lista);
                    }

                    mergeSort(aux, 0, i - 1);


                    for (int j = i - 1; j >= 0; j--) {

                        inserirNoInicioLDE(&Lista, aux[j]);
                    }

                    free(aux);
                    printf("\nA lista foi ordenada.\n");
                }
                break;
            case 6:

                liberarListaDE(&Lista);
                break;
            case 0:

                liberarListaDE(&Lista);
                break;
            default:
                printf("Erro\n");
        }
    }while(opcaoLDE != 0);

    return;
}

//-----------------------------------------------------------------------------

void menuListaVetor() {

    int opcaoLV;
    int valor;
    tpListaV Lista;
    int LVCriada = 0;

    do {

        printf("_______________________________________________________________________________\n");

        printf("Menu Lista com Vetor:\n\n");

        printf("1.\tCriar ListaV;\n");
        printf("2.\tInserir na ListaV;\n");
        printf("3.\tRemover da ListaV;\n");
        printf("4.\tBuscar na ListaV;\n");
        printf("5.\tOrdenar ListaV;\n"); // Usa QuickSort
        printf("6.\tImprimir ListaV;\n");
        printf("7.\tLimpar ListaV;\n");
        printf("0.\tVoltar\n");

        printf("_______________________________________________________________________________\n\n > ");

        scanf("%i", &opcaoLV);

        switch (opcaoLV) {

            case 1:

                int cap = 0;

                printf("\nInsira a capacidade max. desejada: \n\n > ");
                scanf("%i", &cap);

                Lista = criarListaV((0x7FFFFFFF & cap));
                LVCriada = 1;

                break;
            case 2:

                if (LVCriada != 1) break;

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                int onde = 0;
                int tamanhoAntigo = Lista.qte;

                printf("Tamanho da lista: %i\n", tamanhoAntigo);
                printf("Informe onde: \n\n > ");
                scanf("%i", &onde);

                if(onde < 0 || onde > Lista.capacidade) printf("\nLocal inexistente.'\n");
                else if (onde >= tamanhoAntigo) inserirNaPosLV(&Lista, tamanhoAntigo, valor);
                else inserirNaPosLV(&Lista, onde, valor);

                if (Lista.qte - tamanhoAntigo == 1){

                    printf("\n'%i' inserido com sucesso.\n", valor);
                }
                else printf("\nErro ao inserir '%i.'\n", valor);

                break;
            case 3:

                if (LVCriada != 1) break;

                int escolha;
                onde = 0;
                tamanhoAntigo = Lista.qte;

                printf("Tamanho da lista: %i\n", tamanhoAntigo);
                printf("1.\tRemover por pos.;\n");
                printf("2.\tRemover por valor;\n");
                scanf("%i", &escolha);

                if(escolha == 1){

                    printf("Informe onde: \n\n > ");
                    scanf("%i", &onde);

                    removerIndiceLV(&Lista, onde);
                }
                else if (escolha == 2){

                    printf("Insira o valor que desejar: \n\n > ");
                    scanf("%i", &valor);

                    removerDadoLV(&Lista, valor);
                }
                else {

                    printf("\nErro.'\n");
                    break;
                }

                if (Lista.qte - tamanhoAntigo == -1) printf("\n'%i' foi removido com sucesso.\n", valor);
                else printf("\nItem inexistente.");

                break;
            case 4:

                if (LVCriada != 1) break;

                printf("Insira o valor que desejar: \n\n > ");
                scanf("%i", &valor);

                int indice = buscarDadoLV(&Lista, valor);

                if (Lista.dado[indice] == valor) printf("'%i' foi achado com sucesso em '%i'.\n", valor, indice);
                else printf("'%i' inexistente.\n", valor);

                break;
            case 5:

                if (LVCriada != 1) break;

                quickSort(Lista.dado, 0, Lista.qte - 1);
                printf("\nLista ordenada.\n");
                break;
            case 6:

                imprimirListaV(&Lista);
                break;
            case 7:

                liberarListaV(&Lista);
                break;
            case 0:

                liberarListaV(&Lista);
                break;
            default:
                printf("Erro\n");
        }
    }while(opcaoLV != 0);

    return;
}
