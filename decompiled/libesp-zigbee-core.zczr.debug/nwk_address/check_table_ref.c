/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> check_table_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool check_table_ref(uint16_t ref,bitmap_t *table_map,uint16_t table_size)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  uint n;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 in_register_00002032;
  
  n = CONCAT22(in_register_0000202a,ref);
  if ((n < CONCAT22(in_register_00002032,table_size)) &&
     (_Var1 = test_bitmap(n,table_map), CONCAT31(extraout_var,_Var1) != 0)) {
    if (CONCAT22(in_register_00002032,table_size) <= n) {
      return false;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_address.c",0x47,"check_table_ref",
                  "(ref < table_size) && test_bitmap(ref, table_map)");
  }
  _Var1 = test_bitmap(n,table_map);
  return CONCAT31(extraout_var_00,_Var1) != 0;
}

