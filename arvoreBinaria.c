
#include <stdio.h>
#include <stdlib.h>

//link de consulta https://www.ime.usp.br/~pf/mac0122-2002/aulas/trees.html

// ----------------- Estruturas -----------------
typedef struct _no_folha{
    int valor;
    struct _no_folha *direita;
    struct _no_folha *esquerda;
} No; 

typedef struct _arvore{
    No *raiz;
    No *auxiliar;
}ArvoreBinaria;

// ----------------- Declaração das funções -----
ArvoreBinaria *CriaArvore();
No *criaNo(int valor);
No *InsereNo(ArvoreBinaria *arvore, int valor);
void ImprimePreOrdem(No *no);
void ImprimePosOrdem(No *no);
void ImprimeImOrdem(No *no);
int ArvoreVazia(ArvoreBinaria *arvore);
void DestroiArvore(ArvoreBinaria *arvore);
void DestroiNo(No *no);


// ----------------- Corpo das funções -----------
ArvoreBinaria *CriaArvore(){
    ArvoreBinaria * novaArvore = (ArvoreBinaria*)calloc(1,sizeof(ArvoreBinaria));
    novaArvore->raiz = NULL;
    novaArvore->auxiliar = NULL;
}

No *criaNo(int valor){
    No *novoNo = (No*)calloc(1,sizeof(No));
    novoNo->valor = valor;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;
}

No *InsereNo(ArvoreBinaria* arvore, int valor){
    No *novoNo = criaNo(valor);
    if(valor != 0){
        if(ArvoreVazia(arvore)){
        arvore->raiz = novoNo; 
        arvore->auxiliar = novoNo;
    }else{
        No *atual = arvore->raiz;
        No *anterior = NULL;
        
        while(atual != NULL){
            anterior = atual;
            if(novoNo->valor == anterior->valor && novoNo->valor > 0){
            free(novoNo);
            return NULL;
            }else if(novoNo->valor < atual->valor){
                atual = atual->esquerda;
            }else{
                atual = atual->direita;
            }
        }
        if(novoNo->valor < anterior->valor){
            anterior->esquerda = novoNo;
        }else{
            anterior->direita = novoNo;
        }
        return arvore->raiz;
    }
    
    }else{
        return NULL;
    }
    
}

int ArvoreVazia(ArvoreBinaria* arvore){
    return (arvore->raiz == NULL);
}

void ImprimePreOrdem(No *no){
    if(no != NULL){
        printf("\n%d", no->valor);
        ImprimePreOrdem(no->esquerda);
        ImprimePreOrdem(no->direita);    
    }else{
        printf("Arvore vazia");
    }
}

void ImprimePosOrdem(No* no){
    if(no != NULL){
        ImprimePosOrdem(no->esquerda);
        ImprimePosOrdem(no->direita);
        printf("\n%d", no->valor); 
    }
}

void ImprimeImOrdem(No* no){
     if(no != NULL){
        ImprimeImOrdem(no->esquerda);
        printf("\n%d", no->valor);
        ImprimeImOrdem(no->direita);
         
    }
}

void DestroiNo(No* no){
    if(no == NULL)
        return;
    DestroiNo(no->esquerda);
    DestroiNo(no->direita);
    free(no);
    no = NULL;
}

void DestroiArvore(ArvoreBinaria* arvore){
    if(arvore == NULL)
        return;
    DestroiNo(arvore->raiz);
    free(arvore);
    arvore = NULL;
}

// ----------------- Main ----------------------- 


int main() {
    
    int entrada = 1;
    
    ArvoreBinaria *arvoreBinaria = CriaArvore();
    while(entrada != 0 ){
        printf("Digite o valor que deseja colocar na arvore ");
        scanf("%d",&entrada);
        No *no = InsereNo(arvoreBinaria, entrada);
    }
    
    printf("\nPre Ordem");
    ImprimePreOrdem(arvoreBinaria->raiz);
    printf("\nPos Ordem");
    ImprimePosOrdem(arvoreBinaria->raiz);
    printf("\n Em ordem");
    ImprimeImOrdem(arvoreBinaria->raiz);
    
    printf("\nDestroindo arvoreBinaria");
    DestroiArvore(arvoreBinaria);
    ImprimePreOrdem(arvoreBinaria->raiz);
    return (0);
}

