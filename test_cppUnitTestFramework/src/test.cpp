#pragma once


// #include <Owl/Owl.hpp>
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HelloOwlTest
{
    BEGIN_TEST_MODULE_ATTRIBUTE()
        TEST_MODULE_ATTRIBUTE(L"Date", L"2010/6/12")
    END_TEST_MODULE_ATTRIBUTE()

    TEST_MODULE_INITIALIZE(ModuleInitialize)
    {
        Logger::WriteMessage("In Module Initialize");
    }

    TEST_MODULE_CLEANUP(ModuleCleanup)
    {
        Logger::WriteMessage("In Module Cleanup");
    }

    TEST_CLASS(Class1)
    {

    public:

        Class1()
        {
            Logger::WriteMessage("In Class1");
        }

        ~Class1()
        {
            Logger::WriteMessage("In ~Class1");
        }

        TEST_CLASS_INITIALIZE(ClassInitialize)
        {
            Logger::WriteMessage("In Class Initialize");
        }

        TEST_CLASS_CLEANUP(ClassCleanup)
        {
            Logger::WriteMessage("In Class Cleanup");
        }

        TEST_METHOD(Method1)
        {
            Logger::WriteMessage("In Method1");
            Assert::AreEqual(0, 1);
        }

        TEST_METHOD(Method2)
        {
            Assert::Fail(L"Fail");
        }
    };
}