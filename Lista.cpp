/*
 *
 *   Este é o único arquivo que você irá modificar durante toda esta atividade.
 *
 */


#include <stdlib.h>
#include <iostream>
#include "Lista.h"

#define VALOR_QUALQUER -10000

No CriarNo(int);
bool DestruirNo(No);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
Lista LIS_Criar()
{
    Lista lista = (Lista)malloc(sizeof(tpLista));
    if( lista == NULL )
    {
        return NULL;
    }
    
    lista->cabeca = CriarNo(VALOR_QUALQUER);//CRIAR NO PARA A CABEÇA DA LISTA
    if( lista->cabeca == NULL )
    {
        return NULL;
    }

    lista->cauda = CriarNo(VALOR_QUALQUER);//CRIAR NO PARA A CAUDA DA LISTA
    if( lista->cauda == NULL )
    {
        return NULL;
    }
    
    //COMO É UMA LISTA DUPLAMENTE ENCADEADA COM SENTINELA, TEMOS:
    lista->cabeca->proximo  = lista->cauda;
    lista->cabeca->anterior = NULL;

    lista->cauda->anterior = lista->cabeca;
    lista->cauda->proximo = NULL;

    lista->tamanho = 0;

    return lista;
}

/*
    Função que busca a posição de uma determinada chave numa lista.
    @param lista - lista em que será feita a busca
    @param chave - chave a ser buscada na lista
    @return índice que indica a posição do elemento cujo valor é igual a chave. Retorna -1 caso a chave não seja encontrada na lista.
 */
int LIS_Buscar(Lista lista, int chave)
{
    if( lista->tamanho > 0)
    {
        int indice = 1;

        No no = lista->cabeca->proximo;

        while(no != lista->cauda)
        {
            if(no->valor == chave)
            {
                return indice;
            }
            else
            {
                no = no->proximo;
                indice++;
            }
        }
        return -1;
    }
    else
    {
        return -1;    
    }
}

/*
 Função que retorna o valor de um elemento na lista que está na posição indicada pelo parâmetro i.
 @param lista - lista em que será feita a busca
 @param i - indica a posição do elemento cujo valor se deseja retornar
 @return valor do elemento na i-esima posição da lista. Retorna -1 se não existir elemento na i-esima posição
 */
int LIS_PegarValor(Lista lista, int i)
{
    if( lista->tamanho > 0)
    {
        int indice = 1;

        No no = lista->cabeca->proximo;

        while(no != lista->cauda)
        {
            if(indice == i)
            {
                return no->valor;
            }
            else
            {
                no = no->proximo;
                indice++;
            }
        }
        return -1;
    }
    else
    {
        return -1;    
    }
}

/*
 Função que insere um valor no início da lista. Após a execução desta função, o elemento inserido será o primeiro elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirInicio(Lista lista, int v)
{
    No no = CriarNo(v);
    if( no == NULL )
    {
        return false;
    }
    
    No primeiro = lista->cabeca->proximo;
    
    primeiro->anterior = no;

    no->proximo = primeiro;
    no->anterior = lista->cabeca;

    lista->cabeca->proximo = no;
    lista->tamanho += 1;
    
    return true;
}

/*
 Função que insere um valor no fim da lista. Após a execução desta função, o elemento inserido será o último elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirFim(Lista lista, int v)
{

    No no = CriarNo(v);
    if( no == NULL )
    {
        return false;
    }
    
    No ultimo = lista->cauda->anterior;
    
    ultimo->proximo = no;

    no->proximo = lista->cauda;
    no->anterior = ultimo;

    lista->cauda->anterior = no;
    lista->tamanho += 1;

    return true;
}

/*
 Função que insere um valor numa determinada posição da lista. Após a execução desta função, o elemento inserido será o i-esimo elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @param i - indica a posição que o novo elemento ocupará após a inserção
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_Inserir(Lista lista, int v, int i)
{
   
    if(i > lista->tamanho)//tentando adicionar numa posicao maior que o tamanho do vetor
    {
        return false;
    }
    else if(i == 1)//adicionar no inicio
    {
        LIS_InserirInicio(lista, v);
    }
    else if(i == lista->tamanho)//adicionar no final
    {
        LIS_InserirFim(lista, v);
    }
    else//adicionar em uma outra posicao
    {
        int indice = 1;

        No no_iterador = lista->cabeca->proximo;

        while(no_iterador != lista->cauda)
        {
            if(indice == i)
            {

                No no = CriarNo(v);
                if( no == NULL )
                {
                    return false;
                }

                no->anterior = no_iterador->anterior;
                no->proximo = no_iterador;

                no->anterior->proximo = no;
                no_iterador->anterior = no;

                lista->tamanho += 1;

                return true;
            }
            else
            {
                no_iterador = no_iterador->proximo;
                indice += 1;
            }
        }
    }
    
    return false;
} 

/*
 Função que remove um valor no início da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia.
 */
