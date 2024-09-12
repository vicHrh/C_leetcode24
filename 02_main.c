#include <stdio.h>
#include <stdlib.h>

//
// int maxProfit(int *prices, int pricesSize) {
//     int maxProfit = 0;
//     for (int i = 0; i < pricesSize; ++i) {
//         for (int j = i + 1; j < pricesSize; ++j) {
//             if (prices[j] - prices[i] > maxProfit) {
//                 maxProfit = prices[j] - prices[i];
//             }
//         }
//     }
//     return maxProfit;
// }


// int maxProfit(int *prices, int pricesSize) {
//     int maxProfit = 0;
//     int tempProfit = 0;
//     int purchase = prices[0];
//     for (int i = 1; i < pricesSize; ++i) {
//         if(prices[i]-buy>ans)
//             ans=prices[i]-buy;
//         if(prices[i]<buy)
//             buy=prices[i];
//
//         // if (prices[i] > purchase) {
//         //     tempProfit = prices[i] - purchase;
//         //     purchase = prices[i];
//         // }else {
//         //     if (maxProfit < tempProfit) {
//         //         maxProfit = tempProfit;
//         //     }
//         //     purchase = prices[i];
//         //     tempProfit = 0;
//         // }
//     }
//     return maxProfit;
// }

int maxProfit(int *prices, int pricesSize) {
    int maxProfit = 0, minPrice = prices[0];
    for (int i = 0; i < pricesSize; i++) {
        if (minPrice > prices[i]) {
            minPrice = prices[i];
        }
        if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}


void main() {
    // [7,1,5,3,6,4]
    int prices[6] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, 6));
}
