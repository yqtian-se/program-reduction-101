typedef int int32_t;
typedef unsigned int uint32_t;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;

int a, f, g, h;
struct b {
  int c;
} e;
int d[10];
int g_table[5];
int g_step;

int safe_lshift_func_uint8_t_u_s(uint8_t left, int right) {
  return left > right ? (int)left : (int)(left << right);
}

int safe_mod_func_int32_t_s_s(int32_t si1, int32_t si2) {
  if (si2 == 0)
    return 0;
  return si1 % si2;
}

int safe_add_func_int32_t_s_s(int32_t a, int32_t b) {
  return a + b;
}

void func_init(int32_t seed) {
  g_step = seed;
  g_table[0] = 0;
  g_table[1] = 1;
}

int32_t func_helper(int32_t p_val, uint8_t p_shift) {
  int32_t l_result;
  l_result = safe_lshift_func_uint8_t_u_s(p_shift, 2);
  return safe_mod_func_int32_t_s_s(p_val, l_result + 1);
}

int i() {
  struct b j;
  int32_t l_count;
  int32_t l_tmp;
  uint8_t l_buf[7];

  l_count = 0;
  l_tmp = safe_add_func_int32_t_s_s(g_step, 1);

  for (;;) {
    g = 0;
    for (; g <= 39; ++g) {
      h = 0;
      for (; h <= 2; h++) {
        e = j;
        j.c = d[h];
        f = e.c ? e.c : a;
      }
    }
  }
  return l_tmp;
}
