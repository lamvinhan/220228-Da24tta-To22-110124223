#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tuSo;
    int mauSo;
} PHAN_SO;

// Ham tinh UCLN cua 2 so
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Ham rut gon phan so
void rutGon(PHAN_SO* ps) {
    int ucln = UCLN(ps->tuSo, ps->mauSo);
    ps->tuSo /= ucln;
    ps->mauSo /= ucln;
}

// Ham ghi danh sach phan so vao tap tin
void ghiFile(PHAN_SO arr[], int n, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Loi mo file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %d\n", arr[i].tuSo, arr[i].mauSo);
    }
    fclose(file);
}

// Ham doc danh sach phan so tu tap tin
void docFile(PHAN_SO arr[], int* n, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Loi mo file!\n");
        return;
    }
    *n = 0;
    while (fscanf(file, "%d %d", &arr[*n].tuSo, &arr[*n].mauSo) != EOF) {
        (*n)++;
    }
    fclose(file);
}

// Ham hien thi danh sach phan so
void hienThi(PHAN_SO arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d\n", arr[i].tuSo, arr[i].mauSo);
    }
}

// Ham tim phan so co gia tri nho nhat
PHAN_SO timMin(PHAN_SO arr[], int n) {
    PHAN_SO min = arr[0];
    for (int i = 1; i < n; i++) {
        if ((float)arr[i].tuSo / arr[i].mauSo < (float)min.tuSo / min.mauSo) {
            min = arr[i];
        }
    }
    return min;
}

// Ham dem so phan so co gia tri nho nhat
int demMin(PHAN_SO arr[], int n, PHAN_SO min) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].tuSo == min.tuSo && arr[i].mauSo == min.mauSo) {
            count++;
        }
    }
    return count;
}

// Ham sap xep danh sach phan so theo thu tu giam dan
void sapXep(PHAN_SO arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)arr[i].tuSo / arr[i].mauSo < (float)arr[j].tuSo / arr[j].mauSo) {
                PHAN_SO temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    PHAN_SO arr[100];
    int n;
    const char* filename = "phanso.txt";
    
    // Nhap vao n phan so
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d (tu so mau so): ", i + 1);
        scanf("%d %d", &arr[i].tuSo, &arr[i].mauSo);
    }

    // Ghi danh sach phan so vao tep tin
    ghiFile(arr, n, filename);
    
    // Ðoc danh sach phan so tu tep tin
    docFile(arr, &n, filename);
    
    // Hien thi danh sach phan so sau khi rut gon
    printf("Danh sach phan so sau khi rut gon:\n");
    for (int i = 0; i < n; i++) {
        rutGon(&arr[i]);
        printf("%d/%d\n", arr[i].tuSo, arr[i].mauSo);
    }

    // Tim phan so co gia tri nho nhat
    PHAN_SO min = timMin(arr, n);
    printf("Phan so co gia tri nho nhat: %d/%d\n", min.tuSo, min.mauSo);

    // Ðem so phan so co gia tri nho nhat
    int countMin = demMin(arr, n, min);
    printf("So phan so co gia tri nho nhat: %d\n", countMin);

    // Sap xep danh sach phan so theo thu tu giam dan
    sapXep(arr, n);
    printf("Danh sach phan so sau khi sap xep theo thu tu giam dan:\n");
    hienThi(arr, n);

    return 0;
}
