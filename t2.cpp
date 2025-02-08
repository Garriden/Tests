#include <vector>
#include <unordered_set>
#include <iostream>


int countPeaks (vector<double> values) {

    int top_peaks = 0; 
    int down_peaks = 0;
    int size = values.size();

    for (int ii = 1; ii < size - 1; ++ii) { 
        if((values[ii-1] - values[ii] <= -5) && 
           (values[ii+1] - values[ii] <= -5) ) {
               ++top_peaks;
        }


        if((values [ii-1] - values[ii] >= 5) && 
           (values [ii+1] - values[ii] >= 5) ) {
                ++down_peaks;
        }


    return top_peaks + down_peaks;
}