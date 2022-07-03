# CMakeList.txt: проект CMake для Mailbox Akutonn; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Mailbox Akutonn")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "Mailbox Akutonn.cpp" "Mailbox Akutonn.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
