#include <stdio.h>

void main(){
	int j, posicaoMenor;
	int n = 10;
	int vetor[10] = {9,7,4,5,6,1,2,3,8,0};

	for(int i = 0; i < n; i++){
		for(j= n-1; j > i; j-- ){
			if(vetor[j] < vetor[j-1]){
				int temp = vetor[j];
				vetor[j] = vetor[j-1];
				vetor[j-1] = temp;
			}
		}
	}

	for(int i = 0; i < n; i++){
		printf("%d\n",vetor[i]);
	}


}