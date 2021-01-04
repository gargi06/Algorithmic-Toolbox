#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;
//using namespace std;
bool sortcol( const vector<double>& v1,
               const vector<double>& v2 ) {
 return v1[0] > v2[0];
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    /*std::cout<<"WEIGHTS   Values \n";
    for(int i=0;i<weights.size();i++)
    {
        std::cout<<weights[i]<<"   ";
        std::cout<<values[i]<<"   ";
    }
    std::cout<<"\n\n";
    */
    double value = 0.0;
    vector<vector<double> > ratio1( weights.size() , vector<double> (2));

    for(int i=0;i<weights.size();i++)
    {
        ratio1[i][0]=(double)(values[i])/weights[i];
        ratio1[i][1]=i;
    }
    //std::cout<<"WEIGHTS   Values \n";
    sort(ratio1.begin(), ratio1.end(),sortcol);


    /*
    for(int i=0;i<weights.size();i++)
    {
        std::cout<<ratio1[i][0]<<"   ";
        std::cout<<ratio1[i][1]<<"\n";
    }
    */

    int i=0;
    while(capacity!=0 && i!=weights.size())
    {
        if(capacity<=weights[ratio1[i][1]])
        {
            value+=capacity*ratio1[i][0];
            capacity=0;
            break;
        }
        else
        {
            value+=values[ratio1[i][1]];
            capacity-=weights[ratio1[i][1]];
            i++;
        }
    }


    // write your code here

    return (double)value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
