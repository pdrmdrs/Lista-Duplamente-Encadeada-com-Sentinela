/*
 Este é o arquivo onde estão implementadas as funções de teste que irão auxiliar a implementação da sua lista. Não modifique as funções deste arquivo!
 */


#include "TesteLista.h"
#include "Lista.h"
#include <iostream>

using namespace std;

bool testar_Criar()
{
    cout << "INÍCIO: Teste LIS_Criar" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    if( lista == NULL )
    {
        cerr << "\tERRO - Teste LIS_Criar: retornou ponteiro nulo." << endl;
        resultado = false;
    }
    
    if( lista->tamanho != 0 )
    {
        cerr << "\tERRO - Teste LIS_Criar: retornou tamanho diferente de 0." << endl;
        resultado = false;
    }
    
    if( lista->cabeca == NULL )
    {
        cerr << "\tERRO - Teste LIS_Criar: lista->cabeca não foi alocado corretamente." << endl;
        resultado = false;
    }
    else if( lista->cabeca->proximo != lista->cauda )
    {
        cerr << "\tERRO - Teste LIS_Criar: lista->cabeca->proximo não aponta para lista->cauda." << endl;
        resultado = false;
    }
    else if( lista->cabeca->anterior != NULL )
    {
        cerr << "\tERRO - Teste LIS_Criar: lista->cabeca->anterior não aponta para NULL." << endl;
        resultado = false;
    }
    
    if( lista->cauda == NULL )
    {
        cerr << "\tERRO - Teste LIS_Criar: lista->cauda não foi alocado corretamente." << endl;
        resultado = false;
    }
    else if( lista->cabeca != lista->cauda->anterior )
    {
        cerr << "\tERRO - Teste LIS_Criar: lista->cauda->anterior não aponta para lista->cabeca." << endl;
        resultado = false;
    }
    else if( lista->cauda->proximo != NULL )
    {
        cerr << "\tERRO - Teste LIS_Criar: lista->cauda->proximo não aponta para NULL." << endl;
        resultado = false;
    }
        
    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_Criar" << endl << endl;
    
    return resultado;
}

bool testar_Destruir()
{
    cout << "INÍCIO: Teste LIS_Destruir" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        LIS_InserirInicio(lista, v[i]);
    }
    
    LIS_Destruir(lista);
    
    cout << "\n CHAME O PROFESSOR" << endl;
    
    cout << "FIM: Teste LIS_Destruir" << endl << endl;
    
    return resultado;
}

bool testar_InserirInicio()
{
    cout << "INÍCIO: Teste LIS_InserirInicio" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista->tamanho;
        
        int valorInserido = v[i];
        
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_InserirInicio: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        bool inseriu = LIS_InserirInicio(lista, valorInserido);
        if( !inseriu )
        {
            cerr << "\tERRO - Teste LIS_InserirInicio: não inseriu elemento na lista corretamente." << endl;
            resultado = false;
            break;
        }
        
        No primeiroElemento = lista->cabeca->proximo;
        if( primeiroElemento == NULL )
        {
            cerr << "\tERRO - Teste LIS_InserirInicio: ponteiro para o primeiro elemento retornou nulo." << endl;
            resultado = false;
            break;
        }
        
        int primeiroValor = primeiroElemento->valor;
        
        if( primeiroValor != valorInserido )
        {
            cerr << "\tERRO - Teste LIS_InserirInicio: valor inserido foi '" << valorInserido << "' e o valor encontrado no início foi " << primeiroValor << endl;
            resultado = false;
            break;
        }
        
        int tamanhoDepois = lista->tamanho;
        
        if( tamanhoDepois != tamanhoAntes + 1 )
        {
            cerr << "\tERRO - Teste LIS_InserirInicio: tamanho da lista não foi incrementado corretamente." << endl;
            resultado = false;
            break;
        }
    }
    
    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_InserirInicio" << endl << endl;
    
    return resultado;
}


