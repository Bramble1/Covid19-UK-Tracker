# CoronavirusUK_monitor
Program to monitor The Coronavirus cases in the UK.

# Requirements
 - Libcurl openssl library (for debian distros: 'sudo apt install libcurl4-openssl-dev')
 - Lynx (terminal-browser)
 
 # Instructions
 1. ./compile (make sure you have the correct permissions)
 2. ./coronavirus_stats.sh
 
 # Misc
 
 If you wish to set this to an alias or move the Wrapper script into /usr/bin, the the full path directories to the C executables
 will need to be specified and altered in coronavirus_stats.sh
 
 Furthermore this isn't being maintained, so It could already be broken, and is also dependant on the website I'm getting the data not changing. This is a very "hacky" way of getting data from a website.
