#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <cblas.h>
#include <stdlib.h>
#include "../src/mvn.c"

static void test_mvn_logpdf0() {
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma[] = { 13.448159045144756,  9.262621609097568, -4.625091506787965, 10.644757941358025,
                      9.262621609097568, 11.603005022466061, -1.117456379707958, 10.081095682477658,
                     -4.625091506787965, -1.117456379707958,  4.506432405029324, -2.394987833402893,
                     10.644757941358025, 10.081095682477658, -2.394987833402893, 11.378597393300055 };
  double x[] = { 3.777784496859424, 1.684446306406535, -1.020582429866464, 2.852571408797254, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.947891684361871, 1.0e-07);
}

static void test_mvn_logpdf1() {
  double mu[] = { 0.488893770311789, 1.034693009917860, 0.726885133383238, -0.303440924786016 };
  double sigma[] = {  1.345046900251238, 0.413079876608304,  3.821104132525598, -2.463089753533145,
                      0.413079876608304, 1.903315790354978,  0.572426884866194,  0.955235031519136,
                      3.821104132525598, 0.572426884866194, 11.437667056415835, -7.499474265063946,
                     -2.463089753533145, 0.955235031519136, -7.499474265063946,  6.411876650556795 };
  double x[] = { -2.401214863102444, 1.875121560367923, 0.703893009242159, 0.001809323156231, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -258.775212615819271, 1.0e-07);
}

static void test_mvn_logpdf2() {
  double mu[] = { 1.093265669039484, 1.109273297614398, -0.863652821988714, 0.077359091130425 };
  double sigma[] = {  5.637117231365240,  1.163321321329860, -2.723128440559655, -5.065690130633797,
                      1.163321321329860,  1.386250271980310, -0.186335702507454, -1.319576348742758,
                     -2.723128440559655, -0.186335702507454,  2.581062999690693,  1.452771508575535,
                     -5.065690130633797, -1.319576348742758,  1.452771508575535,  5.359795272122508 };
  double x[] = { -1.165578217939301, 3.218092550683545, -2.154662542689270, 0.197980389002762, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -295.398490010123794, 1.0e-07);
}

static void test_mvn_logpdf3() {
  double mu[] = { -0.192418510588264, 0.888610425420721, -0.764849236567874, -1.402268969338759 };
  double sigma[] = {  4.731273637091657, -1.092394890745478, -0.386329685788648, 2.750978068199349,
                     -1.092394890745478,  2.167832390107410,  1.891161727053351, 0.075190657937774,
                     -0.386329685788648,  1.891161727053351,  2.085758985083697, 0.024924596611678,
                      2.750978068199349,  0.075190657937774,  0.024924596611678, 2.629621146094861 };
  double x[] = { 0.435486595591178, 3.694968094597533, -1.295381644079699, -1.303384713477604, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -68.391938315208805, 1.0e-07);
}

static void test_mvn_logpdf4() {
  double mu[] = { -0.082494425370955, -1.933022917850987, -0.438966153934773, -1.794678841455123 };
  double sigma[] = {  5.563841478777587, -2.713145208452899, -2.126091368696406, -1.502441269016176,
                     -2.713145208452899,  2.336193869994514, -0.998211531588691,  0.069683124545366,
                     -2.126091368696406, -0.998211531588691,  5.746080189309868,  2.222304004375298,
                     -1.502441269016176,  0.069683124545366,  2.222304004375298,  1.563467201677911 };
  double x[] = { 6.509388812605171, -2.711549450068536, -1.036498185568444, -2.734558121332821, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -38.482498473538847, 1.0e-07);
}

static void test_mvn_logpdf5() {
  double mu[] = { 2.908008030729362, 0.825218894228491, 1.378971977916614, -1.058180257987362 };
  double sigma[] = {  4.977566690319046, -3.616567361999817, -1.674710838110257, -0.101506889659740,
                     -3.616567361999817,  5.813466791241152,  0.964813424208664,  1.445372149658658,
                     -1.674710838110257,  0.964813424208664,  1.533887093883376, -0.109081254487404,
                     -0.101506889659740,  1.445372149658658, -0.109081254487404,  0.846068968465308 };
  double x[] = { 4.710550244971232, 0.385170332242688, -0.317190391898652, -1.201627970833518, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -5.869592466035105, 1.0e-07);
}

