// Plus Minus
void plusMinus(vector<int> arr) {
    int posCount{0};
    int negCount{0};
    int zeroCount{0};
    
    for (int i: arr) {
        if (i > 0) ++posCount;
        else if (i < 0) ++negCount;
        else ++zeroCount;
    }
    
    int arrSize = static_cast<int>(arr.size());
    cout << fixed << std::setprecision(6);
    cout << static_cast<double>(posCount)/arrSize << '\n';
    cout << static_cast<double>(negCount)/arrSize << '\n';
    cout << static_cast<double>(zeroCount)/arrSize << '\n';
}

// Mini-Max Sum
void miniMaxSum(vector<int> arr) {
    unsigned long long minSum{~static_cast<unsigned long long>(0)};
    unsigned long long maxSum{0};
    unsigned long long sum{0};
    int arrSize{static_cast<int>(arr.size())};
    
    for (int i{0}; i < arrSize; ++i) {
        for (int j{0}; j < arrSize; ++j) {
            if (j == i) continue;
            sum += arr.at(j);
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
        if (sum < minSum) {
            minSum = sum;
        }
        sum = 0;
    }
    
    std::cout << minSum << ' ' << maxSum << '\n';
}

// Time Conversion
string timeConversion(string s) {
    assert(s.size() == 10);
    string ampm{};
    ampm += s.at(8);
    ampm += s.at(9);
    cout << ampm << '\n';
    s.resize(8);
    cout << s << '\n';
    cout << s.at(0) << '\n';
    cout << s.at(1) << '\n';
    
    if (ampm == "AM") {
        if (s.at(0) == '1' && s.at(1) == '2') {
            s.at(0) = '0';
            s.at(1) = '0';
        }
        else {
            // do nothing
        }
    }
    else if (ampm == "PM") {
        if (s.at(0) == '1' && s.at(1) == '2') {
            // do nothing
        }
        else if(s.at(0) == '1' && s.at(1) == '0') {
            s.at(0) = '2';
            s.at(1) = '2';
        }
        else if(s.at(0) == '1' && s.at(1) == '1') {
            s.at(0) = '2';
            s.at(1) = '3';
        }
        else if(s.at(0) == '0' && s.at(1) == '8') {
            s.at(0) = '2';
            s.at(1) = '0';
        }
        else if(s.at(0) == '0' && s.at(1) == '9') {
            s.at(0) = '2';
            s.at(1) = '1';
        }
        else if(s.at(0) == '0' && s.at(1) >= '1' && s.at(1) <= '7') {
            s.at(0) = '1';
            s.at(1) += 2;
        }
        else s = nullptr;
    }
    else s = nullptr;
 
    return s;
}

// Find the Median (Mock Test)
int findMedian(vector<int> arr) {
    int arrSize{static_cast<int>(arr.size())};
    std::sort(arr.begin(), arr.end());
    return arr.at((arrSize - 1)/2);
}