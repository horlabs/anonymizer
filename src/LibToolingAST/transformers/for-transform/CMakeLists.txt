set(LLVM_LINK_COMPONENTS support)

add_executable(extended_for_transformer
        ForStatementTransformMain.cpp
        ../lib/SourceTextHelper.cpp
        ForStatementTransform.cpp
        ConvertForRangeStatement.cpp
        ForStatementToWhileStatement.cpp
        )

target_include_directories(extended_for_transformer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/)

target_link_libraries(extended_for_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")
