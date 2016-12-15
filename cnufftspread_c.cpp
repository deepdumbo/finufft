/******************************************************
** See the accompanying README and LICENSE files
** Author(s): Jeremy Magland
** Created: 4/1/2016
*******************************************************/

#include "cnufftspread_c.h"
#include "cnufftspread.h"
#include <stdio.h>

void cnufftspread_f_(int *N1,int *N2,int *N3,double *d_uniform,int *M,double *kx,double *ky,double *kz,double *d_nonuniform,int *spread_direction,double *kernel_params) {

    if (kernel_params[0]!=1) {
        printf("Error: Unexpected kernel type.\n");
        return;
    }

    cnufftspread_opts opts;
    set_kb_opts_from_kernel_params(opts,kernel_params);

    opts.spread_direction=*spread_direction;

    cnufftspread(*N1,*N2,*N3,d_uniform,*M,kx,ky,kz,d_nonuniform,opts);
}
