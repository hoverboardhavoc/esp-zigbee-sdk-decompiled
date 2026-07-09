/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_switch_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_secur_switch_key(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = core_globals_get();
  uVar2 = nwk_secur_find_slot_by_seq(iVar1 + 0x9fc,param_1);
  if (uVar2 < 2) {
    *(byte *)(iVar1 + 0xa23) = (byte)uVar2 & 1 | *(byte *)(iVar1 + 0xa23) & 0xfe;
    *(char *)(iVar1 + 0xa22) = (char)param_1;
    if (0x80000000 < *(uint *)(iVar1 + 0x9fc)) {
      *(undefined4 *)(iVar1 + 0x9fc) = 0;
    }
    ds_save_common_data();
    uVar3 = 0;
  }
  else {
    uVar3 = 5;
  }
  return uVar3;
}

