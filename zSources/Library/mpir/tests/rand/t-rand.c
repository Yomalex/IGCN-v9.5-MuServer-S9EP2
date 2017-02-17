//////////////////////////////////////////////////////////////////////
// t-rand.c
/* t-rand -- Test random number generators.  */

/*
Copyright 2000, 2001 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

#include <stdlib.h>
#include <stdio.h>
#include "mpir.h"
#include "tests.h"

#define SEED 1
#define BASE 16
#define ENTS 10			/* Number of entries in array when
                                   printing.  */

/* These were generated by this very program.  Do not edit!  */
/* Integers.  */
char *z1[ENTS] = {"0", "1", "1", "1", "1", "0", "1", "1", "1", "1"};
char *z2[ENTS] = {"0", "3", "1", "3", "3", "0", "3", "3", "3", "1"};
char *z3[ENTS] = {"4", "3", "1", "7", "3", "0", "3", "3", "3", "1"};
char *z4[ENTS] = {"c", "3", "1", "f", "b", "8", "3", "3", "3", "1"};
char *z5[ENTS] = {"1c", "13", "11", "1f", "b", "18", "3", "13", "3", "1"};

char *z10[ENTS] = {"29c", "213", "f1", "17f", "12b", "178", "383", "d3", "3a3", "281"};

char *z15[ENTS] = {"29c", "1a13", "74f1", "257f", "592b", "4978", "4783", "7cd3", "5ba3", "4681"};
char *z16[ENTS] = {"29c", "9a13", "74f1", "a57f", "d92b", "4978", "c783", "fcd3", "5ba3", "c681"};
char *z17[ENTS] = {"51e", "f17a", "54ff", "1a335", "cf65", "5d6f", "583f", "618f", "1bc6", "98ff"};

char *z31[ENTS] = {"3aecd515", "13ae8ec6", "518c8090", "81ca077", "70b7134", "7ee78d71", "323a7636", "2122cb1a", "19811941", "41fd605"};
char *z32[ENTS] = {"baecd515", "13ae8ec6", "518c8090", "881ca077", "870b7134", "7ee78d71", "323a7636", "a122cb1a", "99811941", "841fd605"};
char *z33[ENTS] = {"1faf4cca", "15d6ef83b", "9095fe72", "1b6a3dff6", "b17cbddd", "16e5209d4", "6f65b12c", "493bbbc6", "abf2a5d5", "6d491a3c"};

char *z63[ENTS] = {"48a74f367fa7b5c8", "3ba9e9dc1b263076", "1e0ac84e7678e0fb", "11416581728b3e35", "36ab610523f0f1f7", "3e540e8e95c0eb4b", "439ae16057dbc9d3", "734fb260db243950", "7d3a317effc289bf", "1d80301fb3d1a0d1"};
char *z64[ENTS] = {"48a74f367fa7b5c8", "bba9e9dc1b263076", "9e0ac84e7678e0fb", "11416581728b3e35", "b6ab610523f0f1f7", "be540e8e95c0eb4b", "439ae16057dbc9d3", "f34fb260db243950", "fd3a317effc289bf", "1d80301fb3d1a0d1"};
char *z65[ENTS] = {"1ff77710d846d49f0", "1b1411701d709ee10", "31ffa81a208b6af4", "446638d431d3c681", "df5c569d5baa8b55", "197d99ea9bf28e5a0", "191ade09edd94cfae", "194acefa6dde5e18d", "1afc1167c56272d92", "d092994da72f206f"};

