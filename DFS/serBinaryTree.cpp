#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, stoi, string, to_string
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

void serDFS( Node<int>* root, std::vector<std::string>& myVec ){
    if( root == nullptr ) {
        
        myVec.push_back("x"); 
        return; 
    }
    myVec.push_back(std::to_string(root->val)); 
    serDFS(root->left, myVec); 
    serDFS(root->right, myVec); 
}

std::string serialize(Node<int>* root) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::string> myVec; 
    serDFS(root, myVec); 
    
    std::string temp = ""; 
    for( int i = 0; i < myVec.size(); i ++ ){
        temp += myVec[i]; 
        temp += ","; 
    }
    //std::cout << temp << std::endl;
    
    return temp;  
}

Node<int>* desDFS( std::vector<std::string> stringVec, int& index, Node<int>*& root ){
    if( index >= stringVec.size() -1) return nullptr; 
    
    else if( stringVec[index] == "x" ){
        index += 1; 
        //if( root == nullptr ) root = nullptr; 
        return nullptr; 
    }
    
    Node<int>* newNode = new Node( std::stoi( stringVec[index] ) ); 
    if( root == nullptr ) root = newNode; 
    index += 1; 
    newNode->left = desDFS( stringVec, index, root ); 
    newNode->right = desDFS( stringVec, index, root );
    return newNode; 
    
}

Node<int>* deserialize(std::string root) {
    std::vector<std::string> myVec; 
    std::string temp = ""; 
    for( int i = 0; i < root.size(); i ++ ){
        if( root[i] == ',' ){
            myVec.push_back( temp ); 
            temp = ""; 
        }
        else temp += root[i]; 
    }
    Node<int>* head = nullptr; 
    int index = 0; 
    Node<int>* tempo = desDFS( myVec, index, head ); 
    return head; 
    
}

template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
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
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
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
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    Node<int>* res = deserialize(serialize(tree));
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}
