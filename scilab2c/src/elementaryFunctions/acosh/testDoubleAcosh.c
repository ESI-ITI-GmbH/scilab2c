/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2006-2008 - INRIA - Bruno JOFRET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#include <math.h>
#include "isnan.h"
#include "testAcosh.h"


#define IN {38.746443623676896095276,39.8779044859111309052,99.6399083640426397324,\
93.207842670381069183350,6.8147667217999696731567,71.874653641134500503540,\
65.928971720859408378601,43.781969323754310607910,95.70061699487268924713,\
39.777786191552877426147,54.149620747193694114685,14.754852838814258575439,\
91.972588421776890754700,41.853474546223878860474,90.448315022513270378113,\
32.027477025985717773438,57.482325518503785133362,75.726259034126996994019,\
32.547289272770285606384,50.125551037490367889404,26.862081931903958320618,\
11.706684622913599014282,36.675705714151263237000,87.538864836096763610840,\
52.483216533437371253967,76.861125137656927108765,82.899243896827101707458,\
64.99033216387033462524,56.250627012923359870911,21.698794979602098464966,\
93.22312804870307445526,93.5097210109233856201,97.608120972290635108948,\
91.35094834491610527039,26.843591919168829917908,9.1870715841650962829590,\
17.129724519327282905579,73.117265943437814712524,86.922781122848391532898,\
1.4808017760515213012695,65.071928361430764198303,42.254429217427968978882,\
23.262092983350157737732,31.955500133335590362549,74.261871399357914924622,\
77.881882060319185256958,65.248953877016901969910,90.324406325817108154297,\
86.69646182097494602203,70.879780035465955734253,69.452034076675772666931,\
84.671579115092754364014,93.227435695007443428040,95.654127094894647598267,\
16.239900095388293266296,12.728751823306083679199,95.707353064790368080139,\
67.644099798053503036499,39.798104530200362205505,11.081875301897525787354,\
50.97153154201805591583,58.446559030562639236450,25.919713405892252922058,\
29.182348400354385375977,6.0309174004942178726196,90.43274922296404838562,\
61.944271018728613853455,25.037935934960842132568,83.850894169881939888000,\
82.732185069471597671509,73.220202280208468437195,29.458374157547950744629,\
29.091028729453682899475,70.458725746721029281616,30.465652560815215110779,\
75.730663724243640899658,73.18075490184128284454,69.053836632519960403442,\
62.402765033766627311707,41.599050164222717285156,28.105994546785950660706,\
5.6220385245978832244873,58.040395518764853477478,0.4246918484568595886230,\
68.2817161548882722855,89.133544359356164932251,92.980264825746417045593,\
28.40001545846462249756,9.885430941358208656311,41.369083430618047714233,\
64.121548598632216453552,64.692758955061435699463,47.02662643976509571075,\
60.481913108378648757935,67.138904659077525138855,71.394702047109603881836,\
54.127137595787644386292,39.052018057554960250854,1.1089378502219915390015,\
90.150084160268306732178,13.887455360963940620422,8.5074969567358493804932,\
34.66010238043963909149,42.338709905743598937988,80.213972786441445351,\
31.7881367169320583344,18.021041667088866233826,69.688742049038410186768,\
35.482168616726994514465,16.12617420032620429993,75.34236568026244640350,\
62.194181978702545166016,51.510728383436799049377,67.819245439022779464722,\
61.666865786537528038025,70.212037675082683563232,13.621602999046444892883,\
60.870522353798151016235,18.923167092725634574890,47.614179179072380065918,\
17.161004850640892982483,41.371036972850561141968,15.31781828962266445160,\
22.868881560862064361572,95.856341393664479255676,39.499193150550127029419,\
2.500818995758891106,44.927055388689041137695,91.384086245670914649963,\
11.012465786188840866089,74.87958460114896297455,0.7881646975874900817871,\
23.523587780073285102844,80.106287542730569839478,65.456348611041903495789,\
51.620832458138465881348,70.271815219894051551819,5.5151230655610561370850,\
62.56400248967111110687,84.313133545219898223877,17.294042231515049934387,\
41.730730701237916946411,81.875373004004359245300,25.327575206756591796875,\
86.085468018427491188049,17.212611716240644454956,78.060937067493796348572,\
13.735765032470226287842,0.2187759149819612503052,1.4656470157206058502197,\
30.469974083825945854187,80.307766422629356384277,99.052629480138421058655,\
82.85992136225104331970,87.21015579067170619965,29.531141556799411773682,\
58.27610609121620655060,29.06773509457707405090,2.0005736034363508224,\
71.4346818625926971436,26.664068037644028663635,51.992803346365690231323,\
48.17320345900952816010,0.0918259844183921813965,38.418471114709973335266,\
49.06664276495575904846,44.197808159515261650085,65.678765252232551574707,\
10.470610717311501502991,42.787145730108022689819,75.105277216061949729919,\
36.962236650288105010986,84.119305433705449104309,90.374342072755098342896,\
44.184404192492365837097,1.0920032858848571777344,20.380018139258027076721,\
85.418348293751478195190,39.327101549133658409119,97.573022358119487762451,\
8.4199145901948213577271,23.39450428262352943420,48.397052986547350883484,\
33.292300626635551452637,96.453859517350792884827,52.920697536319494247437,\
7.9968032892793416976929,75.475437380373477935791,4.476350219920277596,\
84.631874877959489822388,20.008285669609904289246,69.44785490632057189941,\
28.204387659206986427307,79.546741675585508346558,20.281786611303687095642,\
78.075716458261013031006,93.606285052374005317688,88.801648560911417007446,\
33.848348213359713554382,89.761531725525856018066}

