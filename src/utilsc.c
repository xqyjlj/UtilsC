/*
 * Copyright (c) 2020-2020,  by xqyjlj
 *
 * SPDX-License-Identifier:
 *
 * Change Logs:
 * Date           Author       Notes                    Email
 * 2021-03-02     xqyjlj       the first version        xqyjlj@126.com
 */

#include "utilsc.h"

/**
 * @brief   断言函数
 *
 * @param   ex_string   变量名
 * @param   func    函数名
 * @param   line    行数
 *
 * @return
*/
void utilsc_assert_handler(const char *ex_string, const char *func, uint32_t line)
{
    utilsc_printf("(%s) assertion failed at function:%s, line number:%d \n", ex_string, func, line);
    while (true);

}