typedef int8_t;
typedef int32_t;
typedef uint32_t;
struct S0 {
  int8_t f0;
  int8_t f1;
  int32_t f3;
};
static g_81[];
struct S0 g_152[];
func_129(int32_t p_130, struct S0 p_131, uint32_t p_132) {
  struct S0 l_151;
  int32_t l_195;
  for (; l_195; l_195 += 1)
    for (p_132 = 0; p_132 <= 39; ++p_132) {
      int32_t l_164;
      for (p_131.f0 = 0; p_131.f0 <= 2; p_131.f0 += 1) {
        g_152[0] = l_151;
        l_151.f3 = g_81[p_131.f0];
        struct S0 l_196;
        l_195 = g_152[0].f3 && p_131.f1;
        for (; l_164; l_164 += 1)
          g_152[0] = l_196;
      }
    }
}
