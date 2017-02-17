//////////////////////////////////////////////////////////////////////
// gmp-mparam.h
/* Generated by tuneup.c, 2014-03-21, gcc 4.3 */

#define MUL_KARATSUBA_THRESHOLD          22
#define MUL_TOOM3_THRESHOLD              85
#define MUL_TOOM4_THRESHOLD             244
#define MUL_TOOM8H_THRESHOLD            490

#define SQR_BASECASE_THRESHOLD            0  /* always (native) */
#define SQR_KARATSUBA_THRESHOLD          30
#define SQR_TOOM3_THRESHOLD             113
#define SQR_TOOM4_THRESHOLD             532
#define SQR_TOOM8_THRESHOLD             656

#define POWM_THRESHOLD                  984

#define DIVREM_1_NORM_THRESHOLD       MP_SIZE_T_MAX  /* never */
#define DIVREM_1_UNNORM_THRESHOLD     MP_SIZE_T_MAX  /* never */
#define MOD_1_NORM_THRESHOLD              0  /* always */
#define MOD_1_UNNORM_THRESHOLD            0  /* always */
#define USE_PREINV_DIVREM_1               1  /* native */
#define USE_PREINV_MOD_1                  1
#define DIVEXACT_1_THRESHOLD          MP_SIZE_T_MAX  /* never */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always (native) */
#define MOD_1_1_THRESHOLD                 6
#define MOD_1_2_THRESHOLD                 6
#define MOD_1_3_THRESHOLD                24
#define DIVREM_HENSEL_QR_1_THRESHOLD      7
#define RSH_DIVREM_HENSEL_QR_1_THRESHOLD      6
#define DIVREM_EUCLID_HENSEL_THRESHOLD      8

#define MUL_FFT_FULL_THRESHOLD         8000

#define SQR_FFT_FULL_THRESHOLD         4032

#define MULLOW_BASECASE_THRESHOLD        10
#define MULLOW_DC_THRESHOLD              17
#define MULLOW_MUL_THRESHOLD           9970

#define MULHIGH_BASECASE_THRESHOLD       40
#define MULHIGH_DC_THRESHOLD             40
#define MULHIGH_MUL_THRESHOLD          8681

#define MULMOD_2EXPM1_THRESHOLD          20

#define DC_DIV_QR_THRESHOLD              61
#define INV_DIV_QR_THRESHOLD           3410
#define INV_DIVAPPR_Q_N_THRESHOLD        61
#define DC_DIV_Q_THRESHOLD               62
#define INV_DIV_Q_THRESHOLD            2350
#define DC_DIVAPPR_Q_THRESHOLD           99
#define INV_DIVAPPR_Q_THRESHOLD       19406
#define DC_BDIV_QR_THRESHOLD             42
#define DC_BDIV_Q_THRESHOLD              19

#define ROOTREM_THRESHOLD                11

#define MATRIX22_STRASSEN_THRESHOLD      31
#define HGCD_THRESHOLD                  115
#define HGCD_APPR_THRESHOLD              50
#define HGCD_REDUCE_THRESHOLD          6852
#define GCD_DC_THRESHOLD                610
#define GCDEXT_DC_THRESHOLD             368
#define JACOBI_BASE_METHOD                2

#define GET_STR_DC_THRESHOLD             17
#define GET_STR_PRECOMPUTE_THRESHOLD     23
#define SET_STR_DC_THRESHOLD            547
#define SET_STR_PRECOMPUTE_THRESHOLD   2113

#define FAC_DSC_THRESHOLD              1639
#define FAC_ODD_THRESHOLD                31

/* fft_tuning -- autogenerated by tune-fft */

#define FFT_TAB \
   { { 4, 4 }, { 4, 3 }, { 3, 3 }, { 3, 1 }, { 2, 1 } }

#define MULMOD_TAB \
   { 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1 }

#define FFT_N_NUM 23

#define FFT_MULMOD_2EXPP1_CUTOFF 256


/* Tuneup completed successfully, took 213 seconds */



//////////////////////////////////////////////////////////////////////
// iDev.Games - MuOnline S9EP2 IGC9.5 - TRONG.WIN - DAO VAN TRONG     
//////////////////////////////////////////////////////////////////////

