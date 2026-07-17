{
    files = {
        [[build\.objs\image_viewer\windows\x64\release\src\imgui\imgui.cpp.obj]],
        [[build\.objs\image_viewer\windows\x64\release\src\imgui\imgui_demo.cpp.obj]],
        [[build\.objs\image_viewer\windows\x64\release\src\imgui\imgui_draw.cpp.obj]],
        [[build\.objs\image_viewer\windows\x64\release\src\imgui\imgui_tables.cpp.obj]],
        [[build\.objs\image_viewer\windows\x64\release\src\imgui\imgui_widgets.cpp.obj]],
        [[build\.objs\image_viewer\windows\x64\release\src\main.cpp.obj]]
    },
    values = {
        [[C:\mingw64\bin\x86_64-w64-mingw32-g++]],
        {
            "-m64",
            "-Llib",
            "-lSDL3",
            "-lshell32",
            "-luser32",
            "-lgdi32",
            "-lwinmm",
            "-limm32",
            "-lole32",
            "-loleaut32",
            "-lversion",
            "-lsetupapi"
        }
    }
}