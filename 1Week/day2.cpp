// Lonely Integer
int lonelyinteger(vector<int>& a) {
    int vecASize{static_cast<int>(a.size())};
    std::sort(a.begin(), a.end());
    
    int uniqueInt{a.at(0)};
    if (vecASize == 1) return uniqueInt;
    else if (a.at(vecASize - 1) != a.at(vecASize - 2)) return a.at(vecASize - 1);
    
    for (int i{1}; i < vecASize; ++i) {
        if ((i - 1) % 2 == 0 && a.at(i) != a.at(i - 1)) {
            uniqueInt = a.at(i - 1);
            break;
        }
    }
    
    return uniqueInt;
}

// Diagonal Difference
int diagonalDifference(vector<vector<int>> arr) {
    int arrSize{static_cast<int>(arr.size())};
    int leftRightSum{0};
    int rightLeftSum{0};

    for (int i{0}; i < arrSize; ++i) {
        leftRightSum += (arr.at(i)).at(i);
        rightLeftSum += (arr.at(i)).at(arrSize - 1 - i);
    }

    return abs(leftRightSum - rightLeftSum);
}

// Counting Sort 1
vector<int> countingSort(vector<int> arr) {
    vector<int> countArr(100, 0);
    int arrSize{static_cast<int>(arr.size())};

    for (int i{0}; i < arrSize; ++i) {
        countArr.at(arr.at(i)) += 1;
    }

    return countArr;
}

// Flipping the Matrix (Mock Test)
int flippingMatrix(vector<vector<int>> matrix) {
    int matrixSize{static_cast<int>(matrix.size())};
    int upperLeftSum{0};

    for (int i{0}; i < matrixSize/2; ++i) {
        for (int j{0}; j < matrixSize/2; ++j ) {
            int upperLeft{(matrix.at(i)).at(j)};
            int upperRight{(matrix.at(i)).at(matrixSize - 1 - j)};
            int lowerLeft{(matrix.at(matrixSize - 1 - i)).at(j)};
            int lowerRight{(matrix.at(matrixSize - 1 - i)).at(matrixSize - 1 - j)};
            int maxUpper{std::max(upperLeft, upperRight)};
            int maxLower{std::max(lowerLeft, lowerRight)};
            upperLeftSum += max(maxUpper, maxLower);
        }
    }

    return upperLeftSum;
}