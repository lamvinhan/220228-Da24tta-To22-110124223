#define SIZE 100
#include <stdio.h>

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n);
int tongPhanTuDuong(int a[], int n);
int tongPhanTuViTriLe(int a[],int n);
int demPhanTuAm(int a[],int n);
int demPhanTuLe(int a[],int n);
int demPhanTuNguyenTo(int a[],int n);
int soNguyenToDauTien(int a[],int n);
void inSoDuongLe(int a[], int n);
int tonTaiSoAm(int a[], int n);
int tonTaiGiaTriX(int a[],int n,int x);




//Khai bao ham kiem tra so nguyen
bool isPrime (int i); 
int main()
{
	int A[SIZE];
	int n, kq;
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);
	
	//n hop le
	//goi ham cau a
	nhapMang(A,n);
	
	//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
	//Goi ham cau c
	kq = tongMang(A,n);
	printf("\nTong cac gia trong mang la %d", kq);
	
	//Goi ham cau d
	kq = tongPhanTuDuong(A,n);
	printf("\nTong cac phan tu duong trong mang la %d ",kq);
	
	//Goi ham cau e
	kq =tongPhanTuViTriLe(A,n);
	printf("\nTong cac phan tu vi tri le trong mang la %d",kq);
	
	//Goi ham cau f
	kq = demPhanTuAm(A,n);
	printf("\nSo phan tu am trong mang la %d",kq);
	
	//Goi ham cau g
	kq = demPhanTuLe(A,n);
	printf("\nSo phan tu le trong mang la %d",kq);
	
	//Goi ham cau h
	kq = demPhanTuNguyenTo(A,n);
	printf("\nSo phan tu nguyen to trong mang la %d",kq);
	
	//Goi ham cau i
	kq = soNguyenToDauTien(A,n);
	printf("\nSo nguyen to dau tien trong mang la %d",kq);
	
	//Goi ham cau j
	inSoDuongLe(A,n);
	
	//Goi ham cau k
	tonTaiSoAm(A,n);
    printf ("\nMang khong co chua so nguyen am la ");
    
    //Goi ham cau l
  printf("\nMang khong co ton tai gia tri x");
   

	return 0;
}












    int tonTaiSoAm(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            return 1;
        }
    }
    return 0;
}







void inSoDuongLe(int A[], int n)
{
	printf("\nCac so duong le trong mang :");
	for (int i = 0; i<n ; i++){
		if (A[i] > 0 && A[i] % 2 != 0) {
            printf ("%8d",A[i] );
            
        }
    }
 printf("\n");
}
		
	

     int soNguyenToDauTien(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (isPrime(A[i])) {
            return A[i];
        }
    }
    return -1;  
}




// Hàm kiem tra so nguyên to
bool isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int demPhanTuNguyenTo(int A[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(A[i])) {
            dem++;
        }
    }
    return dem;
}




int demPhanTuLe(int a[],int n){
	int dem = 0;
	for (int i = 0 ; i<n ; i++){
		if ( a[i]%2 != 0) {
			dem++;
		
		}
	}
	return dem;
}


int demPhanTuAm(int A[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            dem++;
        }
    }
    return dem;
}







int tongPhanTuViTriLe(int A[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {  
            tong += A[i];
        }
    }
    return tong;
}



int tongPhanTuDuong(int A[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            tong += A[i];
        }
    }
    return tong;
}

int tongMang(int a[], int n)
{
	int tong = 0;
	int i=0;
	do
	{
		tong = tong + a[i];
		i++;
	}while(i<=n-1);
	return tong;
}

void xuatMang(int a[], int n)
{
	int i;
	for(i=0; i<=n-1; i++)
	{
		printf("%8d", a[i]);
	}
}
void nhapMang(int a[], int n)
{
	int i;
	
	i = 0;
	while(i<=n-1)
	{
		printf("\nNhap gia tri tai vi tri %d: ", i);
		scanf("%d", &a[i]); //a+i
		i++;
	}
}



int tonTaiGiaTriX(int A[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return true;
        }
    }
    return false;
}







