# -*- coding:utf-8 -*-
#!/usr/bin/python3
# python3 rotgenerator.py -f Unknown.txt -r 13
import sys
import getopt

def usage():
    print("usage")
    sys.exit()

def rangecheck(char,rotate):
    if char.isalpha():
        if char.isupper():
            if ord('A') <= ord(char) + rotate <= ord('Z'):
                return chr(ord(char) + rotate)
            else:
                return chr(ord('A') - 1 + rotate - (ord('Z') - ord(char)))
        else:
            if ord('a') <= ord(char) + rotate <= ord('z'):
                return chr(ord(char) + rotate)
            else:
                return chr(ord('a') - 1 + rotate - (ord('z') - ord(char)))
    else:
        return char

def rotate(file,rotate_number):
    string = open(file,'rt').read()
    rotatestring = ""
    for c in string:
        rotatestring += rangecheck(c,rotate_number)

    print("ROT {0} : {1:s}".format(rotate_number,rotatestring))


def rot_bruteforce(file):
    string = open(file,'rt').read()
    workstring = ""
    count = 1
    rotlist = []
    print("Plain  : {0}".format(string),end='')

    for i in range(1,26):
        workstring = ""
        for char in string:
            workstring += rangecheck(char,i)
        rotlist.append(workstring)

    for element in rotlist:
        print("ROT {0:02d} : {1}".format(count,element),end='')
        count = count + 1



def main():
    bruteforce = False
    file = None
    rotate_number = 13
    try:
        shortopt = "bf:hr:"
        longopt = ["bruteforce","file=","help","rotate="]
        opts,args = getopt.getopt(sys.argv[1:],shortopt,longopt)
    except getopt.GetoptError:
        print("getopterror")
        usage()

    for o,a in opts:
        if o in ('-b','--bruteforce'):
            bruteforce = True
        elif o in ('-f','--file'):
            file = a
        elif o in ('-h','--help'):
            usage()
        elif o in ('-r','--rotate'):
            rotate_number = int(a,10)
            if rotate_number < 0:
                rotate_number = 26 + rotate_number
        else:
            usage()

    if bruteforce == True:
        rot_bruteforce(file)
    else:
        rotate(file,rotate_number)


if __name__ == '__main__':
    main()
