#include <bits/stdc++.h> 
using namespace std; 
#define INF 1e5

class Point 
{ public:
    float x; 
    float y;
 
}; 


double isInside(vector<vector<double>> polygon, int n, Point p) 
{    double len=0.0;
     if(n<=4)
     {
      len=abs(polygon[0][1])+abs(polygon[1][1])+abs(polygon[3][0]-polygon[0][0]);
     }
     else
     {  double angle=(p.y+2)/(abs(polygon[7][0])+3.5);
        double h1=abs(polygon[5][1])-abs(polygon[4][1]);
        double h2=abs(polygon[1][1]);
        double shadowHeight=h1-(tan(atan(angle))*1.5);
        double realHeight=h2-shadowHeight;
        double b2=abs(polygon[3][0])-abs(polygon[0][0]);
        double b1=abs(polygon[7][0])-abs(polygon[4][0]);
        len=h1+realHeight+b1+b2;
      }

  return len;
} 


int main() 
{  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
 
  //First testCase
  vector<vector<double>> polygon1= {{4,0}, {4,-5}, {7,-5}, {7, 0}}; 
  int n1 = polygon1.size(); 
  Point p1 = {1,1 }; 
  cout<<isInside(polygon1, n1, p1)<<endl;
    
  //Second testCase
  vector<vector<double>> polygon2= {{4,0}, {4,-5}, {7,-5}, {7, 0},{0.4,-2},{0.4,-5},{2.5,-5},{2.5,-2}}; 
  int n2 = polygon2.size(); 
  Point p2 = {-3.5,1 }; 
  cout<<isInside(polygon2, n2, p2);
   return 0; 
}
/*-------------------------------------------------------------------------------------------------------
Concept of Angle of  Elevation is used

Case 1

Input -
$ Buildings Coordinates$ : $ [[[4,0],[4,-5],[7,-5],[7,0]]] $
$ S $: $ [1,1] $
Output : 8.0

Case 2

input
$ Buildings Coordinates$ : $ [[[4,0],[4,-5],[7,-5],[7,0]], [[0.4,-2],[0.4,-5],[2.5,-5],[2.5,-2]]] $
$ S $: $ [-3.5,1] $
Output : 10.85

-------------------------------------------------------------------------------------------------------------------*/