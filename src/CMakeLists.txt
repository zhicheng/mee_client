# find curl library
find_package (CURL REQUIRED)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
endif (CURL_FOUND)

# find json library
find_package (JSON REQUIRED)
if (JSON_FOUND)
    include_directories(${JSON_INCLUDE_DIR})
endif (JSON_FOUND)

add_library (utils STATIC utils.c)

add_executable(mc main.c)
target_link_libraries (mc ${JSON_LIBRARY})
target_link_libraries (mc ${CURL_LIBRARY})
target_link_libraries (mc utils)

install (TARGETS mc RUNTIME DESTINATION bin)
