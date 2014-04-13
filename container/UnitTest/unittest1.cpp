#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\ComponentsProject\List.h"




using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(ElemInitTest)
		{
			int initValue = 50;

			Elem<int> *elem = new Elem<int>(50, 0);

			Assert::AreEqual(elem->getValue(), initValue);
		}
		TEST_METHOD(ElemSetNextTest)
		{
			int thirdValue = 3;

			Elem<int> *first = new Elem<int>(1, 0);
			Elem<int> *second = new Elem<int>(2, 0);
			Elem<int> *third = new Elem<int>(thirdValue, 0);
			first->setNext(second);
			second->setNext(third);

			Elem<int> *iter = first;
			Assert::AreEqual(iter->getNext()->getNext()->getValue(), thirdValue);
		}

		TEST_METHOD(ListAddElemTest)
		{
			List<int> *list = new List<int>();

			int size = 3;

			for (int i = 0; i < 3; i++)
				list->addElem(i);
			Assert::AreEqual(3, list->size());
		}
		TEST_METHOD(ListGetNullTest)
		{
			List<int> *list = new List<int>();
			list->addElem(3);

			Assert::IsNull(list->getElem(-50));
		}
		TEST_METHOD(ListGetNotNullTest)
		{
			List<int> *list = new List<int>();
			list->addElem(3);

			Assert::IsNotNull(list->getElem(0));
		}
	};

}