bool testar_InserirFim()
{
    cout << "INÍCIO: Teste LIS_InserirFim" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int tamanhoAntes = lista->tamanho;
        
        int valorInserido = v[i];
        
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK)
        {
            cerr << "\tERRO - Teste LIS_InserirFim: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        bool inseriu = LIS_InserirFim(lista, valorInserido);
        if( !inseriu )
        {
            cerr << "\tERRO - Teste LIS_InserirFim: não inseriu elemento na lista corretamente." << endl;
            resultado = false;
            break;
        }
        
        No ultimoElemento = lista->cauda->anterior;
        if( ultimoElemento == NULL )
        {
            cerr << "\tERRO - Teste LIS_InserirFim: ponteiro para o último elemento não deveria retornar nulo." << endl;
            resultado = false;
            break;
        }
        
        int ultimoValor = ultimoElemento->valor;
        
        if( ultimoValor != valorInserido )
        {
            cerr << "\tERRO - Teste LIS_InserirFim: valor inserido foi '" << valorInserido << "' e o valor encontrado no fim foi " << ultimoValor << endl;
            resultado = false;
            break;
        }
        
        int tamanhoDepois = lista->tamanho;
        
        if( tamanhoDepois != tamanhoAntes + 1 )
        {
            cerr << "\tERRO - Teste LIS_InserirFim: tamanho da lista não foi incrementado corretamente." << endl;
            resultado = false;
            break;
        }
    }

    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_InserirFim" << endl << endl;
    return resultado;
}

bool testar_Inserir()
{
    cout << "INÍCIO: Teste LIS_Inserir" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    LIS_Inserir(lista, v[0], 1);
    
    for(int i = 1; i < 10; i++)
    {
        int tamanhoAntes = lista->tamanho;
        
        int valorInserido = v[i];
        
        int indice = i % 2 == 0 ? 2 : 1;
        
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_Inserir: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        bool inseriu = LIS_Inserir(lista, valorInserido, indice);
        if( !inseriu )
        {
            cerr << "\tERRO - Teste LIS_Inserir: não inseriu elemento na lista corretamente." << endl;
            resultado = false;
            break;
        }
        
        int valorRetornado = LIS_PegarValor(lista, indice);
        
        if( valorRetornado != valorInserido )
        {
            cerr << "\tERRO - Teste LIS_Inserir: valor inserido na posição " << indice << " foi '" << valorInserido << "' e o valor retornado desta posição foi " << valorRetornado << endl;
            resultado = false;
            break;
        }
        
        int tamanhoDepois = lista->tamanho;
        
        if( tamanhoDepois != tamanhoAntes + 1 )
        {
            cerr << "\tERRO - Teste LIS_Inserir: tamanho da lista não foi incrementado corretamente." << endl;
            resultado = false;
            break;
        }
    }

    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_Inserir" << endl << endl;
    
    return resultado;
}


bool testar_RemoverInicio()
{
    cout << "INÍCIO: Teste LIS_RemoverInicio" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int removeu = LIS_RemoverInicio(lista);
    if( removeu != -1 )
    {
        cerr << "\tERRO - Teste LIS_RemoverInicio: tentar remover elemento de uma lista vazia deve retornar -1." << endl;
        resultado = false;
    }
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int valorInserido = v[i];
        LIS_InserirInicio(lista, valorInserido);
    }
    
    for(int i = 0; i < 10; i++)
    {
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_RemoverInicio: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int tamanhoAntes = lista->tamanho;
        int valorRemovido = LIS_RemoverInicio(lista);
        int tamanhoDepois = lista->tamanho;
        
        if( tamanhoDepois != tamanhoAntes-1 )
        {
            cerr << "\tERRO - Teste LIS_RemoverInicio: remoção não decrementou tamanho corretamente. Tamanho antes: " << tamanhoAntes << ". Tamanho depois: " << tamanhoDepois << endl;
            resultado = false;
            break;
        }
        
        int valorEsperado = v[9-i];
        if( valorRemovido != valorEsperado )
        {
            cerr << "\tERRO - Teste LIS_RemoverInicio: remoção retornou valor " << valorRemovido << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }

    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_RemoverInicio" << endl << endl;
    
    return resultado;
}

bool testar_RemoverFim()
{
    cout << "INÍCIO: Teste LIS_RemoverFim" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int removeu = LIS_RemoverFim(lista);
    if( removeu != -1 )
    {
        cerr << "\tERRO - Teste LIS_RemoverFim: tentar remover elemento de uma lista vazia deve retornar -1." << endl;
        resultado = false;
    }
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int valorInserido = v[i];
        LIS_InserirFim(lista, valorInserido);
    }
    
    for(int i = 0; i < 10; i++)
    {
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_RemoverFim: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int tamanhoAntes = lista->tamanho;
        int valorRemovido = LIS_RemoverFim(lista);
        int tamanhoDepois = lista->tamanho;
        
        if( tamanhoDepois != tamanhoAntes-1 )
        {
            cerr << "\tERRO - Teste LIS_RemoverFim: remoção não decrementou tamanho corretamente. Tamanho antes: " << tamanhoAntes << ". Tamanho depois: " << tamanhoDepois << endl;
            resultado = false;
            break;
        }
        
        int valorEsperado = v[9-i];
        if( valorRemovido != valorEsperado )
        {
            cerr << "\tERRO - Teste LIS_RemoverFim: remoção retornou valor " << valorRemovido << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }

    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_RemoverFim" << endl << endl;
    
    return resultado;
}

