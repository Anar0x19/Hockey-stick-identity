#include <stdio.h>

int comb(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k == 1 || k == n - 1) return n;
    return comb(n - 1, k - 1) + comb(n - 1, k);
}

int hockey_stick_identity(int r, int n) {
    int sum_coeffs = 0;
    for (int k = r; k < n; k++) {
        sum_coeffs += comb(k, r);
    }
    printf("Sum of binomial coefficients: %d\n", sum_coeffs);
    printf("value of the binomial coefficient: %d\n", comb(n, r + 1));
    return sum_coeffs == comb(n, r + 1);
}

int main() {
    int r, n;

    printf("Input r: ");
    scanf("%d", &r);
    printf("Input n: ");
    scanf("%d", &n);

    if (hockey_stick_identity(r, n)) {
        printf("The identity is satisfied.\n");
    } else {
        printf("The identity is not satisfied.\n");
    }

    return 0;
}
