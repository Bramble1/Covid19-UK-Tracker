#!/bin/bash
gcc -Wall src/download_page.c -lcurl -o download_page
gcc -Wall src/reader.c -o reader
mkdir executables/
mv download_page executables/; mv reader executables/
