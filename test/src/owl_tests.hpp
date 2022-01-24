/**
 * @brief Acts as a mini-test-framework for the implemented functionalities of the FKW and to
 * test the data and/or the types defined in.
 * 
 * @file owl_tests.cpp
 * @author Pyzyryab 
 * @version 0.1.3
 * @date 2022-01-23
 * @copyright Copyright (c) 2022
 */

#pragma warning disable MSVC(C4018)

#include <vector>
#include <string>

namespace OwlTesting {

    class Tester {
        private:
            //
        public:
            // Run the selected tests
            void run(
                // This should accept a fn pointer or a callback
            );

            /**
             * @brief Makes a console ouput of the elements in a collection if they have overloaded the output insertion operator "<<" 
             * making a pretty print of the content outputted to the console.
             * 
             * @param container Contains the elements to print in the console
             * @param message A raw message to provide it as a title
             */
            template<typename T>
            static void show_collection_elements(std::vector<T> container, std::string message_title) {
                /*
                 *  To pretty print the output, we will divide the content in three parts. 
                 *  1 - The initial message
                 *  2 - The tabulated body with the elements
                 *  3 - The closing element 
                 * 
                 * // TODO Add colors to the console 
                */
                for (int i = 0; i < container.size(); i++) {
                    if (i == 0)
                        // TODO Add a logger with the different logging levels
                        std::cout << "[INFO] - " << message_title << ":" << std::endl;
                    else if (i < container.size() )
                        std::cout << "    - " << container[i] << std::endl;
                    else
                        std::cout << "    - " << container[i] << std::endl << std::endl;
                }   

            }
    };
}