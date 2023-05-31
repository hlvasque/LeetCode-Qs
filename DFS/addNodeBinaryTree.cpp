#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, stoi, string, to_string
#include <vector> // vector

//INSERT NODE INTO BINARY SEARCH TREE

//https://algo.monster/problems/insert_into_bst

/*
"Insert Into BST

Given the root node of a valid BST and a value to insert into the tree, 
return a new root node representing the valid BST with the addition of the new item. 
If the new item already exists in the binary search tree, do not insert anything.

You must expand on the original BST by adding a leaf node. 
Do not change the structure of the original BST."
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

void insert_binary_tree( Node<int>* root, int val ){
    
    if( root == nullptr ) return; 
    else if( root->val == val ) return; 
    else if( root->val > val ){
        if( root->left == nullptr ){
            Node<int>* newNode = new Node(val); 
            root->left = newNode; 
            return; 
        }
        else insert_binary_tree( root->left, val ); 
    }
    else{
        if( root->right == nullptr ){
            Node<int>* newNode = new Node(val); 
            root->right = newNode; 
            return; 
        }
        else insert_binary_tree( root->right, val ); 
    }
    
}


Node<int>* insert_bst(Node<int>* bst, int val) {
    // WRITE YOUR BRILLIANT CODE HERE
    
    if( bst == nullptr ){
        Node<int>* newNode = new Node( val ); 
        bst = newNode; 
    }
    else{
        insert_binary_tree( bst, val ); 
    }
    
    return bst; 
    //return nullptr;
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

template<typename T, typename F>
void format_tree(Node<T>* node, F f, std::vector<std::string>& out) {
    if (node == nullptr) {
        out.emplace_back("x");
        return;
    }
    out.emplace_back(f(node->val));
    format_tree(node->left, f, out);
    format_tree(node->right, f, out);
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::string> bst_vec = get_words<std::string>();
    auto bst_it = bst_vec.begin();
    Node<int>* bst = build_tree<int>(bst_it, [](auto s) { return std::stoi(s); });
    int val;
    std::cin >> val;
    ignore_line();
    Node<int>* res = insert_bst(bst, val);
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}
