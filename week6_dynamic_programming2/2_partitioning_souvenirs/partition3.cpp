#include <iostream>
#include <vector>
#include<algorithm>
using std::vector;

int optimal_weight(int W, vector<int> &w) {

    sort(w.begin(),w.end());
    vector<vector<int>> vec(w.size()+1, vector<int>(W+1,0));
    /*
    for(int i=0;i<=w.size();i++)
    {
        std::cout<<"i="<<i<<"\t";
        for(int j=0;j<=W;j++)
        {
            std::cout<<vec[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    for(int i=0;i<w.size();i++)
    {
        std::cout<<w[i]<<"\t";
    }
    std::cout<<"\n";
    */
    for(int i=1;i<=w.size();i++)
    {
        for(int j=1;j<=W;j++)
        {
            int weight1=vec[i-1][j];
            int weight2=-2147483647;
            if(w[i-1]<=j)
            {
                weight2=vec[i-1][j-w[i-1]] + w[i-1];
            }
            vec[i][j]=std::max(weight1,weight2);
        }
    }
    /*
    for(int i=0;i<=w.size();i++)
    {
        std::cout<<"i="<<i<<"\t";
        for(int j=0;j<=W;j++)
        {
            std::cout<<vec[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    */
    if(W!=vec[w.size()][W])
    {
        //std::cout<<"\nW="<<W<<"vec[w.size()][W] : "<<vec[w.size()][W]<<"\n W not equal to sum\n";
        return 0;
    }


    vector<int> check(w.size(),0);
    /*
    for(int i=0;i<w.size();i++)
    {
        std::cout<<check[i]<<"  ";
    }
    std::cout<<"\n"<<w.size()<<"\n";
    */


    for(int k=0;k<3;k++)
    {
        //std::cout<<"*";
        int check_wt=0;
        int i=w.size(),j=W;
        while(check_wt!=W)
        {
            int weight1=vec[i-1][j]; //excluding item
            int weight2=-2147483647;
            if(w[i-1]<=j)
            {
                weight2=vec[i-1][j-w[i-1]] + w[i-1];  //including item
            }

            if(weight1<=weight2)  //including
            {
                if(check[i-1]==1)  //already taken
                {

                    if(weight1==weight2) //go by other way
                        i=i-1;
                    else
                        return 0;
                }
                else  //not taken
                {
                    check[i-1]=1;
                    check_wt+=w[i-1];  //occupy
                    j=j-w[i-1];
                    i=i-1;

                }
            }
            else if(weight1>weight2)
            {
                i=i-1;
            }
        }
    }
    for(int i=0;i<check.size();i++)
    {
        if(check[i]==0)
            return 0;
    }
    return 1;
}

int partition3(vector<int> &A) {

    int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum=sum+A[i];
    }
    if(sum%3!=0)
    {
        //std::cout<<"\nsum not equal to %3\n";
        return 0;
    }
    sum=sum/3;

    return optimal_weight(sum, A);


    //return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}

