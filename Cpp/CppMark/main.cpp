#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <climits>
#include <time.h>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

enum color{RED=1, GREEN, BLUE};

void coutBool();
void showGMKBytes();
void showTypesValues();
void calculateBMI();
void seedsOnTheBoard();
void arrayFunc();
void simpleNumbers();
void moveChar();
void showPointers();
void dynamicArray();
void showRand();
void showEnum();
double ABS(double n);
bool inputWithPointer(int *a);
int swapBetter(int &a, int &b);
int ourSum(const int p[], int length);
void ourGetString(char *str);
/*
int main()
{
//    setlocale(LC_ALL, "Russian");// change locale to russian - <clocale>
//    coutBool();
//    showGMKBytes();
//    showTypesValues();
//    calculateBMI();
//    seedsOnTheBoard();
//    arrayFunc();
//    simpleNumbers();
//    moveChar();
//    showPointers();
//    dynamicArray();
//    void showRand();
//    showEnum();
//    cout << ABS(-3) << endl;
    
/////////////////////////
//    int b = 0;
////    if( inputWithPointer(&b) ) cout << b << endl;
//    int &ss = b;// превязана к параметру и переуказать ее нельзя
//    ss = 12;
//    cout << ss << endl;
//    int a = 10;
//    swapBetter(a,b);
//    cout << "a = " << a << ", b = " << b << endl;
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    cout << ourSum(arr, 10);
/////////////////////////    
//    char str[20];
//    ourGetString(str);
//    cout << str;
    
    
    return 0;
}*/

void coutBool()
{
    int a = 1;
    int b = 2;
    cout << (a>b) << endl;// 0
    cout << (a<b) << endl;// 1
    cout << (a==b) << endl;// 0
}

void showGMKBytes()
{
    const int Size = 1024;
    int gb;
    int mb;
    int kb;
    unsigned long long bytes;
    
    cout << "input number or Gigabytes: ";
    cin >> gb;
    
    mb = gb * Size;
    kb = mb * Size;
    bytes = (unsigned long long) kb * (unsigned long long) Size;
    
    cout << "Gb:    " << gb << endl;
    cout << "Mb:    " << mb << endl;
    cout << "Kb:    " << kb << endl;
    cout << "bytes: " << bytes << endl;
}

void showTypesValues()
{
//    short b;//     2 bytes
//    int a;//       4 bytes ( 4 * 8 = 32. --- 2^32)
//    long c;//      4 bytes
//    long long d;// 8 bytes ( 8 * 8 = 64. --- 2^64 )
    
    int a,b;
    a = 23;
    b = 12;
    
    cout << "a = " << a << ". b = " << b << endl;
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;// 11, because of 23/12 = 1 and 11/12
    
    char c = 'c';// 1 byte
    
    cout << "c = \"" << c << "\"" << endl;
    cout << "int(c) = " << (int)c << endl;
    
    a = static_cast<int>(c);
    cout << "a = " << a << endl;
    
    double d = 12.342;// 8 bytes
    d = 123e-1;// 123*10^(-1) = 12.3
    cout << "d = " << (d=8./3) << endl;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << d << endl;

    float f = 10./3;
    cout.precision(12);// 12 symbols after '.'
    cout << f << endl;
}

void calculateBMI()
{
    cout << "***BMI****\n";
    
    double BMI, height, weight;
    
    cout << "Input your height in cm and weight in kg: ";
    cin >> height >> weight;
    
    height /= 100;
    BMI = weight / (height*height);
    
    cout << "Your BMI: " << BMI << endl;
}

void seedsOnTheBoard()
{
    const int N = 64;
    unsigned long long result = 1, pow = 1;
    
    for(int i=1; i<N; i++)
    {
        for(int j(0); j<i; j++)
        {
            pow *= 2;
        }
        cout << "on the first " << i << " cells we have " << result << " seeds\n";
        result += pow;
        pow = 1;
    }
}

void arrayFunc()
{
    int a[10];
    
    for(int i=0; i<10; i++)
    {
        cout << "Input " << i << " element number: ";
        if(!(cin >> a[i]))
        {
            cin.clear();
            while(cin.get() != '\n')
                cout << "Input " << i << " element number!";
        }
    }
    system("clear");
    
    // source array
    for(int i=0;i<10;i++)
    {
        cout << "a[" << i <<"] = " << a[i] << endl;
    }
    
    int max = a[0], min = a[0];
    for(int i=1;i<10;i++)
    {
        if(max < a[i])
            max = a[i];
        if(min > a[i])
            min = a[i];
    }
    cout << "max: " << max << ", min: " << min << endl;
}

