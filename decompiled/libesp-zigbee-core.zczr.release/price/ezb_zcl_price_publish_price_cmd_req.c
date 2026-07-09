/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> ezb_zcl_price_publish_price_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_price_publish_price_cmd_req(void *param_1)

{
  int iVar1;
  undefined1 auStack_50 [22];
  undefined2 uStack_3a;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if (param_1 == (void *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_38,0);
    if (iVar1 == 0) {
      memcpy(auStack_50,param_1,10);
      iVar1 = zcl_cmd_to_packet(auStack_38,1,0,*(undefined1 *)((int)param_1 + 0xc),0,0,0x700);
      if (iVar1 == 0) {
        iVar1 = zmsg_append_le32(uStack_14,*(undefined4 *)((int)param_1 + 0x18));
        if (iVar1 == 0) {
          iVar1 = 2;
          if (0xc < *(byte *)((int)param_1 + 0x1c)) goto _L0;
          iVar1 = zmsg_append_bytes(uStack_14,*(byte *)((int)param_1 + 0x1c) + 1,(int)param_1 + 0x1c
                                   );
          if ((((iVar1 == 0) &&
               (iVar1 = zmsg_append_le32(uStack_14,
                                         (uint)*(byte *)((int)param_1 + 0x2c) << 0x18 |
                                         *(uint *)((int)param_1 + 0x28) >> 8), iVar1 == 0)) &&
              (iVar1 = zmsg_append_le32(uStack_14,
                                        (uint)*(byte *)((int)param_1 + 0x30) << 0x18 |
                                        *(uint *)((int)param_1 + 0x2c) >> 8), iVar1 == 0)) &&
             (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x31)), iVar1 == 0)) {
            uStack_3a = *(undefined2 *)((int)param_1 + 0x32);
            iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3a);
            if (((iVar1 == 0) &&
                (iVar1 = zmsg_append_u8(uStack_14,
                                        (*(uint *)((int)param_1 + 0x34) & 0xf) << 4 |
                                        *(uint *)((int)param_1 + 0x34) >> 4 & 0xf), iVar1 == 0)) &&
               ((iVar1 = zmsg_append_u8(uStack_14,
                                        *(uint *)((int)param_1 + 0x34) >> 4 & 0xf0 |
                                        *(uint *)((int)param_1 + 0x34) >> 0xc & 0xf), iVar1 == 0 &&
                (iVar1 = zmsg_append_le32(uStack_14,*(undefined4 *)((int)param_1 + 0x36)),
                iVar1 == 0)))) {
              uStack_3a = *(undefined2 *)((int)param_1 + 0x3a);
              iVar1 = zmsg_append_bytes(uStack_14,2,&uStack_3a);
              if ((((iVar1 == 0) &&
                   (iVar1 = zmsg_append_le32(uStack_14,*(undefined4 *)((int)param_1 + 0x3c)),
                   iVar1 == 0)) &&
                  ((iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x40)),
                   iVar1 == 0 &&
                   (((((iVar1 = zmsg_append_le32(uStack_14,
                                                 (uint)*(byte *)((int)param_1 + 0x44) << 0x18 |
                                                 *(uint *)((int)param_1 + 0x40) >> 8), iVar1 == 0 &&
                       (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x45)),
                       iVar1 == 0)) &&
                      (iVar1 = zmsg_append_le32(uStack_14,*(undefined4 *)((int)param_1 + 0x46)),
                      iVar1 == 0)) &&
                     (((iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x4a)),
                       iVar1 == 0 &&
                       (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x4b)),
                       iVar1 == 0)) &&
                      ((iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x4c)),
                       iVar1 == 0 &&
                       ((iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x4d)),
                        iVar1 == 0 &&
                        (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x4e)),
                        iVar1 == 0)))))))) &&
                    (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x4f)),
                    iVar1 == 0)))))) &&
                 (((iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x50)),
                   iVar1 == 0 &&
                   (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x51)),
                   iVar1 == 0)) &&
                  (iVar1 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x52)),
                  iVar1 == 0)))) {
                zcl_packet_send(auStack_38,(int)param_1 + 0x10);
                iVar1 = zcl_status_to_err();
                if (iVar1 == 0) {
                  return 0;
                }
                goto _L0;
              }
            }
          }
        }
        iVar1 = 1;
      }
    }
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar1;
}

