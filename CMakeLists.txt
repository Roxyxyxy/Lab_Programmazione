cmake_minimum_required(VERSION 3.25)
project(myToDoList)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fd7e4e0d09b15a5a15af2e.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Libreria con le classi (senza main)
add_library(todolib 
    ToDoList.cpp 
    ToDo.cpp 
    Date.cpp
)

# File sorgenti per l'eseguibile principale
add_executable(myToDoList 
    main.cpp
)

# Link della libreria all'eseguibile principale
target_link_libraries(myToDoList todolib)

# Test
enable_testing()

add_executable(
  todo_tests
  test/test_todolist.cpp
)

target_link_libraries(
  todo_tests
  todolib
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(todo_tests)
