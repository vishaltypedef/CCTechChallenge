#include <bits/stdc++.h> 
using namespace std; 
#define INF 1e5

class Point 
{ public:
    float x; 
    float y;
 
}; 

bool checkSegment(Point p1, Point p2, Point p3) 
{ 
  if (p2.x <= max(p1.x, p3.x) && p2.x >= min(p1.x, p3.x) && p2.y <= max(p1.y, p3.y) && p2.y >= min(p1.y, p3.y)) 
    {return true;
    }
  return false; 
} 

int orientation(Point p1, Point p2, Point p3) 
{ 
  int val = (p2.y - p1.y) * (p3.x - p2.x) -  (p2.x - p1.x) * (p3.y - p2.y); 

  if (val == 0) return 0;  
  return (val > 0)? 1: 2; 


bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
  int o1 = orientation(p1, q1, p2); 
  int o2 = orientation(p1, q1, q2); 
  int o3 = orientation(p2, q2, p1); 
  int o4 = orientation(p2, q2, q1); 
  if (o1 != o2 && o3 != o4) 
    return true; 
  if (o1 == 0 && checkSegment(p1, p2, q1)) return true;  
  if (o2 == 0 && checkSegment(p1, q2, q1)) return true; 
  if (o3 == 0 && checkSegment(p2, p1, q2)) return true;  
  if (o4 == 0 && checkSegment(p2, q1, q2)) return true; 
  return false; 
} 


bool isInside(Point polygon[], int n, Point p) 
{ 
  if (n < 3) return false; 
  Point extend = {INF, p.y}; 
 
  int cnt = 0, i = 0; 
  do
  { 
    int next = (i+1)%n;  
    if (doIntersect(polygon[i], polygon[next], p, extend)) 
    { 
      if (orientation(polygon[i], p, polygon[next]) == 0) 
      return checkSegment(polygon[i], p, polygon[next]); 

      cnt++; 
    } 
    i = next; 
  } while (i != 0); 

  if(cnt%2 == 1) 
    return true;
  else
    return false;
  
} 


int main() 
{  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
 
  //First testCase
  Point polygon1[] = {{1, 0}, {8, 3}, {8, 8}, {1, 5}}; 
  int n1 = sizeof(polygon1)/sizeof(polygon1[0]); 
  Point p1 = {3, 5 }; 
  if(isInside(polygon1, n1, p1)) 
    cout << "Yes"<<endl;
  else
    cout << "No \n"<<endl; 

  //Second  testCase
  Point polygon2[] = {{-3, 2}, {-2,-0.8}, {0,1.2}, {2.2,0},{2,4.5}}; 
  int n2 = sizeof(polygon2)/sizeof(polygon2[0]); 
  Point p2 = {0,0}; 
  if(isInside(polygon2, n2, p2)) 
    cout << "Yes"<<endl;
  else
    cout << "No \n"<<endl;
  
   return 0; 
}
/*-------------------------------------------------------------------------
Programming language- C++14
Concept of Odd-Even Algorithm is used
The above Algorithm works in all basic situations, whether the polygon is convex or not 
and whether the polygon has holes or not.

Case 1 :
Input -
$ Polygon$ : $ [[1,0], [8,3], [8,8], [1,5]] $
$ P $: $ [3,5] $
Output : True

Case 2 :

input
$ Polygon $ : $ [[-3,2], [-2,-0.8], [0,1.2], [2.2,0], [2,4.5]]$
$ P $ : $[0,0]$
Output : False

---------------------------------------------------------------------------*/