#define RESULT {4.3500195892822599574856,4.378812333443298676627,5.2946847693089331698957,\
5.2279502699832844925254,2.6068118507181217147206,4.968022463585481496295,\
4.8816676362403299549442,4.4722388068202851840738,5.2543446283333992141706,\
4.3762977630646631155287,4.6848128785767624293612,3.3835688928264802122214,\
5.2146082054939908445590,4.4271792498758397726988,5.1978952030053422461719,\
4.159497560939560578674,4.7445490293632399669832,5.0202285648475850621253,\
4.1756051841813626168687,4.6075785448582253778227,3.9835162329116351465075,\
3.1514779837977200394050,4.2950758361772223281605,5.165197419194649697261,\
4.653549840642725143880,5.035105083560019956224,5.1107367420045859418565,\
4.8673265089936572636020,4.7228853485288873059744,3.7698725167565876326137,\
5.2281142583800894740875,5.2311839874435639430317,5.2740816359097371091025,\
5.2078258853539018957690,3.982827186610214287299,2.9079691610609703644741,\
3.5331093207527803912171,4.9851649496034715625115,5.1581342419725935144470,\
0.9450506373811344840163,4.8685813827251553931319,4.4367163112396088564537,\
3.8395099847061766595857,4.1572465837028591550961,5.0006994941965512424531,\
5.0482993082581542054754,4.8712984679982609392823,5.1965242406243383754827,\
5.1555269912574592794385,4.954082618091184997411,4.9337317049920867972901,\
5.1318923054243690273779,5.228160467885317963521,5.2538586990129676479455,\
3.4796690893012534040452,3.2354639460120244720542,5.2544150166005954005755,\
4.9073526741507107473694,4.3768085901327413722584,3.0964161555968114925008,\
4.6243182142058252281913,4.7611868033967539304285,3.9477786701409951497510,\
4.0664175090632737052943,2.4831009250018341028010,5.1977230816033159754852,\
4.8193171469932529760172,3.9131402651137854320496,5.1221517738388655516246,\
5.1087193584020944570057,4.98657191625376672306,4.0758371911626332106948,\
4.0632814774108050315249,4.9481239065017428302440,4.1094776238806378643176,\
5.0202867341820684998766,4.9860329708595516606806,4.9279811897230469952547,\
4.8266925606060153697285,4.421080015153528108840,4.0288134359166507536543,\
2.4118364183807097234080,4.7542122019999739634954,0,\
4.9167355873994562642793,5.1832514554357551617159,5.2255055264178071894321,\
4.0392267678246307482937,2.9816410740582028893186,4.4155348942144980739499,\
4.8538668500531736427206,4.8627367182462748473881,4.5437480774189333843083,\
4.7954231948046981415246,4.8998553915953095838631,4.9613217960209823331752,\
4.6843975172654603866818,4.3578777660333960497496,0.4626347638559775710121,\
5.1945923008314265345575,3.3228343258666956927527,2.830622803369744922009,\
4.238528249750794785200,4.438709481897562980635,5.077806047884725337838,\
4.1519928438683244564800,3.5839165427001460351164,4.9371344840241793150426,\
4.2619788264190443527468,3.4726281293145686568380,5.0151457380383783757338,\
4.8233440014012511909414,4.6348430510092004652734,4.9099388325030934865367,\
4.81482819845952114690,4.9446162371720561168331,3.3034540778469194677314,\
4.8018287252966844746993,3.6328352359975357721567,4.556167488561304601546,\
3.5349368514717505185274,4.41558212917596915048,3.4210967363570983224008,\
3.8224459155669441301484,5.2559705982049909067655,4.3692671498839636967659,\
1.5671566063449566819088,4.4980634827120455909721,5.2081885950679547292452,\
3.0901072205487807309510,5.0089838747007107144782,0,\
3.850698741029123794988,5.076462566530570263978,4.8744723131002718474747,\
4.6369786693462113902342,4.9454673471881154256380,2.3923187222394570738970,\
4.8292733779221936885051,5.127649658742538640865,3.5426723072020398497273,\
4.424241396092424949416,5.0983081346685077406278,3.9246509637740216724922,\
5.1484540607983912963164,3.537944651477085589164,5.0505959169093319616195,\
3.3118225003889145696689,0,0.9310418690232507010762,\
4.1096195393026562214800,5.0789747485012091132717,5.2887730188734272118722,\
5.1102622536361952398920,5.1614350980940946200803,4.0783057415377843568649,\
4.7582657239633334711471,4.0624799671967695147146,1.3172890037212539038336,\
4.9618816771260449982606,3.9761122565887623281,4.64415999832871140285,\
4.5678423566873336270078,0,4.3415161209508754680542,\
4.5862227542495350718355,4.481694375737592217490,4.8778648861550966131517,\
3.0394313734202933474648,4.4492483198356360674097,5.0119936831694982259933,\
4.3028609023006350042806,5.1253479422290126876760,5.1970769705972195140475,\
4.4813909798397162376205,0.4257373352329655857851,3.7070996451820255046528,\
5.1406738437618608728030,4.3648993866947414232982,5.2737219653314042489001,\
2.820201721217977297584,3.8451912168199942065883,4.5724793527790357217100,\
4.1982477070823893683382,5.2621850617105074832125,4.661852422144622920541,\
2.7682565538529817494862,5.0169105620070073570105,2.1792385497944919414692,\
5.131423242241443638534,3.6886685835548016498819,4.9336715234659216378077,\
4.032310316197459165721,5.0694524637856641646749,3.7022621441401133424165,\
5.0507852459760567143121,5.2322161767096924123166,5.1795206909289932539764,\
4.2148191048546337356129,5.19027265701442619417}


