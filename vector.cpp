#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int kataSama (vector<string> data, string line)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == line)
        {
            return i;
        }
    }
    return -1;
}
string newWords(string wordsInput)
{
    string new_word = "";
    
    for (int i = 0; i < wordsInput.length(); i++)
    {
        char alphabet = wordsInput[i];
        int num_alphabet = int(alphabet);
        if (num_alphabet >= 65 and num_alphabet <= 90)
         new_word += (char(num_alphabet + 32));
        else if (num_alphabet >= 97 and num_alphabet <= 122 or num_alphabet >= 48 and num_alphabet <= 57)
         new_word += alphabet;
    }
    return new_word;
}
 

int main(int argc, char const *argv[])
{
    string line;
    ifstream input("input.txt");

    vector<string> kalimat;
    vector<string> _kalimat;
    vector<int> count;
    string data;
    
    while (input.good())
    {
        input >> line;
        line = newWords(line);
        if (line.length() !=0)
        {
            kalimat.push_back(line);
        }
    }

    string special = string(".,;:?");


    for (auto storage : kalimat) //range-based for loop
    {
        int t = kataSama(_kalimat, storage);
        if (t == -1)//-1 karena di fungsi sebelumnya digunakan return -1
        {
            _kalimat.push_back(storage); 
            count.push_back(1);
        }
        else
        {
            count[t]++;
        }
    }

    for(int i = 0; i < _kalimat.size()-1; i++)
    {
        cout << " "<< _kalimat[i] << " " << count[i] << endl;
    }

    return 0;
}

