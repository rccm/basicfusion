/*===========================================================================
=                                                                           =
=                              MtkTaiJdToUtcJd                              =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2006, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrUtil.h"
#include "MisrError.h"

/** \brief Convert TAI Julian date to UTC Julian date
 *
 *  \return MTK_SUCCESS if successful.
 *
 *  \par Example:
 *  In this example, we convert a TAI Julian date to a UTC Julian date.
 *
 *  \code
 *  status = MtkTaiJdToUtcJd(jdTAI, jdUTC);
 *  \endcode
 */

MTKt_status MtkTaiJdToUtcJd(
  double jdTAI[2], /**< [IN] TAI Julian date */
  double jdUTC[2] /**< [OUT] UTC Julian date */ )
{
  MTKt_status status_code; /* Return code of this function */
  double leap_seconds[][2] = LEAP_SECONDS;
  double leapSecs = 0.0;
  int i;
  
  /* Find leap seconds */
  for (i = sizeof(leap_seconds) / sizeof(*leap_seconds) - 1; i >= 0; --i)
    if (leap_seconds[i][0] <= jdTAI[0])
    {
      leapSecs = leap_seconds[i][1];
      break;
    } 

  /* Make sure time isn't before leap second range. */
  if (i == -1)
    MTK_ERR_CODE_JUMP(MTK_BAD_ARGUMENT) 
  
  jdUTC[0] = jdTAI[0];
  jdUTC[1] = jdTAI[1] - leapSecs / SECONDSperDAY;

  if (jdUTC[1] < 0.0)
  {
    jdUTC[0] -= 1.0;
	jdUTC[1] += 1.0;
  }

  if (jdUTC[1] >= 1.0)
  {
    jdUTC[0] += 1.0;
    jdUTC[1] -= 1.0;
  }

  return MTK_SUCCESS;

ERROR_HANDLE:
  return status_code;
}
