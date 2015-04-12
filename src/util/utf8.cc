//
//  utf8.cc
//  rpusbdispsdk
//
//  Created by Tony Huang on 12/29/13.
//  Copyright (c) 2013 RoboPeak.com. All rights reserved.
//

#include <rp/util/utf8.h>

using namespace std;

namespace rp { namespace util { namespace utf8 {
   
    static inline size_t getCharLength(unsigned char leadingChar) {
        unsigned char ch = leadingChar & 0xf0;
        
        if (ch == 0xf0) return 4;
        if (ch == 0xe0) return 3;
        if (ch == 0xc0) return 2;
        
        return 1;
    }

    utf32string utf8ToUtf32(const string& utf8String) {
        utf32string output;
        
        if (!utf8String.size()) return output;
        
        const uint8_t* p = reinterpret_cast<const uint8_t*>(utf8String.c_str());
        
        while (*p) {
            size_t l = getCharLength(*p);
            uint32_t ch;
            
            ch = *p ^ "\0\xc0\xe0\xf0"[l-1];
            p++;
            
            for (size_t i = 1; i < l && *p; i++, p++) {
                ch <<=6;
                ch |= (*p ^ 0x80);
            }
            
            output.push_back(ch);
        }
        
        return output;
    }
    
}}}
