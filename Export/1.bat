@echo off
:: 将file.txt复制到当前目录下所有子目录中的"TargetFolder"文件夹内
set "source_file=config.yaml"
set "target_subfolder=testdata"

for /d %%d in (*) do (
    if not exist "%%d\%target_subfolder%" (
        mkdir "%%d\%target_subfolder%"
    )
    copy "%source_file%" "%%d\%target_subfolder%\"
)
echo 文件已添加到所有子目录的%target_subfolder%文件夹
pause