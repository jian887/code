REM @echo off
@echo off
set str=Test07
for /f %%i in (FileList.txt) do (echo F|(xcopy %str% %%i))