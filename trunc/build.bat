@echo off
IF NOT EXIST bin mkdir bin
cls
pushd bin
cl -nologo ../main.c
popd