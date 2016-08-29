/*===========================================================================
=                                                                           =
=                           MtkReadL2Land_test                              =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2005, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrReadData.h"
#include "MisrError.h"
#include <string.h>
#include <stdio.h>

int main () {

  MTKt_status status;           /* Return status */
  MTKt_boolean pass = MTK_TRUE; /* Test status */
  MTKt_Region region;		/* Region structure */
  MTKt_DataBuffer dbuf = MTKT_DATABUFFER_INIT;
				/* Data buffer structure */
  MTKt_MapInfo mapinfo;		/* Map Info structure */
  char filename[200];		/* HDF-EOS filename */
  char gridname[80];		/* HDF-EOS gridname */
  char fieldname[80];		/* HDF-EOS fieldname */
  int cn = 0;			/* Column number */

  MTK_PRINT_STATUS(cn,"Testing MtkReadL2Land");

  MtkSetRegionByPathBlockRange(37, 45, 45, &region);

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "LandHDRF[1][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.f[20][128] - 0.0830179) < .00001 &&
      (dbuf.data.f[16][140] - 0.1097241) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "Raw LandHDRF[1][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.u16[20][128] - 1088) < .00001 &&
      (dbuf.data.u16[16][140] - 1438) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "Native LandHDRF[1][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.u16[20][128] - 1088) < .00001 &&
      (dbuf.data.u16[16][140] - 1438) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "Flag LandHDRF[1][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.u16[20][128] - 0) < .00001 &&
      (dbuf.data.u16[16][140] - 0) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "LAIDelta1[5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.f[16][128] - 0.117851) < .00001 &&
      (dbuf.data.f[46][200] - 0.122475) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "Flag LAIDelta1[5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.f[16][128] - 1.0) < .00001 &&
      (dbuf.data.f[46][200] - 1.0) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "LandHDRFUnc[1][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.f[16][128] - 0.00869857) < .00001 &&
      (dbuf.data.f[46][200] - 0.00640947) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "RDQI[1][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.u8[15][128] - 253) < .00001 &&
      (dbuf.data.u8[46][200] - 0) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  strcpy(filename, "../Mtk_testdata/in/"
	 "MISR_AM1_AS_LAND_P037_O029058_F06_0017.hdf");
  strcpy(gridname, "SubregParamsLnd");
  strcpy(fieldname, "LandBRF[0][5]");

  status = MtkReadL2Land(filename, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_SUCCESS &&
      (dbuf.data.f[16][128] - 0.0383042) < .00001 &&
      (dbuf.data.f[46][200] - 0.0570748) < .00001) {
    MTK_PRINT_STATUS(cn,".");
    MtkDataBufferFree(&dbuf);
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Argument check */
  status = MtkReadL2Land(NULL, gridname, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_NULLPTR) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  status = MtkReadL2Land(filename, NULL, fieldname, region, &dbuf, &mapinfo);
  if (status == MTK_NULLPTR) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  status = MtkReadL2Land(filename, gridname, NULL, region, &dbuf, &mapinfo);
  if (status == MTK_NULLPTR) {
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
