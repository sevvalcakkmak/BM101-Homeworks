//22118080010 Şevval ÇAKMAK
//31 December 2022
#include <stdio.h> //gerekli kütüphaneler
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//fonksiyonlarım
int ogrenciNumKontrol(char ogrenci_num[], int size); //öğreni numarasının 9 haneli olmasını ve rakamlardan oluşmasını kontrol eder.
int isValid_1(float num); //girilen notların aralığını kontrol eder.
int isValid_2(int* num, char numDemo[]); //ödev sayısının 0-10 aralığında olması ve rakamlardan oluşmasını kontrol eder.
void odev_notlari(char studentNum[], int hmwrkCount, float odevNotu[]); //ödev notlarını okur ve diziye atar.
float genel_ortalama_hesapla(char studentNum[], int hmwrkCount, float odevNotu[]); //struct kullanarak ortalama hesaplar.
void bubbleSort(float arr[], int size); //diziyi küçükten büyüğe sıralar.

int main(){
    char studentNum[10];
    char hmwrkCountDemo[2];
    static int hmwrkCount;
    float odevNotu[10];
    char devamMi[1];
    float genel_not_ort[999];
    int ogrenci_sirasi = 0;
    do{
        printf("Lutfen dersin odev sayisini giriniz: "); //ödev sayısını aldım.
        scanf(" %s", hmwrkCountDemo);
    } while(isValid_2(&hmwrkCount, hmwrkCountDemo)); //kontrol fonksiyonum.

    do{
        do{
            printf("Lutfen ogrenciye ait ogrenci numarasini giriniz: "); //öğrenci numarasını aldım.
            scanf("%s", studentNum);
        } while(ogrenciNumKontrol(studentNum, 10)); //konrtol fonksiyonum.

        genel_not_ort[ogrenci_sirasi] = genel_ortalama_hesapla(studentNum, hmwrkCount, odevNotu); //vize final ödev notlarıyla struct oluşturup hesap yaptığım fonksiyon
        printf("%s numarali ogrencinin genel not ortalamasi: %.2f\n", studentNum, genel_not_ort[ogrenci_sirasi]);
        
        do{ // en az bir kez "do"nun içerisi çalışacak, while(1) olduğu sürece tekrar çalışır.
            printf("Yeni bir ogrenci notu hesaplamak icin '1', cikmak icin '0' tuslayiniz: ");
            scanf("%s", devamMi);
            if (strcmp(devamMi, "1") != 0 && strcmp(devamMi, "0") != 0){ // kullanıcı 0 veya 1 girmemişse uyarı verir.
                printf("Hatali secim yaptiniz!!\n");
            }
            printf("\n");
        } while (strcmp(devamMi, "1") != 0 && strcmp(devamMi, "0") != 0); //kullanıcı 0 veya 1 girmediği sürece tekrar sorar.
        ogrenci_sirasi++; //arrayde yeni bir değer tutabilmek için her seferinde artırıyorum.
    } while (strcmp(devamMi, "1") == 0);

    bubbleSort(genel_not_ort, ogrenci_sirasi); //diziye atadığım tüm ortalamaları sıraladım.

    float sinif_ort, total = 0;
    for(int i = 0; i < ogrenci_sirasi; i++){
        total += genel_not_ort[i]; //tüm ortalamaları topladım.
    }
    sinif_ort = total/ogrenci_sirasi; //sınıf ortalamasını hesapladım.
    printf("Dersi alan %d ogrenci icin en dusuk not: %.2f\n", ogrenci_sirasi, genel_not_ort[0]);
    printf("Dersi alan %d ogrenci icin en yuksek not: %.2f\n", ogrenci_sirasi, genel_not_ort[ogrenci_sirasi-1]);
    printf("Dersi alan %d ogrencinin sinif ortalamasi: %.2f\n", ogrenci_sirasi, sinif_ort);

    return 0;
}

int ogrenciNumKontrol(char studentNum[], int size){ //öğreni numarasının 9 haneli olmasını ve rakamlardan oluşmasını kontrol eder.
    if(strlen(studentNum) == 9){ //char dizisi 9 karakter içermeli
        for(int i = 0; studentNum[i] != '\0'; i++){
            if(isdigit(studentNum[i])){ //tüm karakterler rakamdan oluşmalı
                continue;
            }
            else{
                printf("Ogrenci numarasi yalnizca rakamlardan olusmalidir!!\n");
                return 1;
            }         
        }
    }
    else{
        printf("Ogrenci numarasi '9' haneli olmalidir!!\n");
    return 1;
    }
    return 0;
}

