#include <stdio.h>

/*
A ideia do InsertionSort é inserir um dado elemento em sua posição 
Indicado para servir como base para outros algorítimos como QuickSort e MergeSort
i -> Posição que quero ordenar
j -> Posição quero comparar
-----------------------------
ADAPTATIVO -> Sensível ao grau de ordenação do vetor
ESTÀVEL -> Não troca elemento com valores iguais
*/

void main(){
	int j;
	int n = 10;
	int vetor[10] = {9,7,4,5,6,1,2,3,8,0};

	for(int i = 0; i < n; i++){
		int variavelTemporaria = vetor[i];
		for(j = i; j > 0 && variavelTemporaria < vetor[j-1]; j--){
			vetor[j] = vetor[j-1];
		}
		vetor[j] = variavelTemporaria; 
	}

	for(int i = 0; i < n; i++){
		printf("%d\n",vetor[i]);
	}
}
