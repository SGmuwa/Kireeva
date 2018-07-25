// Kireeva.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "getMaxPath_Maria.h"
#include "UserInterface.h"

#include "Tests.h"

int main() {
	printf("Start test...\n");
	runTest();
	printf("Starting the source program...\n");
	getMaxPath_Maria_UserInterface();
	printf("Exit...\n");
	scanf_s("%*c%*c");
	return 0;
}