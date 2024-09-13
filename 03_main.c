#include <stdio.h>
#include <stdlib.h>


int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    int i, index;
    *returnColumnSizes = malloc(numRows * sizeof(int));
    for (i = 0; i < numRows; i++) (*returnColumnSizes)[i] = i + 1;
    int **res = malloc(numRows * sizeof(int *));
    for (i = 0; i < numRows; i++) {
        res[i] = malloc((*returnColumnSizes)[i] * sizeof(int));
        res[i][0] = 1;
        res[i][(*returnColumnSizes)[i] - 1] = 1;
        if (i > 1) for (index = 1; index < (*returnColumnSizes)[i] - 1; index++)
            res[i][index] = res[i - 1][index - 1] + res[i - 1][index];
    }
    *returnSize = numRows;
    return res;
}


void main() {
    // [7,1,5,3,6,4]
    int prices[6] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, 6));
}
