/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_get_next_chunk.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zmsg_get_next_chunk_part_0(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int extraout_a1;
  uint __n;
  undefined4 *puVar10;
  uint uVar11;
  
  iVar8 = __assert_func(0,0,0,0);
  uVar1 = *(ushort *)(iVar8 + 0xc);
  uVar2 = *(ushort *)(iVar8 + 0x10);
  piVar5 = (int *)(iVar8 + 8);
  uVar11 = 0;
  piVar6 = piVar5;
  do {
    if ((extraout_a1 + (uint)uVar1 + (uint)uVar2 & 0xffff) <= uVar11) {
      piVar4 = piVar5;
      if (piVar5 == piVar6) {
        while (piVar3 = piVar4, piVar3 != (int *)0x0) {
          piVar6 = piVar3;
          piVar4 = (int *)*piVar3;
        }
      }
      __n = (uint)*(ushort *)(iVar8 + 0x10);
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
      puVar9 = (undefined4 *)mempool_malloc(0);
      *piVar5 = (int)puVar9;
      if (puVar9 == (undefined4 *)0x0) {
        uVar7 = 1;
_L0:
        puVar9 = (undefined4 *)*piVar5;
        while (puVar9 != (undefined4 *)0x0) {
          puVar10 = (undefined4 *)*puVar9;
          *puVar9 = 0;
          mempool_free(0);
          puVar9 = puVar10;
        }
        *piVar5 = 0;
        return uVar7;
      }
      *puVar9 = 0;
    }
    else {
      piVar6 = (int *)*piVar6;
    }
    piVar5 = (int *)*piVar5;
    uVar11 = uVar11 + 0xac & 0xffff;
  } while( true );
}

