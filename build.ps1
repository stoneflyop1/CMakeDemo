
if ($args.count -eq 0) {
    $build = "build"
    if (-not (Test-Path $build)) {
        New-Item -ItemType Directory -Force -Path $build
    }
    Set-Location $build
    cmake ..
    cmake --build .
    Set-Location ..
} else {
    $wasm = "wasm"
    if (-not (Test-Path $wasm)) {
        New-Item -ItemType Directory -Force -Path $wasm
    }
    Set-Location $wasm
    $emsdk = $Env:EMSDK
    cmake -GNinja  -DCMAKE_TOOLCHAIN_FILE="$emsdk"\upstream\emscripten\cmake\Modules\Platform\Emscripten.cmake -DCMAKE_BUILD_TYPE=Release ..\
    cmake --build .
    Set-Location ..
}