#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

//fungsi menghitung jumlah kata unique
int Similar(vector<string> source, string data)
{
    for (int i = 0; i < source.size(); i++)
    {
        if(source[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<string> _data;
    vector<string> data;
    vector<int> count;
    string line;
    ifstream input("input.txt");

    //data diambil dari bentuk string, lalu diinputkan ke dalam vektor
    while(input.good())
    {
        input >> line;
        data.push_back(line);
    }

    //variabel ini digunakan untuk menghapus karakter spesial
    string special = string(".,;:?");

    //menghapus karakter spesial dan konvert semua karakter ke lowercase
    for(int i = 0; i < data.size(); i++)
    {
        string temp = data[i];
        data[i] = "";
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        for(int j=0; j < temp.size(); j++)
        {
            if (special.find(temp[j]) == string::npos)
            {
                data[i] += temp[j];
            } 
        }
    }

    //menghitung jumlah kata dan memasukkan ke dalam vektor sesuai indexnya
    for (auto storage : data) //range-based for loop
    {
        int t = Similar(_data, storage);
        if (t == -1)//-1 karena di fungsi sebelumnya digunakan return -1
        {
            _data.push_back(storage); 
            count.push_back(1);
        }
        else
        {
            count[t]++;
        }
    }

    //membuat class objek json sesuai aturan penulisan file json
    string data_json = "";
    data_json += "{\n";
    
    ofstream output("output.json");

    for(int i=0; i < _data.size(); i++)
    {
        if(i < _data.size()-1)
        {
            data_json += "\t\"";
            data_json += _data[i];
            data_json += "\": ";
            data_json += to_string(count[i]);
            data_json += ",\n";
        }
        else
        {
            data_json += "\t\"";
            data_json += _data[i];
            data_json += "\": ";
            data_json += to_string(count[i]);
            data_json += "\n";
        }
    }

    data_json += "}";
    output << data_json;
    return 0;
}
