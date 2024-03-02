# Enable Exceptions
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcxx-exceptions")

add_executable(for_transformer
        for_transformer.cpp
        ControlDataFlow/ControlFlowGraphCore.cpp
        ControlDataFlow/CDFGraphQueryHandler.cpp
        ControlDataFlow/DFSVisitor.cpp
        ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        utils_transform.cpp
        lib/SourceTextHelper.cpp
        ../Utilities/Utils.cpp)
TARGET_LINK_LIBRARIES(
        for_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(while_transformer
        while_transformer.cpp
        utils_transform.cpp
        ControlDataFlow/ControlFlowGraphCore.cpp
        ControlDataFlow/CDFGraphQueryHandler.cpp
        ControlDataFlow/DFSVisitor.cpp
        ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        ../Utilities/Utils.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        while_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(fctcreator_transformer
        fctcreator_transformer.cpp
        ControlDataFlow/ControlFlowGraphCore.cpp
        ControlDataFlow/CDFGraphQueryHandler.cpp
        ControlDataFlow/DFSVisitor.cpp
        ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        utils_transform.cpp
        lib/SourceTextHelper.cpp
        ../Utilities/Utils.cpp
        RenamingGuide.cpp
        )
TARGET_LINK_LIBRARIES(
        fctcreator_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(fctremoval_transformer
        fctremoval_transformer.cpp
        ControlDataFlow/ControlFlowGraphCore.cpp
        ControlDataFlow/CDFGraphQueryHandler.cpp
        ControlDataFlow/DFSVisitor.cpp
        ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        utils_transform.cpp
        lib/SourceTextHelper.cpp
        ../Utilities/Utils.cpp
        RenamingGuide.cpp
        FunctionRemovalTransformer.cpp)
TARGET_LINK_LIBRARIES(
        fctremoval_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(if_transformer
        if_transformer.cpp
        utils_transform.cpp
        ../Utilities/Utils.cpp)
TARGET_LINK_LIBRARIES(
        if_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(compoundstmt_transformer
        compoundstmt_transf.cpp
        utils_transform.cpp
        ../Utilities/Utils.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        compoundstmt_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(datastructure_transformer
        datastructure_transformer.cpp
        utils_transform.cpp
        ../Utilities/Utils.cpp
        ControlDataFlow/ControlFlowGraphCore.cpp
        ControlDataFlow/CDFGraphQueryHandler.cpp
        ControlDataFlow/DFSVisitor.cpp
        ControlDataFlow/ControlFlowGraphWithDataFlow.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        datastructure_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")


add_executable(init_decl_transformer
        init_decl_transformer.cpp
        utils_transform.cpp
        ../Utilities/Utils.cpp
        ../Utilities/Utils_Declarations.cpp
        lib/SourceTextHelper.cpp
        ControlDataFlow/DeclRefMapping/DeclRefMapping.cpp
        )
TARGET_LINK_LIBRARIES(
        init_decl_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(paren_transformer
        paren_transformer.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        paren_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(compoundassign_transformer
        CompoundAssignmentTransformer.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        compoundassign_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(comma_transformer
        CommaOperatorTransformer.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        comma_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(main_transformer
        MainTransformer.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        main_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(braces_transformer
        AddBracesTransformer.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        braces_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(multidecl_transformer
        SplitMultiDeclTransformer.cpp
        lib/SourceTextHelper.cpp
        )
TARGET_LINK_LIBRARIES(
        multidecl_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_executable(codeclone_transformer
        codecloneremoval_transformer.cpp
        lib/SourceTextHelper.cpp
        RenamingGuide.cpp
        )
TARGET_LINK_LIBRARIES(
        codeclone_transformer
        -Wl,--start-group "${PROJECT_LINK_LIBS}" -Wl,--end-group
        "${MY_LLVM_LIBS} ${MY_SYSTEM_LIBS}")

add_subdirectory(lib)
add_subdirectory(return-transform)
add_subdirectory(include-add)
add_subdirectory(include-sort)
add_subdirectory(for-transform)
add_subdirectory(naming-transformers)
add_subdirectory(typedef-transform)
add_subdirectory(IOTransformers)
add_subdirectory(unused-stuff)
add_subdirectory(if-transformers)
add_subdirectory(preparing)