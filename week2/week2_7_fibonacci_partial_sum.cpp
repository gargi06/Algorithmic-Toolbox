#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
int fibonacci_sum(long long n)
{
    if (n%60 <= 2)
        return n%60;

    int sum[60];
    sum[0]=0;
    sum[1]=1;
    sum[2]=2;

    for (int i=3 ; i<= n%60; i++) {
        if(2*sum[i-1]>=sum[i-3]){
            sum[i]=2*sum[i-1]-sum[i-3];
            sum[i]=sum[i]%10;
        }
        else
        {
            sum[i]=10+2*sum[i-1]-sum[i-3];
            sum[i]=sum[i]%10;
        }
        /*sum[i]=2*sum[i-1]-sum[i-3];
        sum[i]=sum[i]%10;
        if(sum[i]<0)
            sum[i]=-sum[i];*/
    }


    return sum[n%60];
}
long long get_fibonacci_partial_sum(long long from, long long to) {

    int last_to=fibonacci_sum(to);

    if(from==0)
        return last_to;

    int last_from=fibonacci_sum(from-1);
    if(last_to<last_from)
    {
        return (long long)(10+last_to - last_from);
    }
    else
        return (long long)(last_to - last_from);


}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
    //std::cout << fibonacci_sum(to) << '\n';
    //std::cout << fibonacci_sum(from-1) << '\n';

}
