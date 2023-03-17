#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> parent;

void makeSet(int x) {
    parent.push_back(x);
}

int findSet(int x) {
    if (x != parent[x - 1]) {
        parent[x - 1] = findSet(parent[x - 1]);
    }
    return parent[x - 1];
}

void unionFun(int x, int y) {
    int p = findSet(x);
    int q = findSet(y);
    parent[p - 1] = q;
}

int distance(int x) {
    int dist = 0;
    if (x != parent[x - 1]) {
        dist += std::abs(x - parent[x - 1]) % 1000;
        dist += distance(parent[x - 1]);
    }
    //std::cout << "Distance for " << x << " is " << dist << "\n";
    return dist;
}

void initializeFleet(int N) {
    for (int i = 1; i <= N; i++) {
        makeSet(i);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) return -1;

    std::ifstream infile(argv[1]);
    //std::ofstream outfile("output.txt");

    int a, b;
    char c;
    std::string command;
    std::stringstream ss;

    if (infile.is_open()) {
        std::getline(infile, command);
        //std::cout << "Number of ships: " << stoi(command) << "\n";
        initializeFleet(stoi(command));

        while (std::getline(infile, command)) {  // infile >> command
            ss << command;
            ss >> c;
            //std::cout << "Command: " << command << "\n";
            //std::cout << "Stringstream: " << ss.str() << "\n";

            if (c == 'C') {
                //std::cout << "Command is C\n";
                ss >> a >> b;
                //std::cout << "Parameters are a: " << a << ", b: " << b << "\n";
                unionFun(a, b);
            }
            else if (c == 'G') {
                //std::cout << "Command is G\n";
                ss >> a;
                //std::cout << "Parameters are a: " << a << "\n";
                int dist = distance(a);
                //outfile << dist << "\n";
                std::cout << dist << "\n";
            }
            //ss.str(std::string());
            ss.clear();
        }
    }
}