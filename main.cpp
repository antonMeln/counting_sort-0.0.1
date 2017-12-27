#include <iostream>
#include <sstream>
using namespace std;

bool read( int &n, int *mas)
{ 
  string str;
  getline(cin,str);
  istringstream stream(str);
  bool f =true;
  
  for (int i =0; i < n; i++){
    if (!(stream >> mas[i]) && mas[i]>255) {
      f =false; 
      break;
      
    }
  }
  return f;
} 
void CountingSort(int *a,  int n)
{   int c[256] = {0};
    
    for (int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < 256; j++) {
        while (c[j] != 0) {
            a[i] = j;
            c[j]--;
            i++;
        }
    }
}
int main()
{  
    
    int n,i;
    int *a= new int[n];
    string str;
    getline(cin,str);
    istringstream stream(str);
    
    if (stream >> n){
      if (read(n,a)){
        CountingSort( a, n);
 
        for (int i = 0; i < n; i++){
           cout << a[i] << " ";
        }
      }  
      else cout <<"An error has occurred while reading numbers";
    } 
    delete[] a;
   return 0;
   
}
