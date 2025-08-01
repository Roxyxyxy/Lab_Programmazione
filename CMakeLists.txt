cmake_minimum_required(VERSION 3.25)
project(myToDoList)

set(CMAKE_CXX_STANDARD 17)

# File sorgenti per l'eseguibile principale
add_executable(myToDoList 
    main.cpp 
    ToDoList.cpp 
    ToDo.cpp 
    Date.cpp
)
