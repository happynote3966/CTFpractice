
#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import base64
import getopt

def usage():
	print("This program is base-decoder.\n")
	print("If you input file to this program, program generate base decodeing file.")
	print("-h or --help option is display usage")
	print("-b or --base option is assign base number,16,32,64,and 85")
	print("-f or --file option is assign file name of decode")
	print("USAGE:python3 basedecoder.py -f decodefile -b 32")
	sys.exit()

def b16(file):
	inputfile = open(file,'rb').read()
	decode = base64.b16decode(inputfile)
	fh = open('decode_file_base16','wb')
	fh.write(decode)

def b32(file):
	inputfile = open(file,'rb').read()
	decode = base64.b32decode(inputfile)
	fh = open('decode_file_base32','wb')
	fh.write(decode)

def b64(file):
	inputfile = open(file,'rb').read()
	decode = base64.b64decode(inputfile)
	fh = open('decode_file_base64','wb')
	fh.write(decode)

def b85(file):
	inputfile = open(file,'rb').read()
	decode = base64.b85decode(inputfile)
	fh = open('decode_file_base85','wb')
	fh.write(decode)


def main():
	baselist = [16,32,64,85]
	try:
		shortopt = "b:f:h"
		longopt = ["base=","file=","help"]
		opts,args = getopt.getopt(sys.argv[1:],shortopt,longopt)
	except getopt.GetoptError:
		usage()

	for o,a in opts:
		if o in ('-b', '--base'):
			base = int(a,10)
			if base not in baselist:
				usage()
		elif o in ('-h','--help'):
			usage()
		elif o in ('-f' '--file'):
			file = a

	if base == 16:
		b16(file)
	elif base == 32:
		b32(file)
	elif base == 64:
		b64(file)
	elif base == 85:
		b85(file)

if __name__ == '__main__':
	main()
