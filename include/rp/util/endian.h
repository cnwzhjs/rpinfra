//
//  endian.h
//  Deal with endian issues
//
//  Created by Tony Huang on 12/11/13.
//  Copyright (c) 2013 RoboPeak.com. All rights reserved.
//

#pragma once

#include <rp/infra_config.h>
#include <rp/util/int_types.h>

namespace rp { namespace util {
    
    /**
     * Convert unsigned 16bit integer from big endian to little endian
     */
    static inline uint16_t be16_to_le16(uint16_t v) {
        return (v>>8) | ((v&0xffu)<<8);
    }
    
    /**
     * Convert unsigned 16bit integer from little endian to big endian
     */
    static inline uint16_t le16_to_be16(uint16_t v) {
        return be16_to_le16(v);
    }

    /**
     * Convert unsigned 16bit integer from little endian to cpu endian
     */
    static inline uint16_t le16_to_cpu(uint16_t v) {
#ifdef RP_INFRA_BIG_ENDIAN
        return be16_to_le16(v);
#else
        return v;
#endif
    }
    
    /**
     * Convert unsigned 16bit integer from big endian to cpu endian
     */
    static inline uint16_t be16_to_cpu(uint16_t v) {
#ifdef RP_INFRA_BIG_ENDIAN
        return v;
#else
        return le16_to_be16(v);
#endif
    }
    
    /**
     * Convert unsigned 16bit integer from cpu endian to little endian
     */
    static inline uint16_t cpu_to_le16(uint16_t v) {
        return le16_to_cpu(v);
    }
    
    /**
     * Convert unsigned 16bit integer from cpu endian to big endian
     */
    static inline uint16_t cpu_to_be16(uint16_t v) {
        return be16_to_cpu(v);
    }
    
    /**
     * Convert unsigned 32bit integer from big endian to little endian
     */
    static inline uint32_t be32_to_le32(uint32_t v) {
        return (v>>24) | (((v>>16)&0xffu)<<8) | (((v>>8)&0xffu)<<16) | (v<<24);
    }
    
    /**
     * Convert unsigned 32bit integer from little endian to big endian
     */
    static inline uint32_t le32_to_be32(uint32_t v) {
        return be32_to_le32(v);
    }
    
    /**
     * Convert unsigned 32bit integer from little endian to cpu endian
     */
    static inline uint32_t le32_to_cpu(uint32_t v) {
#ifdef RP_INFRA_BIG_ENDIAN
        return be32_to_le32(v);
#else
        return v;
#endif
    }
    
    /**
     * Convert unsigned 32bit integer from big endian to cpu endian
     */
    static inline uint32_t be32_to_cpu(uint32_t v) {
#ifdef RP_INFRA_BIG_ENDIAN
        return v;
#else
        return be32_to_le32(v);
#endif
    }
    
    /**
     * Convert unsigned 32bit integer from cpu endian to little endian
     */
    static inline uint32_t cpu_to_le32(uint32_t v) {
        return le32_to_cpu(v);
    }
    
    /**
     * Convert unsigned 32bit integer from cpu endian to big endian
     */
    static inline uint32_t cpu_to_be32(uint32_t v) {
        return be32_to_cpu(v);
    }
    
}}

