#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

///FIND THE FIRST OCCURENCE OF FALSE(IF ANY) IN AN ARRAY OF TRUES

/*
"An array of boolean values is divided into two sections; 
the left section consists of all false and the right section consists of all true. 
Find the First True in a Sorted Boolean Array of the right section, 
i.e. the index of the first true element. 
If there is no true element, return -1."
*/

int find_boundary(std::vector<bool> arr) {
    
    //each time you calculate the mid index 
    //look at the mid index 
    //if it's true 
    //check the index to its left: 
        //if it's -1 or false, return the mid index 
        //else set the right index to mid - 1 
    
    //if it's false 
    //look at its right
    //if its right is true, return mid + 1 
    //else set the left index to mid + 1 
    
    if( arr.size() == 0 ) return -1;
    int left = 0; 
    int right = arr.size() - 1; 
    while( left <= right ){
        int mid = ( left + right ) / 2; 
        if( arr[mid] == true ){
            if( mid - 1 < 0 ) return mid; 
            else if( arr[mid-1] == false ) return mid; 
            else right = mid-1; 
        }
        else{
            if( arr[mid+1] == true ) return mid + 1; 
            else left = mid + 1; 
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

int main() {
    std::vector<bool> arr = get_words<bool>();
    int res = find_boundary(arr);
    std::cout << res << '\n';
}
