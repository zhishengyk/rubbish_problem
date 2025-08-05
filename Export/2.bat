@echo off
:: 使用系统自带的tar命令压缩每个子文件夹
:: 适用于Windows 10 1803及以上版本

chcp 65001 > nul
title 文件夹批量压缩工具

echo 正在压缩当前目录下的所有子文件夹...
echo 请确保使用的是Windows 10 1803或更高版本
echo.

for /d %%i in (*) do (
    echo 正在压缩文件夹: "%%i"
    tar -acf "%%i.zip" "%%i"
    if errorlevel 1 (
        echo 错误: 压缩 "%%i" 失败
    ) else (
        echo 成功创建: "%%i.zip"
    )
    echo.
)

echo 所有文件夹压缩完成!
pause