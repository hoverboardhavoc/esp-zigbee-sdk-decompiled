/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_get_key_by_seq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_secur_get_key_by_seq(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = nwk_secur_find_slot_by_seq(iVar1 + 0x9fc,param_1);
  if (uVar2 < 2) {
    iVar1 = iVar1 + uVar2 * 0x11 + 0xa00;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