#define ZRIN {0.1483933464623987674713,0.5565875237807631492615,0.4628333351574838161469,\
0.9158247429877519607544,0.0444016349501907825470,0.8175177471712231636047,\
0.5320580708794295787811,0.2989391684532165527344,0.5029047676362097263336,\
0.4266923693940043449402,0.3965902938507497310638,0.7440190296620130538940,\
0.7921002809889614582062,0.5715918401256203651428,0.4155966262333095073700,\
0.2953372262418270111084,0.1075767637230455875397,0.7572548976168036460876,\
0.93660886352881789207,0.7694978956133127212524,0.0902581927366554737091,\
0.4731486858800053596497,0.4765542480163276195526,0.6361737176775932312012,\
0.5064576440490782260895,0.9049607468768954277039,0.6742701171897351741791,\
0.3656400945037603378296,0.6837903787381947040558,0.4100628877058625221252,\
0.3582529271952807903290,0.7118562050163745880127,0.7966963038779795169830,\
0.9753969227895140647888,0.5733916512690484523773,0.8998429346829652786255,\
0.5953218084760010242462,0.3765322910621762275696,0.9104355531744658946991,\
0.1861076802015304565430,0.6715109744109213352203,0.2566455481573939323425,\
0.9819463356398046016693,0.7608660291880369186401,0.8556561623699963092804,\
0.8441717335954308509827,0.3884846637956798076630,0.4608103148639202117920,\
0.8381579727865755558014,0.5278776129707694053650,0.0187810636125504970551,\
0.2611750457435846328735,0.6092445817776024341583,0.0081067951396107673645,\
0.0276411953382194042206,0.0158492103219032287598,0.8109004520811140537262,\
0.2429467244073748588562,0.3353355019353330135345,0.4142854567617177963257,\
0.5946544189937412738800,0.9080675477162003517151,0.992223232518881559372,\
0.6239561475813388824463,0.0789771513082087039948,0.5889828568324446678162,\
0.2523608407936990261078,0.5871062893420457839966,0.0000379872508347034454,\
0.4244823055341839790344,0.69984475849196314812,0.4405533373355865478516,\
0.6495711454190313816071,0.4199861017987132072449,0.2716385438106954097748,\
0.0272838752716779708862,0.6936013107188045978546,0.1495713749900460243,\
0.5206344048492610454559,0.9685971699655055999756,0.9657785953022539615631,\
0.0654204180464148521423,0.9626990980468690395355,0.2655456010252237319946,\
0.8290728745050728321075,0.1334408046677708625793,0.8514542016200721263885,\
0.8984219655394554138184,0.1995774977840483188629,0.0138073815032839775085,\
0.2245407640002667903900,0.3930436577647924423218,0.8261723746545612812042,\
0.5051761353388428688049,0.5651183272711932659149,0.822583723813295364380,\
0.9197964356280863285065,0.4713199352845549583435,0.9223483256064355373383,\
0.2136987913399934768677,0.7260794681496918201447,0.9689361499622464179993,\
0.8346118587069213390350,0.8257038742303848266602,0.1350833275355398654938,\
0.7953761396929621696472,0.8992118402384221553802,0.2715440522879362106323,\
0.9219025229103863239288,0.1750466236844658851624,0.3323095212690532207489,\
0.9493130259215831756592,0.7118741781450808048248,0.8032329222187399864197,\
0.3628453887067735195160,0.7530685458332300186157,0.2641473677940666675568,\
0.9660940738394856452942,0.8041944387368857860565,0.5316947177052497863770,\
0.1673618280328810214996,0.955579827539622783661,0.6473058252595365047455,\
0.2645611818879842758179,0.5411860425956547260284,0.4980195099487900733948,\
0.0190768833272159099579,0.4227291680872440338135,0.8374647037126123905182,\
0.4151327675208449363708,0.3497115275822579860687,0.4844544250518083572388,\
0.3347255480475723743439,0.2362121837213635444641,0.0928130256943404674530,\
0.0737370252609252929688,0.4197955676354467868805,0.9802277712151408195496,\
0.8419611467979848384857,0.6906680446118116378784,0.2502765958197414875031,\
0.8266033390536904335022,0.1875236849300563335419,0.5023231171071529388428,\
0.8916302681900560855865,0.8934147348627448081970,0.1574523574672639369965,\
0.1629528645426034927368,0.5226223585195839405060,0.8417599620297551155090,\
0.5858130785636603832245,0.1322202011942863464355,0.8028764897026121616364,\
0.5250511718913912773132,0.2528006075881421566010,0.4602345135062932968140,\
0.996287219692021608353,0.4019785309210419654846,0.1399875725619494915009,\
0.5081327147781848907471,0.9440425024367868900299,0.9318959629163146018982,\
0.6445578685961663722992,0.5729571748524904251099,0.4810055238194763660431,\
0.6713787661865353584290,0.0962744313292205333710,0.8855805248022079467773,\
0.3892059125937521457672,0.2907031057402491569519,0.4209313853643834590912,\
0.9504273366183042526245,0.482190326321870088577,0.2289973804727196693420,\
0.2940405677072703838348,0.6957426778972148895264,0.9139824123121798038483,\
0.2068154653534293174744,0.6285024262033402919769,0.4031575415283441543579,\
0.3064021435566246509552,0.3148818286135792732239,0.7400112929753959178925,\
0.8853011503815650939941,0.788494529668241739273,0.8977585239335894584656,\
0.0339450328610837459564,0.8802101369947195053101,0.5418177028186619281769,\
0.9511840576305985450745,0.5574890668503940105438,0.1312845982611179351807,\
0.9453403786756098270416,0.2518341308459639549255,0.2607447705231606960297,\
0.1215410251170396804810,0.9136986923404037952423,0.9382542567327618598938,\
0.3105722474865615367889,0.9309121072292327880859}

