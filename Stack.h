//******************************************************************************
//!
//! \file   Stack.h
//! \brief  Genernal Stack Model Interface.
//!         You can use uniform stack API to manager different type of data
//!         element.
//! \author cedar
//! \date   2013-11-22
//!
//! \license
//!
//! Copyright (c) 2013 Cedar MIT License
//!
//! Permission is hereby granted, free of charge, to any person obtaining a copy
//! of this software and associated documentation files (the "Software"), to deal
//! in the Software without restriction, including without limitation the rights to
//! use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//! the Software, and to permit persons to whom the Software is furnished to do so,
//! subject to the following conditions:
//!
//! The above copyright notice and this permission notice shall be included in all
//! copies or substantial portions of the Software.
//!
//! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//! IN THE SOFTWARE.
///
//******************************************************************************

#ifndef __STACK_H__
#define __STACK_H__

#ifdef __cplusplus
extern "C"
{
#endif

//******************************************************************************
//!                           CONFIGURE MACRO
//******************************************************************************

#define SYS_INTXX_T                         //!< Use stdint standard datatype
#define USE_MEMORY_ALLOC                    //!< Use system malloc/free function


#include <stdio.h>

#ifdef SYS_INTXX_T
#include <stdint.h>
#else
typedef unsigned char uint8_t;
typedef unsigned int  uint32_t;
#endif

#ifdef USE_MEMORY_ALLOC
#include <stdlib.h>
#endif


//******************************************************************************
//!                           PUBLIC TYPE
//******************************************************************************

//! Stack Memory Model
typedef struct Stack_t
{
    uint8_t* pBaseAddr;                    //!< Stack Base Address
    uint8_t* pEndAddr;                     //!< Stack Top Address
    uint8_t* pIndex;                       //!< Stack Data Index Pointer
    uint32_t UnitSize;                     //!< Statck Element Size(Unit: Byte)
}Stack_t;


//******************************************************************************
//!                           PUBLIC API
//******************************************************************************
#ifdef USE_MEMORY_ALLOC
extern Stack_t* Stack_Create(uint32_t StackSize, uint32_t UnitSize);
extern void Stack_Destory(Stack_t* pStack);
#endif // USE_MEMORY_ALLOC
extern int Stack_Init(Stack_t* pStack, void* pStackBaseAddr, uint32_t StackSize,
        uint32_t UnitSize);
extern int Stack_Pop(Stack_t* pStack, void* pElement);
extern int Stack_Push(Stack_t* pStack, void* pElement);

#ifdef __cplusplus
}
#endif

#endif // __STACK_H__
