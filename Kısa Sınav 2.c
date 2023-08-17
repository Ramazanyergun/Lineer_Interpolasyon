#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double Hata = 8 * pow(10,-4);

double Fonk(double x){
    return pow(x,3) - 5 * pow(x,2) + 9 * x - 1;
}

double Hesapla(double An, double Bn){
    return (An * Fonk(Bn) - Bn * Fonk(An)) / (Fonk(Bn) - Fonk(An));
}

int main(){
    double a = 0;
    double Xn = 1;
    double b = 2;
    double fonkX = Fonk(Xn);
    double hesaplananHata = 1;
    int adim = 0;

    printf("....Doğrusal İnterpolasyon....\n\n");
    printf("F(x) = x^3 - 5x^2 + 9x - 1 \n");
    printf("Aralık değeri : [0,2] \n");
    printf("Durma Koşulu : |Xn - Xn_1| < Hata \n");
    printf("Hata : 8*10^-4 (%f)\n\n",Hata);

    printf("Adım |      a     |     Xn     |     b      |    F(Xn)   |     Hata \n");
    printf("---------------------------------------------------------------------------\n");

    while(hesaplananHata >= Hata){
        double Xn_1 = Xn;
        Xn = Hesapla(a,b);
        adim++;
        fonkX = Fonk(Xn);
        hesaplananHata = fabs(Xn - Xn_1);
        printf("%4d | %10.6f | %10.6f | %10.6f | %10.6f | %10.6f \n", adim, a, Xn, b, fonkX, hesaplananHata);

        if(Fonk(a) * Fonk(Xn) < 0){
            b = Xn;
        }
        else{
            a = Xn;
        } 
    }

    printf("\nKök: %10.6f\n", Xn);
    return 0;
}
