#pragma once
#ifndef TESTS
#define TESTS

#include <iostream>


void equals_string(std::string expected, std::string actual, std::string testName) {
	if (expected.compare(actual) == 0) {
		std::cout << testName << " ... OK" << std::endl;
	}
	else {
		std::cout << "Expected: " << expected << " >> actual: " << actual << std::endl;
		std::cout << testName << " ... FAILED" << std::endl;
	}
}

#endif // TESTS
