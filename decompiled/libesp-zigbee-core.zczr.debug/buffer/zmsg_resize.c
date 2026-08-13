/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_resize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zmsg_resize(int param_1,short param_2)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  piVar5 = (int *)(param_1 + 8);
  sVar1 = *(short *)(param_1 + 0xc);
  sVar2 = *(short *)(param_1 + 0x10);
  uVar3 = 0;
  piVar7 = piVar5;
  do {
    if ((ushort)(sVar2 + sVar1 + param_2) <= uVar3) {
      if (piVar5 == piVar7) {
        piVar7 = (int *)buffers_get_last(piVar5);
      }
      buffer_move_tail(piVar5,piVar7,*(undefined2 *)(param_1 + 0x10));
      uVar4 = 0;
_L0:
      free_bufpool_buffers(*piVar5);
      *piVar5 = 0;
      return uVar4;
    }
    if (*piVar5 == 0) {
      puVar6 = (undefined4 *)mempool_malloc(0);
      *piVar5 = (int)puVar6;
      if (puVar6 == (undefined4 *)0x0) {
        uVar4 = 1;
        goto _L0;
      }
      *puVar6 = 0;
    }
    else {
      piVar7 = (int *)*piVar7;
    }
    piVar5 = (int *)*piVar5;
    uVar3 = uVar3 + 0xac;
  } while( true );
}

