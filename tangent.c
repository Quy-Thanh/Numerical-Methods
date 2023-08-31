#include <stdio.h>
#include <math.h>

double f(double x){
    return pow(x, 3) + x - 5;
}

//Đạo hàm
double fdh(double x){
    return 3*pow(x, 2) + 1;
}

double tangent(double epsilon, double x)
{
    double y = x;
    x = y - f(y)/fdh(y);
    if(epsilon < fabs(x - y))
    {
        return tangent(epsilon, x);
    }
    else{
        return x;
    }
}

int main(){
    double x0 = 2;
    double epsilon = pow(10, -9);
    double x = tangent(epsilon, x0);
    printf("Nghiem xap xi x la: %.15lf\n", x);
    return 0;
}