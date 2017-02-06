# -*- encoding: utf-8 -*-

#TODO
#This program need arugment. If argument is not exist, program will be exit.
#You must implement the usage function.

import sys
import base64

def usage():
	print("This program is base64encoder.\n")
	print("If you input string as arg1, this program output base64 encodeing string.\n")
	print("USAGE:python base64encoder.py AAAA\n")

if sys.arg[1] is None:
	usage()

s = sys.arg[1]

print(base64.b64encode(s))



