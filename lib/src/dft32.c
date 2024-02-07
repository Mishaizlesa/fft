#include "dft.h"
#include "common_defs.h"
void dft32Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    uint32_t n1 = 4;
    uint32_t n2 = 8;
    uint32_t length = n1 * n2;

    cfloat32_t tmpSrc[32];
    cfloat32_t tmpDst[32];

    for (uint32_t i1 = 0; i1 < n1; i1++)
    {

        tmpSrc[i1 * n2].re = pSrc[i1].re;
        tmpSrc[i1 * n2].im = pSrc[i1].im;

        tmpSrc[1 + i1 * n2].re = pSrc[n1 * 1 + i1].re;
        tmpSrc[1 + i1 * n2].im = pSrc[n1 * 1 + i1].im;

        tmpSrc[2 + i1 * n2].re = pSrc[n1 * 2 + i1].re;
        tmpSrc[2 + i1 * n2].im = pSrc[n1 * 2 + i1].im;

        tmpSrc[3 + i1 * n2].re = pSrc[n1 * 3 + i1].re;
        tmpSrc[3 + i1 * n2].im = pSrc[n1 * 3 + i1].im;

        tmpSrc[4 + i1 * n2].re = pSrc[n1 * 4 + i1].re;
        tmpSrc[4 + i1 * n2].im = pSrc[n1 * 4 + i1].im;

        tmpSrc[5 + i1 * n2].re = pSrc[n1 * 5 + i1].re;
        tmpSrc[5 + i1 * n2].im = pSrc[n1 * 5 + i1].im;

        tmpSrc[6 + i1 * n2].re = pSrc[n1 * 6 + i1].re;
        tmpSrc[6 + i1 * n2].im = pSrc[n1 * 6 + i1].im;

        tmpSrc[7 + i1 * n2].re = pSrc[n1 * 7 + i1].re;
        tmpSrc[7 + i1 * n2].im = pSrc[n1 * 7 + i1].im;


        dft8Fwd(&tmpSrc[i1 * n2], &tmpDst[i1 * n2]);
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


    //refDftFwd(pSrc, pDst, 32);
}
