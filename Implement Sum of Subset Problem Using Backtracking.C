#include <stdio.h>
        subsets[subset_count] = (int *)malloc(current_size * sizeof(int));
        for (int i = 0; i < current_size; i++) {
            subsets[subset_count][i] = current_subset[i];
        }
        subset_sizes[subset_count] = current_size;
        subset_count++;
        return;
    }
    
    if (index == n || current_sum > target_sum) {
        return;
    }
    
    current_subset[current_size++] = elements[index];
    backtrack(index + 1, current_sum + elements[index]);
    current_size--;
    
    backtrack(index + 1, current_sum);
}

int main() {
    if (scanf("%d", &n) != 1) return 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }
    scanf("%d", &target_sum);
    
    subsets = (int **)malloc((1 << n) * sizeof(int *));
    subset_sizes = (int *)malloc((1 << n) * sizeof(int));
    
    backtrack(0, 0);
    
    if (subset_count == 0) {
        printf("-1\n");
    } else {
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < subset_sizes[i]; j++) {
                printf("%d ", subsets[i][j]);
            }
            printf("\n");
            free(subsets[i]);
        }
    }
    
    free(subsets);
    free(subset_sizes);
    return 0;
}

