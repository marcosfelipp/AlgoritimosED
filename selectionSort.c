#include <stdio.h>

/*
Selecionar o menor valor do vetor e coloca-lo na posicao i. 
NÂO ESTAVEL -> Troca posições de mesmo valor
NÂO ADAPTATIVO -> Não depende do grau de ordenação prévia
*/
void main(){
	int j, posicaoMenor;
	int n = 10;
	int vetor[10] = {9,7,4,5,6,1,2,3,8,0};

	for(int i = 0; i < n-1; i++){
		for(j= i+1, posicaoMenor = i; j<n; j++){
			if(vetor[posicaoMenor] > vetor[j]){
				posicaoMenor = j;
			}
		}
		//Troca
	}

	for(int i = 0; i < n; i++){
		printf("%d\n",vetor[i]);
	}
}
