#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//  Template declaration
template <typename T> void quickshort(vector<T>& vec, size_t start, size_t end);
template <typename T> void swap(vector<T>& vec, size_t first, size_t second);

int main()
{
    vector<double> double_values{10.3, 7.4, 19.0, 2};
    vector<char> letters {'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f'};

    // Print the double_values vector before sorting
    cout<<"Double vector before sorting"<<endl;
    for (size_t i{0}; i<double_values.size();++i)
    {
        cout<<setw(6)<<double_values[i];
    }
    cout<<endl;

    quickshort(double_values, 0, double_values.size() - 1); // Sort the double_values vector

    // Print the sorted double_values vector
    cout<<"Double vector after sorting"<<endl;
    for (size_t i{0}; i<double_values.size();++i)
    {
        cout<<setw(6)<<double_values[i];
    }
    cout<<endl;

    // Print the letters vector before sorting
    cout<<"letters vector before sorting"<<endl;
    for (size_t i{0}; i<letters.size();++i)
    {
        cout<<setw(6)<<letters[i];
    }
    cout<<endl;

    quickshort(letters, 0, letters.size() - 1); // Sort the letters vector

    //Print the sorted letters vector
    cout<<"letters vector after sorting"<<endl;
    for (size_t i{0}; i<letters.size();++i)
    {
        cout<<setw(6)<<letters[i];
    }
}

//  Template definition
template <typename T>
void quickshort(vector<T>& vec, size_t start, size_t end)
{
    if (!(start < end))
    return;
    // Choose middle address to partition set
    swap(vec, start, (start + end) / 2); // Swap middle address with start
    // Check values against chosen value
    size_t current {start};
    for (size_t i {start + 1} ; i <= end ; i++)
    {
        if (vec[i] < vec[start]) // Is value less than chosen value?
        swap(vec, ++current, i); // Yes, so swap to the left
    }
    swap(vec, start, current); // Swap the chosen value with last in
    if (current > start) quickshort(vec, start, current - 1); // Sort left subset if exists
    if (end > current + 1) quickshort(vec, current + 1, end); // Sort right subset if exists
}

template <typename T>
void swap(vector<T>& vec, size_t first, size_t second)
{
    T temp{vec[first]};
    vec[first] = vec[second];
    vec[second] = temp;
}
