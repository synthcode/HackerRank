// Zig Zag Sequence
// "You can modify at most three lines in the given code"
void findZigZagSequence(vector < int > a, int n){
    sort(a.begin(), a.end());
    int mid = (n + 1)/2 - 1;   // int mid = (n + 1)/2;
    swap(a[mid], a[n-1]);

    int st = mid + 1;
    int ed = n - 2;   // int ed = n - 1;
    while(st <= ed){
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1;   // ed = ed + 1;
    }
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

// Tower Breakers
int towerBreakers(int n, int m) {
    int won{0};
    
    int maxDivisor{1};
    int numDivisors{0};
    for (int i{1}; i <= m; ++i) {
        if (m % i == 0) {
            maxDivisor = i;
            ++numDivisors;
        }
    }
    
    if (numDivisors >= 2 && n % 2 == 1) {
        won = 1;
    }
    else {
        won = 2;
    }
    
    // cout << maxDivisor << ' ' << numDivisors << ' ' << won << '\n';
    return won;
}

// Caesar Cipher
string caesarCipher(string s, int k) {
    int stringSize{static_cast<int>(s.size())};

    for (int i{0}; i < stringSize; ++i) {
        char c{s.at(i)};
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') + k) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + k) % 26 + 'A';
        }
        s.at(i) = c;
    }

    return s;
}

// Palindrome Index (Mock Test)
int palindromeIndex(string s) {
    int stringSize{static_cast<int>(s.size())};
    if (stringSize == 1) return -1;        
    
    bool isPalindrome{true};
    int badIndex1{-1};
    int badIndex2{-1};
    for (int i{0}; i < (stringSize + 1)/2; ++i) {
        if (s.at(i) != s.at(stringSize - 1 - i)) {
            isPalindrome = false;
            badIndex1 = i;
            badIndex2 = stringSize - 1 - i;
            break;
        }
    }
    if (isPalindrome) return -1;
    
    string newS = s;
    newS.erase(badIndex1, 1);
    stringSize = static_cast<int>(newS.size());
    isPalindrome = true;
    for (int i{0}; i < (stringSize + 1)/2; ++i) {
        if (newS.at(i) != newS.at(stringSize - 1 - i)) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) return badIndex1;
    
    newS = s;
    newS.erase(badIndex2, 1);
    stringSize = static_cast<int>(newS.size());
    isPalindrome = true;
    for (int i{0}; i < (stringSize + 1)/2; ++i) {
        if (newS.at(i) != newS.at(stringSize - 1 - i)) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) return badIndex2;

    return -1;
}