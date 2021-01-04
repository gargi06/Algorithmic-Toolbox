#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum,i;
  for(i=1;i<=n;i++)
  {
    sum=(i*(i+1))/2;
    //std::cout<<"sum = "<<sum<<"\t"<<"i="<<i<<"\n";
    if(sum<n)
    {
        //std::cout<<"if"<<i<<"\n";
        continue;
    }
    else if(sum==n)
    {
        for(int j=1;j<=i;j++)
        {
            summands.push_back(j);
        }
        break;
    }
    else
    {
        //std::cout<<"else"<<i<<"\n";
        for(int j=1;j<i-1;j++)
        {
            summands.push_back(j);
        }
        summands.push_back(i-1+(i-(sum-n)));
        break;
    }
  }

  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
