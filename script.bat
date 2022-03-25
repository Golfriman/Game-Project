@echo off
ECHO "Check duplicate"
tasklist | find /I "Название нашего файла.exe" > nul
if not %ERRORLEVEL% == 0 (
echo "Open"
start Название нашего файла.exe
)