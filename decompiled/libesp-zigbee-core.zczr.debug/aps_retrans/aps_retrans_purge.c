/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_purge
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_retrans_purge(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  ushort auStack_22 [7];
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(iVar2 + 0x454,0x20,uVar3);
    uVar3 = uVar3 & 0xff;
    if (0x1f < uVar3) break;
    if ((param_1 == 0xffff) || (*(ushort *)(uVar3 * 0x20 + iVar2 + 0x58) == param_1)) {
      aps_retrans_send_confirm(iVar2 + uVar3 * 0x20 + 0x54,8);
    }
    uVar3 = uVar3 + 1 & 0xff;
  }
  puVar1 = *(undefined4 **)(iVar2 + 0x48);
  while ((undefined4 *)(iVar2 + 0x48) != puVar1) {
    zmsg_get_footer(puVar1,auStack_22,2);
    if ((param_1 == 0xffff) || (puVar4 = puVar1, auStack_22[0] == param_1)) {
      puVar4 = (undefined4 *)puVar1[1];
      zmsg_queue_dequeue(iVar2 + 0x48,puVar1);
      zmsg_remove_footer(puVar1,2);
      zmsg_remove_footer(puVar1,1);
      aps_send_frame_confirm(puVar1,8);
    }
    puVar1 = (undefined4 *)*puVar4;
  }
  return;
}

