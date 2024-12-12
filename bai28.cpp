#include <stdio.h>
#include <string.h>

int main() {
    int arr[10]; 
    char filename[50];
    FILE *fp; 
    //Nhap ten tep
    printf("Nhap ten tep: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = 0;
    //Khoi tao gia tri
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

   //Mo flie o che do ghi
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Khong the mo file!\n");
        return 1;
    }
if (fp == NULL) {
    printf("Khong the mo file!\n");
    return 1;
}
    // Ghi du lieu vao file
for (int i = 0; i < 10; i++) {
    fprintf(fp, "%d ", arr[i]);
}

    // Dong file 
fclose(fp);
return 0;
}


