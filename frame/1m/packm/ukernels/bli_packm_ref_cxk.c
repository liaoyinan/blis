/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas at Austin nor the names
      of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "blis.h"

#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_2xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC2(ch,ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC2(ch,ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC2(ch,ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC2(ch,ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC2(ch,ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC2(ch,ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC2(ch,ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC2(ch,ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC3(ch,ch,ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC3(ch,ch,ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC3(ch,ch,ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC3(ch,ch,ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC3(ch,ch,ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC3(ch,ch,ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC3(ch,ch,ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC3(ch,ch,ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_4xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_6xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_8xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_10xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +11*inca), *(pi1 +11) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,copys)( *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,copys)( *(alpha1 +11*inca), *(pi1 +11) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +11*inca), *(pi1 +11) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +11*inca), *(pi1 +11) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_12xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +13*inca), *(pi1 +13) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,copys)( *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,copys)( *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,copys)( *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,copys)( *(alpha1 +13*inca), *(pi1 +13) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +13*inca), *(pi1 +13) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +13*inca), *(pi1 +13) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_14xk )



#undef  GENTFUNC
#define GENTFUNC( ctype, ch, varname ) \
\
void PASTEMAC(ch,varname)( \
                           conj_t  conja, \
                           dim_t   n, \
                           void*   kappa, \
                           void*   a, inc_t inca, inc_t lda, \
                           void*   p,             inc_t ldp  \
                         ) \
{ \
	ctype* restrict kappa_cast = kappa; \
	ctype* restrict alpha1     = a; \
	ctype* restrict pi1        = p; \
\
	if ( PASTEMAC(ch,eq1)( *kappa_cast ) ) \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copyjs)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +13*inca), *(pi1 +13) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +14*inca), *(pi1 +14) ); \
				PASTEMAC(ch,copyjs)( *(alpha1 +15*inca), *(pi1 +15) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,copys)( *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,copys)( *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,copys)( *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,copys)( *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,copys)( *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,copys)( *(alpha1 +13*inca), *(pi1 +13) ); \
				PASTEMAC(ch,copys)( *(alpha1 +14*inca), *(pi1 +14) ); \
				PASTEMAC(ch,copys)( *(alpha1 +15*inca), *(pi1 +15) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
	else \
	{ \
		if ( bli_is_conj( conja ) ) \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +13*inca), *(pi1 +13) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +14*inca), *(pi1 +14) ); \
				PASTEMAC(ch,scal2js)( *kappa_cast, *(alpha1 +15*inca), *(pi1 +15) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
		else \
		{ \
			for ( ; n != 0; --n ) \
			{ \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 0*inca), *(pi1 + 0) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 1*inca), *(pi1 + 1) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 2*inca), *(pi1 + 2) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 3*inca), *(pi1 + 3) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 4*inca), *(pi1 + 4) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 5*inca), *(pi1 + 5) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 6*inca), *(pi1 + 6) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 7*inca), *(pi1 + 7) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 8*inca), *(pi1 + 8) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 + 9*inca), *(pi1 + 9) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +10*inca), *(pi1 +10) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +11*inca), *(pi1 +11) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +12*inca), *(pi1 +12) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +13*inca), *(pi1 +13) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +14*inca), *(pi1 +14) ); \
				PASTEMAC(ch,scal2s)( *kappa_cast, *(alpha1 +15*inca), *(pi1 +15) ); \
\
				alpha1 += lda; \
				pi1    += ldp; \
			} \
		} \
	} \
}

INSERT_GENTFUNC_BASIC0( packm_ref_16xk )

