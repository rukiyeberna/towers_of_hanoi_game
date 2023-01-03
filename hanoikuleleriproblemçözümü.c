#include <stdio.h>
#include <stdlib.h>
#include <time.h>//problem çözümü ekrana hamle yazdırmak için
int hanoikuleleri(int diskSayisi,char baslangicKonumu, char bitisKonumu, char araCubuk);
double minhamlesayisi(double x);
int main()
{
    clock_t baslangic,bitis;// zamaný tutmak için

    int diskSayisi;

    printf(" Kullanilacak disk sayisini giriniz: ");
    scanf("%d",&diskSayisi);

    baslangic=clock();

    printf("\n\n Cozum icin yapilmasi gereken hamlelerin sirasi: \n\n");
    hanoikuleleri(diskSayisi, 'A', 'C', 'B');

    bitis=clock();

    printf(" disk sayisi : %d hamle sayisi : %lld gecen sure :%.3f\n",diskSayisi,(long long int)minhamlesayisi( diskSayisi),((double)(bitis-baslangic)/CLOCKS_PER_SEC));//ms
    minhamlesayisi( diskSayisi);

    printf("kullanilan bilgisayarin donanimsal ozellikleri:\n");
    printf("Cihaz modeli ACER NITRO AN515-57 :\n");
    printf("ISLEMCÝ: 11th Gen Intel(R) Core(TM) i7-11800H @ 2.30GHz   2.30 GHz:\n");
    printf("RAM 16 GB:\n");
    printf("SSD 512 GB:\n");
     return 0;
}
 int hanoikuleleri(int diskSayisi, char baslangicKonumu, char bitisKonumu, char araCubuk) //recurcive fonksiyonlar kullanýlarak çözülen kýsým
 {   //simple case
     if (diskSayisi==1)
     {
        printf("   En üstteki diski %c'dan %c'ye getir.\n",baslangicKonumu, bitisKonumu);
        return ;
     }
     else
     {
       hanoikuleleri(diskSayisi-1, baslangicKonumu, araCubuk, bitisKonumu);//disk sayisi-1 tanesi oynatýlýr sonrasýnda en altta kalan disk sonra yine disk sayisi-1
       hanoikuleleri(1,baslangicKonumu,bitisKonumu,araCubuk);
       hanoikuleleri(diskSayisi-1, araCubuk, bitisKonumu, baslangicKonumu);
     }
 }
 double  minhamlesayisi(double x )
{
    return  pow(2.0,x)-1; //x burada adým sayýsýný, 2^x-1 ise hamle sayýsýný verir.
}
