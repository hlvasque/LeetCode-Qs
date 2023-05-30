#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

/*
"A balanced binary tree is defined as a tree such that either it is an empty tree, 
or all its subtree are balanced and has a height difference of at most 1.

In that case, given a binary tree, determine if it's balanced.

Parameter: A binary tree.
Result: A boolean representing whether the tree given is balanced."
*/

int max_height( Node<int>* root ){
    if( root == nullptr ) return 0; 
    int left = 1 + max_height( root->left ); 
    int right = 1 + max_height( root->right ); 
    return std::max( left, right ); 
}

bool balanced( Node<int>* root ){
    if( root == nullptr ) return true; 
    int left = max_height( root->left ); 
    int right = max_height( root->right ); 
    if( left - right < 2 && left - right > -2 ){
        return true && balanced( root->left ) && balanced( root->right ); 
    }
    else return false; 
}

bool is_balanced(Node<int>* tree) {
    
    return balanced( tree ); 
    
    //dummy return: return false; 
}

// this function builds a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
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
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    bool res = is_balanced(tree);
    std::cout << std::boolalpha << res << '\n';
}
