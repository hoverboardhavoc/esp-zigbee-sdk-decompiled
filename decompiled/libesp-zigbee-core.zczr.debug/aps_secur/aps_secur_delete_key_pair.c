/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_delete_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_delete_key_pair(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  aps_secur_remove_stored_key_pair();
  iVar1 = core_globals_get();
  uVar2 = *(undefined4 *)(iVar1 + 0x9a0);
  iVar1 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar1 + 0x9a4);
  iVar1 = core_globals_get();
  mempool_free_ent(uVar2,uVar3,0x38,*(undefined2 *)(iVar1 + 0x9a8),param_1);
  return;
}

