#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int chave;
	struct no *pai;
	struct no *filho;
	struct no *irmao;
} celula;

typedef celula *arvore;

typedef struct pilha_no{
	celula *ref_no;
	struct pilha_no *prox;
} pilha;

typedef pilha *stack;


typedef struct fila_no{
	celula *ref_no;
	struct fila_no *prox;
} fila;

typedef fila *queue;

// ############## FUNÇÕES PILHA ##############

stack cria_pilha(){
	stack p;
	p = (stack) malloc(sizeof(pilha));
	p->ref_no = NULL;
	p->prox = NULL;
	return p;
}

stack insere_pilha(stack topo, arvore no){
	stack p;
	p = (stack) malloc(sizeof(pilha));
	p->ref_no = no;
	p->prox = topo;
	return p;
}

stack desempilha_no(stack topo){
	free(topo);
	stack novo_topo = topo->prox;
	return novo_topo;
}

// ############## FUNÇÕES FILA ##############

queue cria_fila(){
	queue q;
	q = (queue) malloc(sizeof(fila));
	q->ref_no = NULL;
	q->prox = NULL;
	return q;
}

queue insere_fila(queue final, arvore no){
	queue q;
	q = (queue) malloc(sizeof(fila));
	q->ref_no = no;
	final->prox = q;
	return q;
}

queue remove_fila(queue inicio){
	free(inicio);
	queue novo_inicio = inicio->prox;
	return novo_inicio;
}

// ############## FUNÇÕES ARVORE ##############

arvore constroi_arvore(int chave){
	arvore r;
	r = (arvore) malloc(sizeof(celula));
	r->pai = NULL;
	r->filho = NULL;
	r->irmao = NULL;
	r->chave = chave;
	return r;
}

void cria_filho(arvore r, int x){
	arvore f;
	f = (arvore) malloc(sizeof(celula));
	f->pai = r;
	f->chave = x;
	f->filho = NULL;
	f->irmao = r->filho;
	r->filho = f;
}


arvore busca_no_recursivo(arvore r, int x){
	arvore prof = NULL; 	
	if(r->chave == x) return r;
	else{
		if(r->filho != NULL){
			prof = busca_no_recursivo(r->filho, x); 	
		}
		if(r->irmao != NULL){
			prof = busca_no_recursivo(r->irmao, x);
		}
		return prof;
	}

}

int insere_no_arvore(arvore r, int x, int pai_para_inserir){
	arvore arvore_inserir = busca_no_recursivo(r, pai_para_inserir);
	if(arvore_inserir != NULL){
		cria_filho(arvore_inserir, x);
		return 1;	
	}else{
		return 0;	
	}

}

int profundidade_recursiva(arvore r, int no, int prof){	
	if(r->chave == no) return prof;
	else{
		if(r->filho != NULL){
			int new_prof = profundidade_recursiva(r->filho, no, prof+1);
			if(new_prof != 0) return new_prof;
		}
		if(r->irmao != NULL){
			int new_prof = profundidade_recursiva(r->irmao, no, prof);
			if(new_prof != 0) return new_prof;
		}
		return 0;
	}
}


int profunidade_iterativa(arvore r, int no){
	int prof = 0;
	stack irmaos = cria_pilha();
	stack filhos = cria_pilha();

	arvore no_pilha = r;
	filhos = insere_pilha(filhos, no_pilha);

	while(irmaos->prox != NULL || filhos->prox != NULL){
		
		// Empilha irmãos:
		while(filhos->ref_no->irmao != NULL){
			no_pilha = filhos->ref_no->irmao;
			irmaos = insere_pilha(irmaos, no_pilha);
		}
		// Desempilha irmãos e empilha filhos:
		while(irmaos->prox != NULL){
			if(irmaos->ref_no->filho != NULL){
				no_pilha = irmaos->ref_no->filho;
				filhos = insere_pilha(filhos, no_pilha);
			}
			irmaos = desempilha_no(irmaos);
		}

	}
	return prof;
}


// ############## FUNÇÕES PERCURSOS ##############


int percurso_largura(arvore r){	
	queue inicio = cria_fila();
	queue final = cria_fila();
	inicio = final;

	arvore no_fila = r;
	final = insere_fila(final, no_fila);
	inicio = final;
	no_fila = no_fila->filho;

	// Percorre irmãos do nó:
	while(no_fila != NULL){
		printf("%d\n",no_fila->chave);
		final = insere_fila(final, no_fila);
		no_fila = no_fila->irmao;
	}

	// Percorre os filhos de cada nó:
	while(inicio->prox != NULL){
		percurso_largura(inicio->prox->ref_no);
		inicio = remove_fila(inicio);
	}

}

// TODO
int percurso_profundidade(arvore r){	
	stack s = cria_pilha();

	// Percorre irmãos do nó:
	arvore no_pilha = r->filho;
	while(no_pilha != NULL){
		printf("%d\n",no_pilha->chave);
		s = insere_pilha(s, no_pilha);
		no_pilha = no_pilha->irmao;
	}

	// Percorre os filhos de cada nó:
	while(s->prox != NULL){
		percurso_largura(s->ref_no);
		s = desempilha_no(s);
	}

}


int main(){
	arvore r = constroi_arvore(1);
	cria_filho(r, 2);

	// Inserindo alguns nós:
	insere_no_arvore(r, 3, 2);
	insere_no_arvore(r, 7, 2);
	insere_no_arvore(r, 8, 2);
	insere_no_arvore(r, 4, 3);
	insere_no_arvore(r, 6, 3);
	insere_no_arvore(r, 9, 8);

	if(insere_no_arvore(r, 5, 4) == 1) printf("Nó inserido\n");
	else printf("Nó não encontrado\n");

	insere_no_arvore(r, 10, 5);

	if(busca_no_recursivo(r,3) != NULL){
		printf("Nó encontrado\n");
	}else{
		printf("Nó não encontrado\n");	
	}

	int i = profundidade_recursiva(r,6,0);
	printf("Profundidade do nó: %i\n",i);

	i = profunidade_iterativa(r, 6);

	percurso_largura(r);

}
