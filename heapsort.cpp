//g++ heapsort.cpp -lm

//Author: Truman Daniels
//CS350
//Homework 4

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int largest_child(int parent_index, int * array_of_elem)
{
}

void swap_down(int parent_index, int child_index, int * array_of_elem)
{
    int temp;
    temp = array_of_elem[parent_index];
    array_of_elem[parent_index] = array_of_elem[child_index];
    array_of_elem[child_index] = temp;
}

void perform_swap_down(int num_array_elem, int last_child_idx, int * array_of_elem)
{
    int parent, parent_idx;
    int child_idx_right, child_idx_left;

    child_idx_right = child_idx_left = -1;
    //parent of A[x] = A[floor((x-1)/2)
    parent_idx = floor(((last_child_idx-1)/2));

    //if need to swap down, swap with largest child, check if there is a larger child than parent
    //check if left child, then find
    if (num_array_elem-1 > parent_idx*2+1)
    {
        child_idx_left = parent_idx*2+1;
        cout << "left idx: " <<  child_idx_left << endl;
    }   
    //check if right child, then find
    if (num_array_elem-1 > parent_idx*2+2)
    {
        child_idx_right = parent_idx+2+2;
        cout << "right idx: " <<  child_idx_right << endl;
    }

    if ((child_idx_right == -1) & (child_idx_left == -1))   
    {
        //no children
        return;
    }
    else if (child_idx_right == -1)
    {
        //no right child
        if (array_of_elem[child_idx_left] > array_of_elem[parent_idx])
        {
            swap_down(parent_idx, child_idx_left, array_of_elem);
        }
        
    }
    else if (child_idx_left == -1)
    {
        //no left child
        if (array_of_elem[child_idx_right] > array_of_elem[parent_idx])
        {
            swap_down(parent_idx, child_idx_right, array_of_elem);
        }
        
    }
    else
    {
        //check if a swap should be made
        bool stop_swap = false;
        if ((array_of_elem[child_idx_left] > array_of_elem[parent_idx]) | (array_of_elem[child_idx_right] > array_of_elem[parent_idx]))
        {
            if (array_of_elem[child_idx_left] >= array_of_elem[child_idx_right]) //swap with larger child
            {
                //swap left child up
                cout << "left" << endl;
                swap_down(parent_idx, child_idx_left, array_of_elem);

                //continue swapping up until found root or until parent is larger
                while (stop_swap == false)
                {
                    int temp_child_idx;
                    temp_child_idx = parent_idx;
                    parent_idx = floor(((temp_child_idx-1)/2));
                    if ((array_of_elem[parent_idx] >= array_of_elem[temp_child_idx]) | (array_of_elem[parent_idx] <= 0))
                    {
                        //stop
                        stop_swap = true;
                    }
                    else
                    {
                        swap_down(parent_idx, temp_child_idx, array_of_elem);
                    }   
                }

            }
            else
            {
                //swap right child up
                cout << "right" << endl;
                swap_down(parent_idx, child_idx_right, array_of_elem);

                //continue swapping up until found root or until parent is larger
                while (stop_swap == false)
                {
                    int temp_child_idx;
                    temp_child_idx = parent_idx;
                    parent_idx = floor(((temp_child_idx-1)/2));
                    if ((array_of_elem[parent_idx] >= array_of_elem[temp_child_idx]) | (array_of_elem[parent_idx] <= 0))
                    {
                        //stop
                        stop_swap = true;
                    }
                    else
                    {
                        swap_down(parent_idx, temp_child_idx, array_of_elem);
                    }   
                }
            }
        }
    }

}

void make_heap_swap_down(int num_array_elem, int * array_of_elem)
{
    //check if only one elem in array
    cout << "num_array_elem" << num_array_elem << endl;
    if ((num_array_elem == 1) | (num_array_elem == 0))
    {
        return;
    }
    
    //find last parent of last element in array
    //to do this, I find last child
    int curr_child_idx;
    curr_child_idx = num_array_elem-1;
    perform_swap_up(num_array_elem, curr_child_idx, array_of_elem);
    //then find that parent and swap if neccesary
    //continue moving left and swapping until root
    /*
    while (curr_child_idx >=1)
        perform_swap_up(num_array_elem, curr_child_idx, array_of_elem);
        curr_child_idx-=1;

    */
    
};


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
    cout << "Current array before creating heap" << endl;
    for (int i =0; i < n; i++) {
        cout << "Index: " << i << " Value: " << num_array[i] << endl;
    }

    //display heap
    cout << "Current array after creating heap" << endl;
    make_heap_swap_down(n, num_array);
    for (int i =0; i < n; i++) {
        cout << "Index: " << i << " Value: " << num_array[i] << endl;
    }

    //display after heap sort
    cout << "Current array after heap sort" << endl;
    //heap_sort(n, num_array, 0, n-1);
    for (int i =0; i < n; i++) {
        cout << "Index: " << i << " Value: " << num_array[i] << endl;
    }

};
