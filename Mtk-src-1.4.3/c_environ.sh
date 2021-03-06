export MTKHOME=/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3
export MTK_CFLAGS="-O2 -m64 -fno-cse-follow-jumps -fno-gcse -DREGEXP_WORKAROUND  -Wall -pedantic -fPIC -std=c99 -fno-common -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/Util/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/FileQuery/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/UnitConv/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/CoordQuery/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/MapQuery/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/OrbitPath/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/SetRegion/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/ReadData/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/WriteData/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/ReProject/include  -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/Regression/include -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/misrcoord -I/mnt/a/u/sciteam/gyzhao/Mtk-src-1.4.3/odl -I/u/sciteam/gyzhao/hdfeoslibs/include -I/u/sciteam/gyzhao/hdfeoslibs/include"
export MTK_LDFLAGS="-L${MTKHOME}/lib -lMisrToolkit -L/u/sciteam/gyzhao/hdfeoslibs/lib -L/u/sciteam/gyzhao/hdfeoslibs/lib -lhdfeos -lGctp -lmfhdf -ldf -ljpeg -lz -lm"
if [ ${#LD_LIBRARY_PATH} -ne 0 ]; then
	export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${MTKHOME}/lib"
else
	export LD_LIBRARY_PATH="${MTKHOME}/lib"
fi
