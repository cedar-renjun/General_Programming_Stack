//******************************************************************************
//!
//! \file   Stack.h
//! \brief  Genernal Stack Model Interface.
//!         You can use uniform stack API to manager different type of data
//!         element.
//! \author cedar
//! \date   2013-11-22
//! \email  xuesong5825718@gmail.com
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
#define USE_DYNAMIC_MEMORY                  //!< Use system malloc/free function


#include <stdio.h>

#ifdef SYS_INTXX_T
#include <stdint.h>
#else
typedef unsigned char uint8_t;
typedef unsigned int  uint32_t;
#endif

#ifdef USE_DYNAMIC_MEMORY
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

#ifdef USE_DYNAMIC_MEMORY
//******************************************************************************************
//
//! \brief  Create An New Stack.
//!
//! \param  [in] StackSize is the size of stack.
//! \param  [in] UnitSize is the size of base element.
//! \retval The Pointer of new create stack.
//! \note   -# If StackSize <= UnitSize or memory allocate failure, this function will return
//!            with NULL pointer, So, Caller must check return pointer carefully.
//!
//! \note   -# You must enable USE_MEMORY_ALLOC macro and ensure your system have <stdlib.h>
//!            Header file before use this function.
//******************************************************************************************
extern Stack_t* Stack_Create(uint32_t StackSize, uint32_t UnitSize);

//******************************************************************************************
//
//! \brief  Destory Stack
//!  This function first release memory section, then reinit the stack pointer parameter.
//!
//! \param  [in] pStack is the pointer of valid stack.
//! \retval None.
//!
//! \note   -# You must enable USE_MEMORY_ALLOC macro and ensure your system have <stdlib.h>
//!            Header file before use this function.
//
//******************************************************************************************
extern void Stack_Destory(Stack_t* pStack);
#endif // USE_DYNAMIC_MEMORY

//******************************************************************************************
//
//! \brief  Initialize an exist stack.
//!
//! \param  [in] pStack is the pointer of valid stack.
//! \param  [in] pStackBaseAddr is the base address pre-alloc memory, such as array.
//! \param  [in] StackSize is the size of stack.
//! \param  [in] UnitSize is the size of base element.
//! \retval 0 if initialize successfully, otherwise return -1.
//!
//! \note   -# If stack pointer invalid or memory allocate failure, this function will return
//!            with NULL pointer, So, Caller must check return pointer carefully.
//!
//******************************************************************************************
extern int Stack_Init(Stack_t* pStack, void* pStackBaseAddr, uint32_t StackSize, uint32_t UnitSize);

//******************************************************************************************
//
//! \brief  Pop an element from stack.
//!
//! \param  [in]  pStack is the pointer of valid stack.
//! \param  [out] pElement is the address of memory that store the pop element.
//!
//! \retval 0 if initialize successfully, otherwise return -1.
//
//******************************************************************************************
extern int Stack_Pop(Stack_t* pStack, void* pElement);

//******************************************************************************************
//
//! \brief  Push an element into stack.
//!
//! \param  [in] pStack is the pointer of valid stack.
//! \param  [in] pElement is data element you want to push.
//!
//! \retval 0 if initialize successfully, otherwise return -1.
//
//******************************************************************************************
extern int Stack_Push(Stack_t* pStack, void* pElement);

//******************************************************************************************
//
//! \brief  Stack is empty ?
//!
//! \param  [in] pStack is the pointer of valid stack.
//!
//! \retval - 1 Stack is empty
//!         - 0 Stack is not empty.
//
//******************************************************************************************
extern int Stack_IsEmpty(Stack_t* pStack);


#ifdef __cplusplus
}
#endif

#endif // __STACK_H__
