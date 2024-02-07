#include "dft.h"
const float C_PI_8 = 0.92387953251f;
const float inv_sqrt2 = 0.7071067811865475f;
const float S_PI_8 = 0.38268343236f;
//#include "common_defs.h"
extern void dft16Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    cfloat32_t tmpDst [16];
    cfloat32_t tmp_op[4];
    
    

    tmp_op[0].re = pSrc[0].re   + pSrc[8].re;
    tmp_op[0].im = pSrc[0].im   + pSrc[8].im;
    tmp_op[1].re = pSrc[0].re   - pSrc[8].re;
    tmp_op[1].im = pSrc[0].im   - pSrc[8].im;
    tmp_op[2].re = pSrc[4].re   + pSrc[12].re;
    tmp_op[2].im = pSrc[4].im   + pSrc[12].im;
    tmp_op[3].re = pSrc[4].re   - pSrc[12].re;
    tmp_op[3].im = pSrc[4].im   - pSrc[12].im;
    tmpDst[0].re   = tmp_op[0].re + tmp_op[2].re;
    tmpDst[0].im   = tmp_op[0].im + tmp_op[2].im;
    tmpDst[1].re   = tmp_op[1].re + tmp_op[3].im;
    tmpDst[1].im   = tmp_op[1].im - tmp_op[3].re;
    tmpDst[2].re   = tmp_op[0].re - tmp_op[2].re;
    tmpDst[2].im   = tmp_op[0].im - tmp_op[2].im;
    tmpDst[3].re   = tmp_op[1].re - tmp_op[3].im;
    tmpDst[3].im   = tmp_op[1].im + tmp_op[3].re;

    tmp_op[0].re = pSrc[1].re   + pSrc[9].re;
    tmp_op[0].im = pSrc[1].im   + pSrc[9].im;
    tmp_op[1].re = pSrc[1].re   - pSrc[9].re;
    tmp_op[1].im = pSrc[1].im   - pSrc[9].im;
    tmp_op[2].re = pSrc[5].re   + pSrc[13].re;
    tmp_op[2].im = pSrc[5].im   + pSrc[13].im;
    tmp_op[3].re = pSrc[5].re   - pSrc[13].re;
    tmp_op[3].im = pSrc[5].im   - pSrc[13].im;
    tmpDst[4].re   = tmp_op[0].re + tmp_op[2].re;
    tmpDst[4].im   = tmp_op[0].im + tmp_op[2].im;
    tmpDst[5].re   = tmp_op[1].re + tmp_op[3].im;
    tmpDst[5].im   = tmp_op[1].im - tmp_op[3].re;
    tmpDst[6].re   = tmp_op[0].re - tmp_op[2].re;
    tmpDst[6].im   = tmp_op[0].im - tmp_op[2].im;
    tmpDst[7].re   = tmp_op[1].re - tmp_op[3].im;
    tmpDst[7].im   = tmp_op[1].im + tmp_op[3].re;



    tmp_op[0].re = pSrc[2].re   + pSrc[10].re;
    tmp_op[0].im = pSrc[2].im   + pSrc[10].im;
    tmp_op[1].re = pSrc[2].re   - pSrc[10].re;
    tmp_op[1].im = pSrc[2].im   - pSrc[10].im;
    tmp_op[2].re = pSrc[6].re   + pSrc[14].re;
    tmp_op[2].im = pSrc[6].im   + pSrc[14].im;
    tmp_op[3].re = pSrc[6].re   - pSrc[14].re;
    tmp_op[3].im = pSrc[6].im   - pSrc[14].im;
    tmpDst[8].re   = tmp_op[0].re + tmp_op[2].re;
    tmpDst[8].im   = tmp_op[0].im + tmp_op[2].im;
    tmpDst[9].re   = tmp_op[1].re + tmp_op[3].im;
    tmpDst[9].im   = tmp_op[1].im - tmp_op[3].re;
    tmpDst[10].re   = tmp_op[0].re - tmp_op[2].re;
    tmpDst[10].im   = tmp_op[0].im - tmp_op[2].im;
    tmpDst[11].re   = tmp_op[1].re - tmp_op[3].im;
    tmpDst[11].im   = tmp_op[1].im + tmp_op[3].re;



    tmp_op[0].re = pSrc[3].re   + pSrc[11].re;
    tmp_op[0].im = pSrc[3].im   + pSrc[11].im;
    tmp_op[1].re = pSrc[3].re   - pSrc[11].re;
    tmp_op[1].im = pSrc[3].im   - pSrc[11].im;
    tmp_op[2].re = pSrc[7].re   + pSrc[15].re;
    tmp_op[2].im = pSrc[7].im   + pSrc[15].im;
    tmp_op[3].re = pSrc[7].re   - pSrc[15].re;
    tmp_op[3].im = pSrc[7].im   - pSrc[15].im;
    tmpDst[12].re   = tmp_op[0].re + tmp_op[2].re;
    tmpDst[12].im   = tmp_op[0].im + tmp_op[2].im;
    tmpDst[13].re   = tmp_op[1].re + tmp_op[3].im;
    tmpDst[13].im   = tmp_op[1].im - tmp_op[3].re;
    tmpDst[14].re   = tmp_op[0].re - tmp_op[2].re;
    tmpDst[14].im   = tmp_op[0].im - tmp_op[2].im;
    tmpDst[15].re   = tmp_op[1].re - tmp_op[3].im;
    tmpDst[15].im   = tmp_op[1].im + tmp_op[3].re;

    cfloat32_t tmp1, tmp2;

    tmp1.re = tmpDst[5].re*C_PI_8;
    tmp1.im = tmpDst[5].im*C_PI_8;
    tmp2.re = tmpDst[5].re*S_PI_8;
    tmp2.im = tmpDst[5].im*S_PI_8;
    tmpDst[5].re = tmp1.re + tmp2.im;
    tmpDst[5].im = tmp1.im - tmp2.re;

    tmp1.re = tmpDst[6].re*inv_sqrt2;
    tmp1.im = tmpDst[6].im*inv_sqrt2;
    tmpDst[6].re = tmp1.re + tmp1.im;
    tmpDst[6].im = tmp1.im - tmp1.re;

    tmp1.re = tmpDst[7].re*C_PI_8;
    tmp1.im = tmpDst[7].im*C_PI_8;
    tmp2.re = tmpDst[7].re*S_PI_8;
    tmp2.im = tmpDst[7].im*S_PI_8;
    tmpDst[7].re = tmp2.re + tmp1.im;
    tmpDst[7].im = tmp2.im - tmp1.re;


    tmp1.re = tmpDst[9].re*inv_sqrt2;
    tmp1.im = tmpDst[9].im*inv_sqrt2;
    tmpDst[9].re = tmp1.re + tmp1.im;
    tmpDst[9].im = tmp1.im - tmp1.re;

    float im = -tmpDst[10].re;
    tmpDst[10].re = tmpDst[10].im;
    tmpDst[10].im = im;


    tmp1.re = tmpDst[11].re*inv_sqrt2;
    tmp1.im = tmpDst[11].im*inv_sqrt2;
    tmpDst[11].re = -tmp1.re + tmp1.im;
    tmpDst[11].im = -tmp1.im - tmp1.re;



    tmp1.re = tmpDst[13].re*C_PI_8;
    tmp1.im = tmpDst[13].im*C_PI_8;
    tmp2.re = tmpDst[13].re*S_PI_8;
    tmp2.im = tmpDst[13].im*S_PI_8;
    tmpDst[13].re = tmp2.re + tmp1.im;
    tmpDst[13].im = tmp2.im - tmp1.re;

    tmp1.re = tmpDst[14].re*inv_sqrt2;
    tmp1.im = tmpDst[14].im*inv_sqrt2;
    tmpDst[14].re = -tmp1.re + tmp1.im;
    tmpDst[14].im = -tmp1.im - tmp1.re;

    tmp1.re = tmpDst[15].re*C_PI_8;
    tmp1.im = tmpDst[15].im*C_PI_8;
    tmp2.re = tmpDst[15].re*S_PI_8;
    tmp2.im = tmpDst[15].im*S_PI_8;
    tmpDst[15].re = -tmp1.re - tmp2.im;
    tmpDst[15].im = -tmp1.im + tmp2.re;


    tmp_op[0].re = tmpDst[0].re   + tmpDst[8].re;
    tmp_op[0].im = tmpDst[0].im   + tmpDst[8].im;
    tmp_op[1].re = tmpDst[0].re   - tmpDst[8].re;
    tmp_op[1].im = tmpDst[0].im   - tmpDst[8].im;
    tmp_op[2].re = tmpDst[4].re   + tmpDst[12].re;
    tmp_op[2].im = tmpDst[4].im   + tmpDst[12].im;
    tmp_op[3].re = tmpDst[4].re   - tmpDst[12].re;
    tmp_op[3].im = tmpDst[4].im   - tmpDst[12].im;
    pDst[0].re   = tmp_op[0].re + tmp_op[2].re;
    pDst[0].im   = tmp_op[0].im + tmp_op[2].im;
    pDst[4].re   = tmp_op[1].re + tmp_op[3].im;
    pDst[4].im   = tmp_op[1].im - tmp_op[3].re;
    pDst[8].re   = tmp_op[0].re - tmp_op[2].re;
    pDst[8].im   = tmp_op[0].im - tmp_op[2].im;
    pDst[12].re   = tmp_op[1].re - tmp_op[3].im;
    pDst[12].im   = tmp_op[1].im + tmp_op[3].re;



    tmp_op[0].re = tmpDst[1].re   + tmpDst[9].re;
    tmp_op[0].im = tmpDst[1].im   + tmpDst[9].im;
    tmp_op[1].re = tmpDst[1].re   - tmpDst[9].re;
    tmp_op[1].im = tmpDst[1].im   - tmpDst[9].im;
    tmp_op[2].re = tmpDst[5].re   + tmpDst[13].re;
    tmp_op[2].im = tmpDst[5].im   + tmpDst[13].im;
    tmp_op[3].re = tmpDst[5].re   - tmpDst[13].re;
    tmp_op[3].im = tmpDst[5].im   - tmpDst[13].im;
    pDst[1].re   = tmp_op[0].re + tmp_op[2].re;
    pDst[1].im   = tmp_op[0].im + tmp_op[2].im;
    pDst[5].re   = tmp_op[1].re + tmp_op[3].im;
    pDst[5].im   = tmp_op[1].im - tmp_op[3].re;
    pDst[9].re   = tmp_op[0].re - tmp_op[2].re;
    pDst[9].im   = tmp_op[0].im - tmp_op[2].im;
    pDst[13].re   = tmp_op[1].re - tmp_op[3].im;
    pDst[13].im   = tmp_op[1].im + tmp_op[3].re;


    tmp_op[0].re = tmpDst[2].re   + tmpDst[10].re;
    tmp_op[0].im = tmpDst[2].im   + tmpDst[10].im;
    tmp_op[1].re = tmpDst[2].re   - tmpDst[10].re;
    tmp_op[1].im = tmpDst[2].im   - tmpDst[10].im;
    tmp_op[2].re = tmpDst[6].re   + tmpDst[14].re;
    tmp_op[2].im = tmpDst[6].im   + tmpDst[14].im;
    tmp_op[3].re = tmpDst[6].re   - tmpDst[14].re;
    tmp_op[3].im = tmpDst[6].im   - tmpDst[14].im;
    pDst[2].re   = tmp_op[0].re + tmp_op[2].re;
    pDst[2].im   = tmp_op[0].im + tmp_op[2].im;
    pDst[6].re   = tmp_op[1].re + tmp_op[3].im;
    pDst[6].im   = tmp_op[1].im - tmp_op[3].re;
    pDst[10].re   = tmp_op[0].re - tmp_op[2].re;
    pDst[10].im   = tmp_op[0].im - tmp_op[2].im;
    pDst[14].re   = tmp_op[1].re - tmp_op[3].im;
    pDst[14].im   = tmp_op[1].im + tmp_op[3].re;



    tmp_op[0].re = tmpDst[3].re   + tmpDst[11].re;
    tmp_op[0].im = tmpDst[3].im   + tmpDst[11].im;
    tmp_op[1].re = tmpDst[3].re   - tmpDst[11].re;
    tmp_op[1].im = tmpDst[3].im   - tmpDst[11].im;
    tmp_op[2].re = tmpDst[7].re   + tmpDst[15].re;
    tmp_op[2].im = tmpDst[7].im   + tmpDst[15].im;
    tmp_op[3].re = tmpDst[7].re   - tmpDst[15].re;
    tmp_op[3].im = tmpDst[7].im   - tmpDst[15].im;
    pDst[3].re   = tmp_op[0].re + tmp_op[2].re;
    pDst[3].im   = tmp_op[0].im + tmp_op[2].im;
    pDst[7].re   = tmp_op[1].re + tmp_op[3].im;
    pDst[7].im   = tmp_op[1].im - tmp_op[3].re;
    pDst[11].re   = tmp_op[0].re - tmp_op[2].re;
    pDst[11].im   = tmp_op[0].im - tmp_op[2].im;
    pDst[15].re   = tmp_op[1].re - tmp_op[3].im;
    pDst[15].im   = tmp_op[1].im + tmp_op[3].re;
    
    return;
}
