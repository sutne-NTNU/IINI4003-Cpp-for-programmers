# Basic C++
## Asignment
Du skal jobbe med et program som leser inn temperaturer for en periode og teller opp antallet i tre intervaller:
- under 10 grader 
- mellom 10 og 20 grader (inkludert 10 og 20 grader) 
- over 20 grader.  

 Lengden på perioden setter du som en konstant: const int length = 5;

### Task A

Les inn temperaturene (datatype double) fra brukeren. Bruk ikke tabeller, og lag heller ikke egne funksjoner.

### Task B

 Les inn temperaturene fra en fil og lagre dem i en tabell før du begynner opptellingen. Innlesingen fra fil skal ligge i en funksjon med følgende prototyp (deklarasjon):
 
 void read_temperatures(double temperatures[], int length);
 
 Denne skal du sette opp foran main(), mens funksjonsdefinisjonen skal plasseres etter main() i filen din:
 
 void read_temperatures(double temperatures[], int length) {
    // her plasserer du koden i funksjonen, vi sier at vi definerer funksjonen
 }
 Du kaller funksjonen på følgende måte fra main():
 
 read_temperatures(temperatures, length);
 Funksjonen skal åpne filen, lese inn temperaturene og lagre dem i tabellen temperatures, og endelig lukke filen.
 
 ## Results
 
 ### Task A
```console
Du skal skrive inn 5 temperaturer.
Temperatur 1: 5
Temperatur 2: 10
Temperatur 3: 15
Temperatur 4: 20
Temperatur 5: 25

Antall under 10: 1
Antall mellom 10 og 20: 3
Antall over 20: 1
```
 
 ### Task B
```console
 Det var skrevet 9 temperaturer
 
 Antall under 10: 2
 Antall mellom 10 og 20: 3
 Antall over 20: 4
 ```
 