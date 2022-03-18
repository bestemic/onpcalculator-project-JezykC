# **Kalkulator w odwrotnej notacji polskiej.**
<br>
<div style="text-align: right"><b>Przemysław Pawlik</b></div>

## **1. Wstęp**
Kalkulator wykonany jako projekt zaliczeniowy podczas przedmiotu Język C na który uczęszczałem w roku akademiskim 20/21.

----------
<br>

## **1. Opis programu**
Reprezentacja działania kalkulatora ONP przy użyciu operacji na stosie.
<br>
Zasada działania programu sprowadza się do kilku prostych akcji: <br>
1. Z wejścia std lub pliku czytamy kolejne słowa (ciągi znaków oddzielone odstępami)
2. Jeśli słowo jest liczbą, to wrzucamy na stos, jako liczbę typu `double`
3. Każde inne słowo to operator, który wykonujemy

----------
<br>

## **2. Dostęne operacje**

### **Arytmetyczne**
* **add** - dodawanie dwóch liczb
* **sub** - odejmowanie dwóch liczb
* **mul** - mnożenie dwóch liczb
* **div** - dzielenie dwóch liczb
* **pow** - podnoszenie liczb do potęgi
* **neg** - obliczanie liczby przeciwnej
* **abs** - obliczanie wartości bezwzględnej
* **sin** - obliczanie sinusa 
* **cos** - obliczanie cosinusa 
* **log** - obliczanie logarytmu 
* **exp** - obliczanie eksponenty 
* **min** - wybranie mniejszego elementu
* **max** - wybranie większego elementu 
* **gamma** - obliczanie wartości funkcji gamma
* **bc** - obliczanie współczynnika dwumianowego

### **Na stosie**
* **=** - wypisanie wartości ze szczytu stosu
* **dup** - duplikacja liczby na szczycie stosu
* **exch** - zamiana dwóch liczb na szczycie stosu
* **pstack** - wypisanie zawartości stosu

### **Inne**
* **?** lub **h** lub **help** - wyświetlanie dostęnych komend i operatorów
* **q** lub **quit** - zakończenie programu

----------
<br>

## **3. Obsługa błędów**
Błędem jest każde słowo, które nie jest liczbą, ani zdefiniowanym operatorem.

**Obsługa**
* Wypisanie zawartości stosu i komunikat o błędzie
* Zignorowanie błędnego słowa

----------
<br>

## **4. Sposób uruchomienia**
Aby uruchomić program należy go skompilować:<br>
`g++ main.cpp stack.cpp stack.hpp kalkulator.exe`<br>

Następnie uruchomić komendą:<br>
`./kalkulator.exe`<br>
Lub gdy podajemy dane z pliku:<br>
`./kalkulator.exe plik.txt`<br>

Przykładowe użycie kalkulatora:
```
7 0.5 add 
2.2 0.2 
sub mul
=
```
Powyższe instrukcje obliczą wartość wyrażenia `(7+0.5)*(2.2-0.2)`

----------
<br>

## **5. Literatura**
https://pl.wikipedia.org/wiki/Odwrotna_notacja_polska

----------
<br>

## **6. Wymagania**
**C++**<br>
**System operacyjny Linux**<br>