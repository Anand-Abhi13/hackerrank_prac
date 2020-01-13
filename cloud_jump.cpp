#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
      int n;
          cin>>n;
          int arr[n];
          for(int i=0;i<n;i++)
          {
              cin>>arr[i];
          }
    int pos=0, jump=0;
    int j =0;
    while(j<n-1)
    {

            if(arr[j+2]==0)
            {
                pos=j+2;
                jump++;

            }

            if(arr[j+2]!=0&&arr[j+1]==0)
            {
                pos=j+1;
                jump++;
                j=j+1;
            }
j=pos;

}
    cout<<jump;
return 0;
}
