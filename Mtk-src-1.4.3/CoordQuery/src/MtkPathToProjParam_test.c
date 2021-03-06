/*===========================================================================
=                                                                           =
=                         MtkPathToProjParam_test                           =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2005, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrCoordQuery.h"
#include "MisrError.h"
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdio.h>

/* Expected longitude of the ascending node for each path (1-233) */
double asclong[] = { 0.0,
  127045037.928240340000,
  126012055.696480690000,
  124040013.464721020000,
  123007031.232961370000,
  121034049.001201720000,
  120002006.769442070000,
  118029024.537682400000,
  116056042.305922750000,
  115024000.074163090000,
  113051017.842403430000,
  112018035.610643770000,
  110045053.378884120000,
  109013011.147124470000,
  107040028.915364800000,
  106007046.683605150000,
  104035004.451845500000,
  103002022.220085830000,
  101029039.988326180000,
   99056057.756566525000,
   98024015.524806872000,
   96051033.293047205000,
   95018051.061287552000,
   93046008.829527900000,
   92013026.597768247000,
   90040044.366008580000,
   89008002.134248927000,
   87035019.902489275000,
   86002037.670729607000,
   84029055.438969955000,
   82057013.207210302000,
   81024030.975450650000,
   79051048.743690982000,
   78019006.511931330000,
   76046024.280171677000,
   75013042.048412010000,
   73040059.816652358000,
   72008017.584892705000,
   70035035.353133053000,
   69002053.121373385000,
   67030010.889613733000,
   65057028.657854080000,
   64024046.426094420000,
   62052004.194334760000,
   61019021.962575108000,
   59046039.730815448000,
   58013057.499055795000,
   56041015.267296135000,
   55008033.035536483000,
   53035050.803776823000,
   52003008.572017170000,
   50030026.340257511000,
   48057044.108497851000,
   47025001.876738198000,
   45052019.644978538000,
   44019037.413218886000,
   42046055.181459226000,
   41014012.949699573000,
   39041030.717939913000,
   38008048.486180261000,
   36036006.254420601000,
   35003024.022660941000,
   33030041.790901288000,
   31057059.559141632000,
   30025017.327381976000,
   28052035.095622316000,
   27019052.863862660000,
   25047010.632103004000,
   24014028.400343347000,
   22041046.168583691000,
   21009003.936824035000,
   19036021.705064379000,
   18003039.473304722000,
   16030057.241545064000,
   14058015.009785408000,
   13025032.778025752000,
   11052050.546266094000,
   10020008.314506438000,
    8047026.082746781400,
    7014043.850987124300,
    5042001.619227468000,
    4009019.387467811300,
    2036037.155708154400,
    1003054.923948497900,
     -28047.307811158760,
   -2001029.539570815400,
   -3034011.771330472100,
   -5006054.003090128300,
   -6039036.234849785500,
   -8012018.466609441700,
   -9045000.698369098800,
  -11017042.930128755000,
  -12050025.161888411000,
  -14023007.393648069000,
  -15055049.625407726000,
  -17028031.857167382000,
  -19001014.088927038000,
  -20033056.320686694000,
  -22006038.552446350000,
  -23039020.784206010000,
  -25012003.015965667000,
  -26044045.247725323000,
  -28017027.479484979000,
  -29050009.711244635000,
  -31022051.943004292000,
  -32055034.174763948000,
  -34028016.406523608000,
  -36000058.638283260000,
  -37033040.870042920000,
  -39006023.101802573000,
  -40039005.333562233000,
  -42011047.565321885000,
  -43044029.797081545000,
  -45017012.028841205000,
  -46049054.260600857000,
  -48022036.492360517000,
  -49055018.724120170000,
  -51028000.955879830000,
  -53000043.187639482000,
  -54033025.419399142000,
  -56006007.651158795000,
  -57038049.882918455000,
  -59011032.114678115000,
  -60044014.346437767000,
  -62016056.578197427000,
  -63049038.809957080000,
  -65022021.041716740000,
  -66055003.273476392000,
  -68027045.505236045000,
  -70000027.736995712000,
  -71033009.968755364000,
  -73005052.200515017000,
  -74038034.432274684000,
  -76011016.664034337000,
  -77043058.895793989000,
  -79016041.127553642000,
  -80049023.359313309000,
  -82022005.591072962000,
  -83054047.822832614000,
  -85027030.054592282000,
  -87000012.286351934000,
  -88032054.518111587000,
  -90005036.749871239000,
  -91038018.981630906000,
  -93011001.213390559000,
  -94043043.445150211000,
  -96016025.676909864000,
  -97049007.908669531000,
  -99021050.140429184000,
 -100054032.372188840000,
 -102027014.603948500000,
 -103059056.835708160000,
 -105032039.067467810000,
 -107005021.299227460000,
 -108038003.530987130000,
 -110010045.762746780000,
 -111043027.994506430000,
 -113016010.226266100000,
 -114048052.458025750000,
 -116021034.689785410000,
 -117054016.921545060000,
 -119026059.153304730000,
 -120059041.385064380000,
 -122032023.616824030000,
 -124005005.848583700000,
 -125037048.080343350000,
 -127010030.312103000000,
 -128043012.543862660000,
 -130015054.775622320000,
 -131048037.007381980000,
 -133021019.239141630000,
 -134054001.470901280000,
 -136026043.702660950000,
 -137059025.934420620000,
 -139032008.166180250000,
 -141004050.397939920000,
 -142037032.629699560000,
 -144010014.861459230000,
 -145042057.093218890000,
 -147015039.324978530000,
 -148048021.556738200000,
 -150021003.788497870000,
 -151053046.020257500000,
 -153026028.252017170000,
 -154059010.483776840000,
 -156031052.715536480000,
 -158004034.947296140000,
 -159037017.179055780000,
 -161009059.410815450000,
 -162042041.642575110000,
 -164015023.874334750000,
 -165048006.106094420000,
 -167020048.337854090000,
 -168053030.569613720000,
 -170026012.801373390000,
 -171058055.033133060000,
 -173031037.264892700000,
 -175004019.496652360000,
 -176037001.728412030000,
 -178009043.960171670000,
 -179042026.191931340000,
 -181015008.423690970000,
 -182047050.655450640000,
 -184020032.887210310000,
 -185053015.118969950000,
 -187025057.350729610000,
 -188058039.582489280000,
 -190031021.814248920000,
 -192004004.046008590000,
 -193036046.277768250000,
 -195009028.509527890000,
 -196042010.741287560000,
 -198014052.973047200000,
 -199047035.204806860000,
 -201020017.436566530000,
 -202052059.668326170000,
 -204025041.900085840000,
 -205058024.131845500000,
 -207031006.363605140000,
 -209003048.595364810000,
 -210036030.827124480000,
 -212009013.058884110000,
 -213041055.290643780000,
 -215014037.522403420000,
 -216047019.754163090000,
 -218020001.985922750000,
 -219052044.217682390000,
 -221025026.449442060000,
 -222058008.681201730000,
 -224030050.912961360000,
 -226003033.144721030000,
 -227036015.376480700000,
 -229008057.608240340000,
 -230041039.840000000000 };

