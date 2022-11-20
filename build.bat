if [%1]==[] (
    echo "build"
    set output=build
    if not exist "%output%\" ( mkdir %output% )
    cd %output%
    cmake ..
    cmake --build .
    cd ..
) else (
    echo "wasm"
    set output=wasm
    if not exist "%output%\" ( mkdir %output% )
    cd %output%
    cmake -GNinja  -DCMAKE_TOOLCHAIN_FILE=%EMSDK%\upstream\emscripten\cmake\Modules\Platform\Emscripten.cmake -DCMAKE_BUILD_TYPE=Release ..\
    cmake --build . --verbose
    cd ..
)