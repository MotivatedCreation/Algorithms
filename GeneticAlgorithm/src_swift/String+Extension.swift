//
//  String+Extension.swift
//  GeneticAlgorithm_Swift
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

import Foundation

extension String
{
    subscript (i: Int) -> Character
        {
            return self[advance(self.startIndex, i)]
    }
    
    subscript (i: Int) -> String
        {
            return String(self[i] as Character)
    }
    
    subscript (r: Range<Int>) -> String
        {
            return substringWithRange(Range(start: advance(startIndex, r.startIndex), end: advance(startIndex, r.endIndex)))
    }
    
    func substring(start:Int, end: Int) -> String
    {
        let startStringIndex = advance(startIndex, start)
        let endStringIndex = advance(startIndex, end)
        
        let range = Range<String.Index>(start: startStringIndex, end: endStringIndex)
        
        return substringWithRange(range)
    }
}