/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_handle_tick(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = core_globals_get();
  uVar5 = 0;
  bVar2 = true;
  while( true ) {
    uVar5 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar3 + 0x9a4),*(undefined2 *)(iVar3 + 0x9a8),uVar5);
    if (*(ushort *)(iVar3 + 0x9a8) <= uVar5) break;
    iVar4 = *(int *)(iVar3 + 0x9a0) + uVar5 * 0x38;
    sVar1 = *(short *)(iVar4 + 0x10);
    if (sVar1 != -1) {
      if (sVar1 != 0) {
        *(short *)(iVar4 + 0x10) = sVar1 + -1;
      }
      if (*(short *)(iVar4 + 0x10) == 0) {
        aps_secur_delete_key_pair();
      }
      else {
        bVar2 = false;
      }
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  if (bVar2) {
    time_ticker_unregister_receiver(3);
  }
  return;
}

