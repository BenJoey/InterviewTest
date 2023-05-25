#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    int pVisibleTrees = 0;
    for (int i = 0; i < pMatrix.size(); i++)
    {
        for (int j = 0; j < pMatrix[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == pMatrix.size() - 1 || j == pMatrix[0].size() - 1)
            {
                pVisibleTrees++;
                continue;
            }
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

    int mss = 0;
    for (int i = 0; i < pMatrix.size(); i++)
    {
        for (int j = 0; j < pMatrix[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == pMatrix.size() - 1 || j == pMatrix[0].size() - 1)
            {
                continue;
            }
            int lss1 = 0;
            for (int k = i - 1; k >= 0; k--)
            {
                lss1++;
                if (pMatrix[k][j] >= pMatrix[i][j])
                    break;
            }
            int lss2 = 0;
            for (int k = i + 1; k < pMatrix.size(); k++)
            {
                lss2++;
                if (pMatrix[k][j] >= pMatrix[i][j])
                    break;
            }
            int lss3 = 0;
            for (int k = j - 1; k >= 0; k--)
            {
                lss3++;
                if (pMatrix[i][k] >= pMatrix[i][j])
                    break;
            }
            int lss4 = 0;
            for (int k = j + 1; k < pMatrix[0].size(); k++)
            {
                lss4++;
                if (pMatrix[i][k] >= pMatrix[i][j])
                    break;
            }
            int ss = lss1 * lss2 * lss3 * lss4;
            if (ss > mss)
                mss = ss;
        }
    }
    std::cout << mss << std::endl;

    return 0;
}