
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <chrono>
#define N 100
using namespace std;

int lookup_table[N];
const int NIL = -1;

long long unsigned int fib(long long unsigned int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}


void init()
{
    std::fill_n(lookup_table, N, NIL);
}


int fib_mem(int n) {
    if(lookup_table[n] == NIL) {
        if(n <= 1)
            lookup_table[n] = n;
        else
            lookup_table[n] = fib_mem(n-1) + fib_mem(n-2);
    }
    return lookup_table[n];
}

int main(){
    init();
    long unsigned int n;
    long unsigned int memresult;
    cin>>n;

    cout<<n<<endl;

    cin.get();
    
    auto start = chrono::high_resolution_clock::now();

    int result = fib(n);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop -start);

    cout<<"Recursion: "<<result<< "time: "<<duration.count()<<endl;
    
     start = chrono::high_resolution_clock::now();
    long long unsigned int f[n];
    f[0] =0;
    f[1] =1;

    for(long unsigned int i=2;i<=n;i++){
        f[i] =f[i-1] + f[i-2];
    }
        

    stop = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::milliseconds>(stop -start);

    cout<<"dynamic programming Tabulation: "<< f[n] << " time:" << duration.count()<<endl;

    start = chrono::high_resolution_clock::now();
    memresult = fib_mem(n);
    stop = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::milliseconds>(stop-start);

    cout<< "dynamic programming Memoization: "<<memresult<< " Time: "<<duration.count()<<endl;


    cin.get();

    return EXIT_SUCCESS;
}
