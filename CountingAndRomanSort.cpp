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
    //if converting find min value, if min<0 subtract from all elements and return min
    //else revert by adding min to all elements
    //a.k.a. add support for arrays with neg. numbers
}

int main(int argc, char* argv[])
{
    cout<<"Hello World!"<<endl;

    return 0;
}
