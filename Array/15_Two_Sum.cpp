    std::vector<std::vector<int>> triangle;
    int i = 0;
    while (i < numRows) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
        i++;
    }
    return triangle;