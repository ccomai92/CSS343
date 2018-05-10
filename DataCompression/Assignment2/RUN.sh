#! /bin/bash 
# ------------------------------------------------------------
# Running Program
# huff takes random.txt and make random.huff which is compressed file.
./huff random.txt 2> randomHuff.txt
# puff takes random.huff and make random.puff which is decompressed file.
./puff random.huff 2> randomPuff.txt
# huff takes CommmonSense.txt and make CommonSense.huff
./huff CommonSense.txt 2> csHuff.txt
# puff takes CommonSense.huff and make CommonSense.huff
./puff CommonSense.huff 2> csPuff.txt
# huff takes CommonSense1.txt and make CommonSense1.huff
./huff CommonSense1.txt 2> cs1Huff.txt
# puff-baseline takes CommonSense1.huff and make CommonSense1.puff 
./puff-baseline CommonSense1.huff 2> cs1Puff.txt


