@echo off

set BUILD_CONFIG=Debug
set BUILD_DIR=build
set TARGET_EXEC=cppl.exe

rem Create build directory if it doesn't exist 
if not exist %BUILD_DIR% mkdir %BUILD_DIR%  

pushd %BUILD_DIR%

if not exist CMakeCache.txt (
    cmake ..
)

rem Build the project
cmake --build . --config %BUILD_CONFIG%

rem Run the executable
.\src\%BUILD_CONFIG%\%TARGET_EXEC%


popd