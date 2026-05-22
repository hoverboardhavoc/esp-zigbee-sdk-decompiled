/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_init(void)

{
  int iVar1;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aaStack_18 [2];
  
  iVar1 = core_globals_get();
  memset((void *)(iVar1 + 0x990),0,0x44);
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9b4) = 10;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9c0) = 1;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9c1) = 5;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0x9d0) = 0xc;
  aps_secur_key_pair_set_init(0x40);
  aaStack_18[0].u64._4_4_ = 0;
  aaStack_18[0].u64._0_4_ = 0;
  aps_secur_set_tc_address((ezb_extaddr_t *)aaStack_18);
  return;
}

