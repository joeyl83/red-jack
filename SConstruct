import os

godot_cpp_path = "godot-cpp"

env = Environment(
    CXX="clang++",
    CCFLAGS=[
        "-std=c++17",
        "-fPIC",
        "-g"
    ],
    CPPPATH=[
        godot_cpp_path + "/include",
        godot_cpp_path + "/gen/include",
        godot_cpp_path + "/gdextension"
    ],
    LIBPATH=[
        godot_cpp_path + "/bin"
    ],
    LIBS=[
        "godot-cpp.macos.template_release.universal"
    ]
)

sources = Glob("src/*.cpp")

if not os.path.exists("bin"):
    os.makedirs("bin")

target = env.SharedLibrary(
    target="bin/game",
    source=sources
)

Default(target)
