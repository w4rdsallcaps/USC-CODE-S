#include<stdio.h>

long fact(long n) {
    long i, factorial = 1;
    for (i = n; i > 1; i--)
        factorial *= i;
    return factorial;
}

long nCr(long n, long r) {
    long nume = 1, i;
    for (i = n; i > r; i--)
        nume *= i;
    return nume / fact(n - r);
}
void genPascalsTriangle(long n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++)
            printf("%3s", " ");
        for (int j = 0; j < (i + 1); j++)
            printf("%3ld%3s", nCr(i, j), " ");
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the height of the triangle: ");
    scanf("%d", &n);
    genPascalsTriangle(n);

    return 0;
}
