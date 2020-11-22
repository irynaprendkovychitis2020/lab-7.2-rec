#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2 rek/lab 7.2 rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rowCount = 3;
            int colCount = 3;

            int** a = new int* [rowCount];

            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            int expected = 0;

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = j;

            int functionResult = SearchMin(a, 0, 0);

            Assert::AreEqual(expected, functionResult);


		}
	};
}
