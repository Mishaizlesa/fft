#include "dft.h"
#include "common_defs.h"
extern void dft16Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    const float inv_sqrt2 = 0.7071067811865475f;
    cfloat32_t tmpDst [16];
    cfloat32_t tmpSrc[16];
    uint32_t n1 = 4;
    uint32_t n2 = 4;
    uint32_t length = n1 * n2;
//n1 = 4 n2 = 4
    for (uint32_t i2 = 0; i2 < n2; i2++)
    {
        for (uint32_t i1 = 0; i1 < n1; i1++)
        {
            tmpSrc[i2 + i1 * n2].re = pSrc[n1 * i2 + i1].re;
            tmpSrc[i2 + i1 * n2].im = pSrc[n1 * i2 + i1].im;
        }
    }
     for (uint32_t i1 = 0; i1 < n1; i1++)
    {
        dft4Fwd(&tmpSrc[i1 * n2], &tmpDst[i1 * n2]);
    }

     for (uint32_t i1 = 1; i1 < n1; i1++)
    {
        for (uint32_t i2 = 0; i2 < n2; i2++)
        {
            float twdRe = cos(OWN_2PI * i2 * i1 / length);
            float twdIm =-sin(OWN_2PI * i2 * i1 / length);
            float re = tmpDst[i1 * n2 + i2].re * twdRe - tmpDst[i1 * n2 + i2].im * twdIm;
            float im = tmpDst[i1 * n2 + i2].im * twdRe + tmpDst[i1 * n2 + i2].re * twdIm;
            tmpDst[i1 * n2 + i2].re = re;
            tmpDst[i1 * n2 + i2].im = im;
        }
    }

    for (uint32_t i1 = 0; i1 < n1; i1++)
    {
        for (uint32_t i2 = 0; i2 < n2; i2++)
        {
            tmpSrc[n1 * i2 + i1].re = tmpDst[n2 * i1 + i2].re;
            tmpSrc[n1 * i2 + i1].im = tmpDst[n2 * i1 + i2].im;
        }
    }

     for (uint32_t i2 = 0; i2 < n2; i2++)
    {
        dft4Fwd(&tmpSrc[i2 * n1], &tmpDst[i2 * n1]);
    }

    for (uint32_t i2 = 0; i2 < n2; i2++)
    {
        for (uint32_t i1 = 0; i1 < n1; i1++)
        {
            pDst[n2 * i1 + i2].re = tmpDst[i1 + i2 * n1].re;
            pDst[n2 * i1 + i2].im = tmpDst[i1 + i2 * n1].im;
        }
    }
    return;
}
