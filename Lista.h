//
//  Lista.h
//  Lista
//
//  Created by Eiji Adachi Medeiros Barbosa on 31/03/16.
//  Copyright (c) 2016 Eiji Adachi Medeiros Barbosa. All rights reserved.
//

// Estas é a estrutura para um nó de uma lista duplamente encadeada. Não a modifique!
struct tpNo
{
    int valor;
    struct tpNo* proximo;
    struct tpNo* anterior;
};

typedef tpNo * No;

// Estas é a estrutura para uma lista com sentinelas. Não a modifique!
struct tpLista
{
    No cabeca;
    No cauda;
    int tamanho;
};

typedef tpLista * Lista;

// Enumeração para identificar os tipos de erro que podem ocorrer na verificação da lista
typedef enum {
    LIS_OK ,
    LIS_CabecaNula,
    LIS_CaudaNula,
    LIS_CondRetNaoAchou,
    LIS_CabecaAnterior,
    LIS_CaudaProximo,
    LIS_CabecaCauda,
    LIS_EncadeamentoErrado
} LIS_tpVerificacao ; 

//Estas duas funções já estão implementadas. Não precisa modificá-las. Use a função LIS_Imprimir para ver o estado da lista e assim ajudar durante sua implementação.
LIS_tpVerificacao LIS_Verificar(Lista);
void LIS_Imprimir(Lista);

// Estas duas funções estão parcialmente implementadas e precisam ser finalizadas
Lista LIS_Criar();
bool LIS_InserirInicio(Lista, int);

// As funções abaixo ainda não foram implementadas. Você deve implementá-las na aula de hoje.
void LIS_Destruir(Lista);

bool LIS_InserirFim(Lista, int);
bool LIS_Inserir(Lista, int, int);

int LIS_RemoverInicio(Lista);
int LIS_RemoverFim(Lista);
int LIS_Remover(Lista, int);

int LIS_Buscar(Lista, int);
int LIS_PegarValor(Lista, int);

void LIS_Ordenar(Lista);
Lista LIS_Intercalar(Lista, Lista);
