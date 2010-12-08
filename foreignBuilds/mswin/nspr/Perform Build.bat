@echo off

%~d0
cd "%~dp0"

echo MSYS build for nspr
echo ===================
echo 1. 32-bit build
echo 2. 64-bit build
echo X. Exit
echo.

choice /c 12x

if errorlevel 1 set BuildBits=32
if errorlevel 2 set BuildBits=64
if errorlevel 3 goto :eof

verify >nul
call "../Set Common Environment Variables"
if errorlevel 1 goto end

set package=nspr-4.8.6.tar.gz
set sourceFolder=nspr-4.8.6-%BuildBits%
set tarFolder=nspr-4.8.6
set curDir=%CD%

if not exist %package% (
	echo.
	echo Downloading
	wget ftp://ftp.mozilla.org/pub/mozilla.org/nspr/releases/v4.8.6/src/%package%
)

if errorlevel 1 goto end

echo.
echo Preparing
rm -r -f "%devDir%\%sourceFolder%"
if errorlevel 1 goto end

mkdir "%devDir%\%sourceFolder%"
if errorlevel 1 goto end

tar xfz "%package%" -C "%devDir%/%sourceFolder%"
if errorlevel 1 goto end

cd "%devDir%\%sourceFolder%"

for /f "delims=" %%a in ('dir /b %tarFolder%') do (
	move "%CD%\%tarFolder%\%%a" "%CD%"
)

echo.
echo Configuring
cd mozilla\nsprpub
sh ./configure --prefix="%usrLocalDir%" --enable-strip --enable-win32-target=WIN95 --enable-optimize --disable-debug

if errorlevel 1 goto end
echo.
pause

make
if errorlevel 1 goto end

make install
if errorlevel 1 goto end

move "%usrLocalDir%\lib\nspr4.dll" "%usrLocalDir%\bin"
copy "%usrLocalDir%\bin\nspr4.dll" "%admBuildDir%"

pexports "%usrLocalDir%/bin/nspr4.dll" > nspr4.def
dlltool -d nspr4.def -l "%usrLocalDir%/lib/nspr4.dll.a"

goto end

:error
echo Error

:end
pause