cmake_minimum_required(VERSION 3.2)

PROJECT(dmsubprocess)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMSUBPROCESS_VERSION_MAJOR "1")
SET(DMSUBPROCESS_VERSION_MINOR "0")
SET(DMSUBPROCESS_VERSION_PATCH "1")
SET(DMSUBPROCESS_VERSION "${DMSUBPROCESS_VERSION_MAJOR}.${DMSUBPROCESS_VERSION_MINOR}.${DMSUBPROCESS_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMSUBPROCESS_VERSION}")

OPTION(USE_DMSUBPROCESS "use dmsubprocess" OFF)

ModuleImportAll("thirdparty")
LibImport("dmsubprocess" "src/dmsubprocess")
ExeImport("test" "dmsubprocess")

#ADD_CUSTOM_COMMAND(
#TARGET dmsubprocesstest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmsubprocesstest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmsubprocess
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMSUBPROCESS_LIBS "dmsubprocess")
#MARK_AS_ADVANCED(${DMSUBPROCESS_LIBS})