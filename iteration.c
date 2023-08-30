#include<stdio.h>
#include<math.h>

double g(double x)
{
    return cbrt(x + 1);
}
double iteration(double epsilon, double x){

    double y = x;
    x = g(x);

    if(fabs(y - x) < epsilon){
        return x;
    }
    else {
        return iteration(epsilon, x);
    } 
}

int main()
{
    double epsilon = pow(10, -3);
    double x = 1;
    x = iteration(epsilon, x);

    printf("So x gan dung la: %.10lf", x);

    return 0;
}
