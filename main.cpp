#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "KAry.cpp"
#include "TK_PPTREE.cpp"

using namespace std;

int main() {

    ofstream output;
    output.open("Results.csv");

    output << "testname,100,1000,10000,100000,1000000" << endl;

    uint iterations[5] = {100, 1000, 10000, 100000, 1000000};
    
    srand(time(NULL));

    cout << "Starting K-Ary tests." << endl;

    KAryTree<int, 2> bintree;
    KAryTree<int, 3> tritree;
    KAryTree<int, 4> quadtree;
    KAryTree<int, 5> quintree;
    KAryTree<int, 6> hextree;
    
    cout << setfill('-') << setw(19) << '-' << endl;
    output << "bintree,";
    cout << "Running K-Ary tree tests for binary tree." << endl;
    for (uint i = 0; i < 5; ++i) {
        uint iteration = iterations[i];
        
        cout << iteration << " iterations....\n";
        auto start = chrono::high_resolution_clock::now();
        for (uint j = 0; j < iteration; ++j) {
            int r = rand() % iteration;
            bintree.insertNode(r);
        }
        auto end = chrono::high_resolution_clock::now();
        auto diff = end - start;
        auto duration = chrono::duration_cast<chrono::microseconds>(diff);
        output << duration.count() << ',';
    }

    output << endl;

    cout << setfill('-') << setw(19) << '-' << endl;

    output << "tritree,";
    cout << "Running K-Ary tree tests for 3 child tree." << endl;
    for (uint i = 0; i < 5; ++i) {
        uint iteration = iterations[i];
        
        cout << iteration << " iterations....\n";
        auto start = chrono::high_resolution_clock::now();
        for (uint j = 0; j < iteration; ++j) {
            int r = rand() % iteration;
            tritree.insertNode(r);
        }
        auto end = chrono::high_resolution_clock::now();
        auto diff = end - start;
        auto duration = chrono::duration_cast<chrono::microseconds>(diff);
        output << duration.count() << ',';
    }

    output << endl;

    cout << setfill('-') << setw(19) << '-' << endl;

    output << "quadtree,";
    cout << "Running K-Ary tree tests for 4 child tree." << endl;
    for (uint i = 0; i < 5; ++i) {
        uint iteration = iterations[i];
        
        cout << iteration << " iterations....\n";
        auto start = chrono::high_resolution_clock::now();
        for (uint j = 0; j < iteration; ++j) {
            int r = rand() % iteration;
            quadtree.insertNode(r);
        }
        auto end = chrono::high_resolution_clock::now();
        auto diff = end - start;
        auto duration = chrono::duration_cast<chrono::microseconds>(diff);
        output << duration.count() << ',';
    }

    output << endl;

    cout << setfill('-') << setw(19) << '-' << endl;

    output << "quintree,";
    cout << "Running K-Ary tree tests for 5 child tree." << endl;
    for (uint i = 0; i < 5; ++i) {
        uint iteration = iterations[i];
        
        cout << iteration << " iterations....\n";
        auto start = chrono::high_resolution_clock::now();
        for (uint j = 0; j < iteration; ++j) {
            int r = rand() % iteration;
            quintree.insertNode(r);
        }
        auto end = chrono::high_resolution_clock::now();
        auto diff = end - start;
        auto duration = chrono::duration_cast<chrono::microseconds>(diff);
        output << duration.count() << ',';
    }

    output << endl;

    cout << setfill('-') << setw(19) << '-' << endl;

    output << "hextree,";
    cout << "Running K-Ary tree tests for 6-child tree." << endl;
    for (uint i = 0; i < 5; ++i) {
        uint iteration = iterations[i];
        
        cout << iteration << " iterations....\n";
        auto start = chrono::high_resolution_clock::now();
        for (uint j = 0; j < iteration; ++j) {
            int r = rand() % iteration;
            hextree.insertNode(r);
        }
        auto end = chrono::high_resolution_clock::now();
        auto diff = end - start;
        auto duration = chrono::duration_cast<chrono::microseconds>(diff);
        output << duration.count() << ',';
    }

    output << endl;

    cout << setfill('-') << setw(19) << '-' << endl;

    // The following code requires two files that
    // were asked to not be included in my open source
    // part of my project. Just comment out the line 
    // '#include "TK_PPTREE.cpp"'
    // and the rest will compile and run

    #ifdef TK_PPTREE_H

    output << "pptree,";
    cout << "Running Parent Pointer Tree tests.\n";
    for (uint i = 0; i < 5; ++i) {
        uint iteration = iterations[i];
        PP pptree(iteration);
        
        cout << iteration << " iterations....\n";
        auto start = chrono::high_resolution_clock::now();
        // The number of iterations needs to be cut in half
        // since the number of nodes increases by 2 every time
        for (uint j = 0; j < iteration/2; ++j) {
            int r = rand() % iteration;
            int r2 = rand() % iteration;
            pptree.UNION(r, r2);
        }
        auto end = chrono::high_resolution_clock::now();
        auto diff = end - start;
        auto duration = chrono::duration_cast<chrono::microseconds>(diff);
        output << duration.count() << ',';
    }

    output << endl;

    cout << setfill('-') << setw(19) << '-' << endl;

    #endif


    output.close();
    return 0;
}