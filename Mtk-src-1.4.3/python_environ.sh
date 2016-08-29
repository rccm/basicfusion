export MTKHOME=/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3
export PYTHONPATH=`echo ${MTKHOME}/wrappers/python/build/lib.*`
if [ ${#LD_LIBRARY_PATH} -ne 0 ]; then
	export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${MTKHOME}/lib"
else
	export LD_LIBRARY_PATH="${MTKHOME}/lib"
fi