static int checkpp( MTKt_MisrProjParam pp, int path, int resolution, 
	     int nline, int nsample, double asclong );
int main () {

  MTKt_status status;		/* Return status */
  MTKt_boolean pass = MTK_TRUE; /* Test status */
  MTKt_MisrProjParam pp = MTKT_MISRPROJPARAM_INIT;
				/* MISR projection parameters */
  int path;			/* Path */
  int good;			/* Good ascending longitude count */
  int cn = 0;                   /* Column number */

  MTK_PRINT_STATUS(cn,"Testing MtkPathToProjParam");

  /* Normal test call */
  good = 0;
  for (path = 1; path <= NPATH; path++) {
    status = MtkPathToProjParam(path, 1100, &pp);
    if (status == MTK_SUCCESS &&
	checkpp(pp, path, 1100, 128, 512, asclong[path])) {
      good++;
    }
  }
  if (good == NPATH) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  path = 52;

  status = MtkPathToProjParam(path, 0, &pp);
  if (status == MTK_SUCCESS &&
      checkpp(pp, path, 1100, 128, 512, 48057044.1084978510)) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  path = 233;

  status = MtkPathToProjParam(path, 275, &pp);
  if (status == MTK_SUCCESS &&
      checkpp(pp, path, 275, 512, 2048, -230041039.840)) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  path = 1;

  status = MtkPathToProjParam(path, 1100, &pp);
  if (status == MTK_SUCCESS &&
      checkpp(pp, path, 1100, 128, 512, 127045037.928240340)) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  path = 199;

  status = MtkPathToProjParam(path, 17600, &pp);
  if (status == MTK_SUCCESS &&
      checkpp(pp, path, 17600, 8, 32, -178009043.960171670000)) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Failure test call */
  status = MtkPathToProjParam(path, 17600, NULL);
  if (status == MTK_NULLPTR) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Failure test call */
  path = 0;

  status = MtkPathToProjParam(path, 17600, &pp);
  if (status == MTK_OUTBOUNDS) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Failure test call */
  path = -1;

  status = MtkPathToProjParam(path, 17600, &pp);
  if (status == MTK_OUTBOUNDS) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Failure test call */
  path = 234;

  status = MtkPathToProjParam(path, 17600, &pp);
  if (status == MTK_OUTBOUNDS) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  if (pass) {
    MTK_PRINT_RESULT(cn,"Passed");
    return 0;
  } else {
    MTK_PRINT_RESULT(cn,"Failed");
    return 1;
  }
}

static int checkpp( MTKt_MisrProjParam pp, int path, int resolution, 
	     int nline, int nsample, double asclong ) {

  int i;			/* Loop index */
  double projparam[] = PROJPARAM; /* MISR projection parameters */
  float reloffset[] = RELOFFSET; /* Relative block offset */
  float resfactor;		/* Resolution factor */

  projparam[4] = asclong;	/* Set ascending longitude of this path */
  resfactor = RESOLUTION / (float)resolution; /* Resolution scale factor */

  if (pp.path != path) return MTK_FALSE;
  if (pp.projcode != PROJCODE) return MTK_FALSE;
  if (pp.zonecode != ZONECODE) return MTK_FALSE;
  if (pp.spherecode != SPHERECODE) return MTK_FALSE;
  for (i = 0; i < 15; i++) {
    if (fabs(pp.projparam[i] - projparam[i]) > 1E-7) return MTK_FALSE;
  }
  if (fabs(pp.ulc[0] - ULC_SOMX) > DBL_EPSILON) return MTK_FALSE;
  if (fabs(pp.ulc[1] - ULC_SOMY) > DBL_EPSILON) return MTK_FALSE;
  if (fabs(pp.lrc[0] - LRC_SOMX) > DBL_EPSILON) return MTK_FALSE;
  if (fabs(pp.lrc[1] - LRC_SOMY) > DBL_EPSILON) return MTK_FALSE;
  if (pp.nblock != NBLOCK) return MTK_FALSE;
  if (pp.nline != nline) return MTK_FALSE;
  if (pp.nsample != nsample) return MTK_FALSE;
  for (i = 0; i < 179; i++) {
    if (fabs(pp.reloffset[i] - (reloffset[i] * resfactor)) > FLT_EPSILON) 
      return MTK_FALSE;
  }
  if (pp.resolution != resolution) return MTK_FALSE;

  return MTK_TRUE;
}
