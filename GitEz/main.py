import subprocess as sb
import json as js
import sys as s

def printHelp():
    print("-init <repo>: initializes json script for project execution\n")
    print("-update <repo>: initalizes a new json script, overwriting the previous\n")
    print("-auto: automatically pushes and pulls updating all repos\n")
    print("-personal <true/false>: sets the \"personal\" flag so you only work on your personal copy of the repo\n" )
    print("")
    return
if s.argv[1] == "-help":
    printHelp()
