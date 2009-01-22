/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2008 - INRIA - Arnaud TORSET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */


#include <stdio.h>
#include <assert.h>
#include "levin.h"



static void dlevinaTest(void) {
	int n=15;

/*	int i=0;

	double cov[128]={2.1632471,0.6253206,-0.2212568,-0.6154865,-0.2646837,0.0144518,-0.2511410,-0.5401314, \
-0.3017069,0.6439519,1.0938702,0.5916342,-0.2832519,-0.5799388,-0.2711958,0.0740953,\
-0.2646536,-0.6427527,-0.2888743,0.5798061,1.0301717,0.5939465,-0.1991420,-0.6068337,\
-0.2532973,-0.0156329,-0.2872505,-0.5836588,-0.2913317,0.5783603,1.0635956,0.5822280,\
-0.2711408,-0.6209564,-0.2485693,-0.0334097,-0.2733096,-0.5363602,-0.2689253,0.5987651,\
1.0441869,0.5835384,-0.2934934,-0.5838854,-0.2848314,-0.0111112,-0.2838466,-0.5757844, \
-0.2925714,0.5468999,1.0859833,0.6045700,-0.2491218,-0.6152090,-0.2322848,-0.0206893, \
-0.3015463,-0.5653637,-0.2812883,0.5947973,1.0040374,0.5830293,-0.2684794,-0.5986135, \
-0.2673449,-0.0504689,-0.2989750,-0.5510215,-0.2771791,0.5943756,0.9436008,0.5795994, \
-0.2586094,-0.5544826,-0.2474743,0.0262180,-0.2474046,-0.5373957,-0.2932611,0.5803651,\
0.9859401,0.5729370,-0.2169815,-0.5399512,-0.2332551,-0.0151484,-0.274592,-0.5905861, \
-0.2844705,0.5987613,0.9710525,0.5330744,-0.2443102,-0.5858032,-0.2166843,-0.0028519, \
-0.2613759,-0.5451755,-0.2489879,0.4847080,0.9502086,0.5870537,-0.2648506,-0.5585377, \
-0.2867994,0.0067153,-0.2101314,-0.5189354,-0.2473348,0.5727840,0.9393745,0.5947526, \
-0.2382349,-0.5675628,-0.2202667,-0.0863862,-0.2534431,-0.5561705,-0.2503315,0.5649435, \
0.9288405,0.5373113,-0.2468931,-0.5345938,-0.2767231,-0.0397433,-0.2345866,-0.4977333};*/

	double cov2[256]={1.8542341,0.2302480,0.5424259,0.2396233,-0.2802882,-0.1343754,-0.4585444,-0.0852306,\
 -0.3683334,0.0258069,-0.0655487,0.1546545,-0.3655665,-0.0310238,-0.4565569,0.0441730,\
 -0.1386023,-0.0434076,0.5189599,0.0357233,1.0210283,0.1781705,0.5183526,0.0801215,\
 -0.1862581,-0.1739927,-0.4755297,-0.1160617,-0.2512805,0.1471775,-0.0995046,0.1707012,\
 -0.3269761,-0.0112160,-0.4411032,-0.0872514,-0.1757269,-0.1472844,0.5471859,-0.0644483,\
 0.8977092,0.2136813,0.3942809,-0.0382849,-0.1260751,-0.0965459,-0.5126250,-0.1452914,\
 -0.3046589,-0.0022501,0.0350519,0.2645226,-0.2509645,-0.0365893,-0.5183898,-0.0318046,\
 -0.1743803,-0.0873962,0.5372009,-0.1704277,0.7164172,0.1710189,0.4685590,-0.0759859,\
 -0.1911539,-0.0679539,-0.4706253,-0.0519689,-0.2791620,-0.0583353,-0.0267250,0.1014851,\
 -0.1576785,-0.1655821,-0.3847449,-0.0386553,-0.1297910,0.0083667,0.4836641,-0.0939749,\
 0.7437560,0.2901242,0.3853338,0.0798201,-0.1689064,-0.1747635,-0.5110532,-0.1476417,\
 -0.1808702,0.0963522,0.0174652,0.2306552,-0.2592396,-0.1491170,-0.3227275,0.0629281,\
 -0.1185767,-0.0827683,0.4598633,0.0349602,0.6505747,0.3114497,0.2631378,-0.0103355,\
 -0.3194549,-0.2351815,-0.4274886,-0.1750659,-0.0813017,0.1245920,-0.0664094,0.1473835,\
 -0.2078978,-0.1688748,-0.3425365,0.1354790,-0.1685176,-0.1444135,0.3966746,-0.177444,\
 0.5809542,0.2654948,0.3486682,0.0369250,-0.1920808,-0.1351589,-0.4381282,-0.1431602,\
0.2302480,2.020749,-0.1453147,-0.4816412,-0.1059289,-0.3953205,0.0167060,0.5071499,\
 -0.0438978,-0.2461159,0.1641866,-0.0420505,-0.0166320,-0.1641097,-0.2515164,0.5068871,\
 -0.2113012,-0.3582454,0.1358039,-0.5180938,0.3298329,1.0316539,-0.1190920,-0.4336184,\
 -0.0743425,-0.1711531,0.0595813,0.5856594,0.0258974,-0.2492872,0.1667785,-0.1520977,\
 -0.0087917,-0.1656533,0.0463118,0.4459719,-0.1475134,-0.2804235,-0.2214265,-0.3674264,\
 0.2137918,0.7380489,0.0643087,-0.4993311,0.0903295,-0.2392031,-0.0495192,0.4715900,\
 0.0560724,-0.0850974,0.1811686,0.0572052,-0.0733149,-0.3059423,-0.1168040,0.4098819,\
 -0.1070201,-0.4125769,-0.0502986,-0.4541070,0.1923829,0.9167427,-0.0450642,-0.3861262,\
 -0.0551742,-0.2979827,-0.0868854,0.4011319,0.1660530,-0.1986059,0.2734969,-0.0263159,\
 0.0112668,-0.0763537,-0.1452256,0.5250867,-0.1852298,-0.3335027,-0.1114010,-0.4129438,\
 0.1639697,0.7177437,-0.1688863,-0.4391817,-0.0468476,-0.2069082,-0.0635808,0.4981539,\
 -0.0965365,-0.2057104,0.2059908,-0.2499686,-0.0270036,-0.0794378,-0.0264147,0.3461999,\
 -0.0746288,-0.3044705,-0.1251745,-0.2032644,0.0744516,0.7004425,-0.1367678,-0.5699592,\
 -0.0909027,-0.3123118,0.0731459,0.3900814,-0.0056685,-0.0145168,0.1415849,-0.0899785,\
 -0.0770252,-0.1568634,0.0146449,0.2642178,-0.0843896,-0.2369412,0.0091955,-0.2899846,\
 0.0811130,0.6213581,-0.2800630,-0.3767941,-0.0630885,-0.155981,0.0395355,0.3978243};

	double la[15*16*2*2],lb[15*16*2*2],sig[15*2*2];

	dlevina(n,cov2,128,2,la,sig,lb);

/*
	for (i=0;i<15*16*2*2;i++){	
			printf("indice : %d valeur : %f - ",i,la[i]);		
			printf("\n");
			if((i+1)%64==0)printf("------------------------------------\n");
			if((i+1)%16==0)printf("###############\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
	for (i=0;i<15;i++){
		printf("i : %d - lb = ",i);
			for (j=0;j<15;j++) printf(" %f - ",lb[15*i+j]);		
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");


	for (i=0;i<15*2;i++){
		printf("indice : %d   %f  |   indice : %d   %f\n",i,sig[i],i+30,sig[i+30]);	
	}
*/

}



static int levinTest(void) {
  printf("\n>>>> Levin Tests\n");
  dlevinaTest();
  return 0;
}

int main(void) {
  assert( levinTest()== 0);
  return 0;
}