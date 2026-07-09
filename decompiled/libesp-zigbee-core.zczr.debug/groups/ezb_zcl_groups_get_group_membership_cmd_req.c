/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> ezb_zcl_groups_get_group_membership_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_groups_get_group_membership_cmd_req(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = zcl_packet_init(&uStack_38,0);
    if (iVar2 == 0) {
      iVar2 = zcl_cmd_to_packet(&uStack_38,0,0,*(undefined1 *)(param_1 + 0xc),0,2,4);
      if (iVar2 == 0) {
        uStack_3a = CONCAT11(uStack_3a._1_1_,*(undefined1 *)(param_1 + 0x18));
        iVar2 = zmsg_append_bytes(uStack_14,1,&uStack_3a);
        uVar1 = 0;
        if (iVar2 == 0) {
          for (; uVar1 < *(byte *)(param_1 + 0x18); uVar1 = uVar1 + 1 & 0xff) {
            uStack_3a = *(undefined2 *)(*(int *)(param_1 + 0x1c) + uVar1 * 2);
            iVar2 = zmsg_append_bytes(uStack_14,2,&uStack_3a);
            if (iVar2 != 0) goto _L0;
          }
          zcl_packet_send(&uStack_38,param_1 + 0x10);
          iVar2 = zcl_status_to_err();
_L0:
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
    }
    else {
      iVar2 = -1;
    }
  }
  zcl_packet_free(&uStack_38);
  return iVar2;
}

