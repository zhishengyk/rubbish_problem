# Compile the generator and the standard solution
g++ ./IntervalSelection/gen.cpp -o ./IntervalSelection/gen.exe
g++ ./IntervalSelection/std.cpp -o ./IntervalSelection/std.exe

# Generate test cases
for ($i = 1; $i -le 20; $i++) {
    echo "Generating test case $i"
    # Generate input file
    ./IntervalSelection/gen.exe $i | Set-Content -Path ./IntervalSelection/$i.in
    
    # Get input from .in file and pipe it to std.exe, then save output to .out file
    Get-Content ./IntervalSelection/$i.in | ./IntervalSelection/std.exe | Set-Content -Path ./IntervalSelection/$i.out
}

# Clean up executable files
Remove-Item ./IntervalSelection/gen.exe
Remove-Item ./IntervalSelection/std.exe

echo "Done."