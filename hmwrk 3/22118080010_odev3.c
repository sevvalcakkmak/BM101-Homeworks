//22118080010 Şevval ÇAKMAK 
//19 December 2022
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float odevFunc(int ogrenci_num, int odevSayisi){ //odev fonksiyonu odev ortlamasini return edecek.
    float total, ort, odevNotu[odevSayisi-1]; 
    for(int i = 1; i <= odevSayisi; i++){ //odevSayisi kadar odev girdisi alacak.
        do{ //en az 1 kere calisir.
            printf("Ogrencinin %d. odev notunu giriniz: ", i);
            scanf("%f", &odevNotu[i-1]);
            if(odevNotu[i-1]>100 || odevNotu[i-1]<0){                //gecersiz not girilirse
                printf("Odev notu 0-100 araliginda olmalidir!!\n");  //uyari verecek.
            }
        }while(odevNotu[i-1]>100 || odevNotu[i-1]<0); //gecersiz not girildigi surece "do" tekrar tekrar calisacak.
    }
    for(int k = 0; k < odevSayisi; k++){ //arraydeki tum notlari topladim.
        total += odevNotu[k];
    }
    ort = total/odevSayisi; //ortalamayi hesapladim,
    return ort;             //float olarak return ettim.
}

float ortalama_hesapla(int ogrenci_num, int odevSayisi){ //genel not ortalamasini hesaplayip return edecek.
    int ogrenci_counter = 0;
    float vize, final, odev_ort, not_ort;
    do{ //en az 1 kere calisir.
        printf("%d numarali ogrenci icin vize notunu giriniz: ", ogrenci_num);
        scanf("%f", &vize);                                        //vize notunu kullanicidan aldim.
        if(vize<0 || vize>100){                                    //gecersiz not girilirse,
            printf("Vize notu 0-100 araliginda olmalidir!!\n");    //uyari verecek.
        }
    }while(vize<0 || vize>100); //gecersiz not girildigi surece "do" tekrar tekrar calisacak.

    do{ //en az 1 kere calisir.
        printf("%d numarali ogrenci icin final notunu giriniz: ", ogrenci_num);
        scanf("%f", &final);                                        //final notunu kullanicidan aldim.
        if(final<0 || final>100){                                   //gecersiz not girilirse,
            printf("Final notu 0-100 araliginda olmalidir!!\n");    //uyari verecek.
        }
    }while(final<0 || final>100); //gecersiz not girildigi surece "do" tekrar tekrar calisacak.

    odev_ort = odevFunc(ogrenci_num, odevSayisi); //odev ort hesaplayan fonksiyonumu cagirdim.
    if(odevSayisi == 0){                //odev yoksa,
        not_ort = vize*0.6 + final*0.4; //not ortalamasi bu katsayilarla hesaplanacak.
    }
    else{                                                                                //odev varsa,
        printf("%d numarali ogrencinin odev ortalamasi: %.2f\n", ogrenci_num, odev_ort); //fonks yardimiyla hesaplanan odev ort yazilacak,
        not_ort = vize*0.3 + final*0.4 + odev_ort*0.3;                                   //not ortalamasi bu katsayilarla hesaplanacak.
    }
    return not_ort; //not ortalamasini verilen sartlara uygun sekilde return ettim.
}

int main(){
    int ogrenci_num;
    static int odevSayisi;
    float not_ort[999];
    int result2, result1 = 0;
    char devam[1];
    int ogrenci_counter = 0;
    printf("NOT ORTALAMASI HESAPLAMA\n************************\n\n");
    printf("Lutfen dersin odev sayisini giriniz: ");
    scanf("%d", &odevSayisi); //odev sayisini okudum.

    while(result1 == 0){ // kullanıcı 1 girerse result1 = 0
        printf("\nLutfen ogrenciye ait ogrenci numarasini giriniz: ");
        scanf("%d", &ogrenci_num);
        not_ort[ogrenci_counter] = ortalama_hesapla(ogrenci_num, odevSayisi); //fonksiyonumu cagirdim, her hesaplamayi sirayla tutabilmek için arraye atadim.
        printf("%d numarali ogrencinin not ortalamasi: %.2f\n\n", ogrenci_num, not_ort[ogrenci_counter]);
        do{ // en az bir kez "do"nun içerisi çalışacak, while(1) olduğu sürece tekrar çalışır.
            printf("Yeni bir ogrenci notu hesaplamak icin '1', cikmak icin '0' tuslayiniz: ");
            scanf("%s", devam);
            result1 = strcmp(devam, "1"); // 1 girerse result1 = 0 olur, while döngüsü devam eder. başka değer girilirse result != 0 olur.
            result2 = strcmp(devam, "0"); // 0 girerse result2 = 0. başka değer girilirse result != 0 olur.
            if (result1 != 0 && result2 != 0){ // kullanıcı 0 veya 1 girmemişse uyarı verir.
               printf("Hatali secim yaptiniz!!\n");
            }
            printf("\n");
        } while (result1 != 0 && result2 != 0 ); //kullanıcı 0 veya 1 girmediği sürece tekrar sorar.
        ogrenci_counter++; //arrayde yeni bir deger tutabilmek icin her seferinde artiriyorum.
    }
    float tut;
    for(int i = 0; i < ogrenci_counter-1; i++){       //bubble sorting algoritmasi ile not_ort[] arrayimi siraliyorum.
        for(int j = 0; j < ogrenci_counter-i-1; j++){
            if (not_ort[j] > not_ort[j+1]){
                tut = not_ort[j];
                not_ort[j] = not_ort[j+1];
                not_ort[j+1] = tut;
            }
        }
    }
    float sinif_ort, total = 0;
    for(int i = 0; i < ogrenci_counter; i++){
        total += not_ort[i]; //tum ortalamalari topladim.
    }
    sinif_ort = total/ogrenci_counter; //sinif ortalamasini hesapladim.
    printf("Dersi alan %d ogrenci icin en dusuk not: %.2f\n", ogrenci_counter, not_ort[0]);
    printf("Dersi alan %d ogrenci icin en yuksek not: %.2f\n", ogrenci_counter, not_ort[ogrenci_counter-1]);
    printf("Dersi alan %d ogrencinin sinif ortalamasi: %.2f\n", ogrenci_counter, sinif_ort);
    return 0;
}