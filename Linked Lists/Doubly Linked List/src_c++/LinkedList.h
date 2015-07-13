//
//  LinkedList.h
//  Algorithms
//
//  Created by Jonathan Sullivan on 7/13/15.
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Jonathan Sullivan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __Algorithms__LinkedList__
#define __Algorithms__LinkedList__

#include <stdio.h>


template<typename T>
struct Node
{
    T data;
    Node<T> * next;
    Node<T> * previous;
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
            tail = head;
        }
        else {
            node->previous = tail;
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


#endif /* defined(__Algorithms__LinkedList__) */
