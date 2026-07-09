/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_srv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_touchlink_srv_handler(void *param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  ushort uStack_5e;
  undefined1 auStack_5c [10];
  undefined2 uStack_52;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [13];
  undefined1 uStack_33;
  undefined1 auStack_32 [2];
  undefined1 auStack_30 [2];
  undefined1 auStack_2e [2];
  undefined1 auStack_2c [2];
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [2];
  undefined1 auStack_24 [2];
  undefined1 auStack_22 [18];
  
  if (param_1 == (void *)0x0) {
    param_1 = (void *)__assert_func(0,0,0);
  }
  bVar1 = *(byte *)((int)param_1 + 0x20);
  if (bVar1 == 0x10) {
    iVar2 = *(int *)((int)param_1 + 0x24);
    if (iVar2 == 0) {
      return 0xfe;
    }
    memset(&uStack_50,0,0x40);
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,&uStack_4c);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_44);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,0x10,(int)&uStack_44 + 1);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_33);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_32);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_30);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2e);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2c);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2a);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_28);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_26);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_24);
    uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar4 < uStack_5e) {
      return 0x80;
    }
    uVar3 = touchlink_network_start_req_handler(auStack_5c);
  }
  else if (bVar1 < 0x11) {
    if (bVar1 == 6) {
      iVar2 = *(int *)((int)param_1 + 0x24);
      if (iVar2 == 0) {
        return 0xfe;
      }
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      memcpy(auStack_5c,param_1,10);
      uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
      uStack_5e = 0;
      af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
      af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
      uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
      if (uVar4 < uStack_5e) {
        return 0x80;
      }
      uVar3 = touchlink_identify_req_handler(auStack_5c);
    }
    else if (bVar1 < 7) {
      if (bVar1 == 0) {
        iVar2 = *(int *)((int)param_1 + 0x24);
        if (iVar2 == 0) {
          return 0xfe;
        }
        uStack_50 = 0;
        uStack_4c = 0;
        uStack_48 = 0;
        uStack_44 = 0;
        memcpy(auStack_5c,param_1,10);
        uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
        uStack_5e = 0;
        af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
        af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
        af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_4c + 1);
        uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
        if (uVar4 < uStack_5e) {
          return 0x80;
        }
        uVar3 = touchlink_scan_req_handler(auStack_5c);
      }
      else {
        if (bVar1 != 2) goto _L0;
        iVar2 = *(int *)((int)param_1 + 0x24);
        if (iVar2 == 0) {
          return 0xfe;
        }
        uStack_50 = 0;
        uStack_4c = 0;
        uStack_48 = 0;
        uStack_44 = 0;
        memcpy(auStack_5c,param_1,10);
        uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
        uStack_5e = 0;
        af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
        af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_4c);
        uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
        if (uVar4 < uStack_5e) {
          return 0x80;
        }
        uVar3 = touchlink_device_info_req_handler(auStack_5c);
      }
    }
    else {
      if (bVar1 != 7) {
_L0:
        uVar4 = zcl_packet_send_default_response(param_1,0x81);
        return uVar4;
      }
      iVar2 = *(int *)((int)param_1 + 0x24);
      if (iVar2 == 0) {
        return 0xfe;
      }
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      memcpy(auStack_5c,param_1,10);
      uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
      uStack_5e = 0;
      af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
      uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
      if (uVar4 < uStack_5e) {
        return 0x80;
      }
      uVar3 = touchlink_factory_new_req_handler(auStack_5c);
    }
  }
  else if (bVar1 == 0x14) {
    iVar2 = *(int *)((int)param_1 + 0x24);
    if (iVar2 == 0) {
      return 0xfe;
    }
    memset(&uStack_50,0,0x38);
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,&uStack_4c);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_44);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,0x10,(int)&uStack_44 + 1);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_33);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_32);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_30);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2e);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2c);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2a);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_28);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_26);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_24);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_22);
    uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar4 < uStack_5e) {
      return 0x80;
    }
    uVar3 = touchlink_join_ed_req_handler(auStack_5c);
  }
  else if (bVar1 == 0x16) {
    iVar2 = *(int *)((int)param_1 + 0x24);
    if (iVar2 == 0) {
      return 0xfe;
    }
    memset(&uStack_50,0,0x1c);
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,&uStack_4c);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_44);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_44 + 1);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,(int)&uStack_44 + 2);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_40);
    uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar4 < uStack_5e) {
      return 0x80;
    }
    uVar3 = touchlink_network_update_req_handler(auStack_5c);
  }
  else {
    if (bVar1 != 0x12) goto _L0;
    iVar2 = *(int *)((int)param_1 + 0x24);
    if (iVar2 == 0) {
      return 0xfe;
    }
    memset(&uStack_50,0,0x38);
    memcpy(auStack_5c,param_1,10);
    uStack_52 = *(undefined2 *)((int)param_1 + 0x1e);
    uStack_5e = 0;
    af_read_le32_isra_0(iVar2,&uStack_5e,&uStack_50);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,8,&uStack_4c);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_44);
    af_read_bytes_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,0x10,(int)&uStack_44 + 1);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,&uStack_33);
    af_read_le8_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_32);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_30);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2e);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2c);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_2a);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_28);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_26);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_24);
    af_read_le16_isra_0(*(undefined4 *)((int)param_1 + 0x24),&uStack_5e,auStack_22);
    uVar4 = zmsg_get_length(*(undefined4 *)((int)param_1 + 0x24));
    if (uVar4 < uStack_5e) {
      return 0x80;
    }
    uVar3 = touchlink_join_router_req_handler(auStack_5c);
  }
  uVar4 = zcl_status_to_err(uVar3);
  return uVar4 & 0xff;
}

