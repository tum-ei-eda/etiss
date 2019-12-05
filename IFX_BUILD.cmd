@echo off

IF "[%IFX_BUILD_ORG_PATH%]"=="[]" (
  SET "IFX_BUILD_ORG_PATH=%PATH%"
) ELSE (
  SET "PATH=%IFX_BUILD_ORG_PATH%"
)

call ..\SETUP_VC.cmd %1

IF [%VSVER%]==[16] (
   SET GEN=-G "Ninja"
)

IF [%VSVER%]==[15] (
   SET GEN=-G "Visual Studio 15 2017"  -A x64
)

SET ETISS_HOME=c:\Inicio\tools\64\etiss-0.6.0.0

REM cmake -DBoost_ROOT=C:\Inicio\lib\boost-1.7.1.0 -B Build-%MSVCVER% -Tv142,host=x64 -A x64 -S . -G "Visual Studio 15 2017"  
echo %CMAKE_INSTALL%\bin\cmake -DBoost_ROOT=C:\Inicio\lib\boost-1.7.1.0 -B Build-vc%MSVCVER% -S . %GEN%
%CMAKE_INSTALL%\bin\cmake -DBoost_ROOT=C:\Inicio\lib\boost-1.7.1.0 -DCMAKE_INSTALL_PREFIX:PATH="%ETISS_HOME%" -B Build-vc%MSVCVER% -S . %GEN%
%CMAKE_INSTALL%\bin\cmake --build Build-vc%MSVCVER% --verbose

:eof
