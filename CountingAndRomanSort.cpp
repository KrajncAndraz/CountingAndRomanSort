#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<int> getArray(string filename)
{
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return {};
    }
    vector<int> arr;
    int extractedNumber;
    if (inputFile.is_open() && inputFile.good())
    {
        while (inputFile >> extractedNumber)
        {
            arr.push_back(extractedNumber);
        }
    }
	inputFile.close();
    return arr;
}

void saveArray(vector<int>& arr)
{
    ofstream outputFile("out.txt");
    for (int i = 0; i < arr.size(); i++)
        outputFile << arr[i] << ' ';
	outputFile.close();
}

int negSupport(vector<int>& arr, bool convert, int min = 0)
{
    if (convert)
    {
        min = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }
        if (min < 0)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i] -= min;
            }
            return min;
        }
    }
    else
    {
        if (min < 0)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i] += min;
            }
        }
    }
    return 0;
}

vector<int> innitC(vector<int>& A)
{
    int max = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return vector<int>(max+1, 0);
}

vector<int> countingSort(vector<int>& A)
{
    int min = negSupport(A, true);
    vector<int> C = innitC(A);

    for (int i = 0; i < A.size(); i++)
        C[A[i]]++;

    for (int i = 1; i < C.size(); i++)
        C[i] += C[i - 1];

    vector<int> B(A.size(), 0);
    for (int i = A.size()-1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    negSupport(B, false, min);
    return B;
}

vector<int> romanSort(vector<int>& A)
{
    int min = negSupport(A, true);
    vector<int> C = innitC(A);

    for (int i = 0; i < A.size(); i++)
        C[A[i]]++;

    vector<int> B(A.size(), 0);
    int k = 0;
    for (int i = 0; i < C.size(); i++)
    {
        if (C[i] != 0)
        {
            for (int j = 0; j < C[i]; j++)
            {
                B[k] = i;
                k++;
            }
        }
    }

    negSupport(B, false, min);
    return B;
}

int main(int argc, char* argv[])
{
    cout<<"Hello World!"<<endl;

    return 0;
}
