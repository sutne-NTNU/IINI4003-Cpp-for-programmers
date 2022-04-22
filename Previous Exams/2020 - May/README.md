## Task 1
Create `escape()` such that:
```c++
int main(){
    cout << escape("Escape these symbols: <<&>>") << endl;
    std::string text("Escape these symbols as well: >>&<<");
    escape(text);
    cout << text << endl;
}
```
yields the following output:
```
Escape these symbols: &lt;&lt;&amp;&gt;&gt;
Escape these symbols as well: &gt;&gt;&amp;&lt;&lt;
```

## Task 2
Create the necessary classes such that:
```c++
int main() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Oreo"));
    animals.emplace_back(new Dog("Buddy"));
    animals.emplace_back(new Dog("Charlie"));
    // animals.emplace_back(new Animal()); // Should cause compilation error
    // animals.emplace_back(new Animal("Max")); // Should cause compilation error
    for (auto &animal : animals)
      cout << *animal << endl;
}
```
yields the following output:
```
Cat named Oreo
Dog named Buddy
Dog named Charlie
```
## Task 3
The following code usually runs without problems, but not always. Correct the code so it runs correctly all the time.
```c++
int main() {
    map<long, long> results;
    vector<thread> threads;
    for (long x = 43; x < 47; ++x) {
        threads.emplace_back([&results, x] {
            auto result = f(x); // Time-consuming task
            results.emplace(x, result);
        });
    }
    for (auto &thread : threads)
        thread.join();
    for (auto &pair : results)
        cout << "f(" << pair.first << ") = " << pair.second << endl;
}

```
Possible output:
```
f(43) = 701408733
f(44) = 1134903170
f(45) = 1836311903
f(46) = 2971215073
```

## Task 4
Create the necessary classes such that:
```c++
int main(){
    cout << Currency<NorwegianKrone>(1) << endl;
    cout << Currency<Euro>(1) << endl;
    cout << (Currency<NorwegianKrone>(10) +
             Currency<Euro>(10) +
             Currency<NorwegianKrone>(10)) << endl;
}
```
yields the following output:
```
€0.1
€1
€12
```

## Task 5
Add a STL-algorithm to the following code such that:
```c++
int main() {
  vector<int> vec = {2, 5, 2, 5, 1, 5, 1};
  
  // Add algorithm here
  
  for (auto &e : vec)
    cout << e << endl;
}
```
yields the following output:
```
a)
1
5
1
5
2
5
2

b)
5
2
5
1
5
1
2

c)
4
10
4
10
2
10
2
```
