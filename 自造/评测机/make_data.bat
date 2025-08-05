@echo off
if not exist "data" mkdir data

g++ -o gen.exe gen.cpp -std=c++17
g++ -o std.exe std.cpp -std=c++17

for /l %%i in (1, 1, 10) do (
    gen.exe > data/%%i.in
    std.exe < data/%%i.in > data/%%i.out
    echo Generated test case %%i
)

del gen.exe
del std.exe

echo All test cases generated.
pause
