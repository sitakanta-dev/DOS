#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int length;
    printf("Enter the length: ");
    scanf("%d", &length);
    int fibArray[length];
    if (vfork() == 0) {
        fibArray[0] = 0;
        fibArray[1] = 1;
        for (int i = 2; i < length; i++)
            fibArray[i] = fibArray[i-1] + fibArray[i-2];
        exit(0);
    }
    wait(NULL);
    printf("Fibonacci series: ");
    for (int i = 0; i < length; i++)
        printf("%d ", fibArray[i]);
    printf("\nPrime Fibonacci numbers:\n");
    for (int i = 0; i < length; i++) {
        int isPrime = 1;
        if (fibArray[i] <= 1)
            isPrime = 0;
        for (int j = 2; j * j <= fibArray[i]; j++)
            if (fibArray[i] % j == 0) {
                isPrime = 0;
                break;
            }
        if (isPrime)
            printf("%d at index %d\n", fibArray[i], i);
    }
    return 0;
}
