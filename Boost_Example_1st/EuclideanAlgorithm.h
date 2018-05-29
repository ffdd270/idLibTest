#pragma once
#include "Example.h"
class EuclideanAlgorithm :
	public IExample
{
public:
	EuclideanAlgorithm();
	int start(int argc, char * argv[]) override;
	~EuclideanAlgorithm();
};

