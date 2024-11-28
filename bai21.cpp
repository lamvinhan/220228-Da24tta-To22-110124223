#include <stdio.h>
#include <stdbool.h>

#define ROW 100
#define COL 100

void nhapMang(int A[ROW][COL], int m, int n);
void xuatMang(int A[ROW][COL], int m, int n);
int tinhTongMang(int A[ROW][COL], int m, int n);
int tongDongK(int A[ROW][COL], int m, int n, int k);
int tongCotK(int A[ROW][COL], int m, int n, int k);
bool kiemTraSoAmDongK(int A[ROW][COL], int m, int n, int k);
bool kiemTraSoNguyenToCotK(int A[ROW][COL], int m, int n, int k);
void sapXepDongK(int A[ROW][COL], int m, int n, int k);

bool kiemTraGiaTriX(int A[ROW][COL], int m, int n, int x);
void timViTriX(int A[ROW][COL], int m, int n, int x);
int giaTriMaxDongK(int A[ROW][COL], int m, int n, int k);
int giaTriMinDongK(int A[ROW][COL], int m, int n, int k);
void inSoNguyenToDongK(int A[ROW][COL], int m, int n, int k);
void inSoNguyenToDongK(int A[ROW][COL], int m, int n, int k);


int main() {
    int A[ROW][COL];
    int m, n;
    printf("Nhap so dong m (0 <= m <= %d): ", ROW);
    scanf("%d", &m);
    printf("Nhap so cot n (0 <= n <= %d): ", COL);
    scanf("%d", &n);
    
    if (m > ROW || n > COL) {
        printf("So dong hoac so cot vuot qua gioi han cho phep!\n");
        return 0;
    }
    
    nhapMang(A, m, n);
    xuatMang(A, m, n);

    printf("Tong mang A: %d\n", tinhTongMang(A, m, n));
    
    int k;
    printf("Nhap chi so dong k (0 <= k < %d): ", m);
    scanf("%d", &k);
    printf("Tong dong %d: %d\n", k, tongDongK(A, m, n, k));

    int x;
    printf("Nhap gia tri x de kiem tra trong mang: ");
    scanf("%d", &x);
    if (kiemTraGiaTriX(A, m, n, x)) {
        printf("Mang co chua gia tri %d.\n", x);
        timViTriX(A, m, n, x);
    } else {
        printf("Mang khong chua gia tri %d.\n", x);
    }

    return 0;
}






// Hàm nhap mang A
void nhapMang(int A[ROW][COL], int m, int n) {
    printf("Nhap cac phan tu cua mang A (%d dong, %d cot):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

// Ham xuat mang A
void xuatMang(int A[ROW][COL], int m, int n) {
    printf("Mang A (%d dong, %d cot):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// Ham tinh tpng mang A
int tinhTongMang(int A[ROW][COL], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tong += A[i][j];
        }
    }
    return tong;
}

// Ham tinh tong cac gia tri tren DONG k
int tongDongK(int A[ROW][COL], int m, int n, int k) {
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += A[k][j];
    }
    return tong;
}

// Ham tinh tong cac gia tri tren COT k
int tongCotK(int A[ROW][COL], int m, int n, int k) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        tong += A[i][k];
    }
    return tong;
}

// Ham kiem tra DONG k có ton tai SO AM hay khong?
bool kiemTraSoAmDongK(int A[ROW][COL], int m, int n, int k) {
    for (int j = 0; j < n; j++) {
        if (A[k][j] < 0) {
            return true;
        }
    }
    return false;
}

// Ham kiem tra COT k có ton tai SO NGUYEN TO hay khong?
bool kiemTraSoNguyenToCotK(int A[ROW][COL], int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        if (A[i][k] > 1) {
            bool isPrime = true;
            for (int j = 2; j * j <= A[i][k]; j++) {
                if (A[i][k] % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                return true;
            }
        }
    }
    return false;
}

// Ham sep xap cac gia tri tren DONG k GIAM DAN
void sapXepDongK(int A[ROW][COL], int m, int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[k][i] < A[k][j]) {
                int temp = A[k][i];
                A[k][i] = A[k][j];
                A[k][j] = temp;
            }
        }
    }
}



// Ham kiem tra mang A co ton tai gia tri x hay khong
bool kiemTraGiaTriX(int A[ROW][COL], int m, int n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == x) {
                return true;
            }
        }
    }
    return false;
}

// Ham tim xac dinh vi tri cua gia tri x trong mang
void timViTriX(int A[ROW][COL], int m, int n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == x) {
                printf("Gia tri %d nam tai vi tri: [%d][%d]\n", x, i, j);
                return;
            }
        }
    }
    printf("Gia tri %d khong co trong mang.\n", x);
}

// Ham tim gia tri lon nhat tren DONG k
int giaTriMaxDongK(int A[ROW][COL], int m, int n, int k) {
    int max = A[k][0];
    for (int j = 1; j < n; j++) {
        if (A[k][j] > max) {
            max = A[k][j];
        }
    }
    return max;
}

// Ham tim gia tri nho nhat tren DONG k
int giaTriMinDongK(int A[ROW][COL], int m, int n, int k) {
    int min = A[k][0];
    for (int j = 1; j < n; j++) {
        if (A[k][j] < min) {
            min = A[k][j];
        }
    }
    return min;
}

// Ham in ra cac so nguyen to tren DONG k
void inSoNguyenToDongK(int A[ROW][COL], int m, int n, int k) {
    printf("Cac so nguyen to tren dong %d: ", k);
    for (int j = 0; j < n; j++) {
        if (A[k][j] > 1) {
            bool isPrime = true;
            for (int div = 2; div * div <= A[k][j]; div++) {
                if (A[k][j] % div == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                printf("%d ", A[k][j]);
            }
        }
    }
    printf("\n");
}


