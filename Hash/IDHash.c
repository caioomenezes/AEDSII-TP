//Amanda(5366), Caio(5784), Leticia(5781), Melissa(5384)

#include "IDHash.h"

void Inicializa_Lista_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido){ //Estamos utilizando célula cabeça
    listaIdInvertido -> primeiro = (Celula_ID_Hash*)malloc(sizeof(Celula_ID_Hash)); 
    listaIdInvertido -> ultimo = listaIdInvertido -> primeiro; 
    listaIdInvertido -> primeiro -> prox = NULL; 
    //Para a lista estar vazia ultimo e proximo terao que apontar
    //para o mesmo elemento, a minha celula cabeca e o proximo tem que ser NULL
}

int Verifica_Vazio_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido){ // A funcao Lista Vazia retorna se a nossa lista encadeada possui elementos ou nao. 
    return(listaIdInvertido-> primeiro == listaIdInvertido-> ultimo); // Retorna 1 se esta vazia, e 0 se nao
} 

int Retorna_Tamanho_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido){
    int tamanho=0; 
    if (Verifica_Vazio_ID_Hash(listaIdInvertido)){ // Verifica se a lista e vazia, se for, a variavel tamanho recebe 0
        return 0;
    }
    Celula_ID_Hash* auxiliar = listaIdInvertido -> primeiro -> prox;
    while ( auxiliar != NULL) {
        tamanho += 1;   // Somamos um ao tamanho
        auxiliar = auxiliar -> prox; // Avancamos para a proxima Celula_ID da lista
    }
    return tamanho;
}

void Adiciona_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido, int qtd, int id_doc){

    listaIdInvertido -> ultimo -> prox = (Celula_ID_Hash*)malloc(sizeof(Celula_ID_Hash)); //Ligando minha nova celula a anterior a ela (antiga ultima)
    
    listaIdInvertido -> ultimo = listaIdInvertido -> ultimo -> prox; //Atualizando o meu ultimo para a nova celula alocada
    
    //adicionando indice invertido:
    listaIdInvertido -> ultimo -> qtd = qtd; 
    
    listaIdInvertido -> ultimo -> id_doc = id_doc;
    
    listaIdInvertido -> ultimo -> prox = NULL; //Como o prox do ultimo nao aponta para nada, passamos NULL
    //printf("%d %d\n", listaIdInvertido->ultimo->id_doc, listaIdInvertido->ultimo->qtd);

}

void Imprime_Indice_Invertido_Hash(Lista_ID_Invertido_Hash* listaIdInvertido){
    Celula_ID_Hash *Aux = (listaIdInvertido -> primeiro->prox);
    putchar('(');
    while (Aux != NULL) { 
        printf("<%d,%d> -> ", Aux->qtd, Aux->id_doc+1);
        Aux = Aux->prox;
    }
    printf("NULL)");
    
} 