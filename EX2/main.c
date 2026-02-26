#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* a alteração dos valores do vetor e feita no main

/* ================= FUNÇÃO AUXILIAR ================= */
int i,j;
void printArray(int arr[], int n) {
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void copiarArray(int origem[], int destino[], int n) {
    for(i = 0; i < n; i++)
        destino[i] = origem[i];
}

/* ================= BUBBLE SORT ================= */

void bubbleSort(int arr[], int n) {
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ================= SELECTION SORT ================= */

void selectionSort(int arr[], int n) {
    for(i = 0; i < n - 1; i++) {
        int min = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

/* ================= INSERTION SORT ================= */

void insertionSort(int arr[], int n) {
    for(i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* ================= QUICK SORT ================= */

int particionar(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = particionar(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ================= MERGE SORT ================= */

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* ================= MENU E TESTES ================= */

int main() {

    int tamanho = 100;  // aqui onde pode alterar o tamanho do vetor
    int original[tamanho];
    int copia[tamanho];

    srand(time(NULL));

    for(i = 0; i < tamanho; i++)
        original[i] = rand() % 10000;

    int opcao;
    clock_t inicio, fim;
    double tempo;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - bubble sort\n");
        printf("2 - selection sort\n");
        printf("3 - insertion sort\n");
        printf("4 - quick sort\n");
        printf("5 - merge sort\n");
        printf("0 - sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        copiarArray(original, copia, tamanho);

        switch(opcao) {

            case 1:
                inicio = clock();
                bubbleSort(copia, tamanho);
                fim = clock();
                break;

            case 2:
                inicio = clock();
                selectionSort(copia, tamanho);
                fim = clock();
                break;

            case 3:
                inicio = clock();
                insertionSort(copia, tamanho);
                fim = clock();
                break;

            case 4:
                inicio = clock();
                quickSort(copia, 0, tamanho - 1);
                fim = clock();
                break;

            case 5:
                inicio = clock();
                mergeSort(copia, 0, tamanho - 1);
                fim = clock();
                break;

            case 0:
                printf("encerrando...\n");
                break;

            default:
                printf("invalido\n");
                continue;
        }

        if(opcao != 0) {
            tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("tempo de execucao: %f segundos\n", tempo);
        }

    } while(opcao != 0);

    return 0;
}
