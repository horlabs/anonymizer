add_executable(empty_function_transformer
        RemoveEmptyFunctions.cpp
        RemoveEmptyFunctions.h
        ../../lib/SourceTextHelper.cpp)
TARGET_LINK_LIBRARIES(
        empty_function_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")