#include <stdio.h>
#include <stdlib.h>

struct arvn {
    int info;
    struct arvn *primo; 
    struct arvn *irmao; 
};

typedef struct arvn Arvn;

int vazia(Arvn* raiz){
    if(raiz == NULL){
        printf("\nLista Vazia\n");
        return 1;
    }else{
        printf("\nLista nao esta vazia\n");
        return 0;
    }
}

Arvn* criar (int c) {
    Arvn *a =(Arvn *) malloc(sizeof(Arvn));
    a->info = c;
    a->primo = NULL;
    a->irmao = NULL;
    return a;
}

Arvn* buscar (Arvn* raiz, int c){
    Arvn* p;
    if(raiz->info==c){
        return raiz;
    }else{
        for(p=raiz->primo; p!=NULL; p=p->irmao){
            Arvn* x = buscar(p,c);// ponteiro auxiliar x recebe o primogenito da raiz eo valor que quer buscar e compara ate achar o valor digitado
            if( x != NULL){
                return x;
            }
        }
        return NULL;
    }
}

Arvn* inserir(Arvn* raiz, int valorFilho, int valorPai) {
	Arvn* pai = buscar(raiz, valorPai);
	if(pai == NULL) {
		return NULL;
	}
	Arvn* novo = criar(valorFilho);
    if(pai->primo == NULL) {
		pai->primo = novo;
	} else {
		Arvn* p = pai->primo;
		while(p->irmao != NULL) {
			p = p->irmao;
		}
		p->irmao = novo;
	}
	return pai;	
}

void imprimir (Arvn* raiz){
    Arvn* p;
    printf("<%d\n",raiz->info);
    for (p=raiz->primo; p!=NULL; p=p->irmao){
        imprimir(p); 
    }
    printf(">");
}

Arvn* liberar (Arvn* raiz) {
    Arvn* p = raiz->primo;
    while (p!=NULL) {
    Arvn* t = p->irmao;
    liberar(p);
    p = t;
}
    free(raiz);
    return NULL;
}
    
int main(int argc, char const *argv[])
{
    printf("\n--------------------------------------------\n");
    Arvn* arvore;// criei o pai
    arvore = criar(9);
    vazia(arvore);
    

    inserir(arvore, 24, 9);// raiz,filho,pai 
    inserir(arvore, 10, 24);
    inserir(arvore, 15, 10);
    inserir(arvore, 80, 9);
    inserir(arvore, 14, 80);
    inserir(arvore, 60, 14);
    imprimir(arvore);
    printf("\n--------------------------------------------\n");
    Arvn* buscarelemento = buscar(arvore , 15);
    if(buscarelemento != NULL){
        printf("\n>>>%d foi achado\n", buscarelemento->info);
    }else{
        printf("\n >>>O Elemento nao foi achado\n");
    }
    imprimir(arvore);
    printf("\n--------------------------------------------\n");
    arvore = liberar(arvore);
    printf("\nLiberado com Sucesso\n");
    vazia(arvore);
    imprimir(arvore);
    
    return 0;
}







