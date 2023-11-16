//Author: Truman Daniels

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void merge_sort(int n, int (&my_array)[], int lo, int hi)
{
    
    if (lo == hi) {
        return;
    }
    
    int temp_array[n];

    //spawn children                    
    int half_way = floor((lo+hi)/2)+1; 
  
    merge_sort(n, my_array, lo, half_way-1); 
    merge_sort(n, my_array, half_way, hi); 

    //process merging into temp array
    int lo_temp = lo; //0
    int half_temp = half_way; //1

    for(int i=lo; i<hi+1; i++) {
        if (my_array[lo_temp] < my_array[half_temp]) {
            temp_array[i] = my_array[lo_temp];
            lo_temp = lo_temp+1;

            //left array finished first, copy everything over from right array
            if (lo_temp >= half_way) { 
                int j = i;
                while (half_temp < hi+1) {
                    j++;
                    temp_array[j] = my_array[half_temp];
                    half_temp++;
                }
                break; //after copying everything over from right array, stop running the loop
            }
        }
        else if (my_array[lo_temp] > my_array[half_temp]) {
            temp_array[i] = my_array[half_temp];
            half_temp = half_temp+1;
          
            //right array finished first, copy everything over from left array
            if (half_temp > hi) { 
                int j = i;
                while (lo_temp < half_way) {
                    j++;
                    temp_array[j] = my_array[lo_temp];
                    lo_temp++;
                }
                break;
            }
        }
    }

    //copy temp values into my_array
    for(int k=lo; k<hi+1; k++) {
        my_array[k] = temp_array[k];
    }
    return;
}


int main()
{
    int n;
    cin >> n;
    int num_array[n];
    int temp_int;

    //inserting into array
    for (int i = 0; i < n; i++) {
        cin >> temp_int;
        num_array[i] = temp_int;
    }

    //display current array
    cout << "Current array after loading" << endl;
    for (int i =0; i < n; i++) {
        cout << "Index: " << i << " Value: " << num_array[i] << endl;
    }

    cout << "Current array after merge sort" << endl;
    merge_sort(n, num_array, 0, n-1);
    for (int i =0; i < n; i++) {
        cout << "Index: " << i << " Value: " << num_array[i] << endl;
    }

}
