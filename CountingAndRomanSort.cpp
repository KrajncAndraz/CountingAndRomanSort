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
    //innitialize C - find max value in A and set C's size to it
}

int main(int argc, char* argv[])
{
    cout<<"Hello World!"<<endl;

    return 0;
}
