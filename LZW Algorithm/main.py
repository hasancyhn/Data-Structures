# HASAN CEYHAN 20010011091 LZW ALGORITMASI
import time

veriGirisi = ""
gelenKarakter = ''
karakterTutmaSozlugu = {}
birinciSayac = 0
stringYapimiz = ""

baslangic = time.perf_counter()


def sozlukOlusturmaFonksiyonu(karakterTutmaSozlugu):
    global birinciSayac
    for i in range(len(veriGirisi)):
        if veriGirisi[i] in karakterTutmaSozlugu.values():
            print(veriGirisi[i] + " Zaten sozlukte mevcut!")
        else:
            karakterTutmaSozlugu[birinciSayac] = veriGirisi[i]
            birinciSayac += 1

def sozlukteKarakterBulmaFonksiyonu(bulunacakKarakter):
    for key, value in karakterTutmaSozlugu.items():
        if value == bulunacakKarakter:
            return key

def lzwAlgorithm():
    global stringYapimiz, birinciSayac, gelenKarakter
    ikinciSayac = 0
    while ikinciSayac < len(veriGirisi):
        gelenKarakter = veriGirisi[ikinciSayac]

        if stringYapimiz + gelenKarakter in karakterTutmaSozlugu.values():
            stringYapimiz += gelenKarakter
            ikinciSayac += 1
        else:
            key = sozlukteKarakterBulmaFonksiyonu(stringYapimiz)
            print(str(key) + " (" + karakterTutmaSozlugu[key] + ")")
            karakterTutmaSozlugu[birinciSayac] = stringYapimiz + gelenKarakter
            stringYapimiz = gelenKarakter
            birinciSayac += 1
            ikinciSayac += 1
    key = sozlukteKarakterBulmaFonksiyonu(stringYapimiz)
    print(str(key) + " (" + karakterTutmaSozlugu[key] + ")")


veriGirisi = input("Lutfen veriyi giriniz: ")
sozlukOlusturmaFonksiyonu(karakterTutmaSozlugu)
print("\nBaslangic Sozluk Yapisi Asagidaki Gibidir:")
print(karakterTutmaSozlugu)

# KAZANILAN BYTE ALANI
print('\nSıkıstırılmadan Onceki Karakter Sayisi: ' +  str(len(veriGirisi)))
karakterSayisi = 0
for anahtar, deger in karakterTutmaSozlugu.items():
    karakterSayisi += len(str(anahtar)) + len(str(deger))
print("Sıkıstırıldıktan Sonraki Karakter Sayisi:", karakterSayisi)

print("LZW Algoritmasindan Sonra Kazanilan BYTE Alani: " + (str(int(len(veriGirisi)) - karakterSayisi)) + "\n")

lzwAlgorithm()
print("\nYeni Sozluk Yapisi Asagidaki Gibidir:")
print(karakterTutmaSozlugu)

bitis = time.perf_counter()
toplamZaman = bitis-baslangic
print(f"\nToplam Harcanan Sure: ",toplamZaman,"saniye\n")
