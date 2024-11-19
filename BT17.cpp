#include <stdio.h>
#include <math.h>

// H�m kiem tra so nguy�n to
int isPrime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap so nguy�n duong n (n < 100): ");
    scanf("%d", &n);

    // Kiem tra dieu kien nhap v�o
    if (n <= 0 || n >= 100) {
        printf("So nhap v�o kh�ng hop li. Vui l�ng nhap n < 100.\n");
        return 0;
    }

    // a. In c�c gi� tri tu 1 den n
    printf("a. C�c gi� tri tu 1 den n: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // b. In c�c gi� tri chan tu 1 den n
    printf("b. C�c gi� tri chan tu 1 den n: ");
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // c. In c�c gi� tri chia het cho 5 tu 1 den n
    printf("c. C�c gi� tr? chia h?t cho 5 tu 1 den n: ");
    for (int i = 5; i <= n; i += 5) {
        printf("%d ", i);
    }
    printf("\n");

    // d. In c�c so nguy�n to nho hon n
    printf("d. C�c so nguy�n to nho hon n: ");
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // e. T�nh tong c�c gi� tri tu 1 den n
    int sum = n * (n + 1) / 2;  // D�ng c�ng thuc tung d�y so
    printf("e. Tong c�c gi� tri tu 1 den n: %d\n", sum);

    // f. T�nh tong c�c so le tu 1 den n
    sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
    }
    printf("f. Tong c�c so le tu 1 den n: %d\n", sum);

    // g. T�nh tong c�c so nguy�n to nho hon n
    sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    printf("g. Tong c�c so nguy�n to nho hon n: %d\n", sum);

    // h. T�nh trung b�nh cong c�c so le tu 1 den n
    int odd_count = 0;
    sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
        odd_count++;
    }
    printf("h. Trung b�nh cong c�c so le tu 1 den n: %.2f\n", (odd_count > 0 ? (float)sum / odd_count : 0));

    // i. T�nh trung b�nh cong c�c so nguy�n to nho hon n
    int prime_count = 0;
    sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
            prime_count++;
        }
    }
    printf("i. Trung b�nh cong c�c so nguy�n to nho hon n: %.2f\n", (prime_count > 0 ? (float)sum / prime_count : 0));

    return 0;
}
