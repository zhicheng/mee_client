# find json-c library
find_path (JSON_INCLUDE_DIR json/json.h)
find_library (JSON_LIBRARY NAMES json)
if (JSON_INCLUDE_DIR AND JSON_LIBRARY)
    set (JSON_FOUND TRUE)
endif (JSON_INCLUDE_DIR AND JSON_LIBRARY)

if (JSON_FOUND)
    if (NOT JSON_FIND_QUIETLY)
        message (STATUS "Found JSON: ${JSON_LIBRARY}")
    endif (NOT JSON_FIND_QUIETLY)
else (JSON_FOUND)
    if (JSON_FIND_REQUIRED)
        message (FATAL_ERROR "Could not find json library")
    endif (JSON_FIND_REQUIRED)
endif (JSON_FOUND)
        

