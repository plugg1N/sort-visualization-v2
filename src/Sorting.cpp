#include "Headers/Sorting.h"


void Sorting::bubble_sort(std::vector<double> array) {
    int i,j,t;
    size_t size = array.size();

    for(i=0; i < size; i++)
    {
        for(j=0; j < size-i; j++)
        {
            if(array[j]>array[j+1])
            {
                t=array[j];
                array[j]=array[j+1];
                array[j+1]=t;

                capture_frame(array);
            }
        }
    }
}