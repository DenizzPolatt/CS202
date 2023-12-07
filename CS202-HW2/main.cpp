/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: main for the time analysis
*/

#include <iostream>
#include "KmerTree.h"

using namespace std;

void timeAnalysis(string inputfilename, int k)
{
    KmerTree kmerTree;

    fstream file(inputfilename);

    string file_contents((std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));

    clock_t start = clock();

    cout << "-------------------- k = " << k << " ---------------------" << endl;

    for(int i = 0; i < file_contents.length()-(k-1); i += k)
    {
        string key = file_contents.substr(i, k);
        kmerTree.addKmer(key);
    
        if(i == 1000*k)
        {
            clock_t end1000 = clock();
            cout << "----------------Added 1000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end1000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 2000*k)
        {
            clock_t end2000 = clock();
            cout << "----------------Added 2000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end2000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 3000*k)
        {
            clock_t end3000 = clock();
            cout << "----------------Added 3000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end3000 - start) / CLOCKS_PER_SEC << endl;
        }


        if(i == 4000*k)
        {
            clock_t end4000 = clock();
            cout << "----------------Added 4000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end4000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 5000*k)
        {
            clock_t end5000 = clock();
            cout << "----------------Added 5000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end5000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 6000*k)
        {
            clock_t end6000 = clock();
            cout << "----------------Added 6000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end6000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 7000*k)
        {
            clock_t end7000 = clock();
            cout << "----------------Added 7000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end7000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 8000*k)
        {
            clock_t end8000 = clock();
            cout << "----------------Added 8000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end8000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 9000*k)
        {
            clock_t end9000 = clock();
            cout << "----------------Added 9000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end9000 - start) / CLOCKS_PER_SEC << endl;
        }

        if(i == 10000*k)
        {
            clock_t end10000 = clock();
            cout << "----------------Added 10000 kmers----------------" << endl;
            cout << "The number of unique kmers: " << kmerTree.getUniqueKmerCount() << endl;
            cout << "The height of the BST: " << kmerTree.getHeight() << endl;
            cout << "Time taken for the period: " << double(end10000 - start) / CLOCKS_PER_SEC << endl;
        }
    }

    file.close();
}

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout << "Missing arguments" << endl;
    }
    else {
        int k = atoi(argv[1]);
        string inputFile = argv[2];
        cout << "\n";
        timeAnalysis(inputFile, k);
    }

        return 0;
}