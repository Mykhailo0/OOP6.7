#include "pch.h"
#include "CppUnitTest.h"

#include "../OOP6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> sequence1 = { 1, 2, 2, 4, 6, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 4, 6 };
			std::vector<int> pattern = { 2, 4, 6 };

			auto result = search_end(sequence1.begin(), sequence1.end(), pattern.begin(), pattern.end());


			Assert::AreEqual(*result, 2);
		}
	};
}
