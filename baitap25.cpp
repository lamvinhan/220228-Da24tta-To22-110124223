#include <stdio.h>
#include <string.h>

#define MAX_MON_HOC 10
#define MAX_SV 100
#define MAX_LEN 100

// Cau truc NGAY_THANG
typedef struct {
    int ngay;
    int thang;
    int nam;
} NGAY_THANG;

// Cau truc MON_HOC
typedef struct {
    char ma_mon[MAX_LEN];
    float diem;
} MON_HOC;

// Cau truc SINH_VIEN
typedef struct {
    char mssv[MAX_LEN];
    char hoten[MAX_LEN];
    NGAY_THANG ngaysinh;
    char gioi_tinh[MAX_LEN];
    char dia_chi[MAX_LEN];
    int somon;
    MON_HOC mon_hoc[MAX_MON_HOC];
} SINH_VIEN;


void nhapSinhVien(SINH_VIEN *sv);
void xuatSinhVien(SINH_VIEN sv);
void nhapDanhSachSinhVien(SINH_VIEN *ds, int n);
void xuatDanhSachSinhVien(SINH_VIEN *ds, int n);
SINH_VIEN* timSinhVienTheoMSSV(SINH_VIEN *ds, int n, char *mssv);
void timSinhVienTheoTen(SINH_VIEN *ds, int n, char *hoten);
void timSinhVienTheoThangSinh(SINH_VIEN *ds, int n, int thang);
void timSinhVienTheoGioiTinh(SINH_VIEN *ds, int n, char *gioi_tinh);
void timSinhVienTheoDiaChi(SINH_VIEN *ds, int n, char *dia_chi);





int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    SINH_VIEN ds[MAX_SV];
    nhapDanhSachSinhVien(ds, n);

    printf("\nDanh sach sinh vien:\n");
    xuatDanhSachSinhVien(ds, n);

    // Vi du cac thao tac tim kiem
    char mssv[MAX_LEN];
    printf("\nNhap MSSV de tim: ");
    scanf("%s", mssv);
    SINH_VIEN *sv = timSinhVienTheoMSSV(ds, n, mssv);
    if (sv != NULL) {
        printf("Sinh vien tim thay:\n");
        xuatSinhVien(*sv);
    } else {
        printf("Khong tim thay sinh vien.\n");
    }

    return 0;
}



void nhapSinhVien(SINH_VIEN *sv) {
    printf("Nhap MSSV: ");
    scanf("%s", sv->mssv);
    printf("Nhap ho ten: ");
    getchar();  
    fgets(sv->hoten, MAX_LEN, stdin);
    sv->hoten[strcspn(sv->hoten, "\n")] = 0;
	  
    printf("Nhap ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &sv->ngaysinh.ngay, &sv->ngaysinh.thang, &sv->ngaysinh.nam);
    
    printf("Nhap gioi tinh: ");
    getchar();
    fgets(sv->gioi_tinh, MAX_LEN, stdin);
    sv->gioi_tinh[strcspn(sv->gioi_tinh, "\n")] = 0;
    
    printf("\nNhap dia chi: ");
    fgets(sv->dia_chi, MAX_LEN, stdin);
    sv->dia_chi[strcspn(sv->dia_chi, "\n")] = 0;
    
    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->somon);
    
    for (int i = 0; i < sv->somon; i++) {
        printf("Nhap ma mon hoc %d: ", i+1);
        scanf("%s", sv->mon_hoc[i].ma_mon);
        
        
        printf("Nhap diem mon hoc %d: ", i+1);
        scanf("%f", &sv->mon_hoc[i].diem);
    }
}






void xuatSinhVien(SINH_VIEN sv) {
    printf("\nMSSV: %s\n", sv.mssv);
    printf("Ho Ten: %s\n", sv.hoten);
    printf("Ngay Sinh: %d/%d/%d\n", sv.ngaysinh.ngay, sv.ngaysinh.thang, sv.ngaysinh.nam);
    printf("Gioi Tinh: %s\n", sv.gioi_tinh);
    printf("Dia Chi: %s\n", sv.dia_chi);
    printf("So Mon Hoc: %d\n", sv.somon);
    for (int i = 0; i < sv.somon; i++) {
        printf("Mon Hoc %d: %s - Diem: %.2f\n", i+1, sv.mon_hoc[i].ma_mon, sv.mon_hoc[i].diem);
    }
}











void nhapDanhSachSinhVien(SINH_VIEN *ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i+1);
        nhapSinhVien(&ds[i]);
    }
}








void xuatDanhSachSinhVien(SINH_VIEN *ds, int n) {
    for (int i = 0; i < n; i++) {
        xuatSinhVien(ds[i]);
    }
}





SINH_VIEN* timSinhVienTheoMSSV(SINH_VIEN *ds, int n, char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssv) == 0) {
            return &ds[i];
        }
    }
    return NULL;
}




void timSinhVienTheoTen(SINH_VIEN *ds, int n, char *hoten) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].hoten, hoten) != NULL) {
            xuatSinhVien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien theo ten %s\n", hoten);
    }
}





void timSinhVienTheoThangSinh(SINH_VIEN *ds, int n, int thang) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].ngaysinh.thang == thang) {
            xuatSinhVien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien sinh trong thang %d\n", thang);
    }
}




void timSinhVienTheoGioiTinh(SINH_VIEN *ds, int n, char *gioi_tinh) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].gioi_tinh, gioi_tinh) != NULL) {
            xuatSinhVien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien theo gioi tinh %s\n", gioi_tinh);
    }
}


void timSinhVienTheoDiaChi(SINH_VIEN *ds, int n, char *dia_chi) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].dia_chi, dia_chi) != NULL) {
            xuatSinhVien(ds[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien theo dia chi %s\n", dia_chi);
    }
}



