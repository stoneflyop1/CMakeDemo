if ($args.count -eq 0) {
    $outputDir = "build"
    if (-not (Test-Path $outputDir)) {
        New-Item -ItemType Directory -Force -Path $outputDir
    }
    Set-Location $outputDir
    cmake ..
    cmake --build .
    Set-Location ..
} else {
    $outputDir = "wasm"
    if (-not (Test-Path $outputDir)) {
        New-Item -ItemType Directory -Force -Path $outputDir
    }
    Set-Location $outputDir
    $emsdk = $Env:EMSDK
    cmake -GNinja  -DCMAKE_TOOLCHAIN_FILE="$emsdk"\upstream\emscripten\cmake\Modules\Platform\Emscripten.cmake -DCMAKE_BUILD_TYPE=Release ..\
    cmake --build . --verbose
    Set-Location ..
}