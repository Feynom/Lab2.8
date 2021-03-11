#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2.8/Lab2.8/Triangle.h"
#include "../Lab2.8/Lab2.8/Triangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest28
{
	TEST_CLASS(UnitTest28)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Triangle::Angle A(90, 0), B(180, 0);
			Assert::AreEqual(round(A.getSin()), 1.);
			Assert::AreEqual(round(B.getSin()), 0.);
		}
	};
}
