#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

void eraseFileLine(string path) {
    string line;
    ifstream fin;

    fin.open(path);
    ofstream temp; 
    temp.open("temp.txt");

    while (getline(fin, line)) {
        if (line.rfind("namespace", 0) == 0) 
            continue;
        if (line.rfind("{", 0) == 0)
            continue;
        if (line.rfind("}", 0) == 0)
            continue;     
        temp << line << std::endl;
    }

    temp.close();
    fin.close();

    const char * p = path.c_str(); 
    remove(p);
    rename("temp.txt", p);
}

vector<string> readFileNames(string path) {
    string line;
    ifstream fin;

    vector<string> fileNames;
    fin.open(path+"/fileNames.txt");
    
    while (getline(fin, line)) {
        if(line == "fileNames.txt") 
            continue;
        fileNames.push_back(path+"/"+line);
    }

    fin.close();
    return fileNames;
}

int main(int argc,char **argv){
    string directoryPath = argv[1];

    vector<string> fileNames = readFileNames(directoryPath);
    
    for(auto i: fileNames)
        eraseFileLine(i);
    
    return 0;
}
