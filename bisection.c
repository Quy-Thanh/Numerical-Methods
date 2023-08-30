#include<stdio.h>
#include<math.h>
#include <stdlib.h>

double f(double x)

{
    return (double)pow(2, x) + x - 4; //Hàm số cần tính
}

double bisection(double entropy,double a,double b)
{

    if (a >= b)
    {
        printf("Dau vao a phai nho hon b.\n");
        exit(1);
    }

    double mid = (a + b) / 2;
    
    if (fabs(b - a) < entropy) {
        return mid; // Đủ chính xác, trả về xấp xỉ của nghiệm
    } else if (f(mid) * f(a) < 0) {
        return bisection(entropy, a, mid);
    } else {
        return bisection(entropy, mid, b);
    }
}

int main(){
    double entropy = pow(10, -14);
    double x = bisection(entropy, 0, 100);
    printf("Nghiem cua phuong trinh la: %.14lf\n", x);
    return 0;
}
