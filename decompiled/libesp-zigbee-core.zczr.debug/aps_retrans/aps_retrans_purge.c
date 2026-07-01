/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_purge
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_purge(ezb_shortaddr_t dst_addr)

{
  undefined4 *puVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  ushort auStack_22 [2];
  ezb_shortaddr_t msg_dst_addr;
  
  uVar2 = CONCAT22(in_register_0000202a,dst_addr);
  iVar3 = core_globals_get();
  uVar4 = 0;
  while( true ) {
    uVar4 = bitmap_find_next_bit(iVar3 + 0x454,0x20,uVar4);
    uVar4 = uVar4 & 0xff;
    if (0x1f < uVar4) break;
    if ((uVar2 == 0xffff) || (*(ushort *)(uVar4 * 0x20 + iVar3 + 0x58) == uVar2)) {
      aps_retrans_send_confirm((aps_retrans_ent_t *)(iVar3 + uVar4 * 0x20 + 0x54),8);
    }
    uVar4 = uVar4 + 1 & 0xff;
  }
  puVar1 = *(undefined4 **)(iVar3 + 0x48);
  while ((undefined4 *)(iVar3 + 0x48) != puVar1) {
    zmsg_get_footer(puVar1,auStack_22,2);
    if ((uVar2 == 0xffff) || (puVar5 = puVar1, auStack_22[0] == uVar2)) {
      puVar5 = (undefined4 *)puVar1[1];
      zmsg_queue_dequeue(iVar3 + 0x48,puVar1);
      zmsg_remove_footer(puVar1,2);
      zmsg_remove_footer(puVar1,1);
      aps_send_frame_confirm(puVar1,8);
    }
    puVar1 = (undefined4 *)*puVar5;
  }
  return;
}

