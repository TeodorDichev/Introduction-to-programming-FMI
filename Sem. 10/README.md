## Динамична памет

### Стекова памет/Stack
- predefined size/предварително определен размер(~2MB)
- паметта се заделя ПО ВРЕМЕ на компилацията на програмата (compile time).
- паметта се освобождава/трие/маркира като свободна автоматично - при излизането от scope-а, в който е дефинирана.

```c++
int value = 5; //allocated on the Stack
```

### Динамична памет/Heap
- паметта се заделя по време на изпълнение на програмата(runtime).
- Масиви и обекти без предварително да е известна големината.

```c++
int value = 5; //allocated on the Stack
int* p = &value; //pointer allocated on the Stack
int* hValue = new int; //hValue is allocated on the stack
                       //allocates 1 integer on the Heap
*hValue = 5; //dereference to give value to the Heap allocated int
```

![Memory](images/Memory.png)

#### Оператор **new**
- Връща указтел към началото на паметта

```c++
new int[n];  //n НЕ е задължително да е константа!
```

- Заделянето на динамична памет е много "бавна" операция!!
- Динамична памет НЕ се трие автоматично.

#### Оператор delete/delete[]
Oсвобождава/маркира като свободна динамична памет! <br />

```c++
void f()
{
  int x = 40; //allocated on the Stack
  char ch[2] = {'a', 'b'}; //allocated on the Stack
  int* ptr = new int[3]; //allocated on the Heap
}
```

![Memory-Leak-example](images/exampleMemoryLeak.png)

След приключването на функцията ще се изчисти паметта в стека, но НЕ и паметта в heap-а. <br />
За това ние трябва ръчно да я маркираме като свободна. <br />

```c++
void f()
{
  int x = 40;
  char ch[2] = {'a', 'b'};
  int* ptr = new int[3];
  delete[] ptr; //free allocated Heap memory
}
```
## Memory leak (Утечка на памет)
Утечка на памет имаме тогава, когато дадена памет в heap-а бъде заделена, но не бъде зачистена след това. При дълга работа на дадена програма и често възникване на утечки, паметта в heap-a може да свърши! Когато пренасочим указател без да зачистим блока heap памет, към който е сочил, имаме гарантирана утечка!

```c++
int *createArr(int size) {
    return new int[size];
}

int main() {
    int *ptr = new int[5]; //this memory is leaked!

    ptr = createArr(4); //we move the pointer without deleting the memory it was pointing to
    delete[] ptr;
}
```