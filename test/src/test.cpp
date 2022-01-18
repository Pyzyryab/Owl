#include "../../include/Owl/Owl.hpp"
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace HelloOwlTest
{

    TEST_MODULE_INITIALIZE(ModuleInitialize)
    {
        Logger::WriteMessage("In Module Initialize");
    }

    TEST_MODULE_CLEANUP(ModuleCleanup)
    {
        Logger::WriteMessage("In Module Cleanup");
    }

    TEST_CLASS(Test1) {
        public:
            TEST_METHOD(IsPowerOfTwo)
            {
                Assert::IsTrue(is_power_of_two(8));
            }

            TEST_METHOD(MultiplyByTwo)
            {
                Assert::AreEqual(14, multiply_by_two(7));
            }

            TEST_METHOD(DivideByTwo)    {
                Assert::AreEqual(-4, divide_by_two(-7));
            }
    };
}
