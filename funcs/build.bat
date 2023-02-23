@echo off
IF NOT EXIST bin mkdir bin
cls
pushd bin
cl -Z7 -nologo ../main.c
popd