#define ZIIN {0.5225624092854559421539,0.7617142526432871818542,0.3009174778126180171967,\
0.1853434126824140548706,0.5148605112917721271515,0.7257346073165535926819,\
0.7033738414756953716278,0.5664369426667690277100,0.7816161573864519596100,\
0.3330347230657935142517,0.4017280167900025844574,0.8503915611654520034790,\
0.41114101978018879890,0.1586530329659581184387,0.6542402538470923900604,\
0.9449902996420860290527,0.400338994804769754410,0.9679889930412173271179,\
0.32740902295336127281,0.8933845367282629013062,0.6218692888505756855011,\
0.0985169494524598121643,0.7449700380675494670868,0.3134250529110431671143,\
0.1409188793040812015533,0.3239218806847929954529,0.9958796552382409572601,\
0.2412899602204561233521,0.4753343504853546619415,0.9194070147350430488586,\
0.0450326460413634777069,0.8481595069169998168945,0.8928631045855581760406,\
0.1469233212992548942566,0.4904643460176885128021,0.9986877571791410446167,\
0.3392539476044476032257,0.8790708789601922035217,0.3107871781103312969208,\
0.1200211457908153533936,0.0909670502878725528717,0.5804221173748373985291,\
0.446611551102250814438,0.3501139078289270401001,0.7262432840652763843536,\
0.3650169344618916511536,0.5597011330537497997284,0.434090383350849151611,\
0.5082829319871962070465,0.3487796885892748832703,0.8136124997399747371674,\
0.337404197081923484802,0.7742837746627628803253,0.0156080657616257667542,\
0.0195691580884158611298,0.0445443131029605865479,0.4240885511972010135651,\
0.8158838218078017234802,0.9913199446164071559906,0.5120379645377397537231,\
0.1021917951293289661407,0.7161553995683789253235,0.4527317988686263561249,\
0.2445004582405090332031,0.1668560453690588474274,0.9187424210831522941589,\
0.3418669118545949459076,0.4624818544834852218628,0.0400874321348965167999,\
0.4700120547786355018616,0.8552942494861781597137,0.3308605216443538665771,\
0.0322206378914415836334,0.9760772576555609703064,0.0763854510150849819183,\
0.2165335658937692642212,0.2348632332868874073029,0.1446668924763798713684,\
0.5313451024703681468964,0.4441541358828544616699,0.5759493880905210971832,\
0.3719177199527621269226,0.5167253850959241390228,0.5186656024307012557983,\
0.6306529571302235126495,0.0928382659330964088440,0.5421750987879931926727,\
0.2833826132118701934814,0.2819099412299692630768,0.1141945635899901390076,\
0.7321730605326592922211,0.9823690224438905715942,0.8243003231473267078400,\
0.6485677706077694892883,0.5304958778433501720428,0.6958626955747604370117,\
0.6050392785109579563141,0.2683336613699793815613,0.5511700971983373165131,\
0.1174971889704465866089,0.7958277617581188678741,0.4983139941468834877014,\
0.9196587274782359600067,0.1420703046023845672607,0.389312467072159051895,\
0.2658497532829642295837,0.9480321384035050868988,0.2326095197349786758423,\
0.0139051643200218677521,0.9270462663844227790833,0.4878733339719474315643,\
0.0354842916131019592285,0.6607114099897444248199,0.0879401965066790580750,\
0.8046676008962094783783,0.212315237149596214294,0.9163186331279575824738,\
0.9393384093418717384338,0.3174265320412814617157,0.9574301876127719879150,\
0.7951935962773859500885,0.3240787154063582420349,0.0472964248619973659515,\
0.1696171183139085769653,0.7654392314143478870392,0.2554624872282147407532,\
0.1189010548405349254608,0.7469239532947540283203,0.0616608508862555027008,\
0.1056091515347361564636,0.1581688239239156246185,0.9732552450150251388550,\
0.8786917333491146564484,0.1824825564399361610413,0.9303942839615046977997,\
0.4655157290399074554443,0.5399280847050249576569,0.9143392136320471763611,\
0.0622840351425111293793,0.6500507537275552749634,0.2340233740396797657013,\
0.3603484155610203742981,0.1917369994334876537323,0.2371335849165916442871,\
0.4136920445598661899567,0.2661342276260256767273,0.3891090690158307552338,\
0.6622495856136083602905,0.4503725995309650897980,0.3829893553629517555237,\
0.1937121297232806682587,0.9629272706806659698486,0.6385000632144510746002,\
0.2695108866319060325623,0.1092974594794213771820,0.0598662365227937698364,\
0.1431378168053925037384,0.2944079088047146797180,0.9022735017351806163788,\
0.9111119657754898071289,0.9847188093699514865875,0.0592310009524226188660,\
0.5464080139063298702240,0.5080275069922208786011,0.6546461437828838825226,\
0.9597736010327935218811,0.1577645908109843730927,0.1818120293319225311279,\
0.4555030376650393009186,0.1048952480778098106384,0.7636235631071031093597,\
0.1893162522464990615845,0.1596221593208611011505,0.3115166993811726570129,\
0.2491372707299888134003,0.0469047501683235168457,0.0797643386758863925934,\
0.3945369226858019828796,0.3254697113297879695892,0.5811151321977376937866,\
0.1456566532142460346222,0.4704219633713364601135,0.8631705637089908123016,\
0.1648640967905521392822,0.0801398889161646366119,0.4932156866416335105896,\
0.4345335862599313259125,0.1079503614455461502075,0.2686753761954605579376,\
0.7417223947122693061829,0.4086893904022872447968,0.6706044673919677734375,\
0.4159612008370459079742,0.4766113189980387687683,0.4431825890205800533295,\
0.6688354592770338058472,0.5834077899344265460968,0.4861929873004555702209,\
0.715783319901674985886,0.1403244398534297943115}

