cmake_minimum_required(VERSION 3.6)
project(Sharp)

set(CMAKE_C_STANDARD 11)

#set(POSIX "os")
if (POSIX)

    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
#-fsanitize=address -fno-omit-frame-pointer
    set(CMAKE_CXX_FLAGS_DEBUG  " -std=c++11 -O0 -Werror -pthread -lstdc++ -g ${CMAKE_CXX_FLAGS_DEBUG}")
    set(CMAKE_CXX_FLAGS_MINSIZEREL  "-Werror -lstdc++ -s -O3 -Ofast -ldl ${CMAKE_CXX_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE  " -pthread -lstdc++ -O3 -Ofast -ldl ${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO   " -pthread -lstdc++ -O3 -Ofast -ldl ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
    set(CMAKE_CXX_FLAGS_RELEASE   " -pthread -lstdc++ -O3 -Ofast -ldl ${CMAKE_CXX_FLAGS_RELEASE}")
else()

    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

    set(CMAKE_CXX_FLAGS_DEBUG  "-std=c++11 -Werror -g -lstdc++ -O0  -gdwarf-2 ${CMAKE_C_FLAGS_DEBUG}")
    set(CMAKE_CXX_FLAGS_MINSIZEREL  "-std=c++11  -Werror -lstdc++ -s -O3 -Ofast ${CMAKE_C_FLAGS_MINSIZEREL}")
    set(CMAKE_CXX_FLAGS_RELEASE   "-std=c++11  -Werror -lstdc++  -O3 -g -Ofast ${CMAKE_C_FLAGS_RELEASE}")
endif ()

set(SHARPC "build")

# compiler
if (SHARPC)
    add_definitions(-DMAKE_COMPILER)
    file(GLOB old_src
#            "lib/old_grammar/parser/Parser.cpp"
#            "lib/old_grammar/parser/Parser.h"
            )

    set(SOURCE_FILES ${old_src} main.cpp stdimports.h lib/grammar/List.h lib/grammar/backend/data/Literal.cpp lib/grammar/backend/data/Literal.h lib/grammar/backend/Expression.h lib/grammar/backend/Expression.cpp lib/grammar/backend/code/CodeHolder.h lib/grammar/backend/data/Utype.h lib/grammar/backend/data/Utype.cpp lib/grammar/backend/ReferencePointer.h lib/grammar/backend/ReferencePointer.cpp lib/grammar/backend/Scope.h lib/grammar/main.cpp lib/grammar/main.h lib/grammar/options.h lib/util/zip/zcompress.cpp lib/util/zip/zcompress.h lib/util/zip/zcore.cpp lib/util/zip/zcore.h lib/util/zip/zdecompress.cpp lib/util/zip/zdecompress.h lib/util/zip/zinclude.h lib/grammar/backend/data/DataEntity.h lib/grammar/backend/data/DataEntity.cpp lib/grammar/DataType.h lib/grammar/AccessFlag.h lib/util/zip/zlib.cpp lib/util/zip/zlib.h lib/util/zip/zstream.cpp lib/util/zip/zstream.h lib/util/File.cpp lib/util/File.h lib/util/time.cpp lib/util/time.h lib/util/KeyPair.h lib/grammar/frontend/tokenizer/token.h lib/grammar/frontend/tokenizer/token.cpp lib/grammar/frontend/tokenizer/tokenizer.h lib/grammar/frontend/tokenizer/tokentype.h lib/grammar/frontend/tokenizer/tokenizer.cpp lib/grammar/frontend/ErrorManager.h lib/grammar/frontend/ErrorManager.cpp lib/grammar/frontend/parser/Ast.cpp lib/grammar/frontend/parser/Ast.h lib/grammar/frontend/parser/Parser.cpp lib/runtime/Opcode.h lib/runtime/Opcode.cpp lib/grammar/frontend/parser/Parser.h lib/grammar/backend/Compiler.cpp lib/grammar/backend/Compiler.h lib/grammar/backend/oo/Field.cpp lib/grammar/backend/oo/Field.h lib/grammar/backend/oo/Method.h lib/grammar/backend/oo/Method.cpp lib/grammar/backend/oo/ClassObject.h lib/grammar/backend/oo/ClassObject.cpp lib/grammar/backend/data/Alias.cpp lib/grammar/backend/data/Alias.h lib/runtime/InterruptFlag.h lib/grammar/main.cpp lib/grammar/main.h lib/runtime/ThreadStates.h lib/grammar/backend/Compiler2.cpp lib/grammar/backend/ofuscation/Obfuscater.cpp lib/grammar/backend/ofuscation/Obfuscater.h lib/grammar/generator/ExeBuilder.cpp lib/grammar/generator/ExeBuilder.h lib/grammar/optimizer/Optimizer.cpp lib/grammar/optimizer/Optimizer.h)

    add_executable(Sharpc ${SOURCE_FILES})
else()
    #virtual machine
    add_definitions(-DDEBUGGING)
    file(GLOB jit_SRC
            "lib/util/jit/asmjit/src/asmjit/*.h"
            "lib/util/jit/asmjit/src/asmjit/x86/*.h"
            "lib/util/jit/asmjit/src/asmjit/x86/*.cpp"
            "lib/util/jit/asmjit/src/asmjit/core/*.h"
            "lib/util/jit/asmjit/src/asmjit/core/*.cpp"
    )
    #            "lib/runtime/jit.cpp.old"
    #            "lib/runtime/jit.h.old"
    set(SOURCE_FILES main.cpp  lib/runtime/main.cpp lib/runtime/symbols/string.h lib/runtime/jit/architecture.h lib/runtime/List.h lib/runtime/memory/GarbageCollector.cpp lib/runtime/memory/GarbageCollector.h lib/runtime/symbols/Object.h lib/runtime/symbols/Exception.cpp lib/runtime/symbols/Exception.h lib/runtime/symbols/Field.h lib/runtime/symbols/ClassObject.cpp lib/runtime/symbols/ClassObject.h lib/runtime/register.h lib/runtime/symbols/Method.h lib/util/fmt/include/core.h lib/util/fmt/include/format.h lib/util/fmt/include/format-inl.h lib/util/fmt/include/ostream.h lib/util/fmt/include/posix.h lib/util/fmt/include/printf.h lib/util/fmt/include/ranges.h lib/util/fmt/include/time.h lib/util/fmt/src/format.cc lib/util/fmt/src/posix.cc lib/runtime/Thread.cpp lib/runtime/Thread.h lib/runtime/symbols/Object.cpp lib/runtime/Manifest.h lib/runtime/Manifest.cpp lib/runtime/Exe.h lib/runtime/Exe.cpp lib/util/zip/zcompress.cpp lib/util/zip/zcompress.h lib/util/zip/zcore.cpp lib/util/zip/zcore.h lib/util/zip/zdecompress.cpp lib/util/zip/zdecompress.h lib/util/zip/zinclude.h lib/util/zip/zlib.cpp lib/util/zip/zlib.h lib/util/zip/zstream.cpp lib/util/zip/zstream.h lib/runtime/VirtualMachine.cpp lib/runtime/VirtualMachine.h lib/runtime/main.h lib/util/File.cpp lib/util/File.h lib/util/time.cpp lib/util/time.h lib/util/KeyPair.h stdimports.h lib/runtime/Opcode.h lib/Modules/std.io/fileio.cpp lib/Modules/std.io/fileio.h lib/runtime/profiler.h lib/runtime/profiler.cpp lib/runtime/SignalHandler.cpp lib/runtime/termios.cpp lib/runtime/termios.h lib/Modules/math/cmath.cpp lib/Modules/math/cmath.h lib/Modules/std/Random.cpp lib/Modules/std/Random.h lib/Modules/std.os.gui/win/Gui.cpp lib/Modules/std.os.gui/win/Gui.h ${jit_SRC} lib/runtime/jit/_BaseAssembler.cpp lib/runtime/jit/_BaseAssembler.h lib/runtime/jit/Jit.cpp lib/runtime/jit/Jit.h lib/runtime/jit/x64Assembler.cpp lib/runtime/jit/x64Assembler.h lib/runtime/Opcode.cpp lib/util/HashMap.h lib/runtime/symbols/symbol.h lib/runtime/symbols/symbol.cpp lib/runtime/symbols/param.h lib/Modules/std.io/memory.cpp lib/Modules/std.io/memory.h lib/runtime/snb/snb.cpp lib/runtime/snb/snb.h lib/runtime/Library.h lib/runtime/snb/util.h)
    if (POSIX)
        set(LRT_LIB -lrt -ldl)
    endif ()

    add_executable(Sharp ${SOURCE_FILES})

    if (POSIX)
        target_link_libraries(Sharp ${LRT_LIB})
    endif ()
endif ()
