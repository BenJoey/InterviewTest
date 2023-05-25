#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int getScenicScore(const std::vector<std::vector<int>> &Matrix, int row, int column, int direction, bool isColumn)
{
    int scenicScore = 0;
    int starterValue = isColumn ? column : row;
    for (int k = starterValue + direction; k < Matrix[0].size() && k >= 0; k += direction)
    {
        scenicScore++;
        int compareValue = isColumn ? Matrix[row][k] : Matrix[k][column];
        if (compareValue >= Matrix[row][column])
            return scenicScore;
    }
    return scenicScore;
}

int main(int argc, char **argv)
{
    std::ifstream inputStream("day8.in");
    std::string line;
    std::vector<std::vector<int>> pMatrix;
    while (std::getline(inputStream, line))
    {
        std::vector<int> t;
        t.reserve(line.size());
        for (int i = 0; i < line.size(); i++)
        {
            t.emplace_back(line[i] - '0');
        }
        pMatrix.emplace_back(t);
    }

    // pVisibleTrees value starts with all the trees on the edge
    int pVisibleTrees = (2 * pMatrix.size()) + (2 * pMatrix[0].size()) - 4;

    for (int i = 1; i < pMatrix.size() - 1; i++)
    {
        for (int j = 1; j < pMatrix[0].size() - 1; j++)
        {
            bool pVisible = true;
            for (int k = 0; k < i; k++)
            {
                if (pMatrix[k][j] >= pMatrix[i][j])
                {
                    pVisible = false;
                    break;
                }
            }
            if (pVisible)
            {
                pVisibleTrees++;
                continue;
            }
            pVisible = true;
            for (int k = pMatrix.size() - 1; k > i; k--)
            {
                if (pMatrix[k][j] >= pMatrix[i][j])
                {
                    pVisible = false;
                    break;
                }
            }
            if (pVisible)
            {
                pVisibleTrees++;
                continue;
            }
            pVisible = true;
            for (int k = 0; k < j; k++)
            {
                if (pMatrix[i][k] >= pMatrix[i][j])
                {
                    pVisible = false;
                    break;
                }
            }
            if (pVisible)
            {
                pVisibleTrees++;
                continue;
            }
            pVisible = true;
            for (int k = pMatrix[0].size() - 1; k > j; k--)
            {
                if (pMatrix[i][k] >= pMatrix[i][j])
                {
                    pVisible = false;
                    break;
                }
            }
            if (pVisible)
                pVisibleTrees++;
        }
    }
    std::cout << pVisibleTrees << std::endl;

    int pMaxScenicScore = 0;
    for (int i = 1; i < pMatrix.size() - 1; i++)
    {
        for (int j = 1; j < pMatrix[0].size() - 1; j++)
        {
            int currentScenicScore = getScenicScore(pMatrix, i, j, -1, false) *
                                     getScenicScore(pMatrix, i, j, 1, false) *
                                     getScenicScore(pMatrix, i, j, -1, true) *
                                     getScenicScore(pMatrix, i, j, 1, true);
            pMaxScenicScore = std::max(pMaxScenicScore, currentScenicScore);
        }
    }
    std::cout << pMaxScenicScore << std::endl;

    return 0;
}