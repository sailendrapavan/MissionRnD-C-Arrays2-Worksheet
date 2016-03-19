/*
Well Done for completing the first part of the C Course ,If you didnt finish 
Do complete them and come here again . 

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int main(){
	/*struct transaction Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
	//Test countGreaterNumbers
	int count = countGreaterNumbers(Arr, 5, "09-10-2003");
	//printf("%d", count);*/
	/*struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 60, "22-04-2006", "Sixth" } };
	//int A[3] = { 1, 2, 3 }, B[3] = { 2, 3, 6 };*/
	struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
	struct transaction *result = sortedArraysCommonElements(A, 3, A, 3);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", result[i].amount);
		printf("%s\n", result[i].date);
		printf("%s\n", result[i].description);
	}
	//Test findSingleOccurenceNumber

	//Test mergeSortedArray

	//Test sortedArraysCommonElements

	return 0;
}