#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode
{
    private: 
        ItemType item;
        BinaryNode<ItemType> *leftChildPtr;
        BinaryNode<ItemType> *rightChildPtr;
    public:
        //Default ctor
        BinaryNode();
        //Param ctor
        BinaryNode(const ItemType & anItem);
        
        //Set item to item private member
        void setItem(const ItemType & anItem);

        //Returns item
        ItemType getItem() const;
       
        //Is node a leaf? 
        bool isLeaf() const;
    
        //Returns child ptrs 
        BinaryNode<ItemType> * getLeftChildPtr() const; 
        BinaryNode<ItemType> * getRightChildPtr() const;

        //Sets child ptr
        void setLeftChildPtr(BinaryNode<ItemType> * leftPtr);
        void setRightChildPtr(BinaryNode<ItemType> * rightPtr);
};

#include "BinaryNode.cpp"
#endif
