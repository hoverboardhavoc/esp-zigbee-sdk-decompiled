/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_endpoint_list_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_get_endpoint_list_rsp_cmd_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_2c;
  void *pvStack_28;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  if (param_1 == 0) {
    uVar1 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar1 = 0xfe;
  }
  else {
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 1);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 2);
    if (uVar3 < auStack_22[0]) {
      uVar1 = 0x80;
    }
    else {
      pvStack_28 = calloc(uStack_2c >> 0x10 & 0xff,10);
      if (pvStack_28 == (void *)0x0) {
        uVar1 = 0x89;
      }
      else {
        for (uVar4 = 0; uVar4 < (uStack_2c >> 0x10 & 0xff); uVar4 = uVar4 + 1 & 0xff) {
          iVar2 = uVar4 * 10;
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(void *)((int)pvStack_28 + iVar2))
          ;
          af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar2 + 2);
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar2 + 4);
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar2 + 6);
          af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar2 + 8);
        }
        if (uVar3 < auStack_22[0]) {
          uVar1 = 0x80;
        }
        else {
          uVar1 = zcl_message_endpoint_list_rsp(param_1,&uStack_2c);
        }
      }
    }
  }
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

