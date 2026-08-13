/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint __n;
  undefined4 *puVar9;
  ushort uVar10;
  
  sVar1 = *(short *)(param_1 + 0xc);
  sVar2 = *(short *)(param_1 + 0x10);
  piVar5 = (int *)(param_1 + 8);
  uVar10 = 0;
  piVar6 = piVar5;
  do {
    if ((ushort)(param_2 + sVar1 + sVar2) <= uVar10) {
      piVar4 = piVar5;
      if (piVar5 == piVar6) {
        while (piVar3 = piVar4, piVar3 != (int *)0x0) {
          piVar6 = piVar3;
          piVar4 = (int *)*piVar3;
        }
      }
      __n = (uint)*(ushort *)(param_1 + 0x10);
      if (__n != 0) {
        if (0xac < __n) {
          buffer_get_tail_part_0();
          goto _L0;
        }
        memmove((void *)((0xb0 - __n) + (int)piVar5),(void *)((int)piVar6 + (0xb0 - __n)),__n);
      }
      uVar7 = 0;
      goto _L0;
    }
_L0:
    if (*piVar5 == 0) {
      puVar8 = (undefined4 *)mempool_malloc(0);
      *piVar5 = (int)puVar8;
      if (puVar8 == (undefined4 *)0x0) {
        uVar7 = 1;
_L0:
        puVar8 = (undefined4 *)*piVar5;
        while (puVar8 != (undefined4 *)0x0) {
          puVar9 = (undefined4 *)*puVar8;
          *puVar8 = 0;
          mempool_free(0);
          puVar8 = puVar9;
        }
        *piVar5 = 0;
        return uVar7;
      }
      *puVar8 = 0;
    }
    else {
      piVar6 = (int *)*piVar6;
    }
    uVar10 = uVar10 + 0xac;
    piVar5 = (int *)*piVar5;
  } while( true );
}

