#!/bin/bash
# create a random binary file

dd if=/dev/urandom of=build/test.bin bs=1024 count=1024
echo "Created test.bin (1kb)"
