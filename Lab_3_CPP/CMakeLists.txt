add_executable(Lab_3_CPP Lab3.cpp)

target_include_directories(Lab_3_CPP PRIVATE ../LibraryCPP)
target_link_libraries(Lab_3_CPP PRIVATE LibraryCPP)

add_test(NAME Lab3_Test1 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test1.txt)
set_tests_properties(Lab3_Test1 PROPERTIES PASS_REGULAR_EXPRESSION "3")

add_test(NAME Lab3_Test2 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test2.txt)
set_tests_properties(Lab3_Test2 PROPERTIES PASS_REGULAR_EXPRESSION "1")

add_test(NAME Lab3_Test3 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test3.txt)
set_tests_properties(Lab3_Test3 PROPERTIES PASS_REGULAR_EXPRESSION "1")

add_test(NAME Lab3_Test4 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test4.txt)
set_tests_properties(Lab3_Test4 PROPERTIES PASS_REGULAR_EXPRESSION "1")

add_test(NAME Lab3_Test5 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test5.txt)
set_tests_properties(Lab3_Test5 PROPERTIES PASS_REGULAR_EXPRESSION "1")

add_test(NAME Lab3_Test6 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test6.txt)
set_tests_properties(Lab3_Test6 PROPERTIES PASS_REGULAR_EXPRESSION "4")

add_test(NAME Lab3_Test7 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test7.txt)
set_tests_properties(Lab3_Test7 PROPERTIES PASS_REGULAR_EXPRESSION "1")

add_test(NAME Lab3_Test8 COMMAND Lab_3_CPP ${CMAKE_CURRENT_SOURCE_DIR}/Tests/test8.txt)
set_tests_properties(Lab3_Test8 PROPERTIES PASS_REGULAR_EXPRESSION "0")

