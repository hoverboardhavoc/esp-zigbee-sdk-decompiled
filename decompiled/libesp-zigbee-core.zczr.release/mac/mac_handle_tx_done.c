/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_tx_done(int param_1,undefined4 param_2,undefined1 param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 uStack_71;
  int *piStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined1 uStack_54;
  byte bStack_53;
  undefined1 auStack_4e [10];
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined1 auStack_3c [10];
  undefined1 auStack_32 [10];
  undefined2 uStack_28;
  ushort uStack_24;
  char cStack_21;
  
  iVar2 = zmsg_queue_get_head(param_2);
  if (iVar2 != 0) {
    uStack_71 = 0;
    zmsg_queue_dequeue(param_2,iVar2);
    if (param_4 != 0) {
      zmsg_remove_footer(iVar2,10);
    }
    memset(&iStack_58,0,0x1a);
    uStack_6c = 0;
    uStack_68 = 0;
    uStack_64 = 0;
    uStack_60 = 0;
    uStack_5c = 0;
    piStack_70 = &iStack_58;
    uVar1 = zmsg_read_bytes(iVar2,0,0x1a,&iStack_58);
    uStack_6c = CONCAT31(uStack_6c._1_3_,uVar1);
    iVar3 = mac_frame_parse_header(&piStack_70,auStack_3c,&uStack_71);
    if (iVar3 == 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      zmsg_remove_header(iVar2,uStack_71);
      if (cStack_21 == '\x02') {
        memcpy(&iStack_58,auStack_32,10);
        memcpy(auStack_4e,auStack_3c,10);
        uStack_44 = uStack_28;
        uStack_42 = param_3;
        nwk_mm_comm_status_indication(*(undefined1 *)(param_1 + 0x2c),&iStack_58);
        zmsg_free(iVar2);
        return;
      }
    } while ((uStack_24 & 7) != 1);
    bStack_53 = bStack_53 & 0xfe | (byte)param_4 & 1;
    iStack_58 = iVar2;
    uStack_54 = param_3;
    nwk_mm_data_confirm(*(undefined1 *)(param_1 + 0x2c),&iStack_58);
  }
  return;
}

