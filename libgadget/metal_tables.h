#ifndef METAL_TABLES_H
#define METAL_TABLES_H

/* Metals followed:
 * H, He, C, N, O, Ne, Mg, Si, Fe (9, following 1703.02970)
 */
#define NSPECIES 9
/* Largest mass in the IMF normalisation*/
#define MAXMASS 40
/* Only used for IMF normalisation*/
#define MINMASS 0.1
/* Mass in solar at which the yield tables switch from AGB stars to SNII*/
#define SNAGBSWITCH 8
/* Metallicity values (in terms of metal yield, not solar metallicity)
 * for the stellar lifetime table. Columns of lifetime.*/
#define LIFE_NMET 5
#define LIFE_NMASS 30
static const double lifetime_metallicity[LIFE_NMET] = { 0.0004 , 0.004 , 0.008, 0.02, 0.05 };
/* Mass values in solar masses for the stellar lifetime table. Rows of lifetime*/
static const double lifetime_masses[LIFE_NMASS] = {0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5,
    1.6, 1.7, 1.8, 1.9, 2.0, 2.5, 3 , 4 , 5 , 6 , 7 , 9 , 12 , 15 , 20 , 30 , 40 , 60 , 100, 120};
/* Stellar lifetimes as a function of mass and metallicity in years.
 * Table 14 of Portinari et al, astro-ph/9711337 */
static const double lifetime[LIFE_NMASS*LIFE_NMET] = {
4.28e+10,   5.35E+10,   6.47E+10,   7.92E+10,   7.18E+10,
2.37E+10,   2.95E+10,   3.54E+10,   4.45E+10,   4.00E+10,
1.41E+10,   1.73E+10,   2.09E+10,   2.61E+10,   2.33E+10,
8.97E+09,   1.09E+10,   1.30E+10,   1.59E+10,   1.42E+10,
6.03E+09,   7.13E+09,   8.46E+09,   1.03E+10,   8.88E+09,
4.23E+09,   4.93E+09,   5.72E+09,   6.89E+09,   5.95E+09,
3.08E+09,   3.52E+09,   4.12E+09,   4.73E+09,   4.39E+09,
2.34E+09,   2.64E+09,   2.92E+09,   3.59E+09,   3.37E+09,
1.92E+09,   2.39E+09,   2.36E+09,   2.87E+09,   3.10E+09,
1.66E+09,   1.95E+09,   2.18E+09,   2.64E+09,   2.51E+09,
1.39E+09,   1.63E+09,   1.82E+09,   2.18E+09,   2.06E+09,
1.18E+09,   1.28E+09,   1.58E+09,   1.84E+09,   1.76E+09,
1.11E+09,   1.25E+09,   1.41E+09,   1.59E+09,   1.51E+09,
9.66E+08,   1.23E+09,   1.25E+09,   1.38E+09,   1.34E+09,
8.33E+08,   1.08E+09,   1.23E+09,   1.21E+09,   1.24E+09,
4.64E+08,   5.98E+08,   6.86E+08,   7.64E+08,   6.58E+08,
3.03E+08,   3.67E+08,   4.12E+08,   4.56E+08,   3.81E+08,
1.61E+08,   1.82E+08,   1.93E+08,   2.03E+08,   1.64E+08,
1.01E+08,   1.11E+08,   1.15E+08,   1.15E+08,   8.91E+07,
7.15E+07,   7.62E+07,   7.71E+07,   7.45E+07,   5.67E+07,
5.33E+07,   5.61E+07,   5.59E+07,   5.31E+07,   3.97E+07,
3.42E+07,   3.51E+07,   3.44E+07,   3.17E+07,   2.33E+07,
2.13E+07,   2.14E+07,   2.10E+07,   1.89E+07,   1.39E+07,
1.54E+07,   1.52E+07,   1.49E+07,   1.33E+07,   9.95E+06,
1.06E+07,   1.05E+07,   1.01E+07,   9.15E+06,   6.99E+06,
6.90E+06,   6.85E+06,   6.65E+06,   6.13E+06,   5.15E+06,
5.45E+06,   5.44E+06,   5.30E+06,   5.12E+06,   4.34E+06,
4.20E+06,   4.19E+06,   4.15E+06,   4.12E+06,   3.62E+06,
3.32E+06,   3.38E+06,   3.44E+06,   3.39E+06,   3.11E+06,
3.11E+06,   3.23E+06,   3.32E+06,   3.23E+06,   3.11E+06};

