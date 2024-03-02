#!/bin/bash

PYPATH="$(pwd)"
CORES=1

# Short check to assure that we start the script in PyProject directory
if [ ${PYPATH##*/} != "PyProject" ];
then
    echo "go to PyProject directory and start the script there"
    exit 1
fi

# Now start the attack for one or more chosen problems

OUTPUT_FILE0="run_train_models_rnn_parallel0.log"
if [ -f OUTPUT_FILE0 ] ; then
    rm OUTPUT_FILE0
fi
OUTPUT_FILE1="run_train_models_rnn_parallel1.log"
if [ -f OUTPUT_FILE1 ] ; then
    rm OUTPUT_FILE1
fi
OUTPUT_FILE2="run_train_models_rnn_parallel2.log"
if [ -f OUTPUT_FILE2 ] ; then
    rm OUTPUT_FILE2
fi

DATASET="GH"

pids=()
if [ "$DATASET" = "CPP" ] ; then
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 0 \
     ::: 3264486_5736519012712448 \
         8294486_5654117850546176 \
         3264486_5654742835396608 \
         >> $OUTPUT_FILE0 &
    pids+=($!)

    sleep 3
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 1 \
     ::: 5304486_5760761888505856 \
         3264486_5633382285312000 \
         5304486_5697460110360576 \
         >> $OUTPUT_FILE1 &
    pids+=($!)

    sleep 3
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 2 \
     ::: 8294486_5681755159789568 \
         8294486_5630967708385280 \
         >> $OUTPUT_FILE2 &
    pids+=($!)
fi

if [ "$DATASET" = "C" ] ; then
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 0 \
     ::: 1460488_1483485 \
         1460488_1483488 \
         1460488_1595491 \
         >> $OUTPUT_FILE0 &
    pids+=($!)

    sleep 3
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 1 \
     ::: 2270488_2449486 \
         2270488_2453486 \
         2270488_2463486 \
         >> $OUTPUT_FILE1 &
    pids+=($!)

    sleep 3
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 2 \
     ::: 2974486_5709773144064000 \
         2974486_5756407898963968 \
         >> $OUTPUT_FILE2 &
    pids+=($!)
fi

if [ "$DATASET" = "GH" ] ; then
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 0 \
     ::: 0 1 2 >> $OUTPUT_FILE0 &
    pids+=($!)

    sleep 3
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 1 \
     ::: 3 4 >> $OUTPUT_FILE1 &
    pids+=($!)

    sleep 3
    parallel -j $CORES  PYTHONPATH=${PYPATH} python evaluations/learning/rnn_css/train_models_rnn_parallel.py {} 2 \
     ::: 5 6 >> $OUTPUT_FILE2 &
    pids+=($!)
fi

for pid in ${pids[*]}; do
    wait $pid
done
