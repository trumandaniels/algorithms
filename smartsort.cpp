//Author: Truman Daniels
//CS350
//Homework 4

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void smart_sort(int my_array[], int lo, int hi)
{
  int pivot_index, pivot_num, p1, p2, temp;
  bool p1_stop, p2_stop;
  p1_stop = false;
  p2_stop = false;

  //base case
  if (lo >= hi) 
  {
    return;
  }
  
  pivot_index = lo;
  p1 = lo + 1;
  p2 = hi;

  while (p1 < p2) 
  {
    if (my_array[p1] > my_array[pivot_index]) 
    {
      //stop
      p1_stop = true;
    }
    
    if (p1_stop == false) 
    {
      p1 = p1 + 1;
    }
    
    if (my_array[p2] < my_array[pivot_index]) 
    {
      //stop
      p2_stop = true;
    }
    
    if (p2_stop == false && p1 < p2) 
    {
      p2 = p2 - 1;
    }

    if (p1_stop==true && p2_stop==true) {
      //swap
      temp = my_array[p1];
      my_array[p1] = my_array[p2];
      my_array[p2] = temp;

      //keep iterating
      p1_stop = false;
      p2_stop = false;

    }
  }
    
  if (p1 >= p2) 
  {
    if (my_array[pivot_index] > my_array[p1]) 
    {
      //swap pivot
      temp = my_array[pivot_index];
      my_array[pivot_index] = my_array[p1];
      my_array[p1] = temp;
      smart_sort(my_array, lo, p1-1);
      smart_sort(my_array, p1+1, hi); 
    }
    else 
    {
      //go back 1 and swap
      temp = my_array[pivot_index];
      my_array[pivot_index] = my_array[p1-1];
      my_array[p1-1] = temp;
      smart_sort(my_array, lo, p1-2);
      smart_sort(my_array, p1, hi); 
    }
  }
   
  
}

int main()
{
  int data, i, n;
  srand48(time(NULL));
  cin >> n;
  int data_array[n];
  cout << "\n>>> BEFORE SMART SORT <<<\n" << endl;
  cout<<"n = " << n << endl;
  for (i = 0; i < n; ++i)
  {
    data = round(1000*drand48());
    cout << data << endl;
    data_array[i] = data;
  }
  cout << "\n>>> AFTER SMART SORT <<<\n" << endl;
  smart_sort(data_array, 0, n-1);
  for (i = 0; i < n; ++i)
  {
    data = data_array[i];
    cout << data << endl;
  }
  return 0;
}