/* Sn1a yields from the W7 model of Nomoto et al 1997 https://arxiv.org/abs/astro-ph/9706025
 * I extracted this from the latex source of their table 1 by hand.
 * total_metals is just the sum of all metal masses in the table.
 */
static const double sn1a_total_metals = 1.3743416565891;
static const double sn1a_yields[NSPECIES] = {0, 0, 4.83E-02, 1.16E-06 , 1.43E-01 , 4.51E-03, 8.57E-03, 1.53E-01, 7.43e-01};

/* AGB yields from Karakas 2010, 0912.2142 Tables A2 - A5. These have been parsed by the script in tools/extract_yields.py
 * Massive stars are from Doherty 2014, https://doi.org/10.1093/mnras/stt1877 and https://doi.org/10.1093/mnras/stu571
 * Some of the metallicities in Karakas are listed at M = 2 and some at M = 2.1. I have altered them all to be at M = 2,
 * a change which is within the uncertainty of the calculation.
 */
#define AGB_NMET 4
#define AGB_NMASS 18
static const double agb_masses[AGB_NMASS] = { 1.00,1.25,1.50,1.75,1.90,2.00,2.25,2.50,3.00,3.50,4.00,4.50,5.00,5.50,6.00,6.50,7.00,7.50 };
static const double agb_metallicities[AGB_NMET] = { 0.0001,0.0040,0.0080,0.0200 };
static const double agb_total_mass[AGB_NMET*AGB_NMASS] = {
0.280,0.390,0.423,0.436,
0.582,0.608,0.650,0.676,
0.839,0.872,0.867,0.900,
1.086,1.120,1.114,1.135,
1.219,1.260,1.260,1.270,
1.315,1.450,1.456,1.360,
1.537,1.586,1.598,1.590,
1.768,1.829,1.837,1.837,
2.187,2.269,2.306,2.318,
2.646,2.686,2.734,2.782,
3.126,3.148,3.164,3.208,
3.603,3.628,3.639,3.648,
4.071,4.095,4.114,4.121,
4.534,4.568,4.593,4.600,
4.994,5.023,5.052,5.071,
5.401,5.494,5.548,5.537,
5.827,5.936,6.001,6.033,
6.269,6.342,6.442,6.489,
};

static const double agb_total_metals[AGB_NMET*AGB_NMASS] = {
2.939e-04,1.485e-03,3.221e-03,8.302e-03,
3.962e-03,2.500e-03,4.963e-03,1.290e-02,
1.255e-02,5.246e-03,6.885e-03,1.721e-02,
2.588e-02,1.014e-02,1.164e-02,2.172e-02,
3.383e-02,1.416e-02,1.501e-02,2.431e-02,
4.129e-02,1.806e-02,2.186e-02,2.603e-02,
5.727e-02,3.139e-02,2.788e-02,3.145e-02,
5.650e-02,4.520e-02,3.684e-02,4.116e-02,
2.582e-02,5.087e-02,5.969e-02,6.170e-02,
2.710e-02,3.576e-02,4.916e-02,7.676e-02,
3.387e-02,4.534e-02,4.494e-02,7.494e-02,
2.771e-02,6.428e-02,6.819e-02,8.330e-02,
2.863e-02,8.468e-02,8.391e-02,9.272e-02,
3.246e-02,6.702e-02,7.944e-02,1.112e-01,
4.058e-02,6.991e-02,7.896e-02,1.164e-01,
1.007e-01,4.809e-02,7.900e-02,1.224e-01,
4.971e-02,3.936e-02,6.945e-02,1.349e-01,
3.387e-02,3.916e-02,6.827e-02,1.432e-01,

};

