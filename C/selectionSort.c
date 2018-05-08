#include <stdio.h>

/*
Selecionar o menor valor do vetor e coloca-lo na posicao i.
Bom porque tem pouca movimentação de valores - ideal para dados muito grandes
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
		// Verificação para não trocar dados da mesma posição:
		if(posicaoMenor != i){
			int temp = vetor[i];
			vetor[i] = vetor[posicaoMenor];
			vetor[posicaoMenor] = temp;
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d\n",vetor[i]);
	}
}
