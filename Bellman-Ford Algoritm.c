#include <stdio.h>
int parent[1005];

void print_path(int v) {
    if (v == source) {
        printf("%d", source);
        return;
    }
    print_path(parent[v]);
    printf("->%d", v);
}

int main() {
    if (scanf("%d %d", &V, &E) != 2) return 0;

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    scanf("%d", &source);

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    for (int i = 1; i <= V; i++) {
        if (i == source) continue;
        if (dist[i] == INF) {
            printf("%d INF None\n", i);
        } else {
            printf("%d %lld ", i, dist[i]);
            print_path(i);
            printf("\n");
        }
    }

    return 0;
}

