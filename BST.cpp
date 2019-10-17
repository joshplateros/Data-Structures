//For the nodes of the search tree
#include "BinaryNode.h"
//For the operations on the search tree
#include "BinarySearchTree.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>

int genRand();
int NUM_SIZE = 200;

int main()
{
    std::ifstream inFile;
    std::ofstream outFile;
    
    BinarySearchTree<int> bst;
    
    int randomNum;
    srand(time(NULL));
    
    inFile.open("200nums.txt");
    int i = 0;
    while(inFile && i < NUM_SIZE)
    {
        inFile >> randomNum;
        i++;
        bst.add(randomNum);
    }
    
    std::cout << "Height: " << std::endl;
    std::cout << bst.getHeight() << std::endl;
    bst.preorder();
    bst.inorder();
    bst.postorder();
    
    return 0;
}

int genRand()
{
    return rand() % NUM_SIZE +1;
}
