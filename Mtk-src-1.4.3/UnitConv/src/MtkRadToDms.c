/*===========================================================================
=                                                                           =
=                               MtkRadToDms                                 =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2005, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrUnitConv.h"
#include "MisrError.h"
/* M_PI is not defined in math.h in Linux unless __USE_BSD is defined */
/* and you can define it at the gcc command-line if -ansi is set */
#ifndef __USE_BSD
# define __USE_BSD
#endif
#include <math.h>

/** \brief Convert radians to packed degrees, minutes, seconds
 *
 *  \return MTK_SUCCESS if successful.
 *
 *  \par Example:
 *  In this example, we convert 2.270373886 radians to packed degrees, minutes, seconds.
 *
 *  \code
 *  status = MtkRadToDms(2.270373886, &dms);
 *  \endcode
 */

MTKt_status MtkRadToDms(
  double rad, /**< [IN] Radians */
  double *dms /**< [OUT] Degrees, minutes, seconds */ )
{
  MTKt_status status_code;      /* Return status of this function */
  MTKt_status status;           /* Return status */
  double dd;			/* Decimal degrees */

  if (dms == NULL)
    MTK_ERR_CODE_JUMP(MTK_NULLPTR);

  dd = rad / (M_PI / 180.0);

  status = MtkDdToDms( dd, dms );
  MTK_ERR_COND_JUMP(status);

  return MTK_SUCCESS;

ERROR_HANDLE:
  return status_code;
}
