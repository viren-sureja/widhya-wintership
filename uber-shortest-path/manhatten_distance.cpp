#include<bits/stdc++.h>
using namespace std;

int distance_sum(int arr[], int n) {
   sort(arr, arr + n);
   int res=0, sum=0;
   for(int i=0;i<n;i++) {
      res += (arr[i] * i - sum);
      sum += arr[i];
      // cout << res << " ";
   }
   // cout << endl;
   return res;
}

int totalDistanceSum(int x[],int y[],int n) {
   return distance_sum(x, n) + distance_sum(y, n);
}

int main() {
   int arr1[] = { 5, 4, 6, 7 };
   int arr2[] = { 3, 4, 2,1 };
   cout << totalDistanceSum( arr1, arr2 , 4);
}
