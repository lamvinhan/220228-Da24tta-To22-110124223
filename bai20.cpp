#include<stdio.h>
#define SIZE 100

void nhapMang(int A[], int n);
void xuatMang(int A[], int n);
int tongMang(int A[], int n);
float tinhTrungBinhCongViTriLe(float A[], int n);
int demSoDuong(int A[], int n);
void sapXepTangDan(int A[], int n);
void inGiaTriViTriLe(int A[], int n);
void inViTriSo0(int A[], int n) ;
float timGiaTriLonNhat(int A[], int n);
int timViTriLonNhat(int A[], int n);
void inViTriGiaTriLonNhat(int A[], int n);
int kiemTraToanSoAm(int A[], int n);


   int main ()
{
	int A[SIZE];
	int n, kq;

	
	
	do
	{
		printf("\nNhap vao so phan tu: ");
		scanf("%d", &n);
	}while(n<=0||n>100);int main();

//Goi ham cau a
	nhapMang(A,n);
	
//Goi ham cau b
	printf("\nMang vua nhap la: ");
	xuatMang(A,n);
	
//Goi ham cau c
	kq = tongMang(A,n);
	printf("\nTong cac gia trong mang la %d", kq);

//Goi ham cau d

    printf("\nTrung binh cong cac phan tu vi tri le trong mang la %d ",kq); 

//Goi ham cau e
    kq = demSoDuong(A,n);
    printf("\nSo pham tu duong trong mang la %d ", kq);

//Goi ham cau f
 sapXepTangDan(A, n);
    printf("\nMang sau khi sap xep tang dan: ");
    xuatMang(A, n);

//Goi ham cau g
  inGiaTriViTriLe(A, n);
  
//Goi ham cau h
    inViTriSo0(A,n);
   
//Goi ha cau i
 printf("Giá tr? l?n nh?t trong m?ng A: %.2f\n", timGiaTriLonNhat(A, n));

//Gioi ham cau j
printf("\nVi tri co gia tri lon nhat dau tien trong mang la : %d\n", timViTriLonNhat(A, n));



//Goi ham cau k
  inViTriGiaTriLonNhat(A, n);

//Goi ham cau l
if (kiemTraToanSoAm(A, n)) {
        printf("Mang co toan so am.\n");
    } else {
        printf("Mang khong co toan so am.\n");
    }
return 0;

}


float timGiaTriLonNhat(int A[], int n) {
    float max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}







void inViTriGiaTriLonNhat(int A[], int n) {
    int max = timGiaTriLonNhat(A, n);
    printf("Cac vi tri co gia tri lon nhat (%.2f) trong mang A: ", max);
    for (int i = 0; i < n; i++) {
        if (A[i] == max) {
            printf("%d ", i);
        }
    }
    printf("\n");
}









int timViTriLonNhat(int A[], int n) {
    float max = timGiaTriLonNhat(A, n);
    for (int i = 0; i < n; i++) {
        if (A[i] == max) {
            return i;
        }
    }
    return -1; 
}












int kiemTraToanSoAm(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] >= 0) {
            return 0; 
        }
    }
    return 1;

}








void inViTriSo0(int A[], int n) {
    printf("Cac vi tri co gia tri bang 0 trong mang la: ");
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}





void inGiaTriViTriLe(int A[], int n) {
    printf("\nCac gia tri tai vi tri le trong mang la : ");
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            printf("%.2f ", A[i]);
        }
    }
    printf("\n");
}























void sapXepTangDan(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                float temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}









int demSoDuong(int A[], int n){
	int dem=0;
	for ( int i=0; i<=n;i++){
		if (A[i]>0);
		{
			dem++;
		}
	}
return dem;
}









float tinhTrungBinhCongViTriLe(float A[], int n) {
    float tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) { 
            tong += A[i];
            dem++;
        }
    }
    return (dem > 0) ? tong / dem : 0;
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
