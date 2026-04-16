/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_secur_handle_tick(void)

{
  uint16_t uVar1;
  bool bVar2;
  int iVar3;
  aps_device_key_pair_t *key_pair;
  uint uVar4;
  
  iVar3 = core_globals_get();
  uVar4 = 0;
  bVar2 = true;
  while( true ) {
    uVar4 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar3 + 0x9a4),*(undefined2 *)(iVar3 + 0x9a8),uVar4);
    if (*(ushort *)(iVar3 + 0x9a8) <= uVar4) break;
    key_pair = (aps_device_key_pair_t *)(*(int *)(iVar3 + 0x9a0) + uVar4 * 0x38);
    uVar1 = key_pair->timeout;
    if (uVar1 != 0xffff) {
      if ((uVar1 == 0) || (key_pair->timeout = uVar1 - 1, (uint16_t)(uVar1 - 1) == 0)) {
        aps_secur_delete_key_pair(key_pair);
      }
      else {
        bVar2 = false;
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  if (bVar2) {
    time_ticker_unregister_receiver(3);
    return;
  }
  return;
}

