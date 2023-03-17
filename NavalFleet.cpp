#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> parent;
std::vector<int> rang;

void makeSet(int x) {
    parent.push_back(x);
    rang.push_back(x);
}

int findSet(int x) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void unionFun(int x, int y) {
    int p = findSet(x);
    int q = findSet(y);
    if (rang[p] > rang[q]) {
        parent[q] = p;
    }
    else {
        parent[p] = q;
        if (rang[p] == rang[q]) {
            rang[q]++;
        }
    }
}

void initializeFleet(int N) {
    for (int i = 0; i < N; i++) {
        makeSet(i);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    std::ifstream infile(argv[1]);

    int a, b;
    char c;
    std::string command;
    std::stringstream ss;

    if (infile.is_open()) {
        /*infile >> N;
        initializeFleet(N);
        std::cout << "Number of ships: " << N << "\n";*/
        std::getline(infile, command);
        std::cout << "Number of ships: " << stoi(command) << "\n";
        initializeFleet(stoi(command));

        while (std::getline(infile, command)) {  // infile >> command
            ss << command;
            ss >> c;
            std::cout << "Command: " << command << "\n";
            //std::cout << "Stringstream: " << ss.str() << "\n";

            if (c == 'C') {
                std::cout << "Command is C\n";
                ss >> a >> b;
                std::cout << "Parameters are a: " << a << ", b: " << b << "\n";
            }
            else if (c == 'G') {
                std::cout << "Command is G\n";
                ss >> a;
                std::cout << "Parameters are a: " << a << "\n";
            }
            //ss.str(std::string());
            ss.clear();
        }
    }
}