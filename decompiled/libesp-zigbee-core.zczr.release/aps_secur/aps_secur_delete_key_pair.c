/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_delete_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_delete_key_pair(aps_device_key_pair_t *key_pair)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  aps_device_key_pair_t *paVar5;
  int iVar6;
  
  aps_secur_remove_stored_key_pair(key_pair);
  iVar2 = core_globals_get();
  paVar5 = *(aps_device_key_pair_t **)(iVar2 + 0x9a0);
  iVar2 = core_globals_get();
  iVar6 = *(int *)(iVar2 + 0x9a4);
  iVar2 = core_globals_get();
  uVar4 = (uint)*(ushort *)(iVar2 + 0x9a8);
  if (paVar5 <= key_pair) goto _L0;
  do {
    do {
      __assert_func(0,0,0,0);
_L0:
      uVar3 = ((int)key_pair - (int)paVar5) / 0x38;
    } while (uVar4 <= (uVar3 & 0xffff));
    uVar1 = 1 << (uVar3 & 7) & 0xff;
    uVar3 = __atomic_fetch_and_1(((uVar3 << 0x10) >> 0x13) + iVar6,~uVar1 & 0xff,5);
    key_pair = (aps_device_key_pair_t *)(uVar1 & uVar3);
  } while (key_pair == (aps_device_key_pair_t *)0x0);
  return;
}