char *z127[ENTS] = {"2f66ba932aaf58a071fd8f0742a99a0c", "73cfa3c664c9c1753507ca60ec6b8425", "53ea074ca131dec12cd68b8aa8e20278", "3cf5ac8c343532f8a53cc0eb47581f73", "50c11d5869e208aa1b9aa317b8c2d0a9", "b23163c892876472b1ef19642eace09", "489f4c03d41f87509c8d6c90ce674f95", "2ab8748c96aa6762ea1932b44c9d7164", "98cb5591fc05ad31afbbc1d67b90edd", "77848bb991fd0be331adcf1457fbc672"};
char *z128[ENTS] = {"af66ba932aaf58a071fd8f0742a99a0c", "73cfa3c664c9c1753507ca60ec6b8425", "53ea074ca131dec12cd68b8aa8e20278", "3cf5ac8c343532f8a53cc0eb47581f73", "50c11d5869e208aa1b9aa317b8c2d0a9", "8b23163c892876472b1ef19642eace09", "489f4c03d41f87509c8d6c90ce674f95", "aab8748c96aa6762ea1932b44c9d7164", "98cb5591fc05ad31afbbc1d67b90edd", "f7848bb991fd0be331adcf1457fbc672"};

/* Floats.  */
char *f1[ENTS] = {"0.@0", "0.8@0", "0.8@0", "0.8@0", "0.8@0", "0.@0", "0.8@0", "0.8@0", "0.8@0", "0.8@0"};
char *f2[ENTS] = {"0.@0", "0.c@0", "0.4@0", "0.c@0", "0.c@0", "0.@0", "0.c@0", "0.c@0", "0.c@0", "0.4@0"};
char *f3[ENTS] = {"0.8@0", "0.6@0", "0.2@0", "0.e@0", "0.6@0", "0.@0", "0.6@0", "0.6@0", "0.6@0", "0.2@0"};
char *f4[ENTS] = {"0.c@0", "0.3@0", "0.1@0", "0.f@0", "0.b@0", "0.8@0", "0.3@0", "0.3@0", "0.3@0", "0.1@0"};
char *f5[ENTS] = {"0.e@0", "0.98@0", "0.88@0", "0.f8@0", "0.58@0", "0.c@0", "0.18@0", "0.98@0", "0.18@0", "0.8@-1"};

char *f10[ENTS] = {"0.a7@0", "0.84c@0", "0.3c4@0", "0.5fc@0", "0.4ac@0", "0.5e@0", "0.e0c@0", "0.34c@0", "0.e8c@0", "0.a04@0"};

char *f15[ENTS] = {"0.538@-1", "0.3426@0", "0.e9e2@0", "0.4afe@0", "0.b256@0", "0.92f@0", "0.8f06@0", "0.f9a6@0", "0.b746@0", "0.8d02@0"};
char *f16[ENTS] = {"0.29c@-1", "0.9a13@0", "0.74f1@0", "0.a57f@0", "0.d92b@0", "0.4978@0", "0.c783@0", "0.fcd3@0", "0.5ba3@0", "0.c681@0"};
char *f17[ENTS] = {"0.28f@-1", "0.78bd@0", "0.2a7f8@0", "0.d19a8@0", "0.67b28@0", "0.2eb78@0", "0.2c1f8@0", "0.30c78@0", "0.de3@-1", "0.4c7f8@0"};

char *f31[ENTS] = {"0.75d9aa2a@0", "0.275d1d8c@0", "0.a319012@0", "0.103940ee@0", "0.e16e268@-1", "0.fdcf1ae2@0", "0.6474ec6c@0", "0.42459634@0", "0.33023282@0", "0.83fac0a@-1"};
char *f32[ENTS] = {"0.baecd515@0", "0.13ae8ec6@0", "0.518c809@0", "0.881ca077@0", "0.870b7134@0", "0.7ee78d71@0", "0.323a7636@0", "0.a122cb1a@0", "0.99811941@0", "0.841fd605@0"};
char *f33[ENTS] = {"0.fd7a665@-1", "0.aeb77c1d8@0", "0.484aff39@0", "0.db51effb@0", "0.58be5eee8@0", "0.b72904ea@0", "0.37b2d896@0", "0.249ddde3@0", "0.55f952ea8@0", "0.36a48d1e@0"};

