//
//  Stack.h
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

#ifndef __Algorithms__Stack__
#define __Algorithms__Stack__

#include <stdio.h>
#include <vector>

template<class T>
class Stack
{
    std::vector<T> elements;
    
public:
    void push(const T &element)
    {
        elements.push_back(element);
    }
    
    T pop()
    {
        if (empty())
            throw std::out_of_range("underflow");
        
        auto element = elements.back();
        elements.pop_back();
        
        return element;
    }
    
    T peek()
    {
        if (empty())
            throw std::out_of_range("underflow");
        
        return elements.back();
    }
    
    bool empty()
    {
        return elements.empty();
    }
    
    int size()
    {
        return elements.size();
    }
};


#endif /* defined(__Algorithms__Stack__) */
