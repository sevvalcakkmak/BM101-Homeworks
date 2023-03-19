//22118080010 Şevval ÇAKMAK
//3 December 2022
#include <stdio.h>
#include <string.h> // string karaktelerin eşitliğini kontrol edebilmek için strcmp(string a, string b); fonksiyonunu kullanmam gerek.

float ortalama_hesapla(int ogrenci_num){ //parametre olarak öğrenci numarasını aldım. return değeri float olduğu için float yazdım.
    float vize_not, final_not;
    do{ // en az bir kez "do"nun içerisi çalışacak, while(1) olduğu sürece tekrar çalışır.
        printf("\n%d numarali ogrencinin vize notu: ", ogrenci_num);
        scanf("%f", &vize_not);
        if (vize_not > 100 || vize_not < 0){ // vize notunun kabul edilmeyeceği değerleri girerse hata verecek.
            printf("Girilen not 0-100 araliginda olmalidir!\n");
        }
    } while (vize_not > 100 || vize_not < 0); //geçersiz vize notu girilirse tekrar "do"nun içerisi çalışacak.

    do{ // en az bir kez "do"nun içerisi çalışacak, while(1) olduğu sürece tekrar çalışır.
        printf("\n%d numarali ogrencinin final notu: ", ogrenci_num);
        scanf("%f", &final_not);
        if (final_not > 100 || final_not < 0){ //final notunun kabul edilmeyeceği değerleri girerse hata verecek.
            printf("Girilen not 0-100 araliginda olmalidir!\n");
        }
    } while (final_not > 100 || final_not < 0); //geçersiz final notu girilirse tekrar "do"nun içerisi çalışacak.
    float ort;
    ort = (vize_not*0.6 + final_not*0.4); // ortalama hesapladım.
    return ort; // ortalama değerini (float) döndürüyorum.
}

int main(){
    printf("NOT HESAPLAMA\n*************\n");
	int ogrenci_num;
    int result2;
	int result1 = 0; //while döngüsüne girebilmek için.
    char devam [1];
    while(result1 == 0){ // kullanıcı 1 girerse result1 = 0
		printf("Lutfen ogrenci numarasini giriniz: ");
        scanf("%d", &ogrenci_num);
        float sonuc = ortalama_hesapla(ogrenci_num); //sonucu ortalama_hesapla() fonksiyonunu kullanarak hesapladım.
        printf("\n%d numarali ogrencinin not ortalamasi: %.2f\n\n", ogrenci_num, sonuc); //sonuç için virgülden sonra iki basamak yazdırdım.
        do{ // en az bir kez "do"nun içerisi çalışacak, while(1) olduğu sürece tekrar çalışır.
            printf("Yeni bir ogrenci notu hesaplamak icin '1', cikmak icin '0' tuslayiniz: ");
            scanf("%s", &devam);
            result1 = strcmp(devam, "1"); // 1 girerse result1 = 0 olur, while döngüsü devam eder. başka değer girilirse result != 0 olur.
            result2 = strcmp(devam, "0"); // 0 girerse result2 = 0. başka değer girilirse result != 0 olur.
            if (result1 != 0 && result2 != 0){ // kullanıcı 0 veya 1 girmemişse uyarı verir.
               printf("Hatali secim yaptiniz!\n");
            }
            printf("\n");
        } while (result1 != 0 && result2 != 0 ); //kullanıcı 0 veya 1 girmediği sürece tekrar sorar.
    } 
	return 0;
}