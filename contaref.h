#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10 // limite máximo de alocação

int qntd_alocada = 0; // variavel global para contabilizar a quantidade de alocações feitas

typedef struct
{
    void *end;
    int referencias;

} registro;

registro Memoria[MAX]; // cria um vetor para registrar os espaços de memória alocados

void *malloc2(int tam)
{
    if (qntd_alocada >= MAX) // verifica se é possivel fazer a alocação
    {
        puts("Não é possivel realizar a alocação!\n");
        return NULL;
    }
    void *temp = malloc(tam);
    assert(temp != NULL); // verifica se foi alocado corretamente

    Memoria[qntd_alocada].end = temp; // preenche as informações da alocação daquele espaço
    Memoria[qntd_alocada].referencias = 1;

    qntd_alocada++;
    return temp;
}

void *atrib2(void *end1, void *end2) // respectivamente, destino e origem
{
    for (int i = 0; i < MAX; i++)
    { // percorre o vetor "memoria" até encontrar os dados de end1
        if (Memoria[i].end == end1)
        {
            Memoria[i].referencias--; // decrementa a quantidade de referências
            if (Memoria[i].referencias == 0)
            {
                free(Memoria[i].end);  // se não houver referências, libera o espaço
                Memoria[i].end = NULL; // atualiza o conteúdo do ponteiro
                qntd_alocada--;        // decrementa a quantidade de alocação total
            }
            break;
        }
    }

    for (int i = 0; i < MAX; i++)
    { // atualiza os dados do espaço reservado para end1
        if (Memoria[i].end == end2 && end2 != NULL)
        {
            Memoria[i].referencias++;
            break;
        }
    }
    return end2;
}

// função para verificar o estado do vetor de registro "Memoria", conforme foi solicitado no slide
void dump()
{
    printf("Quantidade total alocada: %d\n\n", qntd_alocada);
    for (int i = 0; i < MAX; i++)
    {
        printf("Endereco: %p, Quantidade de ref. para essa area: %d\n", Memoria[i].end, Memoria[i].referencias);
    }
    puts("==========================================================\n");
}