bool testar_Remover()
{
    cout << "INÍCIO: Teste LIS_Remover" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int removeu = LIS_Remover(lista, 2);
    if( removeu != -1 )
    {
        cerr << "\tERRO - Teste LIS_Remover: tentar remover elemento de uma lista vazia deve retornar -1." << endl;
        resultado = false;
    }
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int valorInserido = v[i];
        LIS_InserirFim(lista, valorInserido);
        
        removeu = LIS_Remover(lista, i+2);
        if( removeu != -1 )
        {
            cerr << "\tERRO - Teste LIS_Remover: tentar remover elemento em índice maior que o tamanho da lista deve retornar -1." << endl;
            resultado = false;
            break;
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_Remover: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int tamanhoAntes = lista->tamanho;
        int valorRemovido = LIS_Remover(lista, 1);
        int tamanhoDepois = lista->tamanho;
        
        if( tamanhoDepois != tamanhoAntes-1 )
        {
            cerr << "\tERRO - Teste LIS_Remover: remoção não decrementou tamanho corretamente. Tamanho antes: " << tamanhoAntes << ". Tamanho depois: " << tamanhoDepois << endl;
            resultado = false;
            break;
        }
        
        int valorEsperado = v[i];
        if( valorRemovido != valorEsperado )
        {
            cerr << "\tERRO - Teste LIS_Remover: remoção retornou valor " << valorRemovido << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }

    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_Remover" << endl << endl;
   
    return resultado;
}

bool testar_Buscar()
{
    cout << "INÍCIO: Teste LIS_Buscar" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int valorInserido = v[i];
        LIS_InserirFim(lista, valorInserido);
    }
    
    for(int i = 0; i < 10; i++)
    {
        int valorBuscado = v[i];
        int indiceRetornado = LIS_Buscar(lista, valorBuscado);
        if( indiceRetornado != i+1 )
        {
            cerr << "\tERRO - Teste LIS_Buscar: buscou a chave " << v[i] << " e deveria ter retornado índice "<< i+1 << ", mas retornou índice igual a " << indiceRetornado << endl;
            resultado = false;
            break;
        }
        
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_Buscar: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
    }
    
    int inexistentes[] = {0, 50, 100, 200};
    
    for(int i = 0; i < 4; i++)
    {
        int indiceRetornado = LIS_Buscar(lista, inexistentes[i]);
        if( indiceRetornado != -1 )
        {
            cerr << "\tERRO - Teste LIS_Buscar: buscou chave inexistente e não retornou -1." << endl;
            resultado = false;
            break;
        }
        
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_Buscar: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
    }
    
    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_Buscar" << endl << endl;
    
    return resultado;
}

bool testar_PegarValor()
{
    cout << "INÍCIO: Teste LIS_PegarValor" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i < 10; i++)
    {
        int valorInserido = v[i];
        LIS_InserirInicio(lista, valorInserido);
    }
    
    for( int i = 1; i <= 10; i++ )
    {
        LIS_tpVerificacao verificada = LIS_Verificar(lista);
        if( verificada != LIS_OK )
        {
            cerr << "\tERRO - Teste LIS_PegarValor: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
            resultado = false;
            break;
        }
        
        int valorRetornado = LIS_PegarValor(lista, i);
        int valorEsperado  = v[10-i];
        
        if( valorRetornado != valorEsperado )
        {
            cerr << "\tERRO - Teste LIS_PegarValor: função retornou valor " << valorRetornado << ", mas valor esperado era " << valorEsperado << endl;
            resultado = false;
            break;
        }
    }

    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_PegarValor" << endl << endl;
    
    return resultado;
}

