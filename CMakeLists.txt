cmake_minimum_required(VERSION 3.16)

project(sculptor_3d VERSION 0.1 LANGUAGES CXX)

<<<<<<< HEAD
# Desligar AUTOUIC, AUTOMOC e AUTORCC para uma aplicação de console pura
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTORCC OFF)
=======
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
>>>>>>> f4832bb3c02a95e5043b61f0634fe655a309b44f

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

<<<<<<< HEAD
# Encontrar o módulo Core do Qt.
# Se você *realmente* não usa nada do Qt (nem QString, QDebug, etc.),
# esta linha e a de linkagem podem ser removidas.
find_package(Qt6 COMPONENTS Core REQUIRED)

# Seus arquivos de código. sculptor.ui está comentado, então não será processado.
=======
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

>>>>>>> f4832bb3c02a95e5043b61f0634fe655a309b44f
set(PROJECT_SOURCES
        main.cpp
        sculptor.cpp
        sculptor.h
<<<<<<< HEAD
        # sculptor.ui
)

# Cria o executável
add_executable(sculptor_3d ${PROJECT_SOURCES})

# Linka com o Qt Core.
target_link_libraries(sculptor_3d PRIVATE Qt6::Core)

# Configurações mínimas para executável Windows
set_target_properties(sculptor_3d PROPERTIES
    WIN32_EXECUTABLE TRUE
)

# A parte de instalação (install) pode ser mantida, mas não é estritamente necessária para compilar e rodar.
include(GNUInstallDirs)
install(TARGETS sculptor_3d
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
=======
        sculptor.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sculptor_3d
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET sculptor_3d APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(sculptor_3d SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(sculptor_3d
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(sculptor_3d PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.sculptor_3d)
endif()
set_target_properties(sculptor_3d PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS sculptor_3d
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sculptor_3d)
endif()
>>>>>>> f4832bb3c02a95e5043b61f0634fe655a309b44f