static const double agb_yield[NSPECIES][AGB_NMET*AGB_NMASS] = {
{2.098917e-01,2.837685e-01,3.030716e-01,2.917916e-01,
4.181523e-01,4.402004e-01,4.647374e-01,4.526932e-01,
5.871375e-01,6.310413e-01,6.216631e-01,6.062396e-01,
7.231110e-01,8.003024e-01,7.952502e-01,7.689168e-01,
7.975993e-01,8.940117e-01,8.979415e-01,8.627354e-01,
8.418292e-01,1.031207e+00,1.025440e+00,9.253072e-01,
9.679005e-01,1.086865e+00,1.113040e+00,1.078653e+00,
1.159112e+00,1.219034e+00,1.258521e+00,1.233581e+00,
1.581442e+00,1.538121e+00,1.534155e+00,1.524957e+00,
1.893222e+00,1.915657e+00,1.904093e+00,1.819895e+00,
2.169540e+00,2.193368e+00,2.242207e+00,2.143635e+00,
2.481520e+00,2.449144e+00,2.483966e+00,2.400789e+00,
2.761358e+00,2.636303e+00,2.707931e+00,2.652623e+00,
3.037755e+00,2.989116e+00,3.035734e+00,2.888854e+00,
3.240722e+00,3.205465e+00,3.278734e+00,3.136674e+00,
3.129000e+00,3.531000e+00,3.577000e+00,3.389015e+00,
3.581000e+00,3.824000e+00,3.870000e+00,3.770000e+00,
3.959000e+00,4.085000e+00,4.144000e+00,4.017000e+00,

},
{
6.976463e-02,1.046962e-01,1.166566e-01,1.358523e-01,
1.598219e-01,1.652351e-01,1.802360e-01,2.103396e-01,
2.392354e-01,2.356368e-01,2.383760e-01,2.764771e-01,
3.369195e-01,3.094681e-01,3.070183e-01,3.442725e-01,
3.874754e-01,3.517370e-01,3.469518e-01,3.828618e-01,
4.317810e-01,4.006273e-01,4.085950e-01,4.085601e-01,
5.117177e-01,4.676308e-01,4.569640e-01,4.797870e-01,
5.522625e-01,5.646438e-01,5.415177e-01,5.621283e-01,
5.795870e-01,6.798629e-01,7.120018e-01,7.311886e-01,
7.255036e-01,7.344115e-01,7.805668e-01,8.851663e-01,
9.223878e-01,9.090908e-01,8.766484e-01,9.892259e-01,
1.093530e+00,1.114345e+00,1.086616e+00,1.163685e+00,
1.280739e+00,1.373748e+00,1.321897e+00,1.375409e+00,
1.463488e+00,1.511581e+00,1.477543e+00,1.599672e+00,
1.712394e+00,1.747269e+00,1.693976e+00,1.817578e+00,
2.171000e+00,1.915004e+00,1.892005e+00,2.025270e+00,
2.196000e+00,2.073004e+00,2.062005e+00,2.128016e+00,
2.276000e+00,2.218006e+00,2.230006e+00,2.329018e+00,

},
{
2.548307e-04,2.007317e-04,4.499520e-04,1.188860e-03,
3.733844e-03,4.464190e-04,6.100381e-04,1.652404e-03,
1.161688e-02,2.206198e-03,9.797027e-04,2.018329e-03,
2.314672e-02,6.015899e-03,3.854005e-03,2.424878e-03,
2.968959e-02,9.332017e-03,6.109907e-03,2.706045e-03,
3.570287e-02,1.239873e-02,1.124944e-02,2.891137e-03,
4.844249e-02,2.385695e-02,1.585494e-02,4.315774e-03,
4.921946e-02,3.498655e-02,2.250193e-02,9.550566e-03,
2.395744e-02,3.907886e-02,3.964889e-02,2.093392e-02,
7.499905e-03,2.477810e-02,2.842070e-02,2.737855e-02,
5.496491e-03,1.091623e-02,2.201131e-02,1.921261e-02,
3.847183e-03,6.090742e-03,7.251039e-03,1.996513e-02,
3.193289e-03,5.875254e-03,4.790409e-03,1.786269e-02,
2.979007e-03,6.065955e-03,6.545073e-03,8.263152e-03,
1.564622e-03,5.016426e-03,5.207464e-03,6.271126e-03,
3.853600e-03,4.820900e-03,6.313500e-03,6.291284e-03,
2.563200e-03,3.790400e-03,5.379300e-03,7.561300e-03,
2.565400e-03,3.831900e-03,5.280200e-03,8.279700e-03,

},
{
5.571887e-06,1.361231e-04,2.725037e-04,6.631505e-04,
2.301341e-05,2.542933e-04,5.158191e-04,1.252953e-03,
4.452569e-05,3.972116e-04,7.765967e-04,1.880492e-03,
5.958874e-05,5.543761e-04,1.064622e-03,2.507770e-03,
7.103837e-05,6.368285e-04,1.191760e-03,2.815089e-03,
7.813261e-05,6.860504e-04,1.421203e-03,3.024347e-03,
8.142337e-05,8.018469e-04,1.559451e-03,3.694201e-03,
5.836106e-05,9.885715e-04,1.904179e-03,4.309833e-03,
8.782401e-05,1.217263e-03,2.468241e-03,5.661651e-03,
1.805374e-02,1.648287e-03,3.023767e-03,7.118027e-03,
2.634043e-02,2.366309e-02,3.487779e-03,8.631895e-03,
2.241779e-02,4.579481e-02,3.820866e-02,1.046125e-02,
2.405146e-02,6.564541e-02,5.544794e-02,1.642645e-02,
2.796230e-02,4.863977e-02,4.800098e-02,3.906971e-02,
3.745824e-02,5.402872e-02,4.988818e-02,4.182413e-02,
9.045626e-02,3.020097e-02,4.330114e-02,4.271098e-02,
4.486655e-02,2.116088e-02,3.290107e-02,4.301120e-02,
2.942762e-02,1.918132e-02,2.870115e-02,4.533135e-02,

},
{
2.490971e-05,7.457671e-04,1.624870e-03,4.196570e-03,
1.234212e-04,1.169008e-03,2.494431e-03,6.505379e-03,
3.160840e-04,1.706989e-03,3.330410e-03,8.659561e-03,
4.793708e-04,2.266871e-03,4.320108e-03,1.092500e-02,
5.378037e-04,2.564215e-03,4.910615e-03,1.222423e-02,
5.795720e-04,2.952074e-03,5.648813e-03,1.308835e-02,
7.052051e-04,3.252561e-03,6.188843e-03,1.514512e-02,
7.763611e-04,3.616575e-03,6.863281e-03,1.731160e-02,
5.221822e-04,4.374406e-03,8.296453e-03,2.123638e-02,
5.783944e-04,5.266665e-03,9.988093e-03,2.512805e-02,
7.999336e-04,6.077652e-03,1.176262e-02,2.924345e-02,
6.513333e-04,6.113582e-03,1.287679e-02,3.280990e-02,
6.109250e-04,5.122539e-03,1.201272e-02,3.599422e-02,
5.915777e-04,5.593279e-03,1.320244e-02,3.827719e-02,
6.622771e-04,3.847015e-03,1.164147e-02,4.077411e-02,
1.920547e-03,5.879672e-03,1.483454e-02,4.364789e-02,
1.101692e-03,7.012498e-03,1.623960e-02,4.776699e-02,
1.245540e-03,8.272425e-03,1.848258e-02,5.049371e-02,

},
{
3.771378e-06,1.366522e-04,2.967020e-04,7.653311e-04,
7.088088e-05,2.154086e-04,4.557682e-04,1.186591e-03,
5.502761e-04,3.397790e-04,6.141479e-04,1.578606e-03,
2.107102e-03,5.352139e-04,8.800038e-04,1.988661e-03,
3.370820e-03,7.546288e-04,1.072599e-03,2.223432e-03,
4.668795e-03,1.022163e-03,1.535058e-03,2.380030e-03,
7.470195e-03,2.341272e-03,2.068702e-03,2.850746e-03,
5.582660e-03,4.206462e-03,2.998946e-03,3.696213e-03,
9.685537e-04,4.331039e-03,5.897057e-03,5.878638e-03,
6.893982e-04,1.962699e-03,3.747073e-03,7.487394e-03,
8.870731e-04,2.101035e-03,3.135203e-03,6.760196e-03,
5.356187e-04,3.045464e-03,4.243832e-03,7.393902e-03,
4.735030e-04,3.782563e-03,5.084168e-03,8.110790e-03,
4.972539e-04,2.788993e-03,4.618498e-03,9.353449e-03,
4.242995e-04,2.676837e-03,4.541172e-03,9.767407e-03,
1.414044e-03,2.517535e-03,5.249992e-03,1.032522e-02,
3.300342e-04,2.519584e-03,5.119844e-03,1.234227e-02,
1.866221e-04,2.662918e-03,5.306701e-03,1.307199e-02,

},
{
9.455019e-07,5.151808e-05,1.117829e-04,2.882281e-04,
2.232505e-06,8.029951e-05,1.717731e-04,4.469390e-04,
6.836223e-06,1.151794e-04,2.290949e-04,5.949837e-04,
3.313334e-05,1.483363e-04,2.945120e-04,7.503477e-04,
6.736667e-05,1.679304e-04,3.335481e-04,8.395954e-04,
1.247014e-04,1.948988e-04,3.878231e-04,8.990899e-04,
3.621839e-04,2.331503e-04,4.297748e-04,1.051289e-03,
7.180272e-04,3.186369e-04,5.078613e-04,1.216990e-03,
2.311555e-04,5.492023e-04,7.524818e-04,1.556575e-03,
2.196609e-04,5.836734e-04,9.220928e-04,1.920263e-03,
2.767304e-04,7.972837e-04,1.015380e-03,2.198472e-03,
1.887811e-04,1.148456e-03,1.511265e-03,2.545408e-03,
2.277470e-04,1.842968e-03,1.907678e-03,2.872014e-03,
3.411340e-04,1.315514e-03,1.897493e-03,3.416546e-03,
3.504029e-04,1.486829e-03,2.012915e-03,3.675149e-03,
2.503435e-03,1.097400e-03,2.109200e-03,3.984398e-03,
6.246600e-04,1.042920e-03,2.058100e-03,4.734800e-03,
2.920890e-04,1.122820e-03,2.193400e-03,5.149200e-03,

},
{
1.003708e-06,5.549328e-05,1.204001e-04,3.104456e-04,
2.090670e-06,8.651391e-05,1.850165e-04,4.813928e-04,
3.027505e-06,1.240917e-04,2.468060e-04,6.408511e-04,
3.979750e-06,1.594153e-04,3.171329e-04,8.081894e-04,
4.539297e-06,1.793837e-04,3.587247e-04,9.043193e-04,
5.069056e-06,2.064813e-04,4.146332e-04,9.684054e-04,
7.413180e-06,2.262163e-04,4.552052e-04,1.132337e-03,
1.456918e-05,2.615355e-04,5.236178e-04,1.308336e-03,
1.150049e-05,3.277709e-04,6.597087e-04,1.651721e-03,
1.354274e-05,3.924938e-04,7.852946e-04,1.983755e-03,
1.726750e-05,4.656181e-04,9.124538e-04,2.287597e-03,
1.690565e-05,5.476943e-04,1.065059e-03,2.604582e-03,
1.957340e-05,6.417297e-04,1.222199e-03,2.943220e-03,
2.466138e-05,6.879804e-04,1.350983e-03,3.299326e-03,
2.855312e-05,7.600837e-04,1.487615e-03,3.634983e-03,
1.379400e-04,9.100400e-04,1.834180e-03,3.968367e-03,
7.630900e-05,9.734000e-04,1.966520e-03,4.892300e-03,
4.450300e-05,1.039640e-03,2.101830e-03,5.266300e-03,

},
{
1.778093e-06,9.938364e-05,2.156261e-04,5.559812e-04,
3.689621e-06,1.549358e-04,3.313467e-04,8.621287e-04,
5.302608e-06,2.222145e-04,4.420010e-04,1.147705e-03,
6.825926e-06,2.854161e-04,5.678945e-04,1.447389e-03,
7.663427e-06,3.210919e-04,6.423236e-04,1.619551e-03,
8.258400e-06,3.695058e-04,7.422465e-04,1.734322e-03,
9.513126e-06,4.039695e-04,8.146398e-04,2.027870e-03,
1.076578e-05,4.652282e-04,9.363337e-04,2.342809e-03,
1.365988e-05,5.732944e-04,1.173206e-03,2.956308e-03,
1.657160e-05,6.786403e-04,1.387979e-03,3.546689e-03,
1.955280e-05,7.936696e-04,1.606529e-03,4.088933e-03,
2.264573e-05,9.098115e-04,1.837633e-03,4.647151e-03,
2.560047e-05,1.020177e-03,2.071569e-03,5.248905e-03,
2.846764e-05,1.148467e-03,2.319909e-03,5.850658e-03,
3.131396e-05,1.263550e-03,2.554443e-03,6.452388e-03,
3.726125e-05,1.565131e-03,3.160576e-03,7.047671e-03,
4.105254e-05,1.694741e-03,3.425661e-03,8.622082e-03,
4.456126e-05,1.811054e-03,3.679863e-03,9.274617e-03,
}
};