#define ZRRESULT {0.5053397031743451783825,0.7650083608446867078356,0.3289296819323739295982,\
0.3563456766158749622342,0.4948207655225617118688,0.8169593462846268527855,\
0.7132198900639351579755,0.5570137230416445373038,0.7685376318852206178889,\
0.3559803193123551312560,0.4189790595413633300659,0.8813522345691391368661,\
0.5405451162482487470484,0.1905551975849387180695,0.6493731034151291048317,\
0.8578709195697519218626,0.3922142862720902067863,0.9642946930057294530059,\
0.5389615746319644795648,0.9186094888728127960675,0.5890418064066422765279,\
0.1113977102429560134267,0.7345860770241963155769,0.3799876579856086289411,\
0.1619970506356118999935,0.51382943864194075001,0.9605702232101991366875,\
0.2552214504374311077051,0.5588288246069162967800,0.8545155572742579863643,\
0.0482073009402987154304,0.8701819105023789191478,0.9267094766915666692597,\
0.3583874762657675017152,0.5394241582016752190043,1.0267057888096897677599,\
0.3962322220487046187110,0.8200372580795054489045,0.5035682683774097556650,\
0.1218215489911998739014,0.1217295472085216101465,0.5645974853924803360528,\
0.6787204142960019392916,0.4641409785094591788912,0.8320374579652175528466,\
0.5202648072575078996849,0.5635084163999081185992,0.4608376215542885900867,\
0.6521335567127740651117,0.3901559225476997627702,0.7433295520896158192770,\
0.3414853587252406064145,0.7876437052847802267053,0.0156079448330699189357,\
0.0195753850507095344957,0.0445351746116087257588,0.5619901990592348628439,\
0.7563216032216260042986,0.8953230010983072029163,0.5250759023565449989945,\
0.1262270783291525866332,0.8463340938014771719367,0.6903512283163251161966,\
0.3002023271844543317322,0.1665929038330317135674,0.8881085995755062523216,\
0.3450945758035259824936,0.5168125326109850314893,0.0400767031552608649081,\
0.4881659313644853837033,0.8717577944100705078512,0.3559191435167290418207,\
0.0423384874325624382951,0.8962569818869624560520,0.0792669980362326609402,\
0.2149514867261388406661,0.3084002596083564862184,0.1457610223920582370738,\
0.5638322964331675679617,0.6681928703809085767773,0.7715309042125101379739,\
0.3644939000586688848671,0.7241095709372292743566,0.5109856481565466790329,\
0.7492592023075983487246,0.0935322123614654998836,0.6873609600399674945947,\
0.4653574362777189166174,0.2834338708350941926639,0.1139584955905696417311,\
0.6886187601911135658384,0.8966624572124947123442,0.8901159605244814976288,\
0.6621780758434868685569,0.5739364819547106977282,0.7967040377802739881119,\
0.7702556784014074064970,0.2963495189276508789966,0.729639913718978516677,\
0.1199467917211827494572,0.8369585267706058928638,0.7130151705637984838049,\
0.9564173315765011063050,0.2362741844905166255231,0.3829952297292640861492,\
0.3854654409071321952140,0.9956878617898979877410,0.2388852521695121466916,\
0.0357548125472270175718,0.8344528446849692748799,0.4908081134490644426016,\
0.1072298401775326898155,0.7292248632489435333781,0.1444440063075330404896,\
0.7618560442692507983509,0.3014073074948313002430,0.8338433864005018181231,\
1.013809216729007589564,0.4488437286282063176657,0.9028988520348978363828,\
0.7342748763980897486192,0.5492704923146081164020,0.0619250478958671968233,\
0.1747947745500638971894,0.7643392221916658346714,0.2869233753851287982428,\
0.1186438529044472750540,0.7261517086175122148717,0.1110167797262640587697,\
0.1156665104854840142590,0.1677179018762894047168,0.9049771869312485117476,\
0.8140692858573190804350,0.1865250841653489921601,0.8328626043313867022277,\
0.4511026850510220786994,0.5511713324178673101272,1.0040394102716723168101,\
0.1134432764930088655131,0.7136163206069113806862,0.2389915016256592694699,\
0.5061510239067475991348,0.1938531425179492451161,0.267912781705172242663,\
0.594520593176991907214,0.4421595740617755287971,0.3838580911610497414799,\
0.6265966551277006857390,0.4892019455111443759776,0.5371648663643865395656,\
0.2336644699290637006150,0.8580649693764487162539,0.7447932141471096390006,\
0.30664577808112553070,0.1126796888171682081703,0.0673404850217956818526,\
0.3780061914448271664924,0.3135468248495265064513,0.8141814149801622768621,\
0.8656800272972641208113,1.0330415543607425199468,0.1517147576472806791426,\
0.6107832692276639052764,0.5555300503019462432519,0.6621194316643849164805,\
0.9359383537376269046604,0.1578266511911156633197,0.3288869400610432980336,\
0.4688911283964798393242,0.1093517544178844447256,0.7390278072154514710235,\
0.3915656081630794482784,0.1803516698292359499156,0.3140185989593758941751,\
0.2570435038916802361619,0.0651252572213311814453,0.1812803236410877871787,\
0.3918987512324060840108,0.3907169202420177067658,0.5847178774812699098007,\
0.1522469534945809221949,0.4726351219523636792985,0.8890284419930043480207,\
0.3043305148205690535690,0.1282404489119809976039,0.6689999411776240689775,\
0.4220981761434796641907,0.2107039270298768085521,0.3089304668962193911597,\
0.8825265124364938262858,0.4570764804119011315287,0.6317437032300170507426,\
0.6289949625530589782940,0.4716158816756069738219,0.4417016096894970100806,\
0.6297964082740089564183,0.7506329678118981441060,0.6853639001045995771122,\
0.6844909750084481325771,0.3028385676048351293765}

