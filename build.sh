
if [ $# -eq 0] then # https://stackoverflow.com/questions/6482377/check-existence-of-input-argument-in-a-bash-shell-script
    output=build
    [ ! -d "$output" ] && mkdir $output && cd $output
    cmake ..
    cmake --build .
    cd ..
else # build wasm
    output=wasm
    [ ! -d "$output" ] && mkdir $output && cd $output
    cmake -DCMAKE_TOOLCHAIN_FILE=$EMSDK/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../
    make
    cd ..
fi