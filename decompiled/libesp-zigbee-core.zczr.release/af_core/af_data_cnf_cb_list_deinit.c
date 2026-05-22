/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_cnf_cb_list_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void af_data_cnf_cb_list_deinit(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = core_globals_get();
  while( true ) {
    puVar2 = *(undefined4 **)(iVar1 + 0xca4);
    if (puVar2 == (undefined4 *)0x0) break;
    *(undefined4 *)(iVar1 + 0xca4) = *puVar2;
    *puVar2 = puVar2;
    mm_free(puVar2 + -3);
    iVar1 = core_globals_get();
  }
  return;
}

