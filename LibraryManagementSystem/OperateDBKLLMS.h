#pragma once
#include "PatronsLinkedList.h"
class OperateDBKLLMS
{
public:
	static int start();
private:
	OperateDBKLLMS() = delete;										// mark the default constructor as deleted function to prevent any object instantiation
	OperateDBKLLMS(const OperateDBKLLMS &operateDBKLLMS) = delete;  // mark the copy constructor as a deleted function
};