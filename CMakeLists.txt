# CMakeList.txt: projeto de CMake para design patterns, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project ("design patterns")

# Adicione a origem ao executável deste projeto.
# Design Patterns
add_executable (AbstractFactory "creational/abstractFactory/abstractFactory.h" "creational/abstractFactory/abstractProduct.h" "creational/abstractFactory/clientTest.cpp" "tests.h")
add_executable (Builder "creational/builder/builder.cpp" "creational/builder/builder.h" "tests.h" "creational/builder/builderTest.cpp")
# Behavioral
add_executable(strategy "behavioral/strategy/strategy.cpp")
add_executable(chain "behavioral/chainOfResponsibility/chain.cpp")

#selection
add_executable(selection "selection/selection.cpp")

#Sorting
add_executable (quickSort "sorting/quicksort.cpp")


add_subdirectory(behavioral)

set (Headers
	tests.h)