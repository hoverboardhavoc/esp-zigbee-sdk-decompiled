/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  int iVar6;
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
      iVar6 = mempool_malloc(0);
      *piVar5 = iVar6;
      if (iVar6 == 0) {
        uVar4 = 1;
        goto _L0;
      }
    }
    else {
      piVar7 = (int *)*piVar7;
    }
    piVar5 = (int *)*piVar5;
    uVar3 = uVar3 + 0xac;
  } while( true );
}

