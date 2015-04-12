//
//  utf8.h
//  Routines to deal with utf8
//
//  Created by Tony Huang on 12/29/13.
//  Copyright (c) 2013 RoboPeak.com. All rights reserved.
//

#pragma once

#include <string>
#include <rp/util/int_types.h>

namespace std {
    typedef basic_string<uint32_t> utf32string;
}

namespace rp { namespace util { namespace utf8 {

    extern std::utf32string utf8ToUtf32(const std::string& s);
    
}}}
