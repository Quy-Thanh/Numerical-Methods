#include <stdio.h>

// Ham nhap da thuc
void nhap_he_so(int *he_so, int n) {
    printf("Nhap cac he so cua da thuc tu bac cao nhat den bac 0:\n");
    for (int i = 0; i < n; i++) {
        printf("He so cua bac %d: ", n - i - 1);
        scanf("%d", &he_so[i]);
    }
}

void xuat_ham_so(int *he_so, int n) {
    printf("P(x) = ");
    for (int i = 0; i < n - 1; i++) {
        printf("(%d)*x^%d + ", he_so[i], n - i - 1);
    }
    printf("(%d)", he_so[n - 1]);
}

//Ham tinh gia tri cua da thuc bang phuong phap luoc do Horner
int horner(int *he_so, int n, int x) {
    int result = he_so[0]; //Khoi tao ket qua bang he so tu do

    for (int i = 1; i < n; i++) {
        result = result * x + he_so[i];
    }
    return result;
}
int main() {
    int bac, x;
    
    printf("Nhap bac cua da thuc: ");
    scanf("%d", &bac);

    int n = bac + 1; //So luong phan tu cua mang he so
    int he_so[n]; // Mang luu he so
    nhap_he_so(he_so, n);
    
    xuat_ham_so(he_so, n);
    
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    
    int result = horner(he_so, n, x);
    
    printf("\nGia tri cua da thuc tai x = %d la: %d \n", x, result);
    
    return 0;
}