int LIS_RemoverInicio(Lista lista)
{    
    if( lista->tamanho > 0 )
    {
        No primeiro = lista->cabeca->proximo;

        lista->cabeca->proximo = primeiro->proximo;

        primeiro->proximo->anterior = lista->cabeca;

        int valor = primeiro->valor;

        lista->tamanho -= 1;

        DestruirNo(primeiro);

        return valor;
    }
    else
    {
        return -1;
    }
}

/*
 Função que remove um valor no fim da lista.
 @param lista - lista em que será feita a remoção
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia.
 */
int LIS_RemoverFim(Lista lista)
{
    if( lista->tamanho > 0 )
    {
        No ultimo = lista->cauda->anterior;
        
        lista->cauda->anterior = ultimo->anterior;
        
        ultimo->anterior->proximo = lista->cauda;
        
        int valor = ultimo->valor;
        
        lista->tamanho -= 1;
        
        DestruirNo(ultimo);
        
        return valor;
    }
    else
    {
        return -1;
    }
}

/*
 Função que remove um valor numa determinada posição da lista.
 @param lista - lista em que será feita a remoção
 @param indice - indica a posição na lista do elemento que se deseja remover
 @return retorna o valor do elemento removido. Retorna -1 caso a lista esteja vazia, ou caso o índice não aponte para uma posição válida da lista.
 */
int LIS_Remover(Lista lista, int indice)
{
       return -1;
}

/*
    Função que ordena a lista. (Obs.: Implemente os algoritmos: selection sort, insertion sort e bubble sort.)
 */
void LIS_Ordenar(Lista lista)
{
}

/*
    Função que intercala duas listas ordenadas, retornando uma nova lista contendo a intercalação das duas listas de entrada.
 */
Lista LIS_Intercalar(Lista lista1, Lista lista2)
{
    return NULL;
}

/*
    Função que verifica se uma determinda instância da estrutura lista obedece a todas suas invariantes.
 */
LIS_tpVerificacao LIS_Verificar(Lista lista)
{
    if( lista->cabeca == NULL )
    {
        return LIS_CabecaNula;
    }
    
    if( lista->cauda == NULL )
    {
        return LIS_CaudaNula;
    }
    
    if( lista->cabeca->anterior != NULL )
    {
        return LIS_CabecaAnterior;
    }
    
    
    if( lista->cauda->proximo != NULL )
    {
        return LIS_CaudaProximo;
    }
    
    if(lista->tamanho == 0)
    {
        if( lista->cabeca->proximo != lista->cauda )
        {
            return LIS_CabecaCauda;
        }
        
        if( lista->cabeca != lista->cauda->anterior )
        {
            return LIS_CabecaCauda;
        }
    }
    else
    {
        for(No i = lista->cabeca->proximo; i != lista->cauda; i=i->proximo)
        {
            if( i->proximo->anterior != i )
            {
                return LIS_EncadeamentoErrado;
            }
            if( i->anterior->proximo != i )
            {
                return LIS_EncadeamentoErrado;
            }
        }
    }
    
    return LIS_OK;
}

/*
    Função que imprime todos os elementos de uma lista.
 */
void LIS_Imprimir(Lista lista)
{
    std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << "[" << i->valor << "]->";
    }
    std::cout << std::endl;
}

/**
 Função que libera a memória de uma instância da estrutura Lista, liberando a memória de todos os nós encadeados na lista, incluindo os nós cabeça e cauda.
 */
void LIS_Destruir(Lista lista)
{
    No atual = lista->cabeca;
    while( atual != NULL )
    {
        No destruido = atual;
        atual = atual->proximo;
        DestruirNo(destruido);
    }
    free(lista);
}

/*
 Função que aloca a memória para um nó e inicializa os atributos do nó.
 */
No CriarNo(int v)
{
    No no = (No) malloc( sizeof( tpNo ) );
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;
    
    no->valor = v;
    
    return no;
}

/*
 Função que libera a memória alocada para um nó.
 */
bool DestruirNo(No no)
{
    free(no);
    return true;
}


