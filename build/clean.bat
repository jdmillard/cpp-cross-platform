:: This removes everything in the build folder except clean.sh and clean.bat
@ECHO OFF

:: establish build directory path from anywhere
set RAW=%~dp0
set DIR=%RAW:~0,-1%

:: flag to detect if changes were made by this script
set CHANGES=false

:: loop over files
for %%i in (%DIR%\*) do (
    :: call evaluation function for this file
    call :evaluate %%i
)

:: loop over directories
for /D %%j in (%DIR%\*) do (
    :: delete contents and folder
    rmdir /s /q %%j
    echo %%~nj has been deleted
    set CHANGES=true
)

:: have ending statement make sense
if %CHANGES% == true (
    echo.
    echo build directory is now clean
) else (
    echo build directory is already clean
)

:: signal end of the script
goto end



:evaluate
    :: this evaluate function is passed the full path of a file

    :: do not delete the clean scripts
    if NOT "%~n1" == "clean" (
        del /q %1
        echo %~nx1 has been deleted
        set CHANGES=true
    )
goto :eof

:end
