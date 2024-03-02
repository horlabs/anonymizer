#!/bin/bash

PYPATH="$(pwd)"
CORES=8

# Short check to assure that we start the script in PyProject directory
if [ ${PYPATH##*/} != "PyProject" ];
then
    echo "go to PyProject directory and start the script there"
    exit 1
fi

# Now start the attack for one or more chosen problems


OUTPUT_FILE="output_blackboxatt.log"
if [ -f OUTPUT_FILE ] ; then
    rm OUTPUT_FILE
fi

#parallel -j $CORES --delay 5 PYTHONPATH=${PYPATH} python evaluations/blackbox/attack/blackbox_attack.py {}\
# ::: 3264486_5736519012712448  8294486_5654117850546176  3264486_5654742835396608\
#  5304486_5760761888505856  3264486_5633382285312000  5304486_5697460110360576\
#  8294486_5681755159789568  8294486_5630967708385280 >> $OUTPUT_FILE

parallel -j $CORES --delay 5 PYTHONPATH=${PYPATH} python anonymize/blackbox_attack.py {}\
 ::: 1460488_1483485 1460488_1483488 1460488_1595491 \
     2270488_2449486 2270488_2453486 2270488_2463486 \
     2974486_5709773144064000 2974486_5756407898963968 >> $OUTPUT_FILE