int isValid_1(float num){ //girilen notların aralığını kontrol eder.
    if(num <= 100 && num >= 0){ //not 0-100 aralığında olmalı
        return 0;
    }
    else{
        printf("Girilen not 0-100 araliginda olmalidir!!\n");
        return 1;
    }
}

int isValid_2(int* num, char numDemo[]){ //ödev sayısının 0-10 aralığında olması ve rakamlardan oluşmasını kontrol eder.
    for(int i = 0; numDemo[i] != '\0'; i++){
        if(isdigit(numDemo[i])){ //tüm karakterlerin rakam olduğundan emin oldum.
            continue;
        }
        else{
            printf("Odev sayisi harf iceremez!!\n");
            return 1;
        }
    }

    *num = atoi(numDemo); //arrayi inte çevirdim.

    if(*num <= 10 && *num >= 0){ //ödev sayısı 0-10 aralığında olmalı
        return 0;
    }
    else{
        printf("Odev sayisi 0-10 araliginda olmalidir!!\n");
        return 1;
    }
}

void odev_notlari(char studentNum[], int hmwrkCount, float odevNotu[]){ //ödev notlarını okur ve diziye atar.
    float hmwkScan; 
    for(int i = 1; i <= hmwrkCount; i++){ //odevSayisi kadar odev girdisi alacak
        do{
            printf("Ogrencinin %d. odev notunu giriniz: ", i); //ödev sayısı kadar ödev okudum.
            scanf("%f", &hmwkScan);

        } while(isValid_1(hmwkScan));
        odevNotu[i-1] = hmwkScan;
    }
}

float genel_ortalama_hesapla(char studentNum[], int hmwrkCount, float odevNotu[]){ //struct kullanarak ortalama hesaplar.
    static int ogrenci_sayaci = 0;

    typedef struct //öğrencilerin gerekli verilerini içeren struct
    {
        float vize;
        float final;
        float odevler[hmwrkCount];
        float odev_ort;
        float genel_ort;
    } Ogrenci;

    Ogrenci ogrenci[ogrenci_sayaci]; //dizi şeklinde öğrenci bilgilerini okuyacağım.

    do{
        printf("%s numarali ogrenci icin vize notunu giriniz: ", studentNum);
        scanf("%f", &ogrenci[ogrenci_sayaci].vize);
    }while(isValid_1(ogrenci[ogrenci_sayaci].vize)); //kontrol fonksiyonum.
    do{
        printf("%s numarali ogrenci icin final notunu giriniz: ", studentNum);
        scanf("%f", &ogrenci[ogrenci_sayaci].final);
    }while(isValid_1(ogrenci[ogrenci_sayaci].final)); //kontrol fonksiyonum.

    odev_notlari(studentNum, hmwrkCount, odevNotu); //ödev notlarını alan fonksiyon

    for(int i = 0; i < hmwrkCount; i++){
        ogrenci[ogrenci_sayaci].odevler[i] = odevNotu[i]; //tüm ödev notlarını structdaki diziye atadım.
    }
    
    float hmwrkTotal = 0;
    for(int i = 0; i < hmwrkCount; i++){
        hmwrkTotal += ogrenci[ogrenci_sayaci].odevler[i]; //tüm ödev notlarını topladım.
    }
    ogrenci[ogrenci_sayaci].odev_ort = hmwrkTotal/hmwrkCount; //her öğrencinin ödev ortalamasını hesapladım.
   
    if(hmwrkCount == 0){ //ödev yoksa genel ortalama hesabı 
        ogrenci[ogrenci_sayaci].genel_ort = ogrenci[ogrenci_sayaci].vize*0.6 + ogrenci[ogrenci_sayaci].final*0.4;
    }
    else{ //ödev varsa genel ortalama hesabı
        printf("%s numarali ogrencinin odev ortalamasi: %.2f\n", studentNum, ogrenci[ogrenci_sayaci].odev_ort);
        ogrenci[ogrenci_sayaci].genel_ort = ogrenci[ogrenci_sayaci].vize*0.3 + ogrenci[ogrenci_sayaci].final*0.4 + ogrenci[ogrenci_sayaci].odev_ort*0.3;
    }
    ogrenci_sayaci++; //yeni öğrenciler hesaplayabilmek için her fonksiyon çağırıldığında hesap yapabilmek için 

    return ogrenci[ogrenci_sayaci-1].genel_ort; //structtaki hesapladığım ortalamayı dondürdüm.
}

void bubbleSort(float arr[], int size){ //diziyi küçükten büyüğe sıralar.
    float tut;
    for(int i = 0; i < size-1; i++){//bubble sorting algoritmasi ile not_ort[] arrayimi sıralıyorum.
        for(int j = 0; j < size-i-1; j++){
            if (arr[j] > arr[j+1]){
                tut = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tut;
            }
        }
    }
}