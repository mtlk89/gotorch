
#C:\Users\Owner\Desktop\godot_torch\cmake_godot_test>cl init.obj /c init.cpp /nologo -EHsc -DNDEBUG /MDd /I..\godot-cpp\include
#/I..\godot-cpp\include\core /I..\godot-cpp\include\gen /I..\godot-cpp\godot-headers

#C:\Users\Owner\Desktop\godot_torch\cmake_godot_test>link /nologo /dll /out:bin\libtest.dll /implib:bin\libsimple.lib init.obj
#..\godot-cpp\bin\libgodot-cpp.windows.debug.64.lib

cmake_minimum_required (VERSION 3.8)

project ("gotorch")

set(ROOT "C:\\Users\\Owner\\Desktop\\gotorch\\gotorch")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(Godot_headers_DIR "C:\\Users\\Owner\\Desktop\\gotorch\\godot-cpp\\godot-headers")
set(Godot_include_DIR "C:\\Users\\Owner\\Desktop\\gotorch\\godot-cpp\\include")
set(Godot_include_core_DIR "C:\\Users\\Owner\\Desktop\\gotorch\\godot-cpp\\include\\core")
set(Godot_include_gen_DIR "C:\\Users\\Owner\\Desktop\\gotorch\\godot-cpp\\include\\gen")

set(Torch_DIR "C:\\Users\\Owner\\Desktop\\gotorch\\libtorch\\share\\cmake\\Torch")

find_package(Torch REQUIRED)

include_directories(${Godot_headers_DIR} ${Godot_include_DIR} ${Godot_include_core_DIR} ${Godot_include_gen_DIR})


add_library(gotorch SHARED "src/gdlibrary.cpp" "src/gotorch.h" "src/gotorch.cpp")
target_link_libraries(gotorch "${TORCH_LIBRARIES}" "C:/Users/Owner/Desktop/gotorch/godot-cpp/bin/libgodot-cpp.windows.debug.64.lib")

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET gotorch
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:gotorch>)
endif (MSVC)
