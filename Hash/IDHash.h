//Amanda(5366), Caio(5784), Leticia(5781), Melissa(5384)

#ifndef IDHASH_H
#define IDHASH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Celula_ID_Hash {
    int id_doc; //Numero do arquivo em que a palavra esta presente
    int qtd; 
    struct Celula_ID_Hash* prox; 
} Celula_ID_Hash;

typedef struct {
    Celula_ID_Hash* primeiro;
    Celula_ID_Hash* ultimo;
} Lista_ID_Invertido_Hash;

void Inicializa_Lista_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido);
int Retorna_Tamanho_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido);
int Verifica_Vazio_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido);
void Adiciona_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido, int qtd, int id_doc);
void Imprime_Indice_Invertido_Hash(Lista_ID_Invertido_Hash* listaIdInvertido);
int Pesquisa_ID_Hash(Lista_ID_Invertido_Hash* listaIdInvertido, int id_doc);
void free_ID_Invertido_Hash(Lista_ID_Invertido_Hash *lista_ids);


#endif // IDHASH_H