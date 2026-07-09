/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_dup.o -> aps_dup_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_dup_table_handle_tick(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  
  iVar2 = core_globals_get();
  bVar1 = true;
  uVar5 = 0;
  while( true ) {
    uVar5 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0x988),*(undefined2 *)(iVar2 + 0x98c),uVar5);
    uVar6 = (uint)*(ushort *)(iVar2 + 0x98c);
    if (uVar6 <= uVar5) break;
    uVar4 = *(uint *)(iVar2 + 0x984);
    iVar3 = uVar5 * 4;
    uVar7 = uVar4 + iVar3;
    uVar8 = (*(ushort *)(uVar7 + 2) >> 8) + 0x3f & 0x3f;
    *(byte *)(uVar7 + 3) = *(byte *)(uVar7 + 3) & 0xc0 | (byte)uVar8;
    if (uVar8 == 0) {
      if (uVar4 <= uVar7) goto _L0;
      do {
        uVar6 = 0;
        iVar3 = __assert_func(0,0,0);
_L0:
        uVar4 = iVar3 >> 2;
      } while ((uVar6 <= (uVar4 & 0xffff)) ||
              (uVar6 = 1 << (uVar4 & 7) & 0xff,
              uVar4 = __atomic_fetch_and_1((uVar4 >> 3) + *(int *)(iVar2 + 0x988),~uVar6 & 0xff,5),
              (uVar6 & uVar4) == 0));
    }
    else {
      bVar1 = false;
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  if (bVar1) {
    time_ticker_unregister_receiver(4);
    return;
  }
  return;
}

