#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    //std::cout<<current<<"\n";
    return current % m;
}
long long pisanoPeriod(long long m){
    int previous=0;
    int current = 1;

    for(long long i = 0; i < m*m; ++i) {
        /*previous, current \
        = current, (previous + current) % m */

        long long tmp_previous = previous;
        previous=current;
        current=(tmp_previous + current)%m;
        // A Pisano Period starts with 01
        if (previous == 0 && current == 1)
        {
            //std::cout<<i;
            return i+1;
        }
    }
}
long long get_fibonacci_huge(long long n, long long m) {
    long long period=pisanoPeriod(m);
    //std::cout<<"period : "<<period<<"\n";
    if (n%period <= 1)
        return n%m;


    long long previous = 0;
    long long current  = 1;

    for(long long i = 2; i <= n%period; i++) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        //std::cout<<current<<"\n";
        current=current%m;
    }

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';

    std::cout << get_fibonacci_huge(n, m) << '\n';
}
