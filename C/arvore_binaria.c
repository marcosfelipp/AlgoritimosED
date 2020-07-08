#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int chave;
	struct no *esquerda;
	struct no *direita;
} celula;

typedef celula *arvore;


arvore constroi_arvore(int chave){
	arvore r;
	r = (arvore) malloc(sizeof(celula));
	r->esquerda = NULL;
	r->direita = NULL;
	r->chave = chave;
	return r;
}


void cria_filho(arvore r, int x, int esq_dir){
	arvore f;
	f = (arvore) malloc(sizeof(celula));
	f->chave = x;
	f->esquerda = NULL;
	f->direita = NULL;
	// Esquerda -> 0, direita -> 1
	if(esq_dir == 0) r->esquerda = f;
	else r->direita = f;

}

arvore busca_no(arvore r, int x){
	if(r->chave == x) return r;

	if(r->esquerda != NULL){
		arvore e = busca_no(r->esquerda, x);
		if(e != NULL) return e; 
	}
	if(r->direita != NULL){
		arvore r = busca_no(r->direita, x);
		if(r != NULL) return r;
	}
	return NULL;
}


int insere_no_arvore(arvore r, int x, int pai_para_inserir, int esq_dir){
	arvore arvore_inserir = busca_no(r, pai_para_inserir);
	if(arvore_inserir != NULL){
		cria_filho(arvore_inserir, x, esq_dir);
		return 1;	
	}else{
		return 0;	
	}
}

int tamanho(arvore r){
	if(r==NULL) return 0;
	else return tamanho(r->esquerda) + 1 +tamanho(r->direita);
}

int main(){
	arvore r = constroi_arvore(1);
	insere_no_arvore(r, 2, 1, 0);
	insere_no_arvore(r, 3, 1, 1);
	insere_no_arvore(r, 4, 2, 0);
	insere_no_arvore(r, 5, 2, 1);
	// insere_no_arvore(r, 6, 3, 0);
	// insere_no_arvore(r, 7, 3, 1);
}
