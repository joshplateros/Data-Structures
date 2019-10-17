#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include "BinaryNode.h"
#include <memory>
#include <algorithm>
#include <iostream>

template<class ItemType>
class BinarySearchTree
{
    private:
        BinaryNode<ItemType> *rootPtr;
    protected: //Could just make public?
        BinaryNode<ItemType> * placeNode(BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> * newNode);
        BinaryNode<ItemType> * removeValue(BinaryNode<ItemType> * subTreePtr, const ItemType & target, bool & isSuccessful);
    public:
        BinarySearchTree();
        BinarySearchTree(const ItemType & rootItem);
        BinarySearchTree(const BinarySearchTree<ItemType> & tree);
    
        bool isEmpty() const;
        int getHeight() const;
        int getHeightHelper(BinaryNode<ItemType> * subTreePtr) const;
        int getNumberOfNodes() const;

        bool add(const ItemType & newEntry);
        bool remove(const ItemType & target);
        void clear();

        bool contain(const ItemType & target) const;

        //Helper functions
        void preorder();
        void inorder();
        void postorder();
    
        //Traverse functions
        void preorderTraverse(BinaryNode<ItemType> *treePtr) const;
        void inorderTraverse(BinaryNode<ItemType> *treePtr) const;
        void postorderTraverse(BinaryNode<ItemType> *treePtr) const;

        BinarySearchTree<ItemType> & operator=(const BinarySearchTree<ItemType> & rightHandSide);
};

#include "BinarySearchTree.cpp"
#endif
