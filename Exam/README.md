## Task 1
Lag funksjonene spaces_to_underscore1() og spaces_to_underscore2() som skal endre alle mellomrom (’ ’) i en streng til underscore (’_’), og lag funksjonen spaces_to_underscore_or_character() som i tillegg har muligheten til å endre mellomrom til et spesifisert tegn i stedet for.

Kildekoden:
```c++
cout << spaces_to_underscore1("this is a string") << endl;

string str("this is a string");
spaces_to_underscore2(str);
cout << str << endl;

char chr('+');
cout << spaces_to_underscore_or_character("this is a string", &chr) << endl;
cout << spaces_to_underscore_or_character("this is a string", nullptr) << endl;
cout << spaces_to_underscore_or_character("this is a string") << endl;
```
skal gi utskriften:
```
this_is_a_string
this_is_a_string
this+is+a+string
this_is_a_string
this_is_a_string
```

## Task 2
I en butikk har matvarer 15 % merverdiavgift (mva), mens andre varer har 25 % mva. Lag klassene Butikk, Vare og MatVare slik at følgende kildekode:
```c++
Butikk butikk;
butikk.varer.emplace_back(new MatVare("NTNU-nistepakken", 5));
butikk.varer.emplace_back(new Vare("NTNU-koppen", 10));
for (auto &v : butikk.varer) {
  std::cout << v->navn << ", "
            << v->antall << ", "
            << v->mva() << std::endl;
}
```
gir utskriften:
```
NTNU-nistepakken, 5, 0.15
NTNU-koppen, 10, 0.25
```


## Task 3
Lag klassen ThreadSafeGrowingList der en skal kunne legge til og lese tall på en trådsikker måte. Det skal ikke være mulig å slette tall fra listen, og dette kan du utnytte når du implementerer medlemsfunksjonene add(int) og for_each(const std::function<void(int)> &).  ThreadSafeGrowingList skal for eksempel kunne brukes slik:
 ```c++
 ThreadSafeGrowingList list;
 vector<thread> threads;
 for (int i = 0; i < 10; ++i) {
   threads.emplace_back([&list, i] {
     list.add(i);
   });
 }
 list.for_each([](int value) {
   cout << value << endl;
   this_thread::sleep_for(200ms);
 });
 for (auto &thread : threads)
   thread.join();
 ```
Mulig utskrift:
```
1
0
3
2
5
7
6
8
4
9
```



## Task 4
Farger blir ofte oppgitt ved hjelp av 3 elementer; rød, grønn og blå. Disse elementene ligger enten i området fra og med 0 til og med 1, eller fra og med 0 til og med 255.

Lag klassen RGB slik at kildekoden:
```c++
{
  RGB<double> rgb(0.5);
  std::cout << rgb << std::endl;
  std::cout << rgb + 0.3 << std::endl;
  std::cout << rgb + 0.3 + RGB<double>(0.5, 0.1, 0.1) << std::endl;
}
{
  RGB<int> rgb(130);
  std::cout << rgb << std::endl;
  std::cout << rgb + 60 << std::endl;
  std::cout << rgb + 60 + RGB<int>(100, 30, 30) << std::endl;
}
```
gir utskriften:
```
(0.5, 0.5, 0.5)
(0.8, 0.8, 0.8)
(1, 0.9, 0.9)
(130, 130, 130)
(190, 190, 190)
(255, 220, 220)
```


## Task 5
Lag nødvendige klasser og funksjoner slik at følgende kildekode:
```c++
vector<int> vec = {1, 2, 3};

vector<int> vecMultipliedBy2 = vec | Map([](int e) { return e * 2; });
cout << vecMultipliedBy2 << endl;

vector<int> vecFiltered = vec | Filter([](int e) { return e % 2 == 1; });
cout << vecFiltered << endl;
```
gir utskriften:
```
{2, 4, 6}
{1, 3}
```