static void test_mvn_logpdf6() {
  double mu[] = { -0.831366511567624, -0.979206305167302, -1.156401655664002, -0.533557109315987 };
  double sigma[] = {  4.608603450203692, -2.619771794458920, -0.587264319651041, -0.276401879789209,
                     -2.619771794458920,  4.112025896948845,  0.334413531596105, -2.850848982530037,
                     -0.587264319651041,  0.334413531596105,  2.613391652037389, -2.843169439047864,
                     -0.276401879789209, -2.850848982530037, -2.843169439047864,  6.745777655301490 };
  double x[] = { 2.802629189559364, 1.125861752948257, -1.596178367941324, -0.647408993890239, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -705.446602776540431, 1.0e-07);
}

static void test_mvn_logpdf7() {
  double mu[] = { -0.176534114231451, 0.791416061628634, -1.332004421315247, -2.329867155805076 };
  double sigma[] = {  4.276638314511500, -0.552440738377919,  0.032796801027512,  0.386049222610469,
                     -0.552440738377919,  1.431732443150110, -1.504459212954794,  1.466539176337116,
                      0.032796801027512, -1.504459212954794,  2.349303176856232, -1.358427075480577,
                      0.386049222610469,  1.466539176337116, -1.358427075480577,  2.648505199045618 };
  double x[] = { 1.163055400867982, 0.680448475594091, -1.575886030484648, -2.522561686924847, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -4.545736055402437, 1.0e-07);
}

static void test_mvn_logpdf8() {
  double mu[] = { -0.303107621351741, 0.023045624425105, 0.051290355848775, 0.826062790211595 };
  double sigma[] = {  2.409855816717180,  0.617644532465503, -0.024602986982356,  0.610579147511600,
                      0.617644532465503,  1.565241026515496, -0.863004640740354, -0.755068114287319,
                     -0.024602986982356, -0.863004640740354,  1.296371140304045, -0.980649463617985,
                      0.610579147511600, -0.755068114287319, -0.980649463617985,  4.201017964875745 };
  double x[] = { -2.305618131728087, 0.865808956761387, 1.465435032693611, 0.051434217976655, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -37.064643570968364, 1.0e-07);
}

static void test_mvn_logpdf9() {
  double mu[] = { -0.192239517539275, -0.274070229932602, 1.530072514424096, -0.249024742513714 };
  double sigma[] = {  4.367903602208544, -0.450006330287706, -0.700047331686692,  0.459093585365624,
                     -0.450006330287706,  3.514630437371984,  2.599212172251052, -0.807941805358519,
                     -0.700047331686692,  2.599212172251052,  1.960209938147062, -0.653905313031246,
                      0.459093585365624, -0.807941805358519, -0.653905313031246,  1.795908371223251 };
  double x[] = { 0.912064984729237, -7.043002264181975, 1.096429059824819, 1.262030555024653, };

  double res;
  gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res);

  CU_ASSERT_DOUBLE_EQUAL(res, -1691.658265773746280, 1.0e-07);
}

#define CUNIT_ERROR(message) \
  do { \
    CU_cleanup_registry(); \
    fprintf(stderr, "%s\nCUnit error code %d in %s (%s:%d): %s\n", \
                     message, CU_get_error(), __func__, __FILE__, __LINE__, \
                     CU_get_error_msg()); \
    return CU_get_error(); \
  } while (0)

int main() {
  CU_ErrorCode error = CU_initialize_registry();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to initialise test registry");

  CU_pSuite pdf = CU_add_suite("gmcmc_mvn_logpdf", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(pdf, test_mvn_logpdf0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf5);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf6);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf7);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf8);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(pdf, test_mvn_logpdf9);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
