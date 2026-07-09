/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_refresh_stored_key_pairs
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_refresh_stored_key_pairs(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = ds_internal_remove_entry(9,0xffffffff,0);
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    uVar3 = 0;
    while ((uVar3 = bitmap_find_next_bit
                              (*(undefined4 *)(iVar1 + 0x9a4),*(undefined2 *)(iVar1 + 0x9a8),uVar3),
           uVar3 < *(ushort *)(iVar1 + 0x9a8) &&
           (iVar2 = aps_secur_store_key_pair(*(int *)(iVar1 + 0x9a0) + uVar3 * 0x38), iVar2 == 0)))
    {
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  return;
}

