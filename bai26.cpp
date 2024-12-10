#include <stdio.h>
#include <string.h>

#define MAX_SACH 100





// Ðinh nghia cau truc SACH
typedef struct  {
    char maSach[20];
    char tenSach[100];
    char tacGia[50];
    char nhaXuatBan[50];
    int namXuatBan;
    float donGia;
    int soLuongNhap;
    float thanhTien;
    float thue;
    float thucTien;
} SACH;





// Nguyen mau cac ham
void nhapThongTin(SACH *sach);
void inThongTin(SACH sach);
void tinhThanhTien(SACH *sach);
void tinhThucTien(SACH *sach);
void sapXepTheoNam(SACH sach[], int n);
void inSachThucTienMax(SACH sach[], int n);
void tongSoLuong(SACH sach[], int n);





int main() {
    int n;

    // Nhap so luong sach
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    
    // Kiem tra n > 0
    if (n <= 0 || n > MAX_SACH) {
        printf("So luong sach khong hop le!\n");
        return 0;
    }

    // Khai bao mang sach
    SACH sach[n];

    // Nhap thong tin cac quyen sach
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sach %d:\n", i + 1);
        nhapThongTin(&sach[i]);
        tinhThanhTien(&sach[i]);
        tinhThucTien(&sach[i]);
    }

    // In danh sach sach
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < n; i++) {
        inThongTin(sach[i]);
    }

    // Sap xep theo nam xuat ban giam dan
    sapXepTheoNam(sach, n);

    // In danh sach sau khi sap xep
    printf("\nDanh sach sach sau khi sap xep theo nam xuat ban:\n");
    for (int i = 0; i < n; i++) {
        inThongTin(sach[i]);
    }

    // In sach co thuc tien lon nhat
    inSachThucTienMax(sach, n);

    // In tong so luong sach
    tongSoLuong(sach, n);

    return 0;
}

// Ham nhap thong tin sach
void nhapThongTin(SACH *sach) {
    printf("Ma sach: ");
    fflush(stdin);
    gets(sach->maSach);
    
    printf("Ten sach: ");
    gets(sach->tenSach);
    
    printf("Tac gia: ");  
    gets(sach->tacGia);
    
    printf("Nha xuat ban: ");
    gets(sach->nhaXuatBan);
    
    printf("Nam xuat ban: ");
    scanf("%d", &sach->namXuatBan);
    
    printf("Don gia: ");
    scanf("%f", &sach->donGia);
    
    printf("So luong nhap: ");
    scanf("%d", &sach->soLuongNhap);
    
    printf("Thue VAT: ");
    scanf("%f", &sach->thue);
}

// Ham in thong tin sach
void inThongTin(SACH sach) {
    printf("%-20s %-50s %-30s %-20s %-15d %-10.2f %-12d %-12.2f %-10.2f %-10.2f\n", 
           sach.maSach, sach.tenSach, sach.tacGia, sach.nhaXuatBan, sach.namXuatBan, sach.donGia, sach.soLuongNhap, sach.thanhTien, sach.thue, sach.thucTien);
}

// Ham tinh thanh tien
void tinhThanhTien(SACH *sach) {
    sach->thanhTien = sach->soLuongNhap * sach->donGia;
}

// Ham tinh thuc tien
void tinhThucTien(SACH *sach) {
    sach->thucTien = sach->thanhTien + sach->thue;
}

// Ham sap xep sach theo nam xuat ban giam dan
void sapXepTheoNam(SACH sach[], int n) {
    SACH temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sach[i].namXuatBan < sach[j].namXuatBan) {
                temp = sach[i];
                sach[i] = sach[j];
                sach[j] = temp;
            }
        }
    }
}

// Ham in sach co thuc tien lon nhat
void inSachThucTienMax(SACH sach[], int n) {
    float max = sach[0].thucTien;
    for (int i = 1; i < n; i++) {
        if (sach[i].thucTien > max) {
            max = sach[i].thucTien;
        }
    }

    printf("\nSach co thuc tien lon nhat:\n");
    for (int i = 0; i < n; i++) {
        if (sach[i].thucTien == max) {
            inThongTin(sach[i]);
        }
    }
}

// Ham in tong so luong sach
void tongSoLuong(SACH sach[], int n) {
    printf("\nTong so luong sach cua moi quyen:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %s, Tong so luong: %d\n", sach[i].maSach, sach[i].soLuongNhap);
    }
}
























   	
