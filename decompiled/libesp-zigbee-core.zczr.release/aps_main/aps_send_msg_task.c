/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_msg_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_msg_task(int param_1)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort uStack_5e;
  undefined2 uStack_5c;
  ushort uStack_5a;
  short sStack_58;
  undefined2 uStack_56;
  undefined4 uStack_54;
  undefined1 auStack_50 [12];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [4];
  char cStack_38;
  short sStack_36;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined2 uStack_26;
  uint uStack_24;
  
  iVar3 = zmsg_queue_get_head(param_1 + 0x10);
  if (iVar3 == 0) {
    return;
  }
  iVar4 = core_globals_get();
  zmsg_queue_dequeue(iVar4 + 0x2c,iVar3);
  zmsg_get_footer(iVar3,&uStack_5e);
  zmsg_remove_footer(iVar3,2);
  zmsg_get_footer(iVar3,auStack_3c,0x1c);
  uVar5 = aps_get_max_asdu(0,uStack_24 & 1,uStack_24 >> 3 & 1);
  uVar6 = zmsg_get_length(iVar3);
  bVar1 = uVar5 < uVar6;
  if (bVar1) {
    uVar5 = uVar5 - 2 & 0xffff;
  }
  uStack_5c = uStack_26;
  if ((uStack_24 & 0x10) == 0) {
    iVar4 = nwk_get_short_address();
    uStack_5c = 0xfffe;
    if (iVar4 != 0xffff) {
      uStack_5c = nwk_get_short_address();
    }
  }
  uStack_5a = uStack_5e;
  sStack_58 = 0;
  if (cStack_38 == '\x01') {
    sStack_58 = sStack_36;
  }
  uStack_56 = uStack_2e;
  uStack_54 = uStack_2c;
  zmsg_set_offset(iVar3,0);
  iVar4 = aps_frame_prepend_data_hdr
                    (iVar3,&uStack_5c,uStack_24 >> 1 & 1,uStack_24 & 1,bVar1,uStack_24 >> 3 & 1);
  if (iVar4 == 0) {
    uVar6 = (uint)uStack_5e;
    if (uVar6 < 0xfff8) {
      iVar4 = nwk_get_short_address();
      iVar4 = -iVar4;
    }
    else {
      iVar4 = -0xfffe;
    }
    iVar7 = aps_group_table_find(sStack_58);
    sVar2 = sStack_58;
    if (iVar7 == 0) {
      if (uVar6 + iVar4 == 0) {
        bVar1 = false;
        goto _L0;
      }
    }
    else {
      bVar1 = true;
_L0:
      iVar4 = zmsg_clone(iVar3);
      if (iVar4 != 0) {
        uStack_44 = 0;
        uStack_40 = 0;
        memcpy(auStack_50,&uStack_5c,0xc);
        uStack_40 = CONCAT31(uStack_40._1_3_,0x7f);
        aps_handle_data(auStack_50,iVar4);
      }
      if (sVar2 == 0) {
        aps_send_data_confirm(iVar3,iVar4 == 0);
      }
      if (!bVar1) goto _L0;
    }
    if ((uStack_24 & 2) == 0) {
      iVar4 = aps_send_frame(uStack_5e,auStack_3c);
    }
    else {
      iVar4 = aps_retrans_send_msg(uVar5 & 0xff,auStack_3c);
    }
    if (iVar4 == 0) goto _L0;
  }
  aps_send_data_confirm(iVar3,iVar4);
_L0:
  tasklet_post(param_1);
  return;
}

