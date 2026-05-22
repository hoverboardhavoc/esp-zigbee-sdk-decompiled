/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_ctx_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_ctx_clear(void)

{
  _Bool _Var1;
  undefined3 extraout_var;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aaStack_18 [2];
  
  aps_secur_key_pair_set_clear();
  _Var1 = aps_secur_is_centralized();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    return;
  }
  aaStack_18[0].u64._4_4_ = 0;
  aaStack_18[0].u64._0_4_ = 0;
  aps_secur_set_tc_address((ezb_extaddr_t *)aaStack_18);
  return;
}

