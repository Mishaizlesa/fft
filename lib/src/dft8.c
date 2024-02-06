#include "dft.h"
#include "math.h"
#include <stdio.h>
extern void dft8Fwd (const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    const float inv_sqrt2 = 0.7071067811865475f;
    cfloat32_t tmpDst [8];
    
    float tmp_op[8];
    tmp_op[0] = pSrc[0].re  + pSrc[4].re;
    tmp_op[1] = pSrc[2].re  + pSrc[6].re;
    tmp_op[2] = pSrc[0].im   + pSrc[4].im;
    tmp_op[3] = pSrc[2].im  + pSrc[6].im;
    tmp_op[4] = pSrc[0].re   - pSrc[4].re;
    tmp_op[5] = pSrc[2].im  - pSrc[6].im;
    tmp_op[6] = pSrc[0].im   - pSrc[4].im;
    tmp_op[7] = pSrc[2].re  - pSrc[6].re;

    tmpDst[0].re   = tmp_op[0] + tmp_op[1];
    tmpDst[0].im   = tmp_op[2] + tmp_op[3];
    tmpDst[1].re   = tmp_op[4] + tmp_op[5];
    tmpDst[1].im   = tmp_op[6] - tmp_op[7];
    tmpDst[2].re   = tmp_op[0] - tmp_op[1];
    tmpDst[2].im   = tmp_op[2] - tmp_op[3];
    tmpDst[3].re   = tmp_op[4] - tmp_op[5];
    tmpDst[3].im   = tmp_op[6] + tmp_op[7];  


    tmp_op[0] = pSrc[1].re  + pSrc[5].re;
    tmp_op[1] = pSrc[3].re  + pSrc[7].re;
    tmp_op[2] = pSrc[1].im   + pSrc[5].im;
    tmp_op[3] = pSrc[3].im  + pSrc[7].im;
    tmp_op[4] = pSrc[1].re   - pSrc[5].re;
    tmp_op[5] = pSrc[3].im  - pSrc[7].im;
    tmp_op[6] = pSrc[1].im   - pSrc[5].im;
    tmp_op[7] = pSrc[3].re  - pSrc[7].re ;


    tmpDst[4].re   = tmp_op[0] + tmp_op[1];
    tmpDst[4].im   = tmp_op[2] + tmp_op[3];
    tmpDst[5].re   = tmp_op[4] + tmp_op[5];
    tmpDst[5].im   = tmp_op[6] -tmp_op[7];
    tmpDst[6].re   = tmp_op[0] -tmp_op[1];
    tmpDst[6].im   = tmp_op[2] -tmp_op[3];
    tmpDst[7].re   = tmp_op[4] -tmp_op[5];
    tmpDst[7].im   = tmp_op[6] + tmp_op[7];  


    float re = tmpDst[5].re * inv_sqrt2 + tmpDst[5].im * inv_sqrt2;
    float im = tmpDst[5].im * inv_sqrt2 - tmpDst[5].re * inv_sqrt2;
    tmpDst[5].re = re;
    tmpDst[5].im = im;


    im = -tmpDst[6].re;
    tmpDst[6].re = tmpDst[6].im;
    tmpDst[6].im = im;

    re = -tmpDst[7].re * inv_sqrt2 + tmpDst[7].im * inv_sqrt2;
    im = -tmpDst[7].im * inv_sqrt2 - tmpDst[7].re * inv_sqrt2;
    tmpDst[7].re = re;
    tmpDst[7].im = im;



    pDst[4].re = tmpDst[0].re - tmpDst[4].re;
    pDst[4].im = tmpDst[0].im - tmpDst[4].im;
    pDst[0].re = tmpDst[0].re + tmpDst[4].re;
    pDst[0].im = tmpDst[0].im + tmpDst[4].im;


    pDst[5].re = tmpDst[1].re - tmpDst[5].re;
    pDst[5].im = tmpDst[1].im - tmpDst[5].im;
    pDst[1].re = tmpDst[1].re + tmpDst[5].re;
    pDst[1].im = tmpDst[1].im + tmpDst[5].im;


    pDst[6].re = tmpDst[2].re - tmpDst[6].re;
    pDst[6].im = tmpDst[2].im - tmpDst[6].im;
    pDst[2].re = tmpDst[2].re + tmpDst[6].re;
    pDst[2].im = tmpDst[2].im + tmpDst[6].im;


    pDst[3].re = tmpDst[3].re + tmpDst[7].re;
    pDst[3].im = tmpDst[3].im + tmpDst[7].im;
    pDst[7].re = tmpDst[3].re - tmpDst[7].re;
    pDst[7].im = tmpDst[3].im - tmpDst[7].im;

    return;
}
