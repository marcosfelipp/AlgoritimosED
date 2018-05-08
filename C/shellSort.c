#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/*
Divide um vetor em subvetores lógicos menores e ondena eles
Sequencia de incremento definida por Knuth: h(1) = 1,  h(i+1) = 3hi + 1

*/
int sequenciaKnuth(int n){
	int i;
	for(i = 1; i < n/3 - 1; i = 3*i + 1);
	return i;
}


void main(){
	int n = 100;
	int vetor[100];

	srand(time(NULL));
	for(int i=0; i<n; i++){
		vetor[i] = rand()%1000;
	}

	int maximoSequencia = sequenciaKnuth(n);

	for(int i=maximoSequencia; i >= 1; i = (i-1)/3){
		for(j=0; j <maximoSequencia; j++){
			//Ordenar
		}

	}

}