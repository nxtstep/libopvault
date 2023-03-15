find_package(CRYPTOPP REQUIRED)
find_package(LIBUUID REQUIRED)
find_package(SQLITE3 REQUIRED)

if(NOT CRYPTOPP_FOUND)
   message("FATAL CRYPTOPP is NOT FOUND")
else()
  include_directories(${CRYPTOPP_INCLUDE_DIRS})
endif()

if(NOT LIBUUID_FOUND)
  message("FATAL LIBUUID is NOT FOUND")
else()
  include_directories(${LIBUUID_INCLUDE_DIRS})
endif()

if(NOT SQLITE3_FOUND)
  message("FATAL SQLITE3 is NOT FOUND")
else()
  include_directories(${SQLITE3_INCLUDE_DIRS})
endif()

#aux_source_directory(../include SRC_LIST)
aux_source_directory(. SRC_LIST)
#add_library(${PROJECT_NAME} STATIC ${SRC_LIST})
add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

#target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
#target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

target_link_libraries(${PROJECT_NAME} PUBLIC cryptopp::cryptopp SQLite::SQLite3 libuuid::libuuid)
