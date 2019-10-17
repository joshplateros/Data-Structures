#include "BinaryNode.h"

template<class ItemType>
//Default ctor - add stuff maybe?
BinaryNode<ItemType>::BinaryNode()
{}

//Parametrized ctor, sets all private members to default values    
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType & anItem) : item(anItem), leftChildPtr(nullptr) , rightChildPtr(nullptr)
{}

//Return item, which is of ItemType (from template)
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}

//Sets item to anItem    
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType & anItem)
{
    item = anItem;
}

//Getters and Setters
template<class ItemType>
BinaryNode<ItemType> * BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}
template<class ItemType>
BinaryNode<ItemType> * BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType> *leftPtr)
{
    leftChildPtr = leftPtr;
}
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType> * rightPtr)
{
    rightChildPtr = rightPtr;
}









