// Merge two sorted linked lists
SinglyLinkedListNode* createList(int d) {
    SinglyLinkedListNode* h = new SinglyLinkedListNode(d);
    h->data = d;
    h->next = nullptr;
    return h;
}
 
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head{nullptr};
    SinglyLinkedListNode* hptr{nullptr};
    
    if (head1->data < head2->data) {
        head = createList(head1->data);
        hptr = head;
        head1 = head1->next;
    }
    else {
        head = createList(head2->data);
        hptr = head;
        head2 = head2->next;
    }
    
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            SinglyLinkedListNode* tmp{createList(head1->data)};
            hptr->next = tmp;
            head1 = head1->next;
            hptr = hptr->next;
        }
        else {
            SinglyLinkedListNode* tmp{createList(head2->data)};
            hptr->next = tmp;
            head2 = head2->next;
            hptr = hptr->next;
        }
    }
    
    while (head1 != nullptr && head2 == nullptr) {
        SinglyLinkedListNode* tmp{createList(head1->data)};
        hptr->next = tmp;
        head1 = head1->next;
        hptr = hptr->next;
    }
    
    while (head1 == nullptr && head2 != nullptr) {
        SinglyLinkedListNode* tmp{createList(head2->data)};
        hptr->next = tmp;
        head2 = head2->next;
        hptr = hptr->next;
    }
    
    return head;
}

// Queue using Two Stacks
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string line{""};
    std::getline(std::cin, line);
    int numberOfQueries = stoi(line);

    std::deque<int> queue{};
    for (int i{0}; i < numberOfQueries; ++i) {
        std::getline(std::cin, line);
        std::string sQuery{line.substr(0, 1)};
        int query{stoi(sQuery)};
        if (query == 1) {
            std::string sEnqueue = line.substr(2);
            int enqueue{stoi(sEnqueue)};
            queue.push_back(enqueue);
        }
        else if (query == 2) {
            queue.pop_front();
        }
        else if (query == 3) {
            std::cout << queue.front() << '\n';
        }
    }

    return 0;
}


// Balanced Brackets
string isBalanced(string s) {
    string yesNo{"YES"};
    string stack{""};
    int sSize{static_cast<int>(s.size())};
    
    if (sSize % 2 == 1) {   // sSize > 0
        yesNo = "NO";
        return yesNo;
    }
    
    for (int i{0}; i < sSize; ++i) {
        switch(s.at(i)) {
            case '{':   // fallthrough
            case '[':   // fallthrough
            case '(':
                stack.push_back(s.at(i));
                break;
            case '}':
                if (stack.back() == '{') {
                    stack.pop_back();
                    break;
                }
                else {
                    yesNo = "NO";
                    return yesNo;
                }
            case ']':
                if (stack.back() == '[') {
                    stack.pop_back();
                    break;
                }
                else {
                    yesNo = "NO";
                    return yesNo;
                }
            case ')':
                if (stack.back() == '(') {
                    stack.pop_back();
                    break;
                }
                else {
                    yesNo = "NO";
                    return yesNo;
                }
            default:
                break;
        }
    }
    
    if (stack.size() != 0) {
        yesNo = "NO";
    }
    
    return yesNo;
}


// Pairs (Mock Test)
int pairs(int k, vector<int> arr) {
    int arrSize{static_cast<int>(arr.size())};
    int pairCount{0};
    int innerStart{1};
    
    std::sort(arr.begin(), arr.end());
    for (int i{0}; i < arrSize - 1; ++i) {
        int first{arr.at(i)};
        for (int i{innerStart}; i < arrSize; ++i) {
            int second{arr.at(i)};
            if (abs(first - second) == k) {
                ++pairCount;
            }
            else if (abs(first - second) > k) {
                break;
            }
        }
        ++innerStart;
    }
    return pairCount;
}