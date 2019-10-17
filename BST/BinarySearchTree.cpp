#include "BinarySearchTree.h"
#include <algorithm>

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{}
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType & newData)
{
    BinaryNode<ItemType> * newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}
template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType> *subTreePtr, BinaryNode<ItemType> * newNodePtr)
{
    BinaryNode<ItemType> * tempPtr;
    if (subTreePtr == nullptr)
        return newNodePtr;
    else if (subTreePtr->getItem() > newNodePtr->getItem())
    {
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else      
    {
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}
template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType> * subTreePtr, const ItemType & target, bool & isSuccessful)
{
    BinaryNode<ItemType> * tempPtr;
    if(subTreePtr == nullptr)
    {
        isSuccessful = false;
    }
    else if (subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);
        isSuccessful = true;
    }
    else if (subTreePtr->getItem() > target)
    {
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}
template<class ItemType>
void BinarySearchTree<ItemType>::preorder()
{
    std::cout << "Preorder Traverse" << std::endl;
    preorderTraverse(rootPtr);
    std::cout << std::endl;
}
template<class ItemType>
void BinarySearchTree<ItemType>::inorder()
{
    std::cout << "Inorder Traverse" << std::endl;
    inorderTraverse(rootPtr);
    std::cout << std::endl;
}
template<class ItemType>
void BinarySearchTree<ItemType>::postorder()
{
    std::cout << "Postorder Traverse" << std::endl;
    postorderTraverse(rootPtr);
    std::cout << std::endl;
}
//Traverse functions
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(BinaryNode<ItemType> *treePtr) const
{
    if (treePtr == nullptr)
    {
        return;
    }
    std::cout << treePtr->getItem() << " ";
    preorderTraverse(treePtr->getLeftChildPtr());
    preorderTraverse(treePtr->getRightChildPtr());
}
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(BinaryNode<ItemType> *treePtr) const
{
    if(treePtr == nullptr)
    {
        return;
    }
    inorderTraverse(treePtr->getLeftChildPtr());      
    std::cout << treePtr->getItem() << " ";
    inorderTraverse(treePtr->getRightChildPtr());
}
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(BinaryNode<ItemType> *treePtr) const
{
    if(treePtr == nullptr)
    {
        return;
    }
    postorderTraverse(treePtr->getLeftChildPtr());
    postorderTraverse(treePtr->getRightChildPtr());
    std::cout << treePtr->getItem() << " ";
}
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return getHeightHelper(rootPtr);
}
template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType> * subTreePtr) const
{
    if(subTreePtr == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

