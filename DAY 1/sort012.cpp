#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int l = 0, m = 0, r = n - 1;
   while(m <= r){
      if(arr[m] == 0){
         swap(arr[m], arr[l]);
         l += 1;
         m += 1;
      }else if(arr[m] == 1){
         m += 1;
      }else{
         swap(arr[m], arr[r]);
         r -= 1;
      }
   }
}