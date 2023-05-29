
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned short tempo;
    unsigned short qtsPontos;
    double razaoPontoTempo;
} brinquedo;

int compara(const void* a, const void* b) {
    brinquedo* brinquedoA = (brinquedo*)a;
    brinquedo* brinquedoB = (brinquedo*)b;

    if (brinquedoA->razaoPontoTempo > brinquedoB->razaoPontoTempo) {
        return -1;
    } else if (brinquedoA->razaoPontoTempo < brinquedoB->razaoPontoTempo) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    unsigned short i;
    unsigned short instancia;
    unsigned short qtsAtracoes;
    unsigned short limiteTempo, aux;
    unsigned short pontoTotal, tempoTotal;

    instancia = 0;
    while (1) {
        scanf("%hu %hu", &qtsAtracoes, &limiteTempo);

        if (qtsAtracoes == 0)
            break;

        brinquedo* brinquedos = malloc(qtsAtracoes * sizeof(brinquedo));

        for (i = 0; i < qtsAtracoes; ++i) {
            scanf("%hu %hu", &brinquedos[i].tempo, &brinquedos[i].qtsPontos);
            brinquedos[i].razaoPontoTempo = (brinquedos[i].qtsPontos / (double)brinquedos[i].tempo);
        }

        qsort(brinquedos, qtsAtracoes, sizeof(brinquedo), compara);

        i = 0;
        pontoTotal = tempoTotal = 0;

        while (i < qtsAtracoes) {
            aux = tempoTotal + brinquedos[i].tempo;

            if (aux <= limiteTempo) {
                pontoTotal += brinquedos[i].qtsPontos;
                tempoTotal = aux;
            } else {
                i++;
            }
        }

        printf("Instancia %hu\n%hu\n\n", ++instancia, pontoTotal);

        free(brinquedos);
    }

    return 0;
}