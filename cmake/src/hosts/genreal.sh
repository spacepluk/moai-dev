#!/bin/sh

# Create the output directory
output_dir=`dirname "$4"`
mkdir -p "$output_dir"

# Copy the source files to the output directory
cp "$2" "$output_dir"
cp "$3" "$output_dir"
cd "$output_dir"

# Generate the bytecode
the_script=`basename "$2"`
"$1" "$the_script"
