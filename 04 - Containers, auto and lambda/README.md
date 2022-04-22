# Containers, auto and lambda
## Task 1
Opprett en vektor av double. Legg inn fem tall (behøver ikke leses inn.)

Prøv ut medlemsfunksjonene front() og back(). De returnerer hver et element, og de har ingen argumenter.

Bruk emplace() til å sette inn et tall etter det første elementet. Skriv ut resultatet av front() etterpå.

Prøv ut STL-algoritmen find(). Den tar tre argumenter: start, slutt og søkeverdi. De to første er iteratorer til søkeintervallet. Funksjonen returnerer en iterator til den funne verdien, hvis den finnes. Hvis den ikke finnes, er returverdien lik end()-iteratoren. Lag et if-uttrykk som sjekker om resultatet av find() er vellykket eller ikke, og dersom resultatet var vellykket, skriv ut den funne verdien.

### Result

```console
front(): 1.01
back(): 5.01
front() after emplace: 1.01
Element found: 6.99
Elements in vector: 1.01 6.99 2.01 3.01 4.01 5.01
```


## Task 2
Ta utgangspunkt i [eksempelkoden](https://gitlab.com/ntnu-iini4003/gtkmm-example) og lag eit lite program som slår sammen inntastet fornavn og etternavn når du klikker på en knapp. Knappen skal kun være sensitiv når både fornavn og etternavn er tastet inn, og grået ut ellers (ikke sensitiv). Sett også tittel på vinduet.


### Result

![](images/demo.gif)
