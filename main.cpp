#include <iostream>
#include "Lista.h"
#include "TesteLista.h"

/*
    Este é um programa que irá auxiliar a implementação da lista. As funções chamadas na função main estão implementadas no arquivo TesteLista.cpp. Cada função testar_<Nome_Função> testa uma determinada função sobre as listas. Uma função de teste irá inicializar uma lista, invocar uma determinada função sobre esta lista e irá testar se as pós-condições daquela função foram de fato garantidas. Ou seja, a função de teste irá testar se a função foi implementada corretamente. Quando uma determinada condição não é estabelecida, uma mensagem de erro é impressa na tela do console para ajudar você a diagnosticar o que não foi implementado corretamente.
 */
int main(int argc, const char * argv[]) {
    bool passou = true;
    
    passou = testar_Criar();
    
    if(passou)
        passou = testar_InserirInicio();

    if(passou)
        passou = testar_RemoverInicio();

    if(passou)
        passou = testar_InserirFim();
    
    if(passou)
        passou = testar_Buscar();
    
    if(passou)
        passou = testar_PegarValor();
    
    if(passou)
        passou = testar_Inserir();
    
    if(passou)
        passou = testar_Remover();
    
    if(passou)
        passou = testar_RemoverFim();
    
    if(passou)
        passou = testar_Ordenar();
    
    if(passou)
        passou = testar_Intercalar();
    
    if(passou)
        passou = testar_Destruir();
    
    return 0;
}
