/*===========================================================================
=                                                                           =
=                        MtkFileGridFieldToDataType                         =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2005, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrFileQuery.h"
#include "MisrUtil.h"
#include "MisrError.h"
#include <stdlib.h>
#include <mfhdf.h>
#include <HdfEosDef.h>

/** \brief Find data type for a particular field
 *
 *  \return MTK_SUCCESS if successful.
 *
 *  \par Example:
 *  In this example, we read the data type from the file \c MISR_AM1_GRP_TERRAIN_GM_P161_O012115_DF_F03_0021.hdf the grid \c BlueBand and the field \c Blue \c Radiance/RDQI 
 *
 *  \code
 *  status = MtkFileGridFieldToDataType("MISR_AM1_GRP_TERRAIN_GM_P161_O012115_DF_F03_0021.hdf",
 *                "BlueBand", "Blue Radiance/RDQI", &datatype);
 *  \endcode
 */

MTKt_status MtkFileGridFieldToDataType(
  const char *filename, /**< [IN] File name */
  const char *gridname, /**< [IN] Grid name */
  const char *fieldname, /**< [IN] Field name */
  MTKt_DataType *datatype /**< [OUT] Data type */ )
{
  MTKt_status status_code;      /* Return status of this function */
  intn status;			/* HDF-EOS return status */
  int32 fid = FAIL;		/* HDF-EOS file identifier */

  if (filename == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  fid = GDopen((char *)filename, DFACC_READ);
  if (fid == FAIL) MTK_ERR_CODE_JUMP(MTK_HDFEOS_GDOPEN_FAILED);

  /* Read data type for the field. */
  status = MtkFileGridFieldToDataTypeFid(fid, gridname, fieldname, datatype);
  MTK_ERR_COND_JUMP(status);

  status = GDclose(fid);
  if (status == FAIL) MTK_ERR_CODE_JUMP(MTK_HDFEOS_GDCLOSE_FAILED);

  return MTK_SUCCESS;

ERROR_HANDLE:
  if (fid != FAIL) GDclose(fid);
  return status_code;
}

/** \brief Version of MtkFileGridFieldToDataType that takes an HDF-EOS file id rather than a filename. 
 *
 *  \return MTK_SUCCESS if successful.
 */

MTKt_status MtkFileGridFieldToDataTypeFid(
  int32 fid,            /**< [IN] HDF-EOS file identifier */
  const char *gridname, /**< [IN] Grid name */
  const char *fieldname, /**< [IN] Field name */
  MTKt_DataType *datatype /**< [OUT] Data type */ )
{
  MTKt_status status_code;      /* Return status of this function */
  intn status;			/* HDF-EOS return status */
  int32 gid = FAIL;		/* HDF-EOS grid identifier */
  int32 hdf_datatype;		/* HDF-EOS datatype number */
  int32 rank;			/* Not used */
  int32 dims[10];		/* Not used */
  char dimlist[80];		/* Not used */
  char *basefield = NULL;	/* Base fieldname */
  int nextradims;               /* Number of extra dimensions */
  int *extradims = NULL;	/* Extra dimension list */

  if (gridname == NULL ||
      fieldname == NULL || datatype == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  gid = GDattach(fid, (char *)gridname);
  if (gid == FAIL) MTK_ERR_CODE_JUMP(MTK_HDFEOS_GDATTACH_FAILED);

  status = MtkParseFieldname(fieldname, &basefield, &nextradims, &extradims);
  MTK_ERR_COND_JUMP(status);

  status = GDfieldinfo(gid, basefield, &rank, dims, &hdf_datatype, dimlist);
  if (status == FAIL) MTK_ERR_CODE_JUMP(MTK_HDFEOS_GDFIELDINFO_FAILED);

  status = GDdetach(gid);
  if (status == FAIL) MTK_ERR_CODE_JUMP(MTK_HDFEOS_GDDETACH_FAILED);

  status = MtkHdfToMtkDataTypeConvert(hdf_datatype, datatype);
  MTK_ERR_COND_JUMP(status);

  free(basefield);
  free(extradims);
  return MTK_SUCCESS;

ERROR_HANDLE:
  if (gid != FAIL) GDdetach(gid);
  if (basefield != NULL) free(basefield);
  if (extradims != NULL) free(extradims);
  return status_code;
}
