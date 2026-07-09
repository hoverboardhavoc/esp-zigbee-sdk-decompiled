/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_purge
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_purge(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ushort auStack_22 [3];
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(iVar2 + 0x454,0x20,uVar3);
    uVar3 = uVar3 & 0xff;
    if (0x1f < uVar3) break;
    if ((param_1 == 0xffff) || (*(ushort *)(iVar2 + uVar3 * 0x20 + 0x58) == param_1)) {
      aps_retrans_send_confirm(uVar3 * 0x20 + 0x54 + iVar2,8);
    }
    uVar3 = uVar3 + 1 & 0xff;
  }
  piVar1 = *(int **)(iVar2 + 0x48);
  while ((int *)(iVar2 + 0x48) != piVar1) {
    zmsg_get_footer(piVar1,auStack_22,2);
    if ((param_1 == 0xffff) || (piVar4 = piVar1, auStack_22[0] == param_1)) {
      piVar4 = (int *)piVar1[1];
      zmsg_queue_dequeue(iVar2 + 0x48,piVar1);
      zmsg_remove_footer(piVar1,2);
      zmsg_remove_footer(piVar1,1);
      aps_send_frame_confirm(piVar1,8);
    }
    piVar1 = (int *)*piVar4;
  }
  return;
}

