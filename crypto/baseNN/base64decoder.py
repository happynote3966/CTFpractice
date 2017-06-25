# -*- coding:utf-8 -*-

import sys
import base64

def main():
	s = sys.argv[1]
	file = open(s,'rt').read()
	decode = base64.b64decode(file)
	writefile = open('decode_file','w')
	writefile.write(decode)


#print(base64.b64decode(s))


if __name__ == '__main__':
	main()
