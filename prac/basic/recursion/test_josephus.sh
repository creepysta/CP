#set -eux

for i in 2 3 4 5 6 7 8 9 10;
do
    echo "Testing ${i}"
    iter=$(./josephus_iter ${i})
    rec=$(./josephus_rec ${i})
    echo "Got iter=${iter} and rec=${rec}"
    if [ rec != iter ];
    then
        echo "Failed"
        break
    fi
done