#define ZIRESULT {1.4391441245686327210507,1.130955515640670316913,1.1164484564631134144719,\
0.5343429881094952094145,1.5313159234681512632648,0.9218282568507811802760,\
1.1368031918334591257036,1.309961324172885133166,1.1768313149474189938104,\
1.1581725732800560724201,1.198068547194847122128,1.0167778558643913999759,\
0.8107284978807606234952,0.9747572654361357225028,1.2226962809307837520834,\
1.356863284326968122073,1.4708283871101888173882,1.0424189614104724110888,\
0.6175483783889722522176,1.012434899444895508580,1.4941377955828787360559,\
1.081247186686038253001,1.189977918876721885155,0.9361970185325101390106,\
1.0473314366303878575337,0.6478815708564551467674,1.103880390282215628872,\
1.208902068619972958174,0.9405460211534443226711,1.2708555309086870810376,\
1.2048457921815343141247,1.0386992340805454304586,0.9940470159552662332558,\
0.4129471251607437776165,1.0483368304459323994138,0.9626808065085141752348,\
0.9866797451792658213421,1.2893127532844186333705,0.6333368050416610106623,\
1.3849939050391590900091,0.8412033774271403530065,1.3484185557182311043789,\
0.6561721869869621137639,0.8152667302376208624537,0.8942162872449925803409,\
0.7354476761871528989190,1.2302184692777484720239,1.1419032200306009627866,\
0.8136425490751511002685,1.0585917357001826122342,1.5562281161680697749716,\
1.3215709464122720184776,1.0936282246933759498830,1.562690430228121041267,\
1.5431569076078051061529,1.5549621593607869662890,0.7985043985204253180754,\
1.3827954341839958640747,1.3338048203354757603734,1.1992311317991326546917,\
0.9398015526727905299964,0.8526323846859752420002,0.6516084904889641871151,\
0.9312161189612270240090,1.4928235928235611407189,1.1434135639085114544145,\
1.3304436504678796016066,1.0279557218905930326969,1.5707583700301124274290,\
1.18264027414866035315,1.049240570305455033662,1.1438977350867394200407,\
0.8645410048697405036577,1.272544314036070156604,1.2965854453389789036066,\
1.5441276936419627840991,0.8474785980812834518261,1.4222542688372477037717,\
1.1067340541491283989473,0.6658230283826037654293,0.7440600810961385258580,\
1.509454955782236762474,0.7139904083352976993382,1.3343109319103572119047,\
0.8754276015708571945240,1.4375430902494801266300,0.8182153660902479197503,\
0.6279916190243797213810,1.3777792247900606525945,1.5570776874524723254467,\
1.3896877170114805277734,1.292290381577097857502,0.9513544490495031702437,\
1.146595322853661613749,1.0663673649265974496814,0.9066444651210990857138,\
0.7936124351430207113367,1.1025133400691302654195,0.7646931356316959416120,\
1.3570006423237950254901,1.0127507430242304042878,0.6984070724030820853656,\
0.9777377069899801931285,0.6381815285628557044006,1.4447151619316793702552,\
0.7381184252357657626931,0.9463444174447509515957,1.3036540993301888313738,\
0.3993509460349408124458,1.4425649666003559357108,1.2703537792660923866350,\
0.3366052452908819825339,0.9799364183556658058905,0.6519110571169279833015,\
1.288935099739083156578,0.766834829952783847418,1.3765235555687964641436,\
0.9026821267000586512808,0.7532458865053713870097,1.1915253215495016370085,\
1.4398661339551832583084,0.5960292480319858698934,0.8683763627836410536887,\
1.307183356265154250409,1.1437419441048803925298,1.0721920855425228769064,\
1.5518517938677236500666,1.2329687641584510249260,0.5874976025749066854686,\
1.1457409989520814797004,1.2187173974473419768572,1.2272326680013900812583,\
1.3202499364548996307889,1.3364966855772182352524,1.5028659601895917319325,\
1.5039244799556488185743,1.199080874147727016066,0.8850027352965960103504,\
0.5797999065603636204003,0.9935513093218836244702,1.3250345117052622079257,\
0.7510747251416685088543,1.3856864393507652977178,1.0646397833458374204696,\
0.7161423103150551527918,0.6220745390646167383153,1.4237426982899421545881,\
1.4349026977530163762253,1.0862935323189089054097,0.7475103036060971595234,\
0.9640755596017442918821,1.4756182374730877349123,0.8992686396344509169865,\
1.0456992348735927311765,1.316872193719026640224,1.0937098269572853581622,\
0.3787889502350130777053,1.1777575502770252224849,1.466927792635024818679,\
1.198998549247170863907,0.9317214709279717510526,0.3994553068013038665818,\
0.9996993047110468433303,1.0533682169916682713762,1.1680862767422879322510,\
1.0968093743281353003027,1.475564759332087749755,0.5739680940616843640711,\
1.2132055498728515630091,1.277641763762892734846,1.2372616699165408515881,\
0.4908185034943345348424,1.0764535824324550361553,1.3508749145869605179371,\
1.282220574891209663448,0.8033914160655766245611,0.4529330910646225394345,\
1.3777085436870080137339,0.9478851551815749010288,1.2208388985822435923723,\
1.263077873207383738929,1.284175149159334061721,1.023436357706823729430,\
0.5626793926847969418148,0.6728398111486185717567,0.7545922256887819257187,\
1.5396608871785673056110,0.5335122401588628937574,1.0275094129340511805992,\
0.8338356239168208672297,1.0426578447465559840168,1.4617456602888381222982,\
0.6682797094798482717692,1.3426136823908161321839,1.3312882615539098907220,\
1.4697575902556172522395,0.7877417380659905710161,0.7165102522491650915981,\
1.3183788402186256139004,0.4738958779540429211430}

