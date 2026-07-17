add_rules("mode.debug", "mode.release")

set_project("image_viewer")
set_languages("c++17")

-- use mingw toolchain (matches the SDL3 mingw build you downloaded)
set_toolchains("mingw")

target("image_viewer")
    set_kind("binary")

    -- your source files
    add_files("src/main.cpp")

    -- imgui source, compiled directly into the binary
    add_files("src/imgui/*.cpp")

    -- header search paths
    add_includedirs("include")
    add_includedirs("include/imgui")
    add_includedirs("include/imgui/backends")
    add_includedirs("include/stb")
    add_includedirs("include/SDL3")

    -- lib search path
    add_linkdirs("lib")

    -- link SDL3 (mingw import lib is libSDL3.dll.a -> xmake resolves "SDL3" to it)
    add_links("SDL3")

    -- windows system libs SDL3 needs under mingw
    add_syslinks("shell32", "user32", "gdi32", "winmm", "imm32", "ole32", "oleaut32", "version", "setupapi")

    -- output the exe into bin/, next to the dlls
    set_targetdir("bin")