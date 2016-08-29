/*===========================================================================
=                                                                           =
=                             MtkFileToOrbit                                =
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
#include "MisrError.h"
#include <hdf.h>
#include <mfhdf.h>

/** \brief Read orbit number from file
 *
 *  \return MTK_SUCCESS if successful.
 *
 *  \par Example:
 *  In this example, we read the orbit number from the file
 *  \c MISR_AM1_GRP_TERRAIN_GM_P161_O012115_DF_F03_0021.hdf
 *
 *  \code
 *  status = MtkFileToOrbit("MISR_AM1_GRP_TERRAIN_GM_P161_O012115_DF_F03_0021.hdf", &orbit);
 *  \endcode
 */

MTKt_status MtkFileToOrbit( const char *filename, /**< [IN] File name */
			   int *orbit            /**< [OUT] Orbit number */ )
{
  MTKt_status status_code;      /* Return status of this function */
  MTKt_status status;           /* Return status */
  int32 hdf_status;        /* HDF-EOS return status */
  int32 sd_id = FAIL;      /* HDF SD file identifier. */

  if (filename == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  /* Open HDF File */
  hdf_status = sd_id = SDstart(filename, DFACC_READ);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDSTART_FAILED);

  /* Read orbit number. */
  status = MtkFileToOrbitFid(sd_id, orbit);
  MTK_ERR_COND_JUMP(status);

  /* Close HDF File */
  hdf_status = SDend(sd_id);
  if (hdf_status == FAIL)
    MTK_ERR_CODE_JUMP(MTK_HDF_SDEND_FAILED);
  sd_id = FAIL;

  return MTK_SUCCESS;

ERROR_HANDLE:
  if (sd_id != FAIL)
    SDend(sd_id);

  return status_code;
}

/** \brief Version of MtkFileToOrbit that takes an HDF SD file identifier rather than a filename.
 *
 *  \return MTK_SUCCESS if successful.
 */

MTKt_status MtkFileToOrbitFid( int32 sd_id, /**< [IN] HDF SD file identifier */
			       int *orbit            /**< [OUT] Orbit number */ )
{
  MTKt_status status_code;      /* Return status of this function */
  MTKt_status status;           /* Return status */
  MtkCoreMetaData metadata = MTK_CORE_METADATA_INIT;
				/* Core metadata structure */

  if (orbit == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  status = MtkFileCoreMetaDataGetFid(sd_id, "ORBITNUMBER", &metadata);
  MTK_ERR_COND_JUMP(status);

  *orbit = metadata.data.i[0];

  MtkCoreMetaDataFree(&metadata);
  return MTK_SUCCESS;

ERROR_HANDLE:
  MtkCoreMetaDataFree(&metadata);
  return status_code;
}