void dacoshsTest(void) {
  double In[]=IN;
  double Res[]=RESULT;
  double out;
  int i = 0;

  for (i=0;i<200;i++){
	if (In[i]<1) assert(1);
	else {
		out = dacoshs(In[i]);
		assert ( ( fabs(out-Res[i]) / fabs(out) ) <1e-15);
	}
  }
}

void zacoshsTest(void) {
  double InR[]=ZRIN;
  double InI[]=ZIIN;
  double ResR[]=ZRRESULT;
  double ResI[]=ZIRESULT;
  int i=0;
  doubleComplex in,out;

  for (i=0;i<200;i++){
	in=DoubleComplex(InR[i],InI[i]);
	out=zacoshs(in);
	assert( ( fabs(zreals(out)-ResR[i]) / fabs(zreals(out)) ) <1e-15);
	assert( ( fabs(zimags(out)-ResI[i]) / fabs(zimags(out)) ) <1e-15);
  }
}

void dacoshaTest(void) {
  double In[]=IN;
  double Res[]=RESULT;
  double out[200],in[200];
  int i = 0;

  for (i=0;i<200;i++){
	in[i]=In[i];
  } 

  dacosha(in,200,out);
  for (i=0;i<200;i++){
	if (isnan(out[i])) assert(1);
	else{
		assert ( ( fabs(out[i]-Res[i]) / fabs(out[i]) ) <1e-15);
	}
  }
}

void zacoshaTest(void) {
  double InR[]=ZRIN;
  double InI[]=ZIIN;
  double ResR[]=ZRRESULT;
  double ResI[]=ZIRESULT;
  int i=0;
  doubleComplex in[200],out[200];

  for (i=0;i<200;i++){
	in[i]=DoubleComplex(InR[i],InI[i]);
  }
  zacosha(in,200,out);
  for (i=0;i<200;i++){
	assert( ( fabs(zreals(out[i])-ResR[i]) / fabs(zreals(out[i])) ) <1e-15);
	assert( ( fabs(zimags(out[i])-ResI[i]) / fabs(zimags(out[i])) ) <1e-15);
  }
}

int testAcosh(void) {
  printf("\n>>>> Double Hyperbolic ArcCosine Tests\n");
  dacoshsTest();
  zacoshsTest();
  dacoshaTest();
  zacoshaTest();
  return 0;
}

int main(void) {
  assert(testAcosh() == 0);
  return 0;
}