bool testar_Ordenar()
{
    cout << "INÍCIO: Teste LIS_Ordenar" << endl;
    
    bool resultado = true;
    
    Lista lista = LIS_Criar();
    
    int v[] = {0,22,11,33,55,44,66,99,77,88,111};
    
    for(int i = 0; i <= 10; i++)
    {
        int valorInserido = v[i];
        LIS_InserirFim(lista, valorInserido);
    }
    LIS_tpVerificacao verificada = LIS_Verificar(lista);
    if( verificada != LIS_OK )
    {
        cerr << "\tERRO - Teste LIS_Ordenar: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
        resultado = false;
    }
    
    LIS_Ordenar(lista);
    
    verificada = LIS_Verificar(lista);
    if( verificada != LIS_OK )
    {
        cerr << "\tERRO - Teste LIS_Ordenar: alguma invariante da lista foi quebrada. Código do erro: " << verificada << endl;
        resultado = false;
    }
    
    int i = 1;
    for( No no = lista->cabeca->proximo; no != lista->cauda->anterior; no = no->proximo )
    {
        if(no->valor > no->proximo->valor)
        {
            cerr << "\tERRO - Teste LIS_Ordenar: lista não está ordenada corretamente." << endl;
            resultado = false;
            break;
        }
        i++;
    }
    
    LIS_Destruir(lista);
    
    cout << "FIM: Teste LIS_Ordenar" << endl << endl;
    
    return resultado;
}

bool testar_Intercalar()
{
    cout << "INÍCIO: Teste LIS_Intercalar" << endl;
    
    bool resultado = true;
    
    Lista lista1 = LIS_Criar();
    
    int v1[] = {0,11,22,33,44,55,66,77,88,99,111};
    
    for(int i = 0; i <= 10; i++)
    {
        int valorInserido = v1[i];
        LIS_InserirFim(lista1, valorInserido);
    }
    
    Lista lista2 = LIS_Criar();
    
    int v2[] = {15,25,35,45,56,67,78};
    
    for(int i = 0; i <= 6; i++)
    {
        int valorInserido = v2[i];
        LIS_InserirFim(lista2, valorInserido);
    }
    
    Lista listaResultado = LIS_Intercalar(lista1, lista2);
    
    int tamanhoEsperado = lista1->tamanho + lista2->tamanho;
    int tamanhoRetornado = listaResultado->tamanho;
    
    if( tamanhoEsperado != tamanhoRetornado )
    {
        cerr << "\tERRO - Teste LIS_Intercalar: Tamanho da lista retornada deveria ser igual à soma dos tamanhos das listas passadas como parâmetro." << endl;
        resultado = false;
    }
    
    for(No no = listaResultado->cabeca->proximo; no != listaResultado->cauda->anterior; no = no->proximo)
    {
        if(no->valor > no->proximo->valor)
        {
            cerr << "\tERRO - Teste LIS_Intercalar: Lista retornada não está ordenada." << endl;
            resultado = false;
        }
    }
    
    // Todo elemento de lista1 deve estar em listaResultado
    for(No no = lista1->cabeca->proximo; no != lista1->cauda; no = no->proximo)
    {
        int resultado = LIS_Buscar(listaResultado, no->valor);
        if( resultado == -1 )
        {
            cerr << "\tERRO - Teste LIS_Intercalar: chave " << no->valor << " está na lista1 mas não está na lista resultado." << endl;
            resultado = false;
        }
    }
    
    // Todo elemento de lista2 deve estar em listaResultado
    for(No no = lista2->cabeca->proximo; no != lista2->cauda; no = no->proximo)
    {
        int resultado = LIS_Buscar(listaResultado, no->valor);
        if( resultado == -1 )
        {
            cerr << "\tERRO - Teste LIS_Intercalar: chave " << no->valor << " está na lista2 mas não está na lista resultado." << endl;
            resultado = false;
        }
    }
    
    // Todo elemento de listaResultado deve estar em lista1 ou lista2
    for(No no = listaResultado->cabeca->proximo; no != listaResultado->cauda; no = no->proximo)
    {
        int resultado1 = LIS_Buscar(lista1, no->valor);
        int resultado2 = LIS_Buscar(lista2, no->valor);
        if( resultado1 == -1 && resultado2 == -1) // não encontrou em nenhuma das listas
        {
            cerr << "\tERRO - Teste LIS_Intercalar: chave " << no->valor << " está na lista resultado mas não está na lista1 nem na lista2." << endl;
            resultado = false;
        }
    }
    
    cout << "FIM: Teste LIS_Intercalar" << endl << endl;
    
    return resultado;
}
