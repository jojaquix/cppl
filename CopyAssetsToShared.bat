@echo off

set BUILD_CONFIG=Debug
set SOURCE_DIR=.\\build
set DEST_DIR=C:\\Users\\Jhon\Documentos\shared_vm

copy "%SOURCE_DIR%\\src\\%BUILD_CONFIG%\\cppl.exe" "%DEST_DIR%"
copy "%SOURCE_DIR%\\test\\%BUILD_CONFIG%\\tests.exe" "%DEST_DIR%"

echo Files copied successfully!