void simpleNumbers()
{
    const int N = 1500;
    
    bool simpleNumbers[N+1];
    
    for(int i=2;i<N+1;i++)
    {
        simpleNumbers[i] = true;
    }
    
    for(int i=2; i<=N; i++)
    {
        if(simpleNumbers[i])
        {
            for(int j=i*i; j<=N; j+=i)
            {
                simpleNumbers[j] = false;
            }
        }
    }
    
    for(int i=2; i<=N+1; i++)
    {
        if(simpleNumbers[i])
            cout << i << endl;
    }
}

void moveChar()
{
    char str[100] = "";
    char c = '|', c1;
    int index = 0;
    
    do
    {
        cin >> c1;
        system("clear");
        if(c1 == 'D' || c1 == 'd')
        {
            for(int i(0); i<=index; i++)
                if(i != index)
                    str[i] = ' ';
                else
                    str[i] = c;
            str[index+1] = '\0';
            index++;
        }
        
        for(int i(0); i < index; i++)
        {
            cout << endl;
        }
        cout << str;
    
    }while(c1 != 'q');
}

void showPointers()
{
    int a{0};
    double b{0};
    cout << "a = " << a << ", &a = " << &a << endl;
    cout << "b = " << b << ", &b = " << &b << endl;
    
    double c[16];
    for(int i{0}; i<16; i++)
    {
        cout << "c[" << i << "] = " << &(c[i]) << endl;
    }
    
    double p = 12.5;
    double *pp = &p;
    cout << "pointer to double = " << sizeof(pp) << endl;
    cout << "*pp = " << *pp << endl;
    
    int t = 12;;// 4 bytes
    int *tp = &t;// 8 bytes
    cout << "pointer to int = " << sizeof(tp) << endl;
    cout << "*tp = " << *tp << endl;
}

void dynamicArray()
{
    int N;
    cout << "Type size of the array: " << endl;
    cin >> N;
    
    int *p = new int[N];// dynamic array
    
    for(int i{0}; i<N; i++)
    {
        *(p+i) = i+1;// ====== p[i] = i+1;
        cout << "p[" << i << "] = " << p[i] << endl;
    }
    
    delete [] p;
    
    //////////
    
    int K, M;
    cout << "Enter K,M: ";
    cin >> K >> M;
    
    int **pp = new int*[K];
    for(int i{0}; i<K; i++)
        pp[i] = new int[K];
        
    for(int i{0}; i<N; i++)
    {
        for(int j{0}; j<M; j++)
        {
            pp[i][j] = 0;// *(*(pp+i)+j) = 0
            cout << pp[i][j] << ' ';
        }
        cout << endl;
    }
        
    for(int i{0}; i<K; i++)
        delete [] pp[i];// first - delete *.
    delete [] pp;// then delete **.
}

void showRand()
{
    int a;
    
    srand(time(NULL));// чтобы при каждом запуске были РАЗНЫЕ случайные числа
    
    for(int i=0; i<10; i++)
    {
//        a = rand();// при каждом запуске случайные числа, НО ВСЕГДА ОДИНАКОВЫЕ
//        a = rand()%10 + 1;// от 1 до 10
        a = rand()%100 + 1;// от 1 до 100
        cout << a << endl;
    }
}

void showEnum()
{
    unsigned int a;
    
    do{
        cin >> a;
    }while(a == 0 || a > 3);
    
    color c = (color) a;// явно преобразовываем. Потому что типы разные
    
    switch(c)
    {
        case RED:
            //system("color 4");
            cout << "Hello" << endl;
            break;
        case GREEN:
            //system("color 2");
            cout << "Hello" << endl;
            break;
        case BLUE:
            //system("color 3");
            cout << "Hello" << endl;
            break;
    }
}

double ABS(double n)
{
    return n>0.0 ? n : -n;
}

bool inputWithPointer(int *a)
{
    if(cin >> (*a))
        return true;
    else
        return false;
}

int swapBetter(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//int ourSum(const int p[][1])// для двухмерных нужно передавать кол-во подмассивов
//int ourSum(int *p)// не понятно на что указатель(а он - на массив)
int ourSum(const int p[], int length)// лучше(для указателей НА МАССИВЫ)
{
    int sum = 0;
    
    for(int i{0}; i<length; i++)
    {
        sum += p[i];
    }
    
    return sum;
}

void ourGetString(char *str)
{
    int i{0};
    char c;
    cin.get(c);
    
    while(c != '\n')
    {
        str[i] = c;
        i++;
        cin.get(c);
    }
    
    str[i] = '\0';
}

