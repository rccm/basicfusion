/*===========================================================================
=                                                                           =
=                            MtkRegressionCoeffFree                         =
=                                                                           =
=============================================================================

                         Jet Propulsion Laboratory
                                   MISR
                               MISR Toolkit

            Copyright 2008, California Institute of Technology.
                           ALL RIGHTS RESERVED.
                 U.S. Government Sponsorship acknowledged.

============================================================================*/

#include "MisrRegression.h"
#include "MisrError.h"
#include <stdlib.h>

/** \brief Free memory for regression coefficients.
 *
 *  \return MTK_SUCCESS
 *
 *  \par Example:
 *  In this example, we have a MTKt_RegressionCoeff called \c regressbuf that was previously allocated with MtkRegressionCoeffAllocate() and we wish to free it.
 *
 *  \code
 *  status = MtkRegressionCoeffFree(&regressbuf);
 *  \endcode
 */

MTKt_status MtkRegressionCoeffFree(
  MTKt_RegressionCoeff *regressbuf /**< [IN,OUT] Data Buffer */ 
)
{
  MTKt_status status;           /* Return status */

  if (regressbuf != NULL) {
    status = MtkDataBufferFree(&regressbuf->valid_mask);
    status = MtkDataBufferFree(&regressbuf->slope);
    status = MtkDataBufferFree(&regressbuf->intercept);
    status = MtkDataBufferFree(&regressbuf->correlation);
  }

  return MTK_SUCCESS;
}
