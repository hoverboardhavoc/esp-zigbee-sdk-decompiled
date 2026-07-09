/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_delete_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_delete_key_pair(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  aps_secur_remove_stored_key_pair();
  iVar1 = core_globals_get();
  uVar4 = *(uint *)(iVar1 + 0x9a0);
  iVar1 = core_globals_get();
  iVar5 = *(int *)(iVar1 + 0x9a4);
  iVar1 = core_globals_get();
  uVar3 = (uint)*(ushort *)(iVar1 + 0x9a8);
  if (uVar4 <= param_1) goto _L0;
  do {
    do {
      __assert_func(0,0,0,0);
_L0:
      uVar2 = (int)(param_1 - uVar4) / 0x38;
    } while (uVar3 <= (uVar2 & 0xffff));
    param_1 = 1 << (uVar2 & 7) & 0xff;
    uVar2 = __atomic_fetch_and_1(((uVar2 << 0x10) >> 0x13) + iVar5,~param_1 & 0xff,5);
    param_1 = param_1 & uVar2;
  } while (param_1 == 0);
  return;
}

