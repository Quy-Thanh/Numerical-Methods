#include <stdio.h>

// Hàm nh?p da th?c
void nhapHamSo(int *heSo, int bac) {
    printf("Nhap cac he so cua da thuc tu bac cao nhat den bac 0:\n");
    for (int i = bac; i >= 0; i--) {
        printf("He so cua bac %d: ", i);
        scanf("%d", &heSo[i]);
    }
}

//Ham tinh gia tri cua da thuc bang phuong phap luoc do Horner
int Horner(int *heSo, int bac, int x) {
    int result = heSo[0]; //Khoi tao ket qua bang he so tu do

    for (int i = 1; i <= bac; i++) {
        result = result * x + heSo[i];
    }

    return result;
}
int main() {
    int bac, x;
    
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &bac);
    
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    
    int heSo[bac+1]; // Mang luu he so
    nhapHamSo(heSo, bac);
    
    int result = Horner(heSo, bac, x);
    
    printf("Gia tri cua da thuc tai x = %d la: %d \n", x, result);
    
    return 0;
}
