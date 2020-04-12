# CMake Demo

Some demos for building C++/C# with cmake.

## Build Console App

Build on Windows
```ps1
build.ps1
```

Build on Unix/Linux/Mac

```sh
. build.sh
```

## Build wasm

1. Install [emsdk](https://emscripten.org/docs/getting_started/downloads.html), and add `emsdk_env` to your shell.
2. If using windows, download [ninja](https://github.com/ninja-build/ninja) as wasm build tool; add `ninja.exe` folder to your `PATH`.

Build on Windows
```ps1
build.ps1 wasm
```

Build on Unix/Linux/Mac

```sh
. build.sh wasm
```

ps: the `wasm` parameter can be anything. you just need to provide a parameter to indicate you want a wasm build.