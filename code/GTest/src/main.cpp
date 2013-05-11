#include <gtest/gtest.h>
#include "Parser.h"
#include "Configuration.h"
using namespace UXP1A_project::Shared;

TEST(CheckConditionsTest, PositiveNos)
{
    /*
     * Int
     */
    ASSERT_EQ(true, Parser::checkCondition("int:0"));
    ASSERT_EQ(true, Parser::checkCondition("int:66"));
    ASSERT_EQ(true, Parser::checkCondition("int:264"));
    ASSERT_EQ(true, Parser::checkCondition("int:407"));
    ASSERT_EQ(true, Parser::checkCondition("int:388"));
    ASSERT_EQ(true, Parser::checkCondition("int:507"));
    ASSERT_EQ(true, Parser::checkCondition("int:-898"));
    ASSERT_EQ(true, Parser::checkCondition("int:-496"));
    ASSERT_EQ(true, Parser::checkCondition("int:-178"));
    ASSERT_EQ(true, Parser::checkCondition("int:-106"));
    ASSERT_EQ(true, Parser::checkCondition("int:<0"));
    ASSERT_EQ(true, Parser::checkCondition("int:<854"));
    ASSERT_EQ(true, Parser::checkCondition("int:<176"));
    ASSERT_EQ(true, Parser::checkCondition("int:<905"));
    ASSERT_EQ(true, Parser::checkCondition("int:<677"));
    ASSERT_EQ(true, Parser::checkCondition("int:<233"));
    ASSERT_EQ(true, Parser::checkCondition("int:<-325"));
    ASSERT_EQ(true, Parser::checkCondition("int:<-15"));
    ASSERT_EQ(true, Parser::checkCondition("int:<-657"));
    ASSERT_EQ(true, Parser::checkCondition("int:<-308"));
    ASSERT_EQ(true, Parser::checkCondition("int:>0"));
    ASSERT_EQ(true, Parser::checkCondition("int:>271"));
    ASSERT_EQ(true, Parser::checkCondition("int:>872"));
    ASSERT_EQ(true, Parser::checkCondition("int:>26"));
    ASSERT_EQ(true, Parser::checkCondition("int:>404"));
    ASSERT_EQ(true, Parser::checkCondition("int:>814"));
    ASSERT_EQ(true, Parser::checkCondition("int:>-628"));
    ASSERT_EQ(true, Parser::checkCondition("int:>-218"));
    ASSERT_EQ(true, Parser::checkCondition("int:>-715"));
    ASSERT_EQ(true, Parser::checkCondition("int:>-860"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=0"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=528"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=759"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=364"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=396"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=679"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=-411"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=-730"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=-569"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=-366"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=0"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=1"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=525"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=829"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=732"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=549"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=-730"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=-487"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=-147"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=-475"));

    /*
     * Float
     */
    ASSERT_EQ(true, Parser::checkCondition("float:<0"));
    ASSERT_EQ(true, Parser::checkCondition("float:<73.9"));
    ASSERT_EQ(true, Parser::checkCondition("float:<502.177"));
    ASSERT_EQ(true, Parser::checkCondition("float:<618.0148"));
    ASSERT_EQ(true, Parser::checkCondition("float:<75.217"));
    ASSERT_EQ(true, Parser::checkCondition("float:<112.7"));
    ASSERT_EQ(true, Parser::checkCondition("float:<-682.6"));
    ASSERT_EQ(true, Parser::checkCondition("float:<-276.97"));
    ASSERT_EQ(true, Parser::checkCondition("float:<-828.3141"));
    ASSERT_EQ(true, Parser::checkCondition("float:<-540"));
    ASSERT_EQ(true, Parser::checkCondition("float:>0"));
    ASSERT_EQ(true, Parser::checkCondition("float:>360.7"));
    ASSERT_EQ(true, Parser::checkCondition("float:>165.282"));
    ASSERT_EQ(true, Parser::checkCondition("float:>665.5035"));
    ASSERT_EQ(true, Parser::checkCondition("float:>445"));
    ASSERT_EQ(true, Parser::checkCondition("float:>486.27"));
    ASSERT_EQ(true, Parser::checkCondition("float:>-990"));
    ASSERT_EQ(true, Parser::checkCondition("float:>-575.36"));
    ASSERT_EQ(true, Parser::checkCondition("float:>-352.0072"));
    ASSERT_EQ(true, Parser::checkCondition("float:>-316"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=0"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=404.6"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=732.7346"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=745.170"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=387.5"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=859.412"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=-431.06"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=-830.701"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=-147"));
    ASSERT_EQ(true, Parser::checkCondition("float:<=-507.2"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=0"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=141.4562"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=898.0704"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=178"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=53.898"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=696.8"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=-918.3645"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=-742.9752"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=-680.8"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=-916"));

    /*
     * String
     */
    ASSERT_EQ(true, Parser::checkCondition("string:*"));
    ASSERT_EQ(true, Parser::checkCondition("string:\"*\""));
    ASSERT_EQ(true, Parser::checkCondition("string:\"-Yn\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"M=|GFWCBqBtz,y6BjT ~^Q|M{$a c0A%}08%bGjV`n8\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"=]Zra=q$db!&!zjQ0}^8(v\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"hHU-PR 1U-04bCT`i58Ua)qge8Knww$jydORs#F\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"wfPxzNt@rsz93267#X^CSE;-OEkqG5K,o06Bp\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"hxCqdxDdsdTAlld{evNO$,cK\""));
    ASSERT_EQ(true, Parser::checkCondition("string:\"Y%~0c*Pai\""));
    ASSERT_EQ(true, Parser::checkCondition("string:\"IO^ ?XB,}Rg\""));
    ASSERT_EQ(true, Parser::checkCondition("string:\"5#7fylUA_8_4X:=\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"m=W~FwaE|tx.HH{+*d0:;iKA%prN1\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"Z-WQVusxi*Qr'X*mk:4_;SGOs.g_n RI84*X2(\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"VW`'HeU9VjI369#MeYdl,zKOCfhg7OqE!vw.rI'.9#(&\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"NXNmlotab=AtcNSq+qd?`~:]uA$VjQ94Nfo_G?;\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"c3e?H1,6Q}N-nA5RHjb_f(j&_{Xbwi[c@QfR6O\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"(Qgc{Y^n7jC|^Ahfpgw*n&O;{],m$8VU_Zp3?uj^1kpQcRG$y\""));
    ASSERT_EQ(true, Parser::checkCondition("string:<\"3I8R'+\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\" 1EGR=smE97`VV)P}i5g(e,ekrpSsB@~gw\""));
    ASSERT_EQ(true, Parser::checkCondition("string:<\"IY0\""));
    ASSERT_EQ(true, Parser::checkCondition("string:<\"%Nu6,OHKaR \""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"nTuwhEvByZ]C)r`Mxtro9)Ky1NbSHRl,!h?)y'\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>\"=fiVTrirWLn!QDZgp#Efl\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>\"K8g8LDha+N9VPp7@PzNQ%rs3T#3V6MT'~sjaj2mz+FO5k\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>\"\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>\"z32 memRTv6SmQ*V\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>\"U}[5SR*o;@9Ftjvlga^=\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>\"K_=TxiSv!*{gR%5tz\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>\"(;=!67D=s*pk)TEGq=?o_x+*,tn:H^.&x0qr3m?tgAbu~6\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>\"]6~I\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>\" z)Pcdz?NFKk0I@3gP`k:rv6'WkZK]7$?,\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>\"gC&]}]h}S'7CvWzJ9$}duwyC)J=\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\" wC-?|otVIE:C^N4@:wHq=1~Q](Pt_[nk1cHs`*mcH\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"~D ^N$_.Z`g *bQKYT).;d**wEQ[x$Ts(*:Yf@'jmzrh\""));
    ASSERT_EQ(true, Parser::checkCondition("string:<=\",rY0m\""));
    ASSERT_EQ(true, Parser::checkCondition("string:<=\".,3pa~HH\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"4Cv~D=Py9CZvBIAKKb&t0A]c'Tq|vL~ND8'3'fp#NgAFNacx\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"Y,oYzUc.r;UFESk,EOiiT^Z;2l$shNQcIAN9}{\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"C{QuxHF|#s}6(CB4kcPHDnuHB9)6RaDh\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"CN`K)i$[oSV:af]_`zO+*pq914+_ei8-eYh^=&1p**0\""));
    ASSERT_EQ(true, Parser::checkCondition("string:<=\"RW$8Y2t|e\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"3c2-2-q5aEd1qK#VvIc.GNcpoYXK&RSjZZM$!}?{9[ZY}1\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\" M-y)kMl*.M7lBPzr$Yh,cM\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"5DH~w2nQHpoj?B5_,|]Xt*qo`F\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"8E*BtSC_xSjg*jGp-^IlH':b\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"I0g=obi#b(e_N&YiED GS,]^M@-a]|f*93\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"-3MxmDZf0I@}J:Z~kedA}~;,-Miw1\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"5VKqMm-yuBS 3x^XR4Qt=RuCKsWO#T,mgA:Irc iIaF^2z\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>=\",H(PK\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>=\"Zo#xlm&t7XGT_`Ox@BY\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>=\")f`;j3)PK38s5&ka!o[\""));
    ASSERT_EQ(true, Parser::checkCondition("string:>=\"gq(0g1oDtc|gj@#\""));

    /*
     * Combinations
     */
    ASSERT_EQ(true,
            Parser::checkCondition("int:>=-73, float:<=243.74, int:573"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>\"= Dq^Oh)&Z*D`*mANxpbYzh6~g|bK(?_\", string:<=\"9@y1I(,^VJtGD2Ku|\", int:<-118"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<888.2259, int:>163, string:\"T&nwGK,-|w?7.qfv=DZjL21m'ydT[dO^p'4}\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"##fjI&L(Im =\", int:<=-359, int:-625"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:>488, string:>\"K}QYb&l4c^(GIU7TOGjgx$6rmLG,{B;G]\", string:>=\".PXt[mK+o;sQO\""));
    ASSERT_EQ(true,
            Parser::checkCondition("float:>=826.9, float:<-960, string:<=\"ZVy~.Oiq1Oh!99FVj p'7tn*l~D\""));
    ASSERT_EQ(true,
            Parser::checkCondition("float:>-212.621, float:<-959, int:>611"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:>397, string:\"3ty\", float:<501.0834"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:>=-566, string:<\"W^(dq]}\", string:>\"mFLUWFlz965htso(5lT&{6'.S}]fMd}S~g#z=8J=1\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"0QqS^khmrIel\", string:<=\"vM3T0=TpS'i;*v9pM+.\", int:636"));
    ASSERT_EQ(true, Parser::checkCondition("int:<=-272, int:<-660, int:>932"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=236, float:>-60, int:<-591"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"KF)GM4wH|w}dY~P?o]'@J[NHZ}T{#.(8Sl;P__,I3ylVWk\", float:*, float:>-707"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:-234, string:>\"ta9^lF.UT+ck-jxVe(meI9VB$p1.-VWq]\", string:*"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:<=-601, float:<=974.2, int:491"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"_gN?SI%) \", float:<225.67, string:>\"T(ZP;lS\""));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<-203.02, string:\"-Nl-v~+.V3)!mLe9'HWq\", string:<=\"QH.)hIsMJTf4B9O1ko)36 U1~*oy\""));
    ASSERT_EQ(true,
            Parser::checkCondition("int:>659, float:<=392.383, int:-539"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"WG+e1L jj#&j~X1:#zBJjZe^\", string:>\"}#.gG@&Vb.e$94:{Qb).4TRm.u W2;lc$z9H{^(gpHX\", int:<-39"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:-572, string:<=\"\", float:>=289.35"));
    ASSERT_EQ(true, Parser::checkCondition("float:>=359, int:>276, int:<-910"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"{+QxJ`WCYt|?(lK7qb?_]~b,kO&K{)e7Kb$_xc\", string:<\":{aY#V|PB^p\", float:<111.26"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<-444.6683, float:<-981.9292, string:\"B:H@NX}*wYd6(V`0LmLq5*R%U_xcX+u)j#Pb\""));
    ASSERT_EQ(true,
            Parser::checkCondition("int:<-613, int:535, string:<=\"\""));
    ASSERT_EQ(true,
            Parser::checkCondition("float:>=0, string:<\"rD(fOZ!M+SWp@#s]#RPzz]yzCXI?e\", string:>=\"+i&` c\""));
    ASSERT_EQ(true,
            Parser::checkCondition("int:<=343, int:>=895, string:>\"M_=\""));
    ASSERT_EQ(true,
            Parser::checkCondition("int:<28, string:>\"*G59)i8YJ|0\", string:*"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:>=-346, float:<906.92, string:<\" HyF#YT?M@\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:*, int:>-391, float:<-620.87"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<136, int:-266, float:<-108.112"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:827, string:>\"uce'R)|(*H08Y~LM\", string:>\"SYrRe$_=6]kJQux84C:h~,v5\""));
    ASSERT_EQ(true,
            Parser::checkCondition("int:<=510, int:-65, float:>=545.8"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:>338, int:<-796, float:<300.8384"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\":FzH:5)5\", string:>=\"RF|f8Sc=ovvmXj\", float:<-79.5"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:>-208, int:763, string:>=\"wjpZjDmCn+^2\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:>=\"ls3['@YrXSY*MB~VG Wc:o7cL~excN[egXsB'$ _]+c+b[\", int:-929, float:<=32.30"));
    ASSERT_EQ(true, Parser::checkCondition("int:>=804, int:>=498, int:<=-685"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"[Zq%(DHhqDnBZ\", float:>-356, float:<201.7"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<\"IA_DtAl\", int:>-799, int:>133"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:<472, float:<=-159.547, int:>=-248"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:167, string:>=\"@PPE6)H0vTRy,mlHNl7eI?0a+TljMWU\", float:>477.35"));
    ASSERT_EQ(true,
            Parser::checkCondition("string:\"i==U.|XTiM.#dhvZE@L%g&OgAHp#z2wQ%=Tk|q\", float:>=-584.78, int:<-216"));
    ASSERT_EQ(true, Parser::checkCondition("float:*, int:>337, float:*"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:>894, string:<=\"EebrtxpdBu{8AjYuP3hE64g\", string:>=\"%2~xyvXQfF'TQvP7{YxL*h$}JHn@;~i6 $kMIWP';B[?(v6\""));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<879.1, float:<-600.01, float:<425.92"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<-372.8299, float:<-203.4, float:>=614.128"));
    ASSERT_EQ(true,
            Parser::checkCondition("int:>=317, string:<\"tDmkNRLvTebbd~Gncd#0mhExfL\", string:<\"YcH\""));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<-429.801, float:<754.3, int:>=595"));
    ASSERT_EQ(true,
            Parser::checkCondition("float:<=69.964, int:>=-560, string:<\"`u}h%0h~tyg+kEAp6kos%iHly:BWkORK3@&?g\""));
    ASSERT_EQ(true,
            Parser::checkCondition("string:<=\"cqiIrt],`QI)8:\", string:<\"T,\", float:<=-747.11"));
}

/*
 * NE true instead of EQ false due to warnings
 */
TEST(CheckConditionsTest, NegativeNos)
{
    ASSERT_NE(true, Parser::checkCondition("float:2"));
    ASSERT_NE(true, Parser::checkCondition("float:-4"));
    ASSERT_NE(true, Parser::checkCondition("float:0"));
    ASSERT_NE(true, Parser::checkCondition("string:\"\"\""));
    ASSERT_NE(true, Parser::checkCondition("ints:*"));
    ASSERT_NE(true, Parser::checkCondition("Int:*"));
    ASSERT_NE(true, Parser::checkCondition("flaot:*"));
    ASSERT_NE(true, Parser::checkCondition("floaT:*"));
    ASSERT_NE(true, Parser::checkCondition("strong:*"));
    ASSERT_NE(true, Parser::checkCondition("String:*"));
}

TEST(ConfigurationTest, PosNeg)
{
    ASSERT_EQ(QString(Configuration::CONFIG_FILE_NAME),
            Configuration::getServerFifoPath());
    ASSERT_NE(QString("/tmpsaddas sa"), Configuration::getServerFifoPath());
}

/*
 * QString comparison, not const char* due to that -> EQ not STREQ
 */
TEST(ParseStructTest, PositiveString)
{
    ASSERT_EQ("siisisif",
            Parser::parseStruct("string:<\"u5V*9$\", int:<204, int:<-732, string:>\"uq-Ep4 -?B*oT'SMGY!y,,l?\", int:<-178, string:<\"jYu o*Ia|3n{|co2i54uC]YB\", int:>-732, float:<14.7711"));
    ASSERT_EQ("sis",
            Parser::parseStruct("string:<\"UD-Pmr!vFKD;#}40m?d}b9z{GbE\", int:>-225, string:>=\"rH$4nUIou\""));
    ASSERT_EQ("fisffisf",
            Parser::parseStruct("float:<0, int:-72, string:>=\"S$c]&WVfo^\", float:<-342.3, float:<=-367.81, int:>-592, string:<\"{#&yX`HDE3V.k)RV0r!|;uVuuPnLaiOLa1BxM+F,7\", float:>=777.1853"));
    ASSERT_EQ("ssis",
            Parser::parseStruct("string:<=\"o_g#k&{QI2Eub5,[hH][W#r!z:_|sE#Bz#i!cf)*y{wl\", string:<=\"|tN!]AjhZ&AlUZB8nnhvw|[VK4`^(t&a5uH%(9Fp8|LA\", int:>755, string:<=\"l\""));
    ASSERT_EQ("iissf",
            Parser::parseStruct("int:<=662, int:<-740, string:<\"TNTCJe=ww8_VSX.x[D+~_Z#_-M\", string:\"92M=yIq^o{'MRGHwK[;?=vOZ;rD1X!;SR\", float:>=-37.0646"));
    ASSERT_EQ("si",
            Parser::parseStruct("string:<=\"*R?TNgAr}^|B]],@`rV{Cg`0X3AfDbu\", int:>=301"));
    ASSERT_EQ("fif",
            Parser::parseStruct("float:<-19.42, int:<=-102, float:<=235.7342"));
    ASSERT_EQ("ffiss",
            Parser::parseStruct("float:>-137.9264, float:<=-861.9534, int:<=682, string:>=\"0,]3Lb9$|WJAxJftKemtI5Y\", string:>\"yfU@0Od`P?Yh7mV$0k\""));
    ASSERT_EQ("fssi",
            Parser::parseStruct("float:<=-875.06, string:>\"}Qn%eXx).)H H0M*zfro]1_,-@u5,;D7(|-Ey=SjPdn0\", string:<=\"SoQ'zepHI\", int:>=309"));
    ASSERT_EQ("ffsifffi",
            Parser::parseStruct("float:>=508, float:>=-84, string:\"asD9_W?XJznlq2c|Rr.~jSDjh3z1KdJ^.)SLhr'\", int:>=-556, float:<=-926.7, float:<-57, float:<-67.105, int:>-214"));
    ASSERT_EQ("ssifsiifs",
            Parser::parseStruct("string:<\"P#-6A2i|1x7PD({:+o@6O('HC\", string:>=\"dHRQshbR~XFJ@w`!Q,l&\", int:-214, float:<=-733, string:>\"fYjjMQJuGuuXiNJ}sUWBU @V:ZWin}=ECz3\", int:667, int:856, float:<414.020, string:>\"C1[3odbo;s#\""));
    ASSERT_EQ("sisf",
            Parser::parseStruct("string:\"\", int:>=-280, string:>=\"f?1:3N[~'_oCg A@V,cr*]~nC`-1K~{Mbf&Ic\", float:>=47.98"));
    ASSERT_EQ("ifssssisfi",
            Parser::parseStruct("int:>820, float:>-669.68, string:<=\"%w0yh#TJ+Nqe57F\", string:>\"3IADQ7+_gFlM2jxLkywp1#|M}L)D@jYGb0'v63Yx2%H6\", string:\".b$09f#CP:=-fwvurIv,Ey,0HvL+)NH{DjJ?#umOZc5za^Y\", string:>=\"O(c{,^eP_NhG'oEpoz2EsntgH@mo^@Li\", int:<=0, string:<=\"]fCL#6\", float:>=-780, int:<662"));
    ASSERT_EQ("ssifssi",
            Parser::parseStruct("string:<\"+ow6|9\", string:>\"VKK:r)0oM[2`P~X(~!1\", int:<=20, float:<-415, string:>\"_Jl?yk%Yk0DMB{:-8yh2oa\", string:<\"{iv=.ip\", int:<847"));
    ASSERT_EQ("iif", Parser::parseStruct("int:<=-666, int:>-102, float:<-343"));
    ASSERT_EQ("fsffsfiss",
            Parser::parseStruct("float:<=16.10, string:\",;?9CL+mifv\", float:*, float:<-136.9, string:\"Bm7o\", float:>-347, int:>=295, string:<\"n#0bUN?hAruL9?z?Beg|ORus0F:'4`cD5iJfoP\", string:>\"uNGCchP,8jzJ7x=w$?T)TBMb&x~MvNJc+B#jkX-*E?:V\""));
    ASSERT_EQ("sfsfisssis",
            Parser::parseStruct("string:<=\"n(42ThXYK\", float:<=776, string:>=\"1q{}d(Kxl1*WT^l&P*~:F]\", float:>191.42, int:<=871, string:>\"=1iRES%*()MG=z7:q@sI5`cS^K6{YQ3%b5oe~4L39|nm2\", string:<=\"T'nih@pq2kxy&c|L~)u}nSk\", string:\"GuU^-~[H wcOB{ 9 ?t?&S 6rpg22pqtmpey72J|$ki\", int:<755, string:<=\"IU5+~{o5sMV*#2$\""));
    ASSERT_EQ("s",
            Parser::parseStruct("string:\"k`tTT+N%&4bYA#~KbUSKBugb5lrW%'L\""));
    ASSERT_EQ("fsiisff",
            Parser::parseStruct("float:<290.52, string:>=\"4XEqWF2we-VgM:&QpHTjc4$%0lSVSzLXXiyqOK(N\", int:<=820, int:<607, string:>=\"j@XrCb5|Ft_1 \", float:<-611.62, float:>=-110"));
    ASSERT_EQ("iifssfffsi",
            Parser::parseStruct("int:<=-654, int:230, float:>10.0042, string:>\"h0JYwCknz)\", string:*, float:<=886, float:<-885, float:>=-189, string:<=\"\", int:>-414"));
    ASSERT_EQ("isi",
            Parser::parseStruct("int:342, string:>\"je8'ds?GO']h]u~GzUbCC[[PfAAqp,Nxey^\", int:<-334"));
    ASSERT_EQ("s",
            Parser::parseStruct("string:<=\"xJ9ih9E$R;jKc4c|{#^Ir;,W}qVZ= f[6V3{\""));
    ASSERT_EQ("ssiifiii",
            Parser::parseStruct("string:>=\"NWyXZb,6;R=6U~WMx0ii9~gC(4Si\", string:<=\"R*^YqG-VZX'SsfIj@r10pMxe(-.ZBgBjFm\", int:>=-22, int:<0, float:>674.22, int:<-190, int:<=-314, int:<=542"));
    ASSERT_EQ("sississ",
            Parser::parseStruct("string:>\"w}`?CK^jDz1x*^UlU6U,$`F& Ap~WrZyn~BAR4s\", int:<407, string:>\":i+?Ejw94XA%XEiVWr+1\", string:<=\" #5,Oi7d^m#jD5}fhI^ba*TM+Rk6cR\", int:>=0, string:<=\"?K5HN8bKeR4@=@_(^zTOxq,Y{F-$LwCNr\", string:>=\"#\""));
    ASSERT_EQ("sf",
            Parser::parseStruct("string:>=\"xf}^3;9fOMu;Z&x=yIZ \", float:*"));
    ASSERT_EQ("isisssif",
            Parser::parseStruct("int:>=720, string:<=\"\", int:*, string:<\" 5F#HjP`\", string:>=\"H ^ jtoR\", string:>=\"8s*#:*F,YLpIva0bKznnwEE8(pC1 _Q;JP}yN*tdT+#^L\", int:7, float:<-896.332"));
    ASSERT_EQ("ssisf",
            Parser::parseStruct("string:<\"#eLIec] IZ231Rrcvf=(NR67\", string:<=\"R:HG6'-Ei6\", int:>86, string:<=\" QY2Z;sVqxPfI:m%S%xMG17{G{&l`rIh!s||yrG;nT.`\", float:>-524"));
    ASSERT_EQ("sfsf",
            Parser::parseStruct("string:>\"K}\", float:>=408.700, string:\"Ka55G@o`I8T 6}v5\", float:>-795"));
    ASSERT_EQ("ss",
            Parser::parseStruct("string:<\"pmW3b^ cIp,d5Q.DcFkiP^a%;8bSuT-4w590p*|qA57\", string:>\"}sAzn,]&OX[bk+$'`HA=ud 1sDv]Z#TU.%]h}j~as9$$\""));
    ASSERT_EQ("iisfsfffii",
            Parser::parseStruct("int:>=0, int:<=884, string:>=\"zP{nBWwDd7E'7Q4)N8]~~b[#2XhmuP8Dp\", float:<=184.188, string:\"?p:]7acn@\", float:<-276.5, float:<-80.096, float:<-934.75, int:<-730, int:-55"));
    ASSERT_EQ("sfssssff",
            Parser::parseStruct("string:>=\"v+D\", float:>=-97.399, string:>=\"qd2'g4Lcb18 f09X8p%HaKwhJrTexeyB^HbT\", string:\"fH 9Ba^8JUuuPOvHp%V-\", string:<=\"N\", string:\"s?`~X2aiS!t]OBMwn^Oz:!siqJZ.YUR1\", float:<=133, float:<=-686.48"));
    ASSERT_EQ("iiss",
            Parser::parseStruct("int:>=988, int:*, string:<\"9^49Ji3xt`{1 O+x5quHre4B@a[lMh!pe8$KgzT*,=~\", string:<=\"{dY~7i6`k2SW3UiAkpd;vxz*]|\""));
    ASSERT_EQ("ifsfisi",
            Parser::parseStruct("int:<=-213, float:>-402, string:>=\"V`c^?l83qx!@]16gEjNnpa88ji7\", float:<-293.6, int:>=-565, string:\"H{s+k%wNzwrq39~h\", int:<-525"));
    ASSERT_EQ("ssifsssi",
            Parser::parseStruct("string:<\"(LWSIu5S?7..$R^Lo+LUB\", string:\"4@SnK?X=hosDiH4,1BRvV-x{nx(f*C`[`3Gx=z(s~2u7j#\", int:746, float:<=46.43, string:<\".:6C'Zo{s5|E]p=G8J\", string:*, string:<\"$Q8YfoAn|fwVUol|&JteV:LoF\", int:*"));
    ASSERT_EQ("s",
            Parser::parseStruct("string:>\"7(mG4!qpX47FmCz.T?Zk-in#=7W!FD;'Y7CZ{\""));
    ASSERT_EQ("sssissiif",
            Parser::parseStruct("string:>=\".2Q|m!oZoN&_@x6zc-u vs:PlXki\", string:\"%GF1Txl-GK?jpLB*ikyKBWi!(u\", string:<=\"B:SL\", int:>-118, string:>\"HYj#_ApK s#u#5TO#V8hEpSZb#~uJ*)b:i5?-(]3qcLjI=Wyh\", string:>\"G@R)T:t9Bd*efsl5a|4\", int:<-980, int:*, float:<-621.9202"));
    ASSERT_EQ("sffifsfi",
            Parser::parseStruct("string:>=\"\", float:<606.974, float:>=0, int:<=596, float:<807.44, string:<=\"#9=g {$tOSdF[MeGO#'f~];}n-$S\", float:>=493.659, int:>876"));
    ASSERT_EQ("fissfiifi",
            Parser::parseStruct("float:>=116, int:>=-223, string:<\"P}]1JWafPllwjm0-fN!].]V_\", string:\"ZhO=$ T@;I:0|yxUFs1D#U&LaK;64?MEZL`]t\", float:<-236.354, int:>=-663, int:>=-424, float:<=650.9312, int:-602"));
    ASSERT_EQ("isif",
            Parser::parseStruct("int:522, string:<\"drW+5ZY8mR$2?3y[F?|CM|n$\", int:<=599, float:>-352.6"));
    ASSERT_EQ("fsssiffiis",
            Parser::parseStruct("float:<953.33, string:<=\"v[_Mt[S~l^cT&HMEkzfXZm^p9xEK*RL{d]~[gH+Repv{~D\", string:\"d6t@ZSNl]{#?'zL6oM_$z1]1;'Pt-z|rnS7&E4&[H-h,\", string:\"\", int:>=-739, float:*, float:<=-797.72, int:<=-420, int:83, string:<\"^]H1*LL@RjO=dsVgQDzB\""));
    ASSERT_EQ("fi", Parser::parseStruct("float:<620.85, int:>=32"));
    ASSERT_EQ("ffi",
            Parser::parseStruct("float:<-210.8371, float:<-994.5, int:>-672"));
    ASSERT_EQ("ffffsfi",
            Parser::parseStruct("float:<808.718, float:<=753.8, float:>=668.4, float:<542.4288, string:<=\"i%oli|[,0.3.Bk7zCRezmBd6#ylb1Ra,i%0qNLyU?Lu9O0ow\", float:<-844.148, int:>374"));
    ASSERT_EQ("sf", Parser::parseStruct("string:<=\"4D\", float:<=214.074"));
    ASSERT_EQ("ifif",
            Parser::parseStruct("int:-704, float:>884.22, int:<245, float:>595.5178"));
    ASSERT_EQ("fisisssfi",
            Parser::parseStruct("float:<76.37, int:<260, string:<\"(;\", int:>=338, string:>\"#\", string:>=\"}n~@Zcqy=UrrWVQ`SYQt0s8r*SyaI-VPyHD\", string:>=\"fo.%ICqnr2&rn2uh_v'r@bb_H%\", float:<8.0, int:>-593"));
    ASSERT_EQ("fffsi",
            Parser::parseStruct("float:>=880.566, float:>=862.59, float:<=202.0, string:>=\"(TU&|bQ]*~{.Rhm+xMtaiTCEo@rRy`^N,=~DzK}}rz\", int:<22"));
    ASSERT_EQ("issifiis",
            Parser::parseStruct("int:-586, string:>\"1bBOL|S_Sds0YprudXhsW yyRJ9\", string:>=\"$|'Wq^4!`&o*+oX15dS.;f4lW$Q$;kI=RsS|tjB\", int:<-95, float:*, int:<=832, int:-354, string:>\"^D+CUSH~\""));
    ASSERT_EQ("f", Parser::parseStruct("float:>=-432"));
    ASSERT_EQ("ifisifs",
            Parser::parseStruct("int:<=225, float:<=513.67, int:>=-34, string:>=\"qS}]#8{GM_\", int:<=-220, float:>=618.4156, string:>\"y9&Q4lKZNsE&yE+wI?THT][wSO9SYc^`Z\""));
}

TEST(ParseStructTest, PositiveVariant)
{
    QVariantList list;
    list << QVariant(1) << QVariant(-1) << QVariant(23.0f) << QVariant(-0.4f)
            << QVariant("Str") << QVariant("!@$ GDSFsa sd");
    ASSERT_EQ("iiffss", Parser::parseStruct(list));

    list.clear();
    list << QVariant(21.f) << QVariant("strin ") << QVariant(32);
    ASSERT_EQ("fsi", Parser::parseStruct(list));
}

TEST(ParseStructTest, NegativeThrow) {
    ASSERT_THROW(Parser::parseStruct("string:sdfs"), const char*);
    ASSERT_THROW(Parser::parseStruct("fgsdio"), const char*);
    ASSERT_THROW(Parser::parseStruct("string:*, float:43"), const char*);
    ASSERT_THROW(Parser::parseStruct("ints: sdada"), const char*);
    ASSERT_THROW(Parser::parseStruct("n sdfio nds"), const char*);
    ASSERT_THROW(Parser::parseStruct("double:>2, int:5"), const char*);

    QVariantList list;
    list << QVariant(1) << QVariant(-1) << QVariant(23.0) << QVariant(-0.4f)
            << QVariant("Str") << QVariant("!@$ GDSFsa sd");
    ASSERT_THROW(Parser::parseStruct(list), const char*);

    list.clear();
    list << QVariant(21.f) << QVariant("strin ") << QVariant(32) <<QVariant(0.0);
    ASSERT_THROW(Parser::parseStruct(list), const char*);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
