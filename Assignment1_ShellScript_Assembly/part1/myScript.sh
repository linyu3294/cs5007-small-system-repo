#!/bin/bash
# The line above makes your script executable.
# You should write your tutorial in here.
# Include comments inline with your script explaining what is going on.

# You might start out by first saying the purpose of the script and
# demonstrating its usage.

echo OFF
echo START OF THE SCRIPT

echo Welcome to Process Killer
echo 0 - Internet Explorer
echo 1 - Chrome
echo 2 - Firefox
echo 3 - Lync
echo 4 - Outlook
echo 5 - Excel 
set /p userinput="Please make a selection:"

if /i "%userinput%" == "0" goto zero
if /i "%userinput%" == "1" goto one
if /i "%userinput%" == "2" goto two
if /i "%userinput%" == "3" goto three
if /i "%userinput%" == "4" goto four
if /i "%userinput%" == "5" goto five
echo Invalid Option
goto end

:zero
taskkill /f /im "iexplore.exe"
goto end

:one
taskkill /f /im "chrome.exe"
taskkill /f /im "GoogleChromePortable.exe"
goto end

:two
taskkill /f /im "firefox.exe"
taskkill /f /im "FirefoxPortable.exe"
goto end

:three
taskkill /f /im "lync.exe"
goto end

:four
taskkill /f /im "OUTLOOK.EXE"
goto end

:five
taskkill /f /im "EXCEL.exe"
goto end


:end
echo END OF THE SCRIPT
