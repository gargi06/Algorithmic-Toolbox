#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
vector<int> dynamic_sequence(int n) {

    std::vector<int> sequence;
    //sequence.push_back(1);
    vector<int> track;
    track.push_back(0);
    track.push_back(0);
    for(int i=2;i<=n;i++)
    {
      track.push_back(2147483647);   //INT_MAX=2147483647
    }
    for(int i=2;i<=n;i++)
    {
        int min1=2147483647,min2=2147483647,min3=2147483647;
        if(i%3==0)
        {
            min1=track[i/3];
        }
        if(i%2==0)
        {
            min2=track[i/2];
        }
        if(i-1>=1)
        {
            min3=track[i-1];
        }
        int intermediate_min=std::min(min1,min2);
        int final_min=std::min(intermediate_min,min3);
        if(final_min != 2147483647)
            track[i]=final_min+1;
    }
    int i=n;
    while(i>=1)
    {
       int min1=2147483647,min2=2147483647,min3=2147483647;
        if(i%3==0)
        {
            min1=track[i/3];
        }
        if(i%2==0)
        {
            min2=track[i/2];
        }
        if(i-1>=1)
        {
            min3=track[i-1];
        }
        int intermediate_min=std::min(min1,min2);
        int final_min=std::min(intermediate_min,min3);
        if(final_min != 2147483647)
            track[i]=final_min+1;
        if(final_min==min1)
        {
            sequence.push_back(i);
            i=i/3;
        }

        else if(final_min==min2)
        {
            sequence.push_back(i);
            i=i/2;
        }
        else
        {
            sequence.push_back(i);
            i=i-1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dynamic_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
