/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> ezb_zcl_groups_get_group_membership_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_groups_get_group_membership_cmd_req(void *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if ((param_1 == (void *)0x0) || (iVar1 = zcl_packet_init(auStack_38,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_50,param_1,10);
    iVar1 = zcl_cmd_to_packet(auStack_38,0,0,*(undefined1 *)((int)param_1 + 0xc),0,2,4);
    if (iVar1 == 0) {
      iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x18));
      uVar2 = 0;
      if (iVar1 == 0) {
        for (; uVar2 < *(byte *)((int)param_1 + 0x18); uVar2 = uVar2 + 1 & 0xff) {
          iVar1 = zmsg_append_le16(uStack_14,
                                   *(undefined2 *)(*(int *)((int)param_1 + 0x1c) + uVar2 * 2));
          if (iVar1 != 0) goto _L0;
        }
        zcl_packet_send(auStack_38,(int)param_1 + 0x10);
        iVar1 = zcl_status_to_err();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar1;
}

