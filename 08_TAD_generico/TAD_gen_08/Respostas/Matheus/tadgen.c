#include "tadgen.h"

struct generic {
    void *dado;
    int tam;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = (tGeneric*)malloc(sizeof(tGeneric));
    gen->tam = numElem;
    gen->tipo = type;

    if (gen->tipo == FLOAT){
        gen->dado = malloc(numElem * sizeof(float));
    }
    if (gen->tipo == INT){
        gen->dado = malloc(numElem * sizeof(int));
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    if (gen){
        free(gen->dado);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("Digite o vetor:\n");
    if (gen->tipo == FLOAT){
        for(int i = 0; i < gen->tam; i++){
            scanf("%f", &((float *)gen->dado)[i]);
        }
    }
    if (gen->tipo == INT){
        for (int i = 0; i < gen->tam; i++){
            scanf("%d", &((int *)gen->dado)[i]);
        }
    }
}


/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    for (int i = 0; i < gen->tam; i++){
        if (gen->tipo == FLOAT){
            printf("%.2f ", ((float *)gen->dado)[i]);
        }
        if (gen->tipo == INT){
            printf("%d ", ((int *)gen->dado)[i]);
        }
    }
    printf("\n");
}