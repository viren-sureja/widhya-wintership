#include<bits/stdc++.h>
using namespace std;

float fetchDistance (float ax, float ay, float bx, float by) {
   float D = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
   return D;
}

int main() {
   // let's assume 2 points
   float pointAx = 5, pointAy = 10;
   float pointBx = 6, pointBy = 2;
   cout << fetchDistance(pointAx, pointAy, pointBx, pointBy)<<endl;
}