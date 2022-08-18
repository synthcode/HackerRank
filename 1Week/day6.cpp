// Simple Text Editor
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string text{""};
    stack<string> stk{};
    string inputLine{""};
    int deleteNum{0};
    
    std::getline(cin, inputLine);
    int numberOfOperations{stoi(inputLine)};
    
    for (int i{0}; i < numberOfOperations; ++i) {
        std::getline(cin, inputLine);
        int operation{stoi(inputLine)};
        switch (operation) {
            case 1:
                stk.push(text);
                text.append(inputLine.substr(2));
                break;
            case 2:
                stk.push(text);
                deleteNum = stoi(inputLine.substr(2));
                if (deleteNum >= text.size()) deleteNum = text.size();
                text.erase(text.size() - deleteNum, deleteNum);
                break;
            case 3:
                std::cout << text.at(stoi(inputLine.substr(2)) - 1) << '\n';
                break;
            case 4:
                text = stk.top();
                stk.pop();
                break;
            default:
                break;
        }
    }
    
    return 0;
}

// Lego Blocks
int legoBlocks(int n, int m) {   // height, width
    // Let P(n, m) be all possible wall permutations
    const int modNum{1000000007};   // prevents overflow
   
    // n = 1
    // By inspection, P(1, 1) = 1, P(1, 2) = 2, P(1, 3) = 4, P(1, 4) = 8
    std::array<long long, 1001> pnm{0, 1, 2, 4, 8};    
    // For m > 4, P(1, m) = P(1, m-1) + P(1, m-2) + P(1, m-3) + P(1, m-4)
    for (int i{5}; i <= m; ++i) {
        pnm.at(i) = ( pnm.at(i - 1) + pnm.at(i - 2)
                       + pnm.at(i - 3) + pnm.at(i - 4) ) % modNum;
    }
        
    // For n > 1, P(n, m) = P(1, m)^n
    for (int i{1}; i <= m; ++i) {
        long long pnmBase{pnm.at(i)};
        for (int j{2}; j <= n; ++j) {
            pnm.at(i) *= pnmBase;
            pnm.at(i) %= modNum;
        }
    }
    
    // B(n, m) = Sum_{i = 1}^{m-1} G(n, i) * P(n, m-i)
    long long gni{};
    long long bni{};
    std::array<long long, 1001> coeffs{};
    for (int i{1}; i < m; ++i) {
        gni = pnm.at(i);
        for (int j{1}; j < i; ++j) {
            gni -= coeffs.at(j) * pnm.at(i - j);
            gni %= modNum;
        }
        coeffs.at(i) = gni;
        bni += gni * pnm.at(m - i);
        bni %= modNum;
    }
    
    // Answer = P(n, m) - B(n, m)
    long long answer{(pnm.at(m) - bni) % modNum};
    if (answer < 0) answer += modNum;
    
    return static_cast<int>(answer);
}

// Jesse and Cookies
int cookies(int k, vector<int> A) {
    std::sort(A.begin(), A.end());
    std::reverse(A.begin(), A.end());
    int initialSize{static_cast<int>(A.size())};
    std::deque<int> B{};

    for (int i{0}; i < initialSize; ++i) {
        int aSize{static_cast<int>(A.size())};
        int bSize{static_cast<int>(B.size())};
        int aLast{aSize - 1};
        int bLast{bSize - 1};
        int mixed{0};
        
        if (aSize == 0) {
            if (bSize == 0) return -2;   // error
            else if (B.at(bLast) >= k) return i;
            else if (bSize == 1) return -1;
            else {
                mixed = B.at(bLast) + 2 * B.at(bLast - 1);
                int oldBFront{B.front()};
                B.push_front(mixed);
                // assert(B.front() >= oldBFront);
                B.pop_back();
                B.pop_back();
            }
        }
        else if (aSize == 1) {
            if (bSize == 0) {
                if (A.at(0) >= k) return i;
                else return -1;
            }
            else if (bSize == 1) {
                if (A.at(0) >= k && B.at(0) >= k) return i;
                else {
                    if (B.at(0) < A.at(0)) mixed = B.at(0) + 2 * A.at(0);
                    else mixed = A.at(0) + 2 * B.at(0);
                    int oldBFront{B.front()};
                    B.push_front(mixed);
                    // assert(B.front() >= oldBFront);
                    A.pop_back();
                    B.pop_back();
                }
            }
            else {
                if (A.at(0) >= k && B.at(bLast) >= k) return i;
                else {
                    int tmp1{};
                    int tmp2{};
                    if (B.at(bLast) < A.at(0)) tmp1 = B.at(bLast) + 2 * A.at(0);
                    else tmp1 = A.at(0) + 2 * B.at(bLast);
                    tmp2 = B.at(bLast) + 2 * B.at(bLast - 1);
                    if (tmp1 <= tmp2) {
                        mixed = tmp1;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        A.pop_back();
                        B.pop_back();
                    }
                    else {
                        mixed = tmp2;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        B.pop_back();
                        B.pop_back();
                    }   
                }
            }
        }
        else {
            if (bSize == 0) {
                if (A.at(aLast) >= k) return i;
                else {
                    mixed = A.at(aLast) + 2 * A.at(aLast - 1);
                    B.push_front(mixed);
                    A.pop_back();
                    A.pop_back();
                }
            }
            else if (bSize == 1) {
                if (A.at(aLast) >= k && B.at(0) >= k) return i;
                else {
                    int tmp1{};
                    int tmp2{};
                    if (A.at(aLast) < B.at(0)) tmp1 = A.at(aLast) + 2 * B.at(0);
                    else tmp1 = B.at(0) + 2 * A.at(aLast);
                    tmp2 = A.at(aLast) + 2 * A.at(aLast - 1);
                    if (tmp1 <= tmp2) {
                        mixed = tmp1;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        A.pop_back();
                        B.pop_back();
                    }
                    else {
                        mixed = tmp2;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        A.pop_back();
                        A.pop_back();
                    }
                }
            }
            else {
                if (A.at(aLast) >= k && B.at(bLast) >= k) return i;
                else {
                    int tmp1{};
                    int tmp2{};
                    int tmp3{};
                    if (A.at(aLast) < B.at(bLast)) {
                       tmp1 = A.at(aLast) + 2 * B.at(bLast);
                    }
                    else tmp1 = B.at(bLast) + 2 * A.at(aLast);
                    tmp2 = A.at(aLast) + 2 * A.at(aLast - 1);
                    tmp3 = B.at(bLast) + 2 * B.at(bLast - 1);
                    if (tmp1 <= tmp2 && tmp1 <= tmp3) {
                        mixed = tmp1;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        A.pop_back();
                        B.pop_back();
                    }
                    else if (tmp2 <= tmp1 && tmp2 <= tmp3) {
                        mixed = tmp2;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        A.pop_back();
                        A.pop_back();
                    }
                    else {
                        mixed = tmp3;
                        int oldBFront{B.front()};
                        B.push_front(mixed);
                        // assert(B.front() >= oldBFront);
                        B.pop_back();
                        B.pop_back();   
                    }
                }
            }
        }
    }

    return -2;   // should not reach here
}

// Breadth First Search: Shortest Reach (Mock Test)
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    std::vector<int> rVec(n, -1);
    std::queue<int> Q{};
    std::vector<bool> usedVec(n, false);
    std::list<vector<int>> listEdges(edges.begin(), edges.end());
        
    Q.push(s);
    usedVec.at(s - 1) = true;
    int level{};
    int dist{};
    int levelNodes{};
    int nextLevelNodes{1};
    while (Q.size() != 0) {
        if (levelNodes == 0) {
            ++level;
            dist = 6 * level;
            levelNodes = nextLevelNodes;
            nextLevelNodes = 0;
        }
        
        int v{Q.front()};
        std::list<vector<int>>::iterator listIter{listEdges.begin()};
        std::set<int> toPush{};
        while (listIter != listEdges.end()) {
            int a{(*listIter).at(0)};
            int b{(*listIter).at(1)};
            if (a == v) {
                toPush.insert(b);
                listIter = listEdges.erase(listIter);
            }
            else if (b == v) {
                toPush.insert(a);
                listIter = listEdges.erase(listIter);
            }
            else {
                ++listIter;
            }
        }
        
        std::set<int>::iterator setIter{toPush.begin()};
        while (setIter != toPush.end()) {
            int index{*setIter};
            ++setIter;
            if (usedVec.at(index - 1)) continue;
            else {
                Q.push(index);
                usedVec.at(index - 1) = true;
                rVec.at(index - 1) = dist;
                ++nextLevelNodes;
            }
        }
        
        --levelNodes;
        Q.pop();
    }
    
    rVec.erase(rVec.begin() + s - 1);
    return rVec;
}