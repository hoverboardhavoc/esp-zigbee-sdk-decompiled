/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x46,
                  "check_table_ref","(ref < table_size) && test_bitmap(ref, table_map)");
  }
  _Var1 = test_bitmap(n,table_map);
  return CONCAT31(extraout_var_00,_Var1) != 0;
}

