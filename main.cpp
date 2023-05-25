#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
    std::ifstream inputStream("day8.in");
    std::string line;
    std::vector<std::vector<int>> pMatrix;
    while (std::getline(inputStream, line))
    {
        std::vector<int> t;
        for (int i = 0; i < line.size(); i++)
        {
            t.push_back(line[i] - '0');
        }
        pMatrix.push_back(t);
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
    for (int i = 0; i < pMatrix.size(); i++)
    {
        for (int j = 0; j < pMatrix[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == pMatrix.size() - 1 || j == pMatrix[0].size() - 1)
            {
                continue;
            }
            int latestScenicScore1 = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                latestScenicScore1++;
                if (pMatrix[k][j] >= pMatrix[i][j])
                    break;
            }
            int latestScenicScore2 = 0;
            for (int k = i + 1; k < pMatrix.size(); k++)
            {
                latestScenicScore2++;
                if (pMatrix[k][j] >= pMatrix[i][j])
                    break;
            }
            int latestScenicScore3 = 0;
            for (int k = j - 1; k >= 0; k--)
            {
                latestScenicScore3++;
                if (pMatrix[i][k] >= pMatrix[i][j])
                    break;
            }
            int latestScenicScore4 = 0;
            for (int k = j + 1; k < pMatrix[0].size(); k++)
            {
                latestScenicScore4++;
                if (pMatrix[i][k] >= pMatrix[i][j])
                    break;
            }
            int currentScenicScore = latestScenicScore1 * latestScenicScore2 * latestScenicScore3 * latestScenicScore4;
            if (currentScenicScore > pMaxScenicScore)
                pMaxScenicScore = currentScenicScore;
        }
    }
    std::cout << pMaxScenicScore << std::endl;

    return 0;
}