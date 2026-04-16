/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_commissioning.o -> touchlink_commissioning_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: resp */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t touchlink_commissioning_cluster_cli_cmd_proc_handler(void *arg)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint16_t uStack_72;
  undefined1 auStack_70 [2];
  uint16_t offset;
  ezb_zcl_touchlink_ep_info_t ep_info;
  uint16_t uStack_5a;
  ezb_zcl_touchlink_ep_info_message_t message;
  zcl_packet_t resp;
  
  iVar2 = 1;
  memset(&message.out,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar2 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  cVar1 = *(char *)((int)arg + 0x20);
  if (cVar1 == 'A') {
    uStack_72 = 0;
    _auStack_70 = 0;
    ep_info.ieee_addr.field_0.u64._0_4_ = 0;
    uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,auStack_70);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,auStack_70 + 1);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&offset);
    if (uVar4 < uStack_72) goto _L0;
    uVar5 = 0x89;
    ep_info.ieee_addr.field_0.u64._0_4_ = calloc(_auStack_70 >> 0x10 & 0xff,2);
    uVar3 = 0;
    if ((void *)ep_info.ieee_addr.field_0.u64._0_4_ != (void *)0x0) {
      for (; uVar3 < (_auStack_70 >> 0x10 & 0xff); uVar3 = uVar3 + 1 & 0xff) {
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                     (uint16_t *)(ep_info.ieee_addr.field_0.u64._0_4_ + uVar3 * 2));
      }
      if (uVar4 < uStack_72) goto _L0;
      ep_info.version = '\0';
      ep_info._17_1_ = '\0';
      uStack_5a = 0;
      message.info.status = '\0';
      message.info.dst_ep = '\0';
      message.info.cluster_id = 0;
      message.info.cluster_role = '\0';
      message.info._5_1_ = 0;
      message._6_2_ = 0;
      message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
      message.in.ep_info = (ezb_zcl_touchlink_ep_info_t *)0x0;
      uVar5 = zcl_packet_to_message(&ep_info.version,arg);
      if (uVar5 == 0) {
        uVar6 = 0x51;
_L0:
        message.in.header = (ezb_zcl_cmd_hdr_t *)auStack_70;
        message.in.ep_info = (ezb_zcl_touchlink_ep_info_t *)CONCAT31(message.in.ep_info._1_3_,0xfe);
        message._4_4_ = arg;
        zcl_core_action_schedule(uVar6,&ep_info.version);
        if (((uint)message.in.ep_info & 0xff) != 0xfe) {
          uVar5 = (uint)message.in.ep_info & 0xff;
        }
      }
    }
_L0:
    if (ep_info.ieee_addr.field_0.u64._0_4_ != 0) {
      mm_free();
    }
  }
  else {
    if (cVar1 == 'B') {
      uStack_72 = 0;
      _auStack_70 = 0;
      ep_info.ieee_addr.field_0.u64._0_4_ = 0;
      uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,auStack_70);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,auStack_70 + 1);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&offset);
      if (uStack_72 <= uVar4) {
        ep_info.ieee_addr.field_0.u64._0_4_ = calloc(_auStack_70 >> 0x10 & 0xff,10);
        uVar3 = 0;
        uVar5 = 0x89;
        if ((void *)ep_info.ieee_addr.field_0.u64._0_4_ != (void *)0x0) {
          for (; uVar3 < (_auStack_70 >> 0x10 & 0xff); uVar3 = uVar3 + 1 & 0xff) {
            iVar2 = uVar3 * 10;
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                         (uint16_t *)(ep_info.ieee_addr.field_0.u64._0_4_ + iVar2));
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                        (uint8_t *)(ep_info.ieee_addr.field_0.u64._0_4_ + iVar2 + 2));
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                         (uint16_t *)(ep_info.ieee_addr.field_0.u64._0_4_ + iVar2 + 4));
            af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                         (uint16_t *)(ep_info.ieee_addr.field_0.u64._0_4_ + iVar2 + 6));
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                        (uint8_t *)(ep_info.ieee_addr.field_0.u64._0_4_ + iVar2 + 8));
          }
          if (uVar4 < uStack_72) goto _L0;
          ep_info.version = '\0';
          ep_info._17_1_ = '\0';
          uStack_5a = 0;
          message.info.status = '\0';
          message.info.dst_ep = '\0';
          message.info.cluster_id = 0;
          message.info.cluster_role = '\0';
          message.info._5_1_ = 0;
          message._6_2_ = 0;
          message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
          message.in.ep_info = (ezb_zcl_touchlink_ep_info_t *)0x0;
          uVar5 = zcl_packet_to_message(&ep_info.version,arg);
          if (uVar5 == 0) {
            uVar6 = 0x52;
            goto _L0;
          }
        }
        goto _L0;
      }
_L0:
      uVar5 = 0x80;
      goto _L0;
    }
    uVar5 = 0x81;
    if (cVar1 == '@') {
      _auStack_70 = 0;
      ep_info.ieee_addr.field_0.u64._0_4_ = 0;
      ep_info.ieee_addr.field_0.u64._4_4_ = 0;
      ep_info.nwk_addr = 0;
      ep_info.ep_id = '\0';
      ep_info._11_1_ = 0;
      ep_info.profile_id = 0;
      uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24),0x81);
      iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,8,(ezb_zcl_cmd_hdr_t *)auStack_70);
      if (iVar2 == 0) {
        iVar2 = 0xffff;
      }
      uStack_72 = (uint16_t)iVar2;
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                   (uint16_t *)(ep_info.ieee_addr.field_0.u8 + 4));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,ep_info.ieee_addr.field_0.u8 + 6);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&ep_info.nwk_addr);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint16_t *)&ep_info.ep_id);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&ep_info.profile_id);
      uVar5 = 0x80;
      if (uStack_72 <= uVar4) {
        ep_info.version = '\0';
        ep_info._17_1_ = '\0';
        uStack_5a = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message.in.ep_info = (ezb_zcl_touchlink_ep_info_t *)0x0;
        uVar5 = zcl_packet_to_message(&ep_info.version,arg,0x80);
        if (uVar5 == 0) {
          message.in.ep_info =
               (ezb_zcl_touchlink_ep_info_t *)CONCAT31(message.in.ep_info._1_3_,0xfe);
          message._4_4_ = arg;
          message.in.header = (ezb_zcl_cmd_hdr_t *)auStack_70;
          zcl_core_action_schedule(0x50,&ep_info.version,0);
          if (((uint)message.in.ep_info & 0xff) != 0xfe) {
            uVar5 = (uint)message.in.ep_info & 0xff;
          }
        }
      }
    }
  }
  iVar2 = zcl_packet_setup_default_response(&message.out,arg,uVar5);
  if (iVar2 == 0) {
    zcl_packet_send(&message.out,0);
  }
  else {
    zcl_packet_free(&message.out);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