/* Supernova II yields are from Kobayashi 2006. There is a mass gap from 8 - 13 Msun, between AGB and SNII,
 * for which we extrapolate Kobayashi 2006 yields to lower masses.*/
#define SNII_NMET 4
#define SNII_NMASS 7
static const double snii_masses[SNII_NMASS] = { 13.00,15.00,18.00,20.00,25.00,30.00,40.00 };
static const double snii_metallicities[SNII_NMET] = { 0.0000,0.0010,0.0040,0.0200 };
static const double snii_total_mass[SNII_NMET*SNII_NMASS] = {
11.430,11.280,11.250,11.130,
13.520,13.390,12.890,12.640,
16.350,16.140,14.980,15.180,
18.340,17.870,17.760,16.810,
23.080,22.510,22.350,19.940,
27.930,26.990,25.000,22.480,
37.110,34.640,30.120,19.620,

};

static const double snii_total_metals[SNII_NMET*SNII_NMASS] = {
8.208e-01,9.820e-01,8.451e-01,6.734e-01,
1.539e+00,7.860e-01,8.312e-01,6.045e-01,
2.501e+00,1.135e+00,1.451e+00,1.539e+00,
3.634e+00,3.489e+00,1.778e+00,2.110e+00,
4.411e+00,5.733e+00,3.703e+00,4.296e+00,
6.712e+00,7.570e+00,6.944e+00,5.378e+00,
1.120e+01,1.088e+01,1.171e+01,1.136e+01,

};

