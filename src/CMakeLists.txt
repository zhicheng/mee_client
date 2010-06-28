# find json-c library
find_path (JSON_INCLUDE_DIR json/json.h)
find_library (JSON_LIBRARY NAMES json)
if (JSON_INCLUDE_DIR AND JSON_LIBRARY)
    message (STATUS "Found JSON-C: ${JSON_LIBRARY}")
    include_directories ("${JSON_INCLUDE_DIR}")
else (JSON_INCLUDE_DIR AND JSON_LIBRARY)
    message(SEND_ERROR "Could not find JSON-C library")
endif (JSON_INCLUDE_DIR AND JSON_LIBRARY)

# find curl library
find_package (CURL)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
else (CURL_FOUND)
    message (SEND_ERROR "Could not find CURL library")
endif (CURL_FOUND)

add_library (utils STATIC utils.c)

add_executable(mc main.c)
target_link_libraries (mc ${JSON_LIBRARY})
target_link_libraries (mc ${CURL_LIBRARY})
target_link_libraries (mc utils)

install (TARGETS mc RUNTIME DESTINATION bin)
