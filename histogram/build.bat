@echo off
IF NOT EXIST bin mkdir bin
cls
pushd bin
cl -nologo -Z7 ../main.c
popd