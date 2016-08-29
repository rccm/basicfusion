/*===========================================================================
=                                                                           =
=                        MtkDataBufferAllocate_test                         =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2005, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrUtil.h"
#include <stdio.h>
#include <math.h>

int main () {

  MTKt_status status;           /* Return status */
  MTKt_boolean pass = MTK_TRUE; /* Test status */
  MTKt_boolean good = MTK_TRUE; /* Good data flag */
  MTKt_DataBuffer dbuf = MTKT_DATABUFFER_INIT;
				/* Data buffer structure */
  int l;			/* Line index */
  int s;			/* Sample index */
  int nline;			/* Number of lines */
  int nsample;			/* Number of samples */
  int datatype;			/* Data type */
  MTKt_uint16 data;		/* Data element */
  MTKt_float data2;		/* Data element */
  MTKt_double data3;		/* Data element */
  MTKt_int8 data4;		/* Data element */
  int cn = 0;			/* Column number */

  MTK_PRINT_STATUS(cn,"Testing MtkDataBufferAllocate");

  /* Normal test call */
  nline = 5;
  nsample = 10;
  datatype = MTKe_uint16;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_SUCCESS) {
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data = l * s;
	dbuf.data.u16[l][s] = data;
      }
    }
    good = MTK_TRUE;
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data = l * s;
	/*	printf("[%d, %d] = %d, %d\n", l, s, data, dbuf.data.u16[l][s]); */
	if (dbuf.data.u16[l][s] != data){
	  good = MTK_FALSE;
	}
      }
    }
    MtkDataBufferFree(&dbuf);
    if (good) {
      MTK_PRINT_STATUS(cn,".");
    } else {
      MTK_PRINT_STATUS(cn,"*");
      pass = MTK_FALSE;
    }
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  nline = 10;
  nsample = 5;
  datatype = MTKe_float;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_SUCCESS) {
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data2 = 1.0 / ((l+1) * (s+1));
	dbuf.data.f[l][s] = data2;
      }
    }
    good = MTK_TRUE;
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data2 = 1.0 / ((l+1) * (s+1));
	/*	printf("[%d, %d] = %f, %f\n", l, s, data2, dbuf.data.f[l][s]);*/
	if (fabsf(dbuf.data.f[l][s] - data2) > .000001){
	  good = MTK_FALSE;
	}
      }
    }
    MtkDataBufferFree(&dbuf);
    if (good) {
      MTK_PRINT_STATUS(cn,".");
    } else {
      MTK_PRINT_STATUS(cn,"*");
      pass = MTK_FALSE;
    }
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  nline = 13;
  nsample = 12;
  datatype = MTKe_double;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_SUCCESS) {
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data3 = 1.0 / ((l+1) * (s+1));
	dbuf.data.d[l][s] = data3;
      }
    }
    good = MTK_TRUE;
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data3 = 1.0 / ((l+1) * (s+1));
	/*	printf("[%d, %d] = %f, %f\n", l, s, data3, dbuf.data.d[l][s]); */
	if (fabsf(dbuf.data.d[l][s] - data3) > .000001 ){
	  good = MTK_FALSE;
	}
      }
    }
    MtkDataBufferFree(&dbuf);
    if (good) {
      MTK_PRINT_STATUS(cn,".");
    } else {
      MTK_PRINT_STATUS(cn,"*");
      pass = MTK_FALSE;
    }
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  nline = 5;
  nsample = 3;
  datatype = MTKe_int8;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_SUCCESS) {
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data4 = l * -s;
	dbuf.data.i8[l][s] = data4;
      }
    }
    good = MTK_TRUE;
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	data4 = l * -s;
	/*	printf("[%d, %d] = %d, %d\n", l, s, data4, dbuf.data.i8[l][s]); */
	if (dbuf.data.i8[l][s] != data4){
	  good = MTK_FALSE;
	}
      }
    }
    MtkDataBufferFree(&dbuf);
    if (good) {
      MTK_PRINT_STATUS(cn,".");
    } else {
      MTK_PRINT_STATUS(cn,"*");
      pass = MTK_FALSE;
    }
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Normal test call */
  nline = 1;
  nsample = 1;
  datatype = MTKe_float;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_SUCCESS) {
    good = MTK_TRUE;
    for (l = 0; l < dbuf.nline; l++) {
      for (s = 0; s < dbuf.nsample; s++) {
	/*	printf("[%d, %d] = %d, %d\n", l, s, 0.0, dbuf.data.i8[l][s]); */
	if (dbuf.data.f[l][s] != 0.0){
	  good = MTK_FALSE;
	}
      }
    }
    MtkDataBufferFree(&dbuf);
    if (good) {
      MTK_PRINT_STATUS(cn,".");
    } else {
      MTK_PRINT_STATUS(cn,"*");
      pass = MTK_FALSE;
    }
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Failure test call */
  nline = -5;
  nsample = 3;
  datatype = MTKe_int8;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_OUTBOUNDS) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Failure test call */
  nline = 5;
  nsample = -3;
  datatype = MTKe_int8;

  status = MtkDataBufferAllocate(nline, nsample, datatype, &dbuf);
  if (status == MTK_OUTBOUNDS) {
    MTK_PRINT_STATUS(cn,".");
  } else {
    MTK_PRINT_STATUS(cn,"*");
    pass = MTK_FALSE;
  }

  /* Argument Check */
  status = MtkDataBufferAllocate(nline, nsample, datatype, NULL);
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
