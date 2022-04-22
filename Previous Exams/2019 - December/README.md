## Task 1
Create `swap` such that:
```c++
int main(){
    int a = 1, b = 2;
    swap(a, b);
    std::cout << a << ' ' << b << std::endl;
    swap(&a, &b);
    std::cout << a << ' ' << b << std::endl;
    auto c = &a;
    auto d = &b;
    swap(c, *d);
    std::cout << *c << ' ' << *d << std::endl;
}
```
yields the following output:
```
2 1
1 2
2 1
```



## Task 2
Create the classes `Degrees`, `Hot` and `Cold` such that:
```c++
int main(){
    Degrees degrees;
    cout << +degrees << endl;
    cout << -degrees << endl;
}
```
yields the following output:
```
hot
cold
```


## Task 3
Study the following code:
```c++
std::thread *a_thread;
{
  int a = 2;
  int *b = new int(2);
  a_thread = new std::thread([&a, b] {
    std::cout << (a + *b) << std::endl;
  });
}
a_thread->join();
```

### a)
What problems do you see in the code?

### b)
Replace the pointers in the code with `std::unique_ptr` pointers. Then perform the necassary alterations to the code 
to make it compile and run without problems.



## Task 4
Create the necassary classes such that:
```c++
int main(){
    vector<unique_ptr<Car>> cars;
    cars.emplace_back(new Saab<Electric>());
    cars.emplace_back(new Saab<Gasoline>());
    cars.emplace_back(new Volvo<Electric>());
    for (auto &car : cars)
      cout << *car << endl;
}
```
yields the following output:
```
Saab with electric engine
Saab with gasoline engine
Volvo with electric engine
```



## Task 5
What is printed in the following code snippets:

### a)
```c++
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
copy(v2.begin(), v2.end(), v1.begin() + 2); for (auto e : v1)
  cout << e << endl;
```

### b)
```c++
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
v1.insert(v1.end(), v2.begin(), v2.begin() + 1); for (auto e : v1)
  cout << e << endl;
```

### c)
```c++
vector<int> v1 = {1, 2, 3, 4};
cout << *find_if(v1.begin(), v1.end(), [](int e) {
  return e > 2;
}) << endl;
```

### d)
```c++
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
cout << equal(v1.begin(), v1.end(), v2.begin(), [](int e1, int e2) {
  return e1 == e2 - 2;
}) << endl;
```

### e)
```c++
vector<int> v1 = {1, 2};
vector<int> v2 = {3, 4};
cout << equal(v2.begin(), v2.end(), v1.begin(), [](int e1, int e2) {
  return e1 == e2 + 2;
}) << endl;
```
