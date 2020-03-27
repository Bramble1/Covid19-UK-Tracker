#!/bin/bash
clear
executables/./download_page > index.html
lynx --dump index.html > page.txt

executables/./reader | sed '13,14d'
rm index.html;rm page.txt
