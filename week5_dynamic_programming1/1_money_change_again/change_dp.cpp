#include <iostream>
#include<vector>
using std::vector;

int get_change(int m) {
    //write your code here
    //storing coin denominations
    vector<int> coin_denominations;
    coin_denominations.push_back(1);
    coin_denominations.push_back(3);
    coin_denominations.push_back(4);

    vector<int> track;
    track.push_back(0);    //track[0]=0;
    for(int i=1;i<=m;i++)
    {
        track.push_back(2147483647);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<coin_denominations.size();j++)
        {
            if(coin_denominations[j]<=i)
            {
                int coins=track[i-coin_denominations[j]];
                if(coins != 2147483647 && (coins+1)<track[i])
                    track[i]=coins+1;
            }
            else
                break;

        }
    }
    return track[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
