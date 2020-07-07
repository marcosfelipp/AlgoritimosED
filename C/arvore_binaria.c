#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int chave;
	struct no *pai;
	struct no *esquerda;
	struct no *direita;
} celula;

typedef celula *arvore;


arvore constroi_arvore(int chave){
	arvore r;
	r = (arvore) malloc(sizeof(celula));
	r->pai = NULL;
	r->esquerda = NULL;
	r->direita = NULL;
	r->chave = chave;
	return r;
}

void cria_filho(arvore r, int x, int esq_dir){
	arvore f;
	f = (arvore) malloc(sizeof(celula));
	f->pai = r;
	f->chave = x;
	f->esquerda = NULL;
	f->direita = NULL;
	// Esquerda -> 1, direita -> 0
	if(esq_dir == 1) r->esquerda = f;
	else r->direita = f;

}


int main(){
	arvore r = constroi_arvore(1);
	cria_filho(r, 2, 1);
	printf("Hello");

}
