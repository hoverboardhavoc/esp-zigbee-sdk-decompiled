/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_get_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_get_panid(int param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  iVar2 = check_table_ref(param_1,iVar1 + 0xc48,0x10);
  if (iVar2 != 0) {
    *param_2 = *(undefined2 *)(iVar1 + param_1 * 10 + 0xbb0);
  }
  return;
}

