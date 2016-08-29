/*===========================================================================
=                                                                           =
=                              MtkFileAttrGet                               =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2006, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrFileQuery.h"
#include "MisrUtil.h"
#include "MisrError.h"
#include <mfhdf.h>
#include <HdfEosDef.h>

/** \brief Get a file attribute
 *
 *  \return MTK_SUCCESS if successful.
 *
 *  \par Example:
 *  In this example, we get the \c Camera attribute from the file \c MISR_AM1_GRP_TERRAIN_GM_P161_O012115_DF_F03_0021.hdf
 *
 *  \code
 *  status = MtkFileAttrGet("MISR_AM1_GRP_TERRAIN_GM_P161_O012115_DF_F03_0021.hdf", "Camera", &attrbuf);
 *  \endcode
 *
 *  \note
 *  The caller is responsible for using MtkDataBufferFree() to free the memory used by \c attrbuf
 */

MTKt_status MtkFileAttrGet(
  const char *filename,    /**< [IN] File name */
  const char *attrname,    /**< [IN] Attribute name */
  MTKt_DataBuffer *attrbuf /**< [OUT] Attribute value */ )
{
  MTKt_status status_code; /* Return status of this function */
  MTKt_status status;      /* Return status */
  intn hdf_status;
  int32 sds_id = FAIL;

  if (filename == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  /* Open HDF File */
  hdf_status = sds_id = SDstart(filename, DFACC_READ);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDSTART_FAILED);

  /* Read attribute. */
  status = MtkFileAttrGetFid(sds_id, attrname, attrbuf);
  MTK_ERR_COND_JUMP(status);

  /* Close HDF File */
  hdf_status = SDend(sds_id);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDEND_FAILED);
  sds_id = FAIL;

  return MTK_SUCCESS;

ERROR_HANDLE:
  if (sds_id != FAIL)
    SDend(sds_id);
  return status_code;
}

/** \brief Version of MtkFileAttrGet that takes an HDF SD file identifier rather than a filename.
 *
 *  \return MTK_SUCCESS if successful.
 */

MTKt_status MtkFileAttrGetFid(
  int32 sds_id,            /**< [IN] HDF SD file identifier */
  const char *attrname,    /**< [IN] Attribute name */
  MTKt_DataBuffer *attrbuf /**< [OUT] Attribute value */ )
{
  MTKt_status status_code; /* Return status of this function */
  MTKt_status status;      /* Return status */
  intn hdf_status;
  int32 attr_index;
  int32 hdf_datatype;
  int32 count;
  MTKt_DataType datatype;       /* Mtk data type */
  MTKt_DataBuffer attrbuf_tmp = MTKT_DATABUFFER_INIT; /* Temp attribute buffer */
  char attr_name_tmp[MAXSTR];

  if (attrname == NULL || attrbuf == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  /* Find attribute index */
  hdf_status = attr_index = SDfindattr(sds_id, attrname);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDFINDATTR_FAILED);

  /* Get attribute information */
  hdf_status = SDattrinfo(sds_id, attr_index, attr_name_tmp, &hdf_datatype, &count);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDATTRINFO_FAILED);

  /* Convert to Mtk Data Type */
  status = MtkHdfToMtkDataTypeConvert(hdf_datatype, &datatype);
  if (status != MTK_SUCCESS)
    MTK_ERR_CODE_JUMP(status);

  /* Allocate Memory */
  status = MtkDataBufferAllocate(1, count, datatype, &attrbuf_tmp);
  if (status != MTK_SUCCESS)
    MTK_ERR_CODE_JUMP(status);

  /* Read attribute */
  hdf_status = SDreadattr(sds_id, attr_index, attrbuf_tmp.dataptr);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDREADATTR_FAILED);

  *attrbuf = attrbuf_tmp;

  return MTK_SUCCESS;

ERROR_HANDLE:

  MtkDataBufferFree(&attrbuf_tmp);

  return status_code;
}
