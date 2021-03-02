/*
 * Copyright (c) 2020-2020,  by xqyjlj
 *
 * SPDX-License-Identifier:
 *
 * Change Logs:
 * Date           Author       Notes                    Email
 * 2021-03-02     xqyjlj       the first version        xqyjlj@126.com
 */
#ifndef UTILSC_H_
#define UTILSC_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define UTILSC_DEBUG    0
#define UTILSC_RELEASE  1

#define UTILSC_MODE UTILSC_RELEASE

#define utilsc_printf( format, ... )  printf( format, ##__VA_ARGS__)

#define UTILSC_MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )//!< 最大值
#define UTILSC_MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )//!< 最小值

#define UTILSC_FPOS( type, field ) ( (uint32_t) &(( type *) 0)-> field ) //!< 得到一个field在结构体(struct)中的偏移量

#define UTILSC_FLIPW( ray ) ( (((uint16_t) (ray)[0]) * 256) + (ray)[1] )//!< 按照LSB格式把两个字节转化为一个

#define UTILSC_FLOPW( ray, val )        \
do{                                     \
        (ray)[0] = ((val) / 256);       \
        (ray)[1] = ((val) & 0xFF);      \
}while(0)       //!< 按照LSB格式把一个uint16_t转化为两个字节


#define UTILSC_WORD_LO(xxx) ((uint8_t) ((uint16_t)(xxx) & 255))//!< 得到一个字的高位字节
#define UTILSC_WORD_HI(xxx) ((uint8_t) ((uint16_t)(xxx) >> 8))//!< 得到一个字的低位字节

void utilsc_assert_handler(const char *ex_string, const char *func, uint32_t line);

#if (UTILSC_MODE==UTILSC_DEBUG)
#define UTILSC_ASSERT(EX)                                                         \
if (!(EX))                                                                    \
{                                                                             \
    utilsc_assert_handler(#EX, __FUNCTION__, __LINE__);                           \
}
#else
#define UTILSC_ASSERT(EX)   ((void)0U)
#endif

#endif /* UTILSC_H_ */
