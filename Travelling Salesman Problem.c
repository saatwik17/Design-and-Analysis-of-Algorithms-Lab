//NAME:SAATWIK SINHA;PRN:25070521077
    int num_states = 1 << n;
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < num_states; mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == INF) continue;

            for (int v = 0; v < n; v++) {
                if (!(mask & (1 << v)) && matrix[u][v] != -1) {
                    dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + matrix[u][v]);
                }
            }
        }
    }

    int ans = INF;
    for (int v = 0; v < n; v++) {
        if (matrix[v][0] != -1 && dp[num_states - 1][v] != INF) {
            ans = min(ans, dp[num_states - 1][v] + matrix[v][0]);
        }
    }

    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}

