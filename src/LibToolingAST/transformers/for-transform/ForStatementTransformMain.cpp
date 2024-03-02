#include "ForStatementTransform.h"
#include "StatusCodes.h"
#include "clang/Format/Format.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Tooling/CommonOptionsParser.h"

static OptionCategory MyToolCategory("comp-transform options");
static opt<bool> Inplace("i", desc("Overwrite edited <file>s."),
                         cat(MyToolCategory));
opt<Strategies>
    Strategy("strategy", desc("Transformation strategy:"), Required,
             values(clEnumValN(S_ForStmtToWhileStmt, "forStmt2WhileStmt",
                               "Convert for statement to while statement"),
                    clEnumValN(S_ConvertForRangeStmt, "convertForRange",
                               "Convert for range statement")),
             cat(MyToolCategory));
opt<int> Seed("seed", desc("PRNG seed"), init(0), cat(MyToolCategory));
static opt<string> Style("style",
                         desc(clang::format::StyleOptionHelpDescription),
                         init("LLVM"), cat(MyToolCategory));

int main(int argc, const char **argv) {
    CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
    RefactoringTool Tool(OptionsParser.getCompilations(),
                         OptionsParser.getSourcePathList());
    ForStmtTransformationAction TransformAction(Tool.getReplacements());
    auto Factory = tooling::newFrontendActionFactory(&TransformAction);

    int ExitCode;
    ExitCode = Tool.run(Factory.get());
    if (Tool.getReplacements().empty()) {
        return TRANSFORMATION_NOT_APPLICABLE;
    }

    LangOptions DefaultLangOptions;
    IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts = new DiagnosticOptions();
    TextDiagnosticPrinter DiagnosticPrinter(llvm::errs(), &*DiagOpts);
    DiagnosticsEngine Diagnostics(
        IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs()), &*DiagOpts,
        &DiagnosticPrinter, false);
    SourceManager Sources(Diagnostics, Tool.getFiles());
    Rewriter Rewrite(Sources, DefaultLangOptions);
    tooling::formatAndApplyAllReplacements(Tool.getReplacements(), Rewrite,
                                           Style);

    if (Inplace) {
        ExitCode = Rewrite.overwriteChangedFiles();
    } else {
        for (const auto &File : OptionsParser.getSourcePathList()) {
            const auto *Entry = Tool.getFiles().getFile(File);
            const auto ID = Sources.getOrCreateFileID(Entry, SrcMgr::C_User);
            Rewrite.getEditBuffer(ID).write(llvm::outs());
        }
    }
    return ExitCode;
}
