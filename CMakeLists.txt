cmake_minimum_required(VERSION 3.8)

project(dmsubprocess)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(cmake/ModuleImport.cmake)
include(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

set(DMSUBPROCESS_VERSION_MAJOR "1")
set(DMSUBPROCESS_VERSION_MINOR "0")
set(DMSUBPROCESS_VERSION_PATCH "1")
set(DMSUBPROCESS_VERSION "${DMSUBPROCESS_VERSION_MAJOR}.${DMSUBPROCESS_VERSION_MINOR}.${DMSUBPROCESS_VERSION_PATCH}")

message(STATUS "VERSION: ${DMSUBPROCESS_VERSION}")

option(USE_DMSUBPROCESS "use dmsubprocess" OFF)

ModuleImportAll("thirdparty")
LibImport("dmsubprocess" "src/dmsubprocess")

if(PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "dmsubprocess")
endif()
