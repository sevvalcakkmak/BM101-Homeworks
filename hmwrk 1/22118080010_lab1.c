// 22118080010 Sevval CAKMAK
//10 November 2022
#include <stdio.h>

int main(){
    int ogrenci_sayisi, ogrenci_numarasi; // gerekli degiskenleri tanimladim.
    int vize_not, final_not, i;
    double ortalama;

    printf("Lutfen ogrenci sayisini giriniz: "); //kullaniciya kac ogrencinin ortalamasini hesaplayacagini sordum.
    scanf("%d", &ogrenci_sayisi); // ve bu ogrenci sayisini okuttum.
    printf("\n");

    for(i = 1; i <= ogrenci_sayisi; i++){ //ogrenci sayisi kadar kodun donmesini istiyorum.
        printf("Lutfen %d. ogrenciye ait ogrenci numarasini giriniz: ", i); //sirayla her ogrencinin numarasini aldim.
        scanf("%d", &ogrenci_numarasi); // sirayla ogrenci numaralarini okudum.
        printf("%d numarali ogrenci icin vize notunu giriniz: ", ogrenci_numarasi);  //vize notlarini istedim.
        scanf("%d", &vize_not); //vize notlarini okudum.
        printf("%d numarali ogrenci icin final notunu giriniz: ", ogrenci_numarasi); // final notlarini istedim.
        scanf("%d", &final_not); //final notlarini okudum.
        ortalama = (vize_not*0.6 + final_not*0.4); //vize %60, final %40 etkiledigi icin gerekli islemleri yaptim.
        printf("%d numarali ogrencinin not ortalamsi: %f\n\n", ogrenci_numarasi, ortalama); //ve ekrana her ogrenci icin ortalamayi yazdirdim.
    }

    return 0;
}