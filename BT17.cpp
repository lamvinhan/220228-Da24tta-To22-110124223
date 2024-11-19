#include <stdio.h>
#include <math.h>

// Hàm kiem tra so nguyên to
int isPrime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap so nguyên duong n (n < 100): ");
    scanf("%d", &n);

    // Kiem tra dieu kien nhap vào
    if (n <= 0 || n >= 100) {
        printf("So nhap vào không hop li. Vui lòng nhap n < 100.\n");
        return 0;
    }

    // a. In các giá tri tu 1 den n
    printf("a. Các giá tri tu 1 den n: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // b. In các giá tri chan tu 1 den n
    printf("b. Các giá tri chan tu 1 den n: ");
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // c. In các giá tri chia het cho 5 tu 1 den n
    printf("c. Các giá tr? chia h?t cho 5 tu 1 den n: ");
    for (int i = 5; i <= n; i += 5) {
        printf("%d ", i);
    }
    printf("\n");

    // d. In các so nguyên to nho hon n
    printf("d. Các so nguyên to nho hon n: ");
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // e. Tính tong các giá tri tu 1 den n
    int sum = n * (n + 1) / 2;  // Dùng công thuc tung dãy so
    printf("e. Tong các giá tri tu 1 den n: %d\n", sum);

    // f. Tính tong các so le tu 1 den n
    sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
    }
    printf("f. Tong các so le tu 1 den n: %d\n", sum);

    // g. Tính tong các so nguyên to nho hon n
    sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    printf("g. Tong các so nguyên to nho hon n: %d\n", sum);

    // h. Tính trung bình cong các so le tu 1 den n
    int odd_count = 0;
    sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
        odd_count++;
    }
    printf("h. Trung bình cong các so le tu 1 den n: %.2f\n", (odd_count > 0 ? (float)sum / odd_count : 0));

    // i. Tính trung bình cong các so nguyên to nho hon n
    int prime_count = 0;
    sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
            prime_count++;
        }
    }
    printf("i. Trung bình cong các so nguyên to nho hon n: %.2f\n", (prime_count > 0 ? (float)sum / prime_count : 0));

    return 0;
}
