#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector

//https://algo.monster/problems/lowest_common_ancestor_on_bst

//find the first common ancestor of a pair of nodes

/*
"Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), 
find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
that has both p and q as descendants (where we allow a node to be a descendant of itself).” "

*/

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

int find_ancestor( Node<int>* root, int p, int q ){

    if( root == nullptr ) return -1; //these values do not exist in the BST
    if( root->val == p || root->val == q ) return root->val; 
    if( root->val < p && root->val > q || root->val > p && root->val < q ) return root->val; 
    else{
        if( root->val > p && root->val > q ) find_ancestor( root->left, p, q ); 
        else find_ancestor( root->right, p, q ); 
    }
    
}


int lca_on_bst(Node<int>* bst, int p, int q) {
    // WRITE YOUR BRILLIANT CODE HERE
    
    return find_ancestor( bst, p, q );
    //return 0;
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::string> bst_vec = get_words<std::string>();
    auto bst_it = bst_vec.begin();
    Node<int>* bst = build_tree<int>(bst_it, [](auto s) { return std::stoi(s); });
    int p;
    std::cin >> p;
    ignore_line();
    int q;
    std::cin >> q;
    ignore_line();
    int res = lca_on_bst(bst, p, q);
    std::cout << res << '\n';
}
