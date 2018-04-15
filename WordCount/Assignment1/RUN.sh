#!/bin/bash
#
# running programming takes words.txt and sortedWords.txt as input. 
# standard output prints into WordCount1R, WordCount1optR, or WordCount2R.txt
# 	and sortedWordCount1R, sortedWordCount1potR, sortedWordCount2R.txt 
# standard error output prints into visual1, visual1opt, visual2.txt 
#	and visual1s, visual1opts, visual2s.txt 
#	which shows the structure of the dictionary 
#------------------------------------------------------------------
# Reference
#	https://stackoverflow.com/questions/23659229/write-stdcerr-to-txt-file?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google#	_rich_qa

./WordCount1 < words.txt > WordCount1R.txt 2> visual1.txt
./WordCount1 < sortedWords.txt > sortedWordCount1R.txt 2> visual1s.txt

./WordCount1opt < words.txt > WordCount1optR.txt 2> visual1opt.txt
./WordCount1opt < sortedWords.txt > sortedWordCount1optR.txt 2> visual1opts.txt

./WordCount2 < words.txt > WordCount2R.txt 2> visual2.txt
./WordCount2 < sortedWords.txt > sortedWordCount2R.txt 2> visual2s.txt

