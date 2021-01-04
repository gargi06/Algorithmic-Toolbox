#include <iostream>
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
//as pisano period for 10 is 60
//same is for sum of fibonacci numbers
//i.e (sum of n fibonacci numbers)%10 's period is 60
//this happens because sum of last didgits of (sum of n fibonacci numbers) for 0-59 is 260
//which ends with zero
//hence the cycle goes on repeating i.e period = 60
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

int main() {
    long long n = 0;

    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);

    /*
    int sum=0;
    for(int i=0;i<60;i++)
    {
        sum=sum+fibonacci_sum(i);
        //std::cout << fibonacci_sum(i)<<"\n";
    }
    std::cout << sum<<"\n";
    */
    std::cout << fibonacci_sum(n);

}
