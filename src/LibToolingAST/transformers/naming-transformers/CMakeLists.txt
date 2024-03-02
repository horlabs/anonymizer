# Enable Exceptions
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcxx-exceptions")

add_executable(declname_transformer
        declname_transformer.cpp
        ../ControlDataFlow/ControlFlowGraphCore.cpp
        ../ControlDataFlow/CDFGraphQueryHandler.cpp
        ../ControlDataFlow/DFSVisitor.cpp
        ../ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        ../utils_transform.cpp
        ../lib/SourceTextHelper.cpp
        ../RenamingGuide.cpp
        ../ControlDataFlow/DeclRefMapping/DeclRefMapping.cpp
        VariableNameTransformer.cpp)
TARGET_LINK_LIBRARIES(
        declname_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(global_const_transformer
        global_const_transformer.cpp
        ../utils_transform.cpp
        ../../Utilities/Utils.cpp
        ../lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        global_const_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(itervar_transformer
        itervar_transformer.cpp
        ../AssertRemover.cpp
        ../utils_transform.cpp
        ../ControlDataFlow/DeclRefMapping/DeclRefMapping.cpp
        ../ControlDataFlow/DeclScopeBuilder/DeclScopeBuilder.cpp
        ../ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        ../ControlDataFlow/ControlFlowGraphCore.cpp
        ../ControlDataFlow/CDFGraphQueryHandler.cpp
        ../ControlDataFlow/DFSVisitor.cpp
        ../lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        itervar_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}"
)

# ToDo: clean up
add_executable(bufname_transformer
        bufname_transformer.cpp
        ../utils_transform.cpp
        ../ControlDataFlow/DeclRefMapping/DeclRefMapping.cpp
        ../ControlDataFlow/DeclScopeBuilder/DeclScopeBuilder.cpp
        ../ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        ../ControlDataFlow/ControlFlowGraphCore.cpp
        ../ControlDataFlow/CDFGraphQueryHandler.cpp
        ../ControlDataFlow/DFSVisitor.cpp
        ../lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        bufname_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}"
)

add_executable(numbering_transformer
        numbering_transformer.cpp
        ../AssertRemover.cpp
        ../ControlDataFlow/DeclRefMapping/DeclRefMapping.cpp
        ../ControlDataFlow/ControlFlowGraphCore.cpp
        ../ControlDataFlow/CDFGraphQueryHandler.cpp
        ../ControlDataFlow/DFSVisitor.cpp
        ../ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        ../utils_transform.cpp
        ../lib/SourceTextHelper.cpp
        ../RenamingGuide.cpp
        VariableNameTransformer.cpp TypeMapping.cpp TypeMapping.h)

TARGET_LINK_LIBRARIES(
        numbering_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}"
)