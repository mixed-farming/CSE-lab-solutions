#!/usr/bin/env python
# A basic mapper function/program that# takes whatever is passed on the input and
# outputs tuples of all the words formatted
# as (word, 1)
# from __future__ import print_function
import sys
# input comes from STDIN (standard input)
for line in sys.stdin:
    word, count = line.strip().split('\t')
    count = int(count)
    print( '%d\t%s' % (count, word) )