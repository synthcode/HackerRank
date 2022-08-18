// Tree: Preorder Traversal
void preOrder(Node* root) {
    std::cout << root->data << ' ';
    if (root->left != nullptr) {
        preOrder(root->left);
    }
    if(root->right != nullptr) {
        preOrder(root->right);
    }
}

// Tree: Huffman Decoding
void decode_huff(node* root, string s) {
    node* n{root};
    
    for (int i{0}; i < s.size(); ++i) {
        if (s.at(i) == '0') {
            n = n->left;
        }
        else {
            n = n->right;
        }
        if (static_cast<bool>(n->data)) {
            std::cout << n->data;
            n = root;
        }
    }
}

// No Prefix Set
void noPrefix(vector<string> words) {
    std::set<string> prefixSet{};
    std::set<string> wordSet{};
    
    for (string word: words) {        
        unsigned long numCount{prefixSet.count(word)};
        if (numCount != 0) {
            cout << "BAD SET" << '\n';
            cout << word << '\n';
            return;
        }
        
        string prefix{};
        for (char c: word) {
            prefix += c;
            prefixSet.insert(prefix);
            unsigned long numCount{wordSet.count(prefix)};
            if (numCount != 0) {
                cout << "BAD SET" << '\n';
                cout << word << '\n';
                return;
            }
        }
        
        wordSet.insert(word);
    }
    
    cout << "GOOD SET" << '\n';
}
