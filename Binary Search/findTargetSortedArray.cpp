#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

//FIND TARGET IN SORTED ARRAY 
//RETURN -1 IF IT DOES NOT EXIST IN THE ARRAY

int binary_search(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    if( arr.size() == 0 ) return -1; 
    int left = 0; 
    int right = arr.size() -1;
    while( left <= right ){
        int mid = ( left + right ) / 2; 
        if( arr[mid] == target ) return mid; 
        else if( arr[mid] < target ){
            left = mid + 1; 
        }
        else if( arr[mid] > target ){
            right = mid - 1; 
        }
    }
    return -1;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = binary_search(arr, target);
    std::cout << res << '\n';
}
