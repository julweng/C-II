//
// Julia Tzu-Ya Weng, U07487022
// julweng@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// Section: 121616
// Instructor: Raymond Mitchell
// Apr 24, 2017
// C2A4E3_pointerArray4D.cpp
// Mac OS X
// Xcode Version 8.3.1
//
// description:
// In this file, 4D array is created using the prointer array method.
//

// declare dimension sizes as extern so they can be accessed from other source files
extern const int DIM0 = 2, DIM1 = 3, DIM2 = 4, DIM3 = 5;

//dimension4
static float za[DIM3], zb[DIM3], zc[DIM3], zd[DIM3];
static float ze[DIM3], zf[DIM3], zg[DIM3], zh[DIM3];
static float zi[DIM3], zj[DIM3], zk[DIM3], zl[DIM3];
static float zm[DIM3], zn[DIM3], zo[DIM3], zp[DIM3];
static float zq[DIM3], zr[DIM3], zs[DIM3], zt[DIM3];
static float zu[DIM3], zv[DIM3], zw[DIM3], zx[DIM3];

//dimension3
static float *yi[DIM2] = {za, zb, zc, zd}, *yj[DIM2] = {ze, zf, zg, zh}, *yk[DIM2] = {zi, zj, zk, zl};
static float *yl[DIM2] = {zm, zn, zo, zp}, *ym[DIM2] = {zq, zr, zs, zt}, *yn[DIM2] = {zu, zv, zw, zx};

//dimension 2
static float **xr[DIM1] = {yi, yj, yk}, **xs[DIM1] = {yl, ym, yn};

//dimension 1
float ***pointerArray4D[DIM0] = {xr, xs};
