# -*- coding:utf-8 -*-
#!/usr/bin/python3

import sys
import getopt

def usage():
	print("This program is xor encoder")
	print("USAGE python3 xorencoder.py -f sourcefile")
	sys.exit()

def encode(file,canary):
	inputfile = open(file,'rb').read()
	encode = []
	for i in inputfile:
		encode.append(i ^ canary)
	encodefile = open('xorencoded_file','wb')

	for i in encode:
		print(encode)

	encode = bytes(encode)
	encodefile.write(encode)


def main():
	try:
		shortopt = "c:f:h"
		longopt = ["canary=","file=","help"]
		opts,args = getopt.getopt(sys.argv[1:],shortopt,longopt)
	except getopt.GetoptError:
		usage()

	for o,a in opts:
		if o in ('-c','--canary'):
			canary = int(a,16)
		elif o in ('-f','--file'):
			file = a
		elif o in ('-h','--help'):
			usage()

	encode(file,canary)

if __name__ == '__main__':
	main()