char *f63[ENTS] = {"0.914e9e6cff4f6b9@0", "0.7753d3b8364c60ec@0", "0.3c15909cecf1c1f6@0", "0.2282cb02e5167c6a@0", "0.6d56c20a47e1e3ee@0", "0.7ca81d1d2b81d696@0", "0.8735c2c0afb793a6@0", "0.e69f64c1b64872a@0", "0.fa7462fdff85137e@0", "0.3b00603f67a341a2@0"};
char *f64[ENTS] = {"0.48a74f367fa7b5c8@0", "0.bba9e9dc1b263076@0", "0.9e0ac84e7678e0fb@0", "0.11416581728b3e35@0", "0.b6ab610523f0f1f7@0", "0.be540e8e95c0eb4b@0", "0.439ae16057dbc9d3@0", "0.f34fb260db24395@0", "0.fd3a317effc289bf@0", "0.1d80301fb3d1a0d1@0"};
char *f65[ENTS] = {"0.ffbbb886c236a4f8@0", "0.d8a08b80eb84f708@0", "0.18ffd40d1045b57a@0", "0.22331c6a18e9e3408@0", "0.6fae2b4eadd545aa8@0", "0.cbeccf54df9472d@0", "0.c8d6f04f6eca67d7@0", "0.ca5677d36ef2f0c68@0", "0.d7e08b3e2b1396c9@0", "0.68494ca6d39790378@0"};

char *f127[ENTS] = {"0.5ecd7526555eb140e3fb1e0e85533418@0", "0.e79f478cc99382ea6a0f94c1d8d7084a@0", "0.a7d40e994263bd8259ad171551c404f@0", "0.79eb5918686a65f14a7981d68eb03ee6@0", "0.a1823ab0d3c411543735462f7185a152@0", "0.16462c791250ec8e563de32c85d59c12@0", "0.913e9807a83f0ea1391ad9219cce9f2a@0", "0.5570e9192d54cec5d4326568993ae2c8@0", "0.13196ab23f80b5a635f7783acf721dba@0", "0.ef09177323fa17c6635b9e28aff78ce4@0"};
char *f128[ENTS] = {"0.af66ba932aaf58a071fd8f0742a99a0c@0", "0.73cfa3c664c9c1753507ca60ec6b8425@0", "0.53ea074ca131dec12cd68b8aa8e20278@0", "0.3cf5ac8c343532f8a53cc0eb47581f73@0", "0.50c11d5869e208aa1b9aa317b8c2d0a9@0", "0.8b23163c892876472b1ef19642eace09@0", "0.489f4c03d41f87509c8d6c90ce674f95@0", "0.aab8748c96aa6762ea1932b44c9d7164@0", "0.98cb5591fc05ad31afbbc1d67b90edd@-1", "0.f7848bb991fd0be331adcf1457fbc672@0"};


struct rt
{
  char **s;
  int nbits;
};

static struct rt zarr[] =
{
  {z1, 1},
  {z2, 2},
  {z3, 3},
  {z4, 4},
  {z5, 5},
  {z10, 10},
  {z15, 15},
  {z16, 16},
  {z17, 17},
  {z31, 31},
  {z32, 32},
  {z33, 33},
  {z63, 63},
  {z64, 64},
  {z65, 65},
  {z127, 127},
  {z128, 128},
  {NULL, 0}
};

static struct rt farr[] =
{
  {f1, 1},
  {f2, 2},
  {f3, 3},
  {f4, 4},
  {f5, 5},
  {f10, 10},
  {f15, 15},
  {f16, 16},
  {f17, 17},
  {f31, 31},
  {f32, 32},
  {f33, 33},
  {f63, 63},
  {f64, 64},
  {f65, 65},
  {f127, 127},
  {f128, 128},
  {NULL, 0}
};
  

int 
#if __STDC__
main (int argc, char *argv[])
#else
main (argc, argv)
     int argc;
     char *argv[];
