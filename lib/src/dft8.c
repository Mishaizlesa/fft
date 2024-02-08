#include "dft.h"
#include "riscv_vector.h"
extern void dft8Fwd (const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    const float inv_sqrt2 = 0.7071067811865475f;
    //cfloat32_t tmpDst [8];
    
    float tmp_op[16];
    vfloat32m2_t vec_dst1 = vfmv_v_f_f32m2(0.0,8);
    vfloat32m2_t vec_dst2 = vfmv_v_f_f32m2(0.0,8);
    vfloat32m2_t vec_src1 = vle32_v_f32m2((float*) pSrc, 8);
    vfloat32m2_t vec_src2 = vle32_v_f32m2((float*) (pSrc +4), 8);
    

    vec_dst1 = vfadd_vv_f32m2 (vec_src1, vec_src2, 8);
    vec_dst2 = vfsub_vv_f32m2 (vec_src1, vec_src2, 8);
    

    vse32_v_f32m2 (tmp_op, vec_dst1, 8);
    vse32_v_f32m2 (tmp_op+8, vec_dst2, 8);
    /*tmp_op[0] = pSrc[0].re  + pSrc[4].re;
    tmp_op[1] = pSrc[2].re  + pSrc[6].re;
    tmp_op[2] = pSrc[0].im   + pSrc[4].im;
    tmp_op[3] = pSrc[2].im  + pSrc[6].im;
    tmp_op[4] = pSrc[0].re   - pSrc[4].re;
    tmp_op[5] = pSrc[2].im  - pSrc[6].im;
    tmp_op[6] = pSrc[0].im   - pSrc[4].im;
    tmp_op[7] = pSrc[2].re  - pSrc[6].re;

    tmp_op[0] = pSrc[1].re  + pSrc[5].re;
    tmp_op[1] = pSrc[3].re  + pSrc[7].re;
    tmp_op[2] = pSrc[1].im   + pSrc[5].im;
    tmp_op[3] = pSrc[3].im  + pSrc[7].im;
    tmp_op[4] = pSrc[1].re   - pSrc[5].re;
    tmp_op[5] = pSrc[3].im  - pSrc[7].im;
    tmp_op[6] = pSrc[1].im   - pSrc[5].im;
    tmp_op[7] = pSrc[3].re  - pSrc[7].re ;*/


    pDst[0].re   = tmp_op[0] + tmp_op[4];
    pDst[0].im   = tmp_op[1] + tmp_op[5];
    pDst[1].re   = tmp_op[8] + tmp_op[13];
    pDst[1].im   = tmp_op[9] - tmp_op[12];
    pDst[2].re   = tmp_op[0] - tmp_op[4];
    pDst[2].im   = tmp_op[1] - tmp_op[5];
    pDst[3].re   = tmp_op[8] - tmp_op[13];
    pDst[3].im   = tmp_op[9] + tmp_op[12];  


    

    pDst[4].re   = tmp_op[2] + tmp_op[6];
    pDst[4].im   = tmp_op[3] + tmp_op[7];
    pDst[5].re   = tmp_op[10] + tmp_op[15];
    pDst[5].im   = tmp_op[11] -tmp_op[14];
    pDst[6].re   = tmp_op[2] -tmp_op[6];
    pDst[6].im   = tmp_op[3] -tmp_op[7];
    pDst[7].re   = tmp_op[10] -tmp_op[15];
    pDst[7].im   = tmp_op[11] + tmp_op[14];  

    float re = pDst[5].re * inv_sqrt2 + pDst[5].im * inv_sqrt2;
    float im = pDst[5].im * inv_sqrt2 - pDst[5].re * inv_sqrt2;
    pDst[5].re = re;
    pDst[5].im = im;


    im = -pDst[6].re;
    pDst[6].re = pDst[6].im;
    pDst[6].im = im;

    re = -pDst[7].re * inv_sqrt2 + pDst[7].im * inv_sqrt2;
    im = -pDst[7].im * inv_sqrt2 - pDst[7].re * inv_sqrt2;
    pDst[7].re = re;
    pDst[7].im = im; 


    cfloat32_t TMP_0 = pDst[0];
    cfloat32_t TMP_1 = pDst[1];
    cfloat32_t TMP_2 = pDst[2];
    cfloat32_t TMP_3 = pDst[3];

    pDst[0].re = TMP_0.re + pDst[4].re;
    pDst[0].im = TMP_0.im + pDst[4].im;
    pDst[4].re = TMP_0.re - pDst[4].re;
    pDst[4].im = TMP_0.im - pDst[4].im;


    pDst[1].re = TMP_1.re + pDst[5].re;
    pDst[1].im = TMP_1.im + pDst[5].im;
    pDst[5].re = TMP_1.re - pDst[5].re;
    pDst[5].im = TMP_1.im - pDst[5].im;
    


    pDst[2].re = TMP_2.re + pDst[6].re;
    pDst[2].im = TMP_2.im + pDst[6].im;
    pDst[6].re = TMP_2.re - pDst[6].re;
    pDst[6].im = TMP_2.im - pDst[6].im;
    

    pDst[3].re = TMP_3.re + pDst[7].re;
    pDst[3].im = TMP_3.im + pDst[7].im;
    pDst[7].re = TMP_3.re - pDst[7].re;
    pDst[7].im = TMP_3.im - pDst[7].im;

    return;
}
