cmake_minimum_required(VERSION 3.10)
project(myToDoList)

# Usa C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ottimizzazioni per Debug/Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
# Configurazione per Windows (evita conflitti di linking)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Creo l'applicazione principale
add_executable(myToDoList 
    main.cpp
    ToDoList.cpp 
    ToDo.cpp 
    Date.cpp
)

# Eseguibile per i test
add_executable(todo_tests
    test/test_todo.cpp
    test/test_todolist.cpp
    test/test_date.cpp
    ToDoList.cpp 
    ToDo.cpp 
    Date.cpp
)

# Collegamento GoogleTest ai test
target_link_libraries(todo_tests gtest_main)

# Abilito i test
enable_testing()
add_test(NAME AllTests COMMAND todo_tests)
