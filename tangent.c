#include <stdio.h>
#include <math.h>

double f(double x){
    return pow(2, x) + x - 4;
}

double tangent(double epsilon, double a, double b){
    double x = a - ((b - a) * f(a)) / (f(b) - f(a));

    while (fabs(f(x)) > epsilon) {
        if (f(x) * f(a) < 0) {
            b = x;
        } else {
            a = x;
        }
        x = a - ((b - a) * f(a)) / (f(b) - f(a));
    }

    return x;
}

int main(){
    double a = 1, b = 2; // Khoảng nghiệm a, b
    double epsilon = pow(10, -9);
    double x = tangent(epsilon, a, b);
    printf("Nghiem xap xi x la: %.15lf\n", x);
    return 0;
}
