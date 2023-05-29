#include <stdio.h>
#include <limits.h>

int minBlocks(int blocks[], int N, int M) {
    int dp[M + 1];
    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (blocks[j] <= i && dp[i - blocks[j]] + 1 < dp[i]) {
                dp[i] = dp[i - blocks[j]] + 1;
            }
        }
    }

    return dp[M];
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        int blocks[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &blocks[i]);
        }

        int min = minBlocks(blocks, N, M);
        printf("%d\n", min);
    }

    return 0;
}