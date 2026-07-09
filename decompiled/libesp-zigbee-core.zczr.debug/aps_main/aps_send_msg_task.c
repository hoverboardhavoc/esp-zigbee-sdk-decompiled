/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_msg_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_msg_task(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uStack_4c;
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined1 uStack_46;
  undefined1 uStack_45;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined1 auStack_40 [4];
  char cStack_3c;
  undefined2 uStack_3a;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2a;
  uint uStack_28;
  undefined2 auStack_22 [5];
  
  iVar2 = zmsg_queue_get_head(param_1 + 0x10);
  if (iVar2 == 0) goto _L0;
  iVar3 = core_globals_get();
  zmsg_queue_dequeue(iVar3 + 0x2c,iVar2);
  zmsg_get_footer(iVar2,auStack_22,2);
  zmsg_remove_footer(iVar2,2);
  zmsg_get_footer(iVar2,auStack_40,0x1c);
  uVar4 = aps_get_max_asdu(0,uStack_28 & 1,uStack_28 >> 3 & 1);
  uVar5 = zmsg_get_length(iVar2);
  bVar1 = uVar4 < uVar5;
  if (bVar1) {
    uVar4 = uVar4 - 2 & 0xffff;
  }
  if ((uStack_28 & 0x10) == 0) {
    uStack_2a = aps_get_shortaddr();
  }
  uStack_4a = auStack_22[0];
  if (cStack_3c != '\x01') {
    uStack_3a = 0;
  }
  uStack_46 = uStack_32;
  uStack_45 = uStack_31;
  uStack_44 = uStack_30;
  uStack_42 = uStack_2e;
  uStack_4c = uStack_2a;
  uStack_48 = uStack_3a;
  zmsg_set_offset(iVar2,0);
  iVar3 = aps_frame_prepend_data_hdr
                    (iVar2,&uStack_4c,uStack_28 >> 1 & 1,uStack_28 & 1,bVar1,uStack_28 >> 3 & 1);
  if (iVar3 == 0) {
    uVar6 = aps_is_shortaddr_loopback(auStack_22[0],0);
    uVar7 = (uVar6 ^ 1) & 0xff;
    uVar5 = aps_is_in_group(uStack_48);
    if ((uVar5 != 0) || (uVar5 = uVar7, uVar6 != 0)) {
      aps_send_msg_loopback(&uStack_4c,iVar2);
    }
    if (uVar5 == 0) goto _L0;
    if ((uStack_28 & 2) == 0) {
      iVar3 = aps_send_frame(auStack_22[0],auStack_40);
    }
    else {
      iVar3 = aps_retrans_send_msg(auStack_22[0],uVar4 & 0xff,auStack_40);
    }
    if (iVar3 == 0) goto _L0;
  }
  aps_send_data_confirm(iVar2,iVar3);
_L0:
  if (iVar2 != 0) {
    tasklet_post(param_1);
  }
  return;
}

