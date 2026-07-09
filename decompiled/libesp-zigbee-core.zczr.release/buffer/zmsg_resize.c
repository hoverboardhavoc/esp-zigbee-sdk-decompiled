/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_resize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zmsg_resize(int param_1,short param_2)

{
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint __n;
  ushort uVar7;
  
  sVar1 = *(short *)(param_1 + 0xc);
  sVar2 = *(short *)(param_1 + 0x10);
  puVar3 = (undefined4 *)(param_1 + 8);
  uVar7 = 0;
  puVar5 = puVar3;
  do {
    if ((ushort)(param_2 + sVar1 + sVar2) <= uVar7) {
      puVar6 = puVar3;
      if (puVar3 == puVar5) {
        do {
          puVar5 = puVar6;
          puVar6 = (undefined4 *)*puVar5;
        } while ((undefined4 *)*puVar5 != (undefined4 *)0x0);
      }
      __n = (uint)*(ushort *)(param_1 + 0x10);
      if (__n != 0) {
        if (0xac < __n) {
          buffer_get_tail_part_0();
          goto _L0;
        }
        memmove((void *)((0xb0 - __n) + (int)puVar3),(void *)((int)puVar5 + (0xb0 - __n)),__n);
      }
      uVar4 = 0;
      goto _L0;
    }
_L0:
    if ((undefined4 *)*puVar3 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)mempool_malloc();
      *puVar3 = puVar6;
      if (puVar6 == (undefined4 *)0x0) {
        uVar4 = 1;
_L0:
        puVar5 = (undefined4 *)*puVar3;
        while (puVar5 != (undefined4 *)0x0) {
          puVar6 = (undefined4 *)*puVar5;
          *puVar5 = 0;
          mempool_free(0);
          puVar5 = puVar6;
        }
        *puVar3 = 0;
        return uVar4;
      }
    }
    else {
      puVar5 = (undefined4 *)*puVar5;
      puVar6 = (undefined4 *)*puVar3;
    }
    puVar3 = puVar6;
    uVar7 = uVar7 + 0xac;
  } while( true );
}

