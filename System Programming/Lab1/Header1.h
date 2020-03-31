#pragma once
#include "pch.h"
#include <iostream>
#include <objbase.h>

//Èםעונפויסû
interface IX :IUnknown
{
	virtual void __stdcall Fx() = 0;
	virtual void __stdcall SqrX() = 0;
};

interface IY :IUnknown
{
	virtual void __stdcall Fy() = 0;
};
