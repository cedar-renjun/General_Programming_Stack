#include "Stack.h"

#ifdef USE_MEMORY_ALLOC
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
Stack_t* Stack_Create(uint32_t StackSize, uint32_t UnitSize)
{
    Stack_t*  pStack         = NULL;         //!< Stack Pointer
    uint8_t*  pStackBaseAddr = NULL;         //!< Stack Memory Base Address

    //! Check stack parameters.
    if(StackSize <= UnitSize)
    {
        //! Error, exit now.
        return (NULL);
    }

    //! Allocate Memory for pointer of new stack.
    pStack = (Stack_t*) malloc(sizeof(Stack_t));
    if(NULL == pStack)
    {
        //! Allocate Failure, exit now.
        return (NULL);
    }

    //! Allocate memory for stack.
    pStackBaseAddr = malloc(StackSize);
    if(NULL == pStackBaseAddr)
    {
        //! Allocate Failure, exit now.
        return (NULL);
    }

    //! Initialize General Stack.
    Stack_Init(pStack, pStackBaseAddr, StackSize, UnitSize);

    return (pStack);
}

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
void Stack_Destory(Stack_t* pStack)
{
    //! Check stack parameters.
    if(NULL == pStack || NULL == pStack->pBaseAddr)
    {
        return; //!< Failure
    }

    //! Free stack memory
    free(pStack->pBaseAddr);

    //! Reset stack parameters
    pStack->pBaseAddr = NULL;
    pStack->pEndAddr  = NULL;
    pStack->pIndex    = NULL;
    pStack->UnitSize  = NULL;

    return;     //!< Success
}
#endif // USE_MEMORY_ALLOC

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
int Stack_Init(Stack_t* pStack, void* pStackBaseAddr, uint32_t StackSize, uint32_t UnitSize)
{
    //! Check stack parameters.
    if(NULL == pStack || NULL == pStackBaseAddr || StackSize <= UnitSize)
    {
        //! Error, exit now.
        return (-1);
    }

    //! Success, Initilize stack
    pStack->pBaseAddr = (uint8_t*) pStackBaseAddr;
    pStack->pEndAddr  = (uint8_t*) ((uint32_t)pStackBaseAddr + StackSize);
    pStack->pIndex    = (uint8_t*) pStackBaseAddr;
    pStack->UnitSize  = UnitSize;

    return (0);

}

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
int Stack_Pop(Stack_t* pStack, void* pElement)
{
    uint8_t * _pElement = (uint8_t *)pElement;
    int i = 0;

    //! Check stack parameters.
    if(NULL == pStack || NULL == pElement)
    {
        //! Error, exit now.
        return (-1);
    }

    //! UnderFlow ?
    if(pStack->pIndex < pStack->pBaseAddr + pStack->UnitSize)
    {
        //! Error, Stack is empty!
        return (-1);
    }

    //! Move Stack Pointer
    pStack->pIndex = pStack->pIndex - pStack->UnitSize;

    //! Copy Data
    for(i = 0; i < pStack->UnitSize; i++)
    {
        *_pElement++ = *(pStack->pIndex + i);
    }

    return (0);
}

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
int Stack_Push(Stack_t* pStack, void* pElement)
{
    uint8_t * _pElement = (uint8_t *)pElement;
    int i = 0;

    //! Check stack parameters.
    if(NULL == pStack || NULL == pElement)
    {
        //! Error, exit now.
        return (-1);
    }

    //! Overflow ?
    if(pStack->pIndex + pStack->UnitSize > pStack->pEndAddr)
    {
        return (-1);
    }

    //! Copy Data
    for(i = 0; i < pStack->UnitSize; i++)
    {
         *(pStack->pIndex++) = *_pElement++;
    }

    return (NULL);
}

