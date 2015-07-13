//
//  LinkedList.h
//  LinkedList_C++
//
//  Created by Jonathan Sullivan on 7/12/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#ifndef __LinkedList_C____JPSLinkedList__
#define __LinkedList_C____JPSLinkedList__

#include <stdio.h>

template<typename T>
struct Node
{
    T data;
    Node * next;
};


template<class T>
class LinkedList
{
    
    
public:
    Node<T> * head;
    Node<T> * tail;
    
#pragma mark - Life Cycle Functions
    
    virtual ~LinkedList()
    {
        removeAllNodes();
    }
    
#pragma mark -
    
    
#pragma mark - Helper Functions
    
    int count() const
    {
        int count = 0;
        
        Node<T> * currentNode = head;
        
        while (currentNode)
        {
            count++;
            currentNode = currentNode->next;
        }
        
        return count;
    }
    
#pragma mark -
    
    
#pragma mark - Action Fucntions
    
    void removeAllNodes()
    {
        Node<T> * currentNode = head;
        
        while (currentNode)
        {
            Node<T> * nodeToDelete = currentNode;
            currentNode = currentNode->next;
            
            delete nodeToDelete;
        }
        
        head = nullptr;
        tail = nullptr;
    }
    
    void addNode(Node<T> * node)
    {
        if (head == nullptr)
        {
            head = node;
            head->next = nullptr;
            
            tail = head;
            tail->next = nullptr;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    
    void removeNode(Node<T> * node)
    {
        if (head == node)
        {
            head = node->next;
            
            delete node;
        }
        else {
            Node<T> * currentNode = head;
            Node<T> * previousNode = head;
            
            while (currentNode)
            {
                if (currentNode == node)
                {
                    previousNode->next = currentNode->next;
                    
                    delete node;
                    
                    break;
                }
                
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    }
    
#pragma mark -
    
};

#endif /* defined(__LinkedList_C____JPSLinkedList__) */
