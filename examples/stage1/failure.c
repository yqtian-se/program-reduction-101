typedef int8_t;
typedef int16_t;
typedef int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef uint32_t;
uint8_t safe_lshift_func_uint8_t_u_s(uint8_t left, int right) {
  return left > right ? left : left << right;
}
safe_div_func_uint16_t_u_u() {}
safe_rshift_func_uint16_t_u_u(uint16_t left, unsigned right) {
  return right ? left : right;
}
safe_sub_func_uint32_t_u_u(uint32_t ui1, uint32_t ui2) { return; }
struct S0 {
  int8_t f0;
  int8_t f1;
  int32_t f3;
};
static g_4 = {0xD4A0D461L};
static g_32;
static g_80;
static g_81[];
struct S0 g_152[];
static g_203;
static struct S0 func_76(uint32_t, int16_t, uint8_t);
static uint8_t func_99();
static struct S0 func_129(int32_t, struct S0, uint32_t, int16_t);
func_1() {
  int16_t l_2;
  func_76(l_2, g_81[2] |= g_32, l_2);
}
struct S0 func_76(uint32_t p_77, int16_t p_78, uint8_t p_79) { func_99(p_78); }
uint8_t func_99(p_100) {
  uint8_t l_110;
  struct S0 l_147 = {5L};
  uint32_t l_148;
  if (func_129(p_100, l_147, l_148, l_110), p_100)
    ;
}
struct S0 func_129(int32_t p_130, struct S0 p_131, uint32_t p_132,
                   int16_t p_133) {
  struct S0 l_151;
  int32_t l_195;
  for (; l_195; l_195 += 1)
    for (p_132 = 0; p_132 <= 39; ++p_132) {
      int32_t l_164;
      for (p_131.f0 = 0; p_131.f0 <= 2; p_131.f0 += 1) {
        g_152[0] = l_151;
        l_151.f3 = g_81[p_131.f0];
        struct S0 l_196;
        g_80 =
            safe_rshift_func_uint16_t_u_u(
                g_4,
                safe_sub_func_uint32_t_u_u(
                    g_4, l_195 = safe_lshift_func_uint8_t_u_s(g_152[0].f3, 2) &&
                                 p_131.f1)) < p_131.f1;
        for (; l_164; l_164 += 1)
          g_152[0] = l_196;
      }
    }
  return p_131;
}
