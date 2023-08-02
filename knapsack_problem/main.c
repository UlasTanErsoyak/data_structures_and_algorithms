#include <stdlib.h>
#include <stdio.h>

float max_profit(int weights[], int len, int profits[], int knapsack_capacity);

int main(void) {
    int profits[] = {10, 6, 8, 11, 12, 4};
    int weights[] = {1, 6, 2, 12, 4, 5};
    int capacity = 20;
    int len = sizeof(profits) / sizeof(profits[0]);
    float result = max_profit(weights, len, profits, capacity);
    printf("%f", result);
    return 0;
}

float max_profit(int weights[], int len, int profits[], int knapsack_capacity) {
    float value[len];
    for (int i = 0; i < len; i++) {
        value[i] = (float)profits[i] / weights[i];
    }

    float pick[len];
    for (int i = 0; i < len; i++) {
        pick[i] = 0;
    }

    float current = (float)knapsack_capacity;
    float max_profit = 0;

    while (current >= 0) {
        float max_value = 0;
        int max_value_idx = -1;

        for (int i = 0; i < len; i++) {
            max_value_idx = (value[i] > max_value && pick[i] == 0) ? i : max_value_idx;
            max_value = (value[i] > max_value && pick[i] == 0) ? value[i] : max_value;
        }
            
        if (max_value_idx == -1 || current == 0) break;
        
        float fraction_taken = (current < weights[max_value_idx]) ? (current / weights[max_value_idx]) : 1;
        pick[max_value_idx] = fraction_taken;
        current -= weights[max_value_idx] * fraction_taken;
        max_profit += profits[max_value_idx] * fraction_taken;
    }

    return max_profit;
}