static const double snii_yield[NSPECIES][SNII_NMET*SNII_NMASS] = {
{6.600000e+00,6.440000e+00,6.370000e+00,6.160000e+00,
7.580000e+00,7.450000e+00,7.110000e+00,6.790000e+00,
8.430000e+00,8.460000e+00,7.470000e+00,7.530000e+00,
8.770000e+00,8.430000e+00,8.950000e+00,7.930000e+00,
1.060000e+01,9.800000e+00,1.020000e+01,8.410000e+00,
1.170000e+01,1.110000e+01,1.010000e+01,8.750000e+00,
1.400000e+01,1.290000e+01,1.030000e+01,3.550000e+00,

},
{
4.010041e+00,3.860143e+00,4.040170e+00,4.300196e+00,
4.400041e+00,5.160153e+00,4.950159e+00,5.250218e+00,
5.420033e+00,6.540157e+00,6.060224e+00,6.110230e+00,
5.940048e+00,5.940160e+00,7.030175e+00,6.760238e+00,
8.030211e+00,6.970126e+00,8.480185e+00,7.240221e+00,
9.520206e+00,8.380144e+00,7.920184e+00,8.360212e+00,
1.190003e+01,1.090012e+01,8.120180e+00,4.710051e+00,

},
{
7.410008e-02,1.071670e-01,8.798800e-02,1.080000e-01,
1.720001e-01,8.505380e-02,8.830900e-02,6.625000e-02,
2.190000e-01,1.300720e-01,1.653000e-01,1.373800e-01,
2.110000e-01,1.280196e-01,9.769200e-02,2.464500e-01,
2.940000e-01,2.150981e-01,1.323830e-01,2.186000e-01,
3.380000e-01,1.210820e-01,1.823390e-01,2.519200e-01,
4.290000e-01,7.398200e-02,4.583680e-01,5.964310e-01,

},
{
1.830064e-03,9.077570e-03,9.086840e-03,4.804090e-02,
1.860069e-03,3.580859e-03,1.290870e-02,6.155970e-02,
1.890240e-04,4.470921e-03,1.262000e-01,6.611530e-02,
5.421130e-05,1.290137e-02,1.842780e-02,7.212400e-02,
5.911180e-04,9.207240e-03,3.159530e-02,1.306000e-01,
1.656800e-06,6.190379e-03,2.010498e-02,1.020066e-01,
1.218000e-06,8.692450e-03,2.600501e-02,5.810572e-02,

},
{
4.500017e-01,5.058796e-01,3.870375e-01,2.223680e-01,
7.730065e-01,2.943916e-01,2.930546e-01,1.653520e-01,
1.380005e+00,4.223302e-01,5.741100e-01,7.825760e-01,
2.110000e+00,2.180030e+00,9.953840e-01,1.056171e+00,
2.790002e+00,3.820098e+00,2.200960e+00,2.435640e+00,
4.810000e+00,5.330076e+00,4.790164e+00,3.227870e+00,
8.380000e+00,8.370055e+00,7.960996e+00,7.343272e+00,

},
{
1.530074e-02,6.751500e-02,1.332350e-01,3.944500e-02,
3.270537e-01,1.903415e-01,1.258970e-01,3.575000e-02,
4.941169e-01,1.775626e-01,2.051700e-01,1.558320e-01,
9.121122e-01,6.283170e-01,2.794180e-01,4.048500e-01,
5.330335e-01,1.221979e+00,8.249530e-01,8.713900e-01,
8.511408e-01,1.452171e+00,9.439010e-01,9.585700e-01,
3.070175e-01,2.879870e-01,1.884040e+00,2.225870e+00,

},
{
8.642770e-02,6.583400e-02,4.642000e-02,2.994000e-02,
6.889700e-02,6.572000e-02,7.848000e-02,4.110000e-02,
1.584600e-01,6.117300e-02,8.396000e-02,1.159800e-01,
1.503540e-01,2.468400e-01,1.005800e-01,9.487000e-02,
1.200906e-01,1.827300e-01,2.457500e-01,2.766000e-01,
2.273760e-01,2.938200e-01,2.321700e-01,2.472000e-01,
4.785540e-01,7.073200e-01,4.043000e-01,4.562000e-01,

},
{
8.257000e-02,9.317000e-02,6.229700e-02,7.784000e-02,
7.358800e-02,4.370700e-02,1.054100e-01,8.875000e-02,
1.167870e-01,1.541350e-01,1.006900e-01,1.147800e-01,
9.969200e-02,1.298860e-01,1.268800e-01,6.768000e-02,
3.513464e-01,1.207150e-01,1.225100e-01,1.412500e-01,
2.488430e-01,1.667390e-01,4.031900e-01,2.579800e-01,
1.036660e+00,8.971400e-01,5.340500e-01,2.607500e-01,

},
{
7.172600e-02,7.559680e-02,7.493770e-02,8.746100e-02,
7.238000e-02,7.327010e-02,7.540890e-02,8.976000e-02,
7.227800e-02,7.444550e-02,9.409600e-02,9.294600e-02,
7.228700e-02,7.404090e-02,7.768170e-02,9.375600e-02,
7.377700e-02,7.395780e-02,7.734500e-02,9.664700e-02,
7.457300e-02,7.518580e-02,8.269400e-02,1.038800e-01,
8.000101e-02,8.257700e-02,8.525500e-02,8.967500e-02,
}
};

/* These definitions are here for the tests*/
#define GSL_WORKSPACE 1000

double compute_imf_norm(gsl_integration_workspace * gsl_work);
double compute_agb_yield(gsl_interp2d * agb_interp, const double * agb_weights, double stellarmetal, double masslow, double masshigh, gsl_integration_workspace * gsl_work );
double compute_snii_yield(gsl_interp2d * snii_interp, const double * snii_weights, double stellarmetal, double masslow, double masshigh, gsl_integration_workspace * gsl_work );

double chabrier_mass(double mass, void * params);

double sn1a_number(double dtmyrstart, double dtmyrend, double hub);

void set_metal_params(double Sn1aN0);

void find_mass_bin_limits(double * masslow, double * masshigh, const double dtstart, const double dtend, double stellarmetal, gsl_interp2d * lifetime_tables);

#endif