#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

    int N;
    std::string command;

    if (infile.is_open()) {
        /*infile >> N;
        initializeFleet(N);
        std::cout << "Number of ships: " << N << "\n";*/
        std::getline(infile, command);
        std::cout << "Number of ships: " << stoi(command) << "\n";
        initializeFleet(stoi(command));

        while (std::getline(infile, command)) {  // infile >> command    
            std::cout << "Command: " << command << "\n";
            std::cout << typeid(command).name() << "\n";

            if (command.at(0) == 'C') {
                std::cout << "Command is C\n";
            }
            else if (command.at(0) == 'G') {
                std::cout << "Command is G\n";
            }
        }
    }
}