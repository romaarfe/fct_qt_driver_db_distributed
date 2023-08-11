# Este arquivo CMakeLists.txt define um projeto chamado "newPluginDB".
# O projeto usará Qt 5 ou Qt 6, dependendo da versão do Qt que for encontrada.
cmake_minimum_required(VERSION 3.5)

# Define o nome e a versão do projeto.
project(newPluginDB VERSION 0.1 LANGUAGES CXX)

# Ativa automoc, autoui e autoRCC.
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Define o padrão C++ para 17.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontra Qt 5 ou Qt 6.
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Sql Network sqlcipher dqlite)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Sql Network)

# Define as fontes do projeto.
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Se Qt 6 for encontrado, use qt_add_executable() para criar o executável.
# Caso contrário, use add_executable() se o Android não estiver sendo construído ou add_library() se o Android estiver sendo construído.
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(newPluginDB
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Defina propriedades de destino para o Android com Qt 6 como:
#    set_property(TARGET newPluginDB APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# Para obter mais informações, consulte https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(newPluginDB SHARED
            ${PROJECT_SOURCES}
        )
# Defina propriedades para o Android com Qt 5 após as chamadas find_package() como:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(newPluginDB
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Vincula o executável às bibliotecas Qt.
target_link_libraries(newPluginDB PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Network sqlcipher dqlite)

# Defina as propriedades de destino para o executável.
set_target_properties(newPluginDB PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Instale o executável.
install(TARGETS newPluginDB
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Se Qt 6 for encontrado, finalize o executável.
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(newPluginDB)
endif()
