{
    depfiles_format = "gcc",
    values = {
        [[C:\mingw64\bin\x86_64-w64-mingw32-g++]],
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++17",
            "-Iinclude",
            [[-Iinclude\imgui]],
            [[-Iinclude\imgui\backends]],
            [[-Iinclude\stb]],
            [[-Iinclude\SDL3]],
            "-fexceptions",
            "-DNDEBUG"
        }
    },
    depfiles = "imgui_tables.o: src\\imgui\\imgui_tables.cpp include\\imgui/imgui.h  include\\imgui/imconfig.h include\\imgui/imgui_internal.h\
",
    files = {
        [[src\imgui\imgui_tables.cpp]]
    }
}