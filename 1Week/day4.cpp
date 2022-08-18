// Grid Challenge
string gridChallenge(vector<string> grid) {
    string YesNo{""};
    int rowSize{static_cast<int>(grid.size())};
    int columnSize{static_cast<int>( (grid.at(0)).size() )};
    
    for (int i{0}; i < rowSize; ++i) {
        sort((grid.at(i)).begin(), (grid.at(i)).end());
    }
    
    string column{""};
    string sortedColumn{""};
    bool pass{true};
    for (int j{0}; j < columnSize; ++j) {
        for (int i{0}; i < rowSize; ++i) {
            column.push_back((grid.at(i)).at(j));
        }
        sortedColumn.assign(column);
        sort(sortedColumn.begin(), sortedColumn.end());
        if (sortedColumn != column) {
            pass = false;
            break;
        }
        column.clear();
    }
    
    if (pass) {
        YesNo.assign("YES");
    }
    else {
        YesNo.assign("NO");
    }
    
    return YesNo;
}

// Recursive Digit Sum
int superDigit(string n, int k) {
    long long stringSize{static_cast<long long>(n.size())};
    
    long long sum{0};
    for (long long i{0}; i < stringSize; ++i) {
        string temp{n.at(i)};
        int digit{stoi(temp)};
        sum += digit;
    }
    sum *= k;
    
    while (true) {
        stringstream ss{};
        ss << sum;
        string str{ss.str()};
        long long stringSize{static_cast<long long>(str.size())};
        if (stringSize == 1) break;
        sum = 0;
        for (long long i{0}; i < stringSize; ++i) {
            string temp{str.at(i)};
            int digit{stoi(temp)};
            sum += digit;
        }
    }
    
    return sum;
}

// New Year Chaos
void minimumBribes(vector<int> q) {
    int vecSize{static_cast<int>(q.size())};
    bool chaotic{false};
        
    for (int i{0}; i < vecSize; ++i) {
        int difference{q.at(i) - (i + 1)};
        if (difference > 2) {
            chaotic = true;
            break;
        }
    }
    
    int prevSwaps{0};
    int swaps{0};
    if (!chaotic) {
        while (true) {
            for (int i{0}; i < vecSize - 1; ++i) {
                if (q.at(i) > q.at(i + 1)) {
                    int temp{q.at(i)};
                    q.at(i) = q.at(i + 1);
                    q.at(i + 1) = temp;
                    swaps += 1;
                }
            }
            if (prevSwaps == swaps) {
                break;
            }
            prevSwaps = swaps;
        }
    }

    int numberOfBribes{0};
    if (!chaotic) {
        numberOfBribes = swaps;
        cout << numberOfBribes << '\n';
    }
    else {
        cout << "Too chaotic" << '\n';
    }
}

// Truck Tour (Mock Test)
int truckTour(vector<vector<int>> petrolpumps) {
    int N{static_cast<int>(petrolpumps.size())};
    int selectedPump{0};
    
    for (int i{0}; i < N; ++i) {
        int distanceSpare{0};
        bool isRoute{true};
        for (int j{i}; j < N + i; ++j) {
            int jIndex{j % N};
            distanceSpare += (petrolpumps.at(jIndex)).at(0);
            distanceSpare -= (petrolpumps.at(jIndex)).at(1);
            if (distanceSpare < 0) {
                isRoute = false;
                break;
            }
        }
        if (isRoute) {
            selectedPump = i;
            break;
        }
    }
    
    return selectedPump;
}