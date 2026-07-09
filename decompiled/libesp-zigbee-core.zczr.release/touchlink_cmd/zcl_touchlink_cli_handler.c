/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_cli_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_touchlink_cli_handler(void *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ushort uStack_5e;
  undefined1 auStack_5c [10];
  undefined2 uStack_52;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 uStack_3b;
  undefined1 auStack_3a [2];
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [2];
  char cStack_34;
  undefined1 uStack_33;
  undefined1 auStack_32 [2];
  undefined1 auStack_30 [2];
  undefined1 auStack_2e [2];
  undefined1 uStack_2c;
  undefined1 auStack_2b [19];
  
  if (param_1 == (void *)0x0) {
    param_1 = (void *)__assert_func(0,0,0);
  }
  bVar1 = *(byte *)((int)param_1 + 0x20);
  if (bVar1 == 0x11) {
    iVar5 = *(int *)((int)param_1 + 0x24);
    if (iVar5 == 0) {
      return 0xfe;
    }
    memset(&uStack_50,0,0x1c);
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar5,&uStack_5e,&uStack_50);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,(int)&uStack_4c + 1);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_44 + 1);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_44 + 2);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_40);
    uVar3 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar3 < uStack_5e) {
      return 0x80;
    }
    uVar2 = touchlink_network_start_rsp_handler(auStack_5c);
  }
  else if (bVar1 < 0x12) {
    if (bVar1 != 1) {
      if (bVar1 == 3) {
        iVar5 = *(int *)((int)param_1 + 0x24);
        uVar3 = 0xfe;
        if (iVar5 != 0) {
          uStack_50 = 0;
          uStack_4c = 0;
          uStack_48 = (void *)0x0;
          uStack_44 = 0;
          uStack_40 = 0;
          memcpy(auStack_5c,param_1,10);
          uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
          uStack_5e = 0;
          af_read_le32_isra_0(iVar5,&uStack_5e,&uStack_50);
          af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_4c + 1);
          af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
          af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_4c + 2);
          uVar3 = 0x80;
          uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
          if (uStack_5e <= uVar4) {
            uVar3 = uStack_4c >> 0x10 & 0xff;
            if (uVar3 != 0) {
              uStack_48 = calloc(uVar3,0x12);
              for (uVar3 = 0; uVar3 < (uStack_4c >> 0x10 & 0xff); uVar3 = uVar3 + 1 & 0xff) {
                iVar5 = uVar3 * 0x12;
                af_read_bytes_isra_0
                          (*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,
                           (void *)((int)uStack_48 + iVar5));
                af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,
                                   (int)uStack_48 + iVar5 + 8);
                af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,
                                    (int)uStack_48 + iVar5 + 10);
                af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,
                                    (int)uStack_48 + iVar5 + 0xc);
                af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,
                                   (int)uStack_48 + iVar5 + 0xe);
                af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,
                                   (int)uStack_48 + iVar5 + 0xf);
                af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,
                                   (int)uStack_48 + iVar5 + 0x10);
              }
            }
            uVar2 = touchlink_device_info_rsp_handler(auStack_5c);
            uVar3 = zcl_status_to_err(uVar2);
            uVar3 = uVar3 & 0xff;
          }
        }
        if (uStack_48 == (void *)0x0) {
          return uVar3;
        }
        mm_free();
        return uVar3;
      }
_L0:
      uVar3 = zcl_packet_send_default_response(param_1,0x81);
      return uVar3;
    }
    iVar5 = *(int *)((int)param_1 + 0x24);
    if (iVar5 == 0) {
      return 0xfe;
    }
    memset(&uStack_50,0,0x30);
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar5,&uStack_5e,&uStack_50);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_44);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_48);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_48 + 1);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_48 + 2);
    af_read_le32_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,(int)&uStack_44 + 1);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_3b);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_3a);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_38);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_36);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&cStack_34);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_33);
    if (cStack_34 == '\x01') {
      af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_32);
      af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_30);
      af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2e);
      af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_2c);
      af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2b);
    }
    uVar3 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar3 < uStack_5e) {
      return 0x80;
    }
    uVar2 = touchlink_scan_rsp_handler(auStack_5c);
  }
  else if (bVar1 == 0x13) {
    iVar5 = *(int *)((int)param_1 + 0x24);
    if (iVar5 == 0) {
      return 0xfe;
    }
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = (void *)0x0;
    uStack_44 = 0;
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar5,&uStack_5e,&uStack_50);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
    uVar3 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar3 < uStack_5e) {
      return 0x80;
    }
    uVar2 = touchlink_join_router_rsp_handler(auStack_5c);
  }
  else {
    if (bVar1 != 0x15) goto _L0;
    iVar5 = *(int *)((int)param_1 + 0x24);
    if (iVar5 == 0) {
      return 0xfe;
    }
    uStack_50 = 0;
    uStack_4c = 0;
    uStack_48 = (void *)0x0;
    uStack_44 = 0;
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar5,&uStack_5e,&uStack_50);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
    uVar3 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar3 < uStack_5e) {
      return 0x80;
    }
    uVar2 = touchlink_join_ed_rsp_handler(auStack_5c);
  }
  uVar3 = zcl_status_to_err(uVar2);
  return uVar3 & 0xff;
}

