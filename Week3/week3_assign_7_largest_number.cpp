/*#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
*/
#include <bits/stdc++.h>
using namespace std;
string largest_number(vector<string> a) {
  //write your code here

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
  /*
  string result;

  int max_len = 0 ;
  for(int i=0;i<a.size();i++)
  {
    if(a[i].length()>max_len)
        max_len=a[i].length();
  }
  //std::cout<<max_len;
  vector<vector<string> > vec( a.size() , vector<string> (2));


  for(int i=0;i<a.size();i++)
  {
    int num_zeroes=max_len-a[i].length();
    //std::cout<<"\nnumzeroes="<<num_zeroes<<"\n";
    char con[100];
    strcat(con,a[i]);
    std::cout<<a[i].size()<<"\n";
    /*for(int z=0;z<a[i].size();z++)
    {

        std::cout<<"z="<<z<<"\t"<<a[i][z]<<"##";
    }
    std::cout<<"\n";
    //std::cout<<"\ncon1="<<con<<"\n";
    //std::cout<<"begin";
    char zero[5]="0";
    for(int j=a[i].length();j<max_len;j++)
    {
        std::cout<<"\nj="<<j<<"\n";
        strcat(con,zero);
        std::cout<<"con[j] = "<<con[j]<<"\n";
    }
    //std::cout<<"end1";
    //std::cout<<"con="<<con<<"\n";
    con[max_len]='\0';
    std::cout<<"con[2]="<<con[2]<<"\n";
    //std::cout<<"con len = "<<con.length()<<"\n";
    std::cout<<"\ncon2="<<con<<"\n";
    //std::cout<<"end2";
    vec[i][0]=con;
    //std::cout<<"end3";
    vec[i][1]=num_zeroes+'0';
  }
  //std::cout<<"\nnextloop\n";
  for(int i=0;i<a.size();i++)
  {
    std::cout<<vec[i][0]<<"\t"<<vec[i][1]<<"\n";
  }

  return result;
  */
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
