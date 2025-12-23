@echo off
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
mkdir ..\..\build\maths
pushd ..\..\build\maths
cl /std:c++20 /utf-8 /D_AMD64_ -Zi /EHsc w:\maths\vector.cpp
popd

"W:\build\maths\vector.exe"
