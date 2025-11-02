#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std ;
using pt = pair<double, double> ;
// is the middle point below the a--b segment?
int interplow(const pt &a, const pt &b, const pt &c) {
   double delta { c.first - a.first } ;
   if (delta == 0)
      return b.second < a.second || b.second < c.second ;
   double y { (a.second * (c.first - b.first) +
               c.second * (b.first - a.first)) / delta } ;
   return b.second < y ;
}
int main(int argc, char *[]) {
   cout << setprecision(2) << fixed ;
   int N { 0 } ;
   double budget { 0 } ;
   cin >> N >> budget ;
   vector<pt> pts ;
   pts.push_back(make_pair(0, 0)) ;
   for (int i=0; i<N; i++) {
      double cost{0}, health{0}, potency{0} ;
      cin >> cost >> health >> potency ;
      pts.push_back(make_pair(budget*health/cost, budget*potency/cost)) ;
   }
   sort(pts.begin(), pts.end()) ;
   double r {0} ;
   for (int i=1; i<pts.size(); i++)
      r = max(pts[i].first*pts[i].second, r) ;
   if (argc > 1)
      cout << "Stupid solution: " << r << endl ;
   int wr {1} ;
   for (int i=1; i<(int)pts.size(); i++) {
      while (wr > 1 && interplow(pts[wr-2], pts[wr-1], pts[i]))
         wr-- ;
      pts[wr++] = pts[i] ;
   }
   for (int i=1; i+1<wr; i++) {
      double a { pts[i+1].second - pts[i].second } ; // p2 - p1
      double b { pts[i].first - pts[i+1].first } ; // h1 - h2
      double c { a * pts[i].first + b * pts[i].second } ; // (p2-p1)*p1 + (h1-h2)*h1 
      cout<<"C "<<c<<'\n';
      cout<<"fuck "<<a<<' '<<b<<'\n';
      cout<<"fff "<<- c*c/a/b/4<<'\n';

      double bx= c / (2*a) ;
      double by = (c - a * bx) / b ; // (c-a*(c/(2a)))/b = c/(2b) = ( (p2-p1)*p1 + (h1-h2)*h1 ) / (2(h1-h2))
      
      
      cout<<bx*by<<'\n';
      if (a != 0) {
         double bx { c / (2*a) } ; // ((p2-p1)*p1 + (h1-h2)*h1) / (2(p2-p1))
         if (bx > pts[i].first && bx < pts[i+1].first) {
            cout<<"???\n";
            by = (c - a * bx) / b ; // (c-a*(c/(2a)))/b = c/(2b) = ( (p2-p1)*p1 + (h1-h2)*h1 ) / (2(h1-h2))
            r = max(r, bx*by) ;
         }
      }
   }
   cout << r << endl ;
}
