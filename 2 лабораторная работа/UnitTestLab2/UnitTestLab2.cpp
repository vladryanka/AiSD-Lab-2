#include "pch.h"
#include "CppUnitTest.h"
#include "../2 лабораторная работа/2lab.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2
{
	TEST_CLASS(UnitTestLab2)
	{
	public:

		TEST_METHOD(Method_BinarySearch)
		{
			const int n = 6;
			int mas[n] = { 1,2,5,18,20,91 };
			int find = 5;
			int check;
			for (int i = 0; i < n; i++)
			{
				find = mas[i];
				check = BinarySearch(mas, find);
				Assert::IsTrue(check == i);
			}
		}
		TEST_METHOD(Method_QuickSearch)
		{
			const int n = 6;
			int mas[n] = { 5,7,0,9,21,2 };
			QuickSort(mas, n);
			bool answer;
			for (int i = 0; i < n-1; i++)
			{
				if (mas[i] < mas[i + 1])
					answer = true;
				else answer = false;
			}
			Assert::IsTrue(answer == true);
		}
		TEST_METHOD(Method_InsertionSort)
		{
			const int n = 6;
			int mas[n] = { 5,7,0,9,21,2 };
			InsertionSort(mas, n);
			bool answer;
			for (int i = 0; i < n-1; i++)
			{
				if (mas[i] < mas[i + 1])
					answer = true;
				else answer = false;
			}
			Assert::IsTrue(answer == true);
		}
		TEST_METHOD(Method_BogoSort)
		{
			const int n = 6;
			int mas[n] = { 5,7,0,9,21,2 };
			BogoSort(mas, n);
			bool answer;
			for (int i = 0; i < n-1; i++)
			{
				if (mas[i] < mas[i + 1])
					answer = true;
				else answer = false;
			}
			Assert::IsTrue(answer == true);
		}
		TEST_METHOD(Method_CountingSort)
		{
			const int n = 6;
			char mas[n] = { 'c','d','e','v','g','v' };
			CountingSort(mas);
			bool answer;
			for (int i = 0; i < n-1; i++)
			{
				if (mas[i] <= mas[i + 1])
					answer = true;
				else answer = false;
			}
			Assert::IsTrue(answer == true);
		}
	}; 
}
