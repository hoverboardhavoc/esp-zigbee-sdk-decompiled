/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_device_info_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_touchlink_device_info_rsp(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 auStack_60 [16];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [26];
  byte bStack_2e;
  undefined1 uStack_2a;
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if ((param_1 == (void *)0x0) || (iVar1 = zcl_packet_init(auStack_48,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,param_1,10);
    iVar2 = zcl_touchlink_cmd_to_packet(auStack_48,1,3,auStack_60);
    iVar1 = 2;
    if (iVar2 == 0) {
      uStack_2a = *(undefined1 *)((int)param_1 + 10);
      bStack_2e = bStack_2e | 0x20;
      iVar1 = zmsg_append_le32(uStack_24,*(undefined4 *)((int)param_1 + 0xc));
      if (((iVar1 == 0) &&
          (iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x10)), iVar1 == 0)) &&
         (iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x11)), iVar1 == 0)) {
        iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x12));
        uVar4 = 0;
        if (iVar1 == 0) {
          for (; uVar4 < *(byte *)((int)param_1 + 0x12); uVar4 = uVar4 + 1 & 0xff) {
            iVar2 = uVar4 * 0x12;
            puVar3 = (undefined4 *)(*(int *)((int)param_1 + 0x14) + iVar2);
            uStack_50 = *puVar3;
            uStack_4c = puVar3[1];
            iVar1 = zmsg_append_bytes(uStack_24,8,&uStack_50);
            if (((((iVar1 != 0) ||
                  (iVar1 = zmsg_append_u8(uStack_24,
                                          *(undefined1 *)(*(int *)((int)param_1 + 0x14) + iVar2 + 8)
                                         ), iVar1 != 0)) ||
                 ((iVar1 = zmsg_append_le16(uStack_24,
                                            *(undefined2 *)
                                             (*(int *)((int)param_1 + 0x14) + iVar2 + 10)),
                  iVar1 != 0 ||
                  ((iVar1 = zmsg_append_le16(uStack_24,
                                             *(undefined2 *)
                                              (*(int *)((int)param_1 + 0x14) + iVar2 + 0xc)),
                   iVar1 != 0 ||
                   (iVar1 = zmsg_append_u8(uStack_24,
                                           *(undefined1 *)
                                            (*(int *)((int)param_1 + 0x14) + iVar2 + 0xe)),
                   iVar1 != 0)))))) ||
                (iVar1 = zmsg_append_u8(uStack_24,
                                        *(undefined1 *)(*(int *)((int)param_1 + 0x14) + iVar2 + 0xf)
                                       ), iVar1 != 0)) ||
               (iVar1 = zmsg_append_u8(uStack_24,
                                       *(undefined1 *)(*(int *)((int)param_1 + 0x14) + iVar2 + 0x10)
                                      ), iVar1 != 0)) goto _L0;
          }
          zcl_packet_intrp_send(auStack_48,(int)param_1 + 0x18);
          iVar1 = zcl_status_to_err();
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar1;
}

