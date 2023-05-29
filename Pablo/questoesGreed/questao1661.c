#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll calculateWork(int *demands, int n) {
    ll totalWork = 0;
    ll accumulatedWine = 0;

    for (int i = 0; i < n; i++) {
        accumulatedWine += demands[i];
        totalWork += labs(accumulatedWine); // Calcula o valor absoluto do trabalho necessário

        // Atualiza as quantidades de vinho nas casas envolvidas na transação
        demands[i] = accumulatedWine;
    }

    return totalWork;
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        int *demands = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &demands[i]);
        }

        ll minWork = calculateWork(demands, n);
        printf("%lld\n", minWork);

        free(demands);
    }

    return 0;
}