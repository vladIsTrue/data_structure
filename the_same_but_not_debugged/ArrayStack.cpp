#include "ArrayStack.h"

bool ArrayStack::is_empty()
{
    return top == -1;
}


void ArrayStack::push(const int value)
{
    if (top < size - 1)
    {
        top++; stack[top] = value;
    }
}


void ArrayStack::pop()
{
    if (top >= 0)
    {
        top--;
    }
}


int ArrayStack::peek()
{
    return stack[top];
}


void ArrayStack::clear()
{
    top = -1;
}
