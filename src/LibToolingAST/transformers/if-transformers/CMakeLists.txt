# Enable Exceptions
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcxx-exceptions")

add_executable(ifelse_transformer
        IfElseTransformer.cpp
        ../lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        ifelse_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(switch_transformer
        SwitchTransformer.cpp
        ../lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        switch_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(flattenif_transformer
        FlattenIfTransformer.cpp
        ../lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        flattenif_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")