cmake_minimum_required(VERSION 3.10)
project(myToDoList)

# Usa C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fd7e4e0d09b15a5a15af2e.zip
)
FetchContent_MakeAvailable(googletest)

# Creo l'applicazione principale
add_executable(myToDoList 
    main.cpp
    ToDoList.cpp 
    ToDo.cpp 
    Date.cpp
)

# Creo i test (tutti i file insieme)
add_executable(todo_tests
    test/test_todo.cpp
    test/test_todolist.cpp
    test/test_date.cpp
    ToDoList.cpp 
    ToDo.cpp 
    Date.cpp
)

# Collego GoogleTest ai miei test
target_link_libraries(todo_tests gtest_main)

# Abilito i test
enable_testing()
add_test(NAME AllTests COMMAND todo_tests)