#endif
{
  static char usage[] = "\
usage: t-rand [function nbits]\n\
  function is one of z, f\n\
  nbits is number of bits\n\
";
  gmp_randstate_t rstate;
  mpz_t z, rz;
  mpf_t f, rf;
  enum { Z, F } func = Z;
  int nbits = 1;
  int verify_mode_flag = 1;
  register int i;
  struct rt *a;

  tests_start();

  if (argc > 1)
    {
      if (argc < 3)
	{
	  fputs (usage, stderr);
	  exit (1);
	}
      verify_mode_flag = 0;
      if (*argv[1] == 'z')
	func = Z;
      if (*argv[1] == 'f')
	func = F;
      nbits = atoi (argv[2]);
    }

  mpz_init (rz);
  
  if (verify_mode_flag)
    {
#ifdef VERBOSE
      printf ("%s: verifying random numbers: ", argv[0]);
#endif

      /* Test z.  */
      mpz_init (z);
      for (a = zarr; a->s != NULL; a++)
	{
	  gmp_randinit_lc_2exp_size (rstate, a->nbits);
	  gmp_randseed_ui (rstate, SEED);

	  for (i = 0; i < ENTS; i++)
	    {
	      mpz_urandomb (rz, rstate, a->nbits);
	      mpz_set_str (z, a->s[i], BASE);
	      if (mpz_cmp (z, rz) != 0)
		{
		  printf ("z%d: ", a->nbits); 
		  mpz_out_str (stdout, BASE, rz);
		  printf (" should be ");
		  mpz_out_str (stdout, BASE, z);
		  puts ("");
		  exit (1);
		}
	    }
#ifdef VERBOSE
	  printf ("z%d ", a->nbits);
#endif
	  gmp_randclear (rstate);
	}
      mpz_clear (z);


      /* Test f.  */
      for (a = farr; a->s != NULL; a++)
	{
	  gmp_randinit_lc_2exp_size (rstate, a->nbits);
	  gmp_randseed_ui (rstate, SEED);

	  mpf_init2 (f, a->nbits);
	  mpf_init2 (rf, a->nbits);
	  for (i = 0; i < ENTS; i++)
	    {
	      mpf_urandomb (rf, rstate, a->nbits);
	      mpf_set_str (f, a->s[i], BASE);
	      if (mpf_cmp (f, rf) != 0)
		{
		  printf ("f%d: ", a->nbits); 
		  mpf_out_str (stdout, BASE, a->nbits, rf);
		  printf (" should be ");
		  mpf_out_str (stdout, BASE, a->nbits, f);
		  puts ("");
		  exit (1);
		}
	    }
#ifdef VERBOSE
	  printf ("f%d ", a->nbits);
#endif
	  gmp_randclear (rstate);
	  mpf_clear (f);
	  mpf_clear (rf);
	}

#ifdef VERBOSE
      puts ("");
#endif
    }
  else				/* Print mode.  */
    {
      gmp_randinit_lc_2exp_size (rstate, nbits);
      gmp_randseed_ui (rstate, SEED);

      switch (func)
	{
	case Z:
	  printf ("char *z%d[ENTS] = {", nbits);
	  for (i = 0; i < ENTS; i++)
	    {
	      mpz_urandomb (rz, rstate, nbits);
	      printf ("\"");
	      mpz_out_str (stdout, BASE, rz);
	      printf ("\"");
	      if (i != ENTS - 1)
		printf (", ");
	    }
	  printf ("};\n");
	  printf ("  {z%d, %d},\n", nbits, nbits);
	  break;

	case F:
	  printf ("char *f%d[ENTS] = {", nbits);
	  mpf_init2 (rf, nbits);
	  for (i = 0; i < ENTS; i++)
	    {
	      mpf_urandomb (rf, rstate, nbits);
	      printf ("\"");
	      mpf_out_str (stdout, BASE, nbits, rf);
	      printf ("\"");
	      if (i != ENTS - 1)
		printf (", ");
	    }
	  printf ("};\n");
	  printf ("  {f%d, %d},\n", nbits, nbits);
	  mpf_clear (rf);
	  break;

	default:
	  exit (1);
	}

      gmp_randclear (rstate);
    }
  
  mpz_clear (rz);
  tests_end();
  return 0;
}


//////////////////////////////////////////////////////////////////////
// iDev.Games - MuOnline S9EP2 IGC9.5 - TRONG.WIN - DAO VAN TRONG     
//////////////////////////////////////////////////////////////////////

