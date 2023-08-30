// Online C compiler to run C program online
#include <stdio.h>


void nhap_he_so(int *he_so, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Nhap he so cua bac %d: ", n - i - 1);
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

void tinh_he_so(int *he_so, int n, int c) {
    for(int i = n; i >= 0; i--)
    {
        for(int j = 1; j < i; j++){
            he_so[j] = he_so[j - 1] * c + he_so[j];
        }
    }
}

int main() {
    int bac; // bac cua ham p(x)

    printf("Nhap bac cua ham so: ");
    scanf("%d", &bac);

    int n = bac + 1;
    int a[n], c; // Mang luu tru he so cua P(x): a0, a1, ..., an ; gia tri c cua ham P(x + c).

    printf("Nhap he so cua ham P(x) tu bac cao nhat den bac thap nhat\n");
    nhap_he_so(a, n);

    printf("Nhap gia tri cua c cua ham P(y + c): ");
    scanf("%d", &c);
    tinh_he_so(a, n, c);
    
    xuat_ham_so(a, n);
    return 0;
}
