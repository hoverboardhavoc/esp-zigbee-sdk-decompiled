/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> groups_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t groups_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  anon_struct_1_1_6971b95b_for_out aVar2;
  uint8_t uVar3;
  undefined1 uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  void *pvVar9;
  uint __nmemb;
  uint uStack_74;
  uint8_t uStack_65;
  uint16_t uStack_64;
  ushort uStack_62;
  uint8_t status;
  uint16_t offset;
  uint16_t group_id;
  ezb_zcl_groups_add_group_rsp_message_t message;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  iVar6 = 1;
  memset(auStack_48,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar6 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar6 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar6 != 0))
  goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 2) {
    uStack_62 = 0;
    uStack_65 = '\0';
    uStack_64 = uStack_64 & 0xff00;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9e,&uStack_65);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9e,(uint8_t *)&uStack_64);
    __nmemb = (uint)(byte)uStack_64;
    pvVar9 = calloc(__nmemb,2);
    uVar7 = 0;
    if ((__nmemb == 0) || (uStack_74 = 0x89, pvVar9 != (void *)0x0)) {
      while( true ) {
        if ((byte)uStack_64 <= uVar7) break;
        af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff9e,
                     (uint16_t *)(uVar7 * 2 + (int)pvVar9));
        uVar7 = uVar7 + 1 & 0xff;
      }
      uVar7 = zmsg_get_length();
      uVar3 = uStack_65;
      uStack_74 = 0x80;
      if (uStack_62 <= uVar7) {
        uVar4 = (byte)uStack_64;
        memset(&offset,0,0x18);
        uStack_74 = zcl_packet_to_message(&offset,arg);
        if (uStack_74 == 0) {
          message.out.result = 0xfe;
          message.in.header._0_2_ = CONCAT11(uVar4,uVar3);
          message._4_4_ = arg;
          message.in._4_4_ = pvVar9;
          zcl_core_action_schedule(0xf,&offset);
          if (message.out.result != 0xfe) {
            uStack_74 = (uint)message.out.result;
          }
        }
      }
      if (pvVar9 != (void *)0x0) {
        mm_free(pvVar9);
      }
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      uStack_62 = 0xffff;
      uStack_64 = 0;
      uStack_65 = '\0';
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_64,&uStack_65);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_64,&stack0xffffff9e);
      uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar5 = uStack_62;
      uVar3 = uStack_65;
      uStack_74 = 0x80;
      if (uStack_64 <= uVar7) {
        _offset = 0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message.in.status = '\0';
        message.in._5_1_ = 0;
        message.in.group_id = 0;
        uStack_74 = zcl_packet_to_message(&offset,arg,0x80);
        if (uStack_74 == 0) {
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,uVar3);
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT22(uVar5,message.in.header._0_2_);
          uVar8 = 0xd;
_L0:
          message.in._5_1_ = (char)message.in._5_3_;
          message.in.group_id = SUB32(message.in._5_3_,1);
          message.in.status = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(uVar8,&offset,uStack_74);
          aVar2.result = message.in.status;
_L0:
          if (aVar2.result != 0xfe) {
            uStack_74 = (uint)aVar2.result;
          }
        }
      }
    }
    else {
      uStack_62 = 0xffff;
      uStack_64 = 0;
      uStack_65 = '\0';
      uVar7 = zmsg_get_length(*(zmsg_t **)((int)arg + 0x24));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_64,&uStack_65);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_64,&stack0xffffff9e);
      uVar5 = uStack_62;
      uVar3 = uStack_65;
      uStack_74 = 0x80;
      if (uStack_64 <= uVar7) {
        memset(&offset,0,0x18);
        uStack_74 = zcl_packet_to_message(&offset,arg);
        if (uStack_74 == 0) {
          message.out.result = 0xfe;
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,uVar3);
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT22(uVar5,message.in.header._0_2_);
          message.in.status = '\0';
          message.in._5_1_ = 0;
          message.in.group_id = 0;
          message._4_4_ = arg;
          zcl_core_action_schedule(0xe,&offset,0);
          aVar2 = message.out;
          goto _L0;
        }
      }
    }
  }
  else if (bVar1 == 3) {
    uStack_62 = 0xffff;
    uStack_64 = 0;
    uStack_65 = '\0';
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_64,&uStack_65);
    af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_64,&stack0xffffff9e);
    uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar5 = uStack_62;
    uVar3 = uStack_65;
    uStack_74 = 0x80;
    if (uStack_64 <= uVar7) {
      _offset = 0;
      message.info.status = '\0';
      message.info.dst_ep = '\0';
      message.info.cluster_id = 0;
      message.info.cluster_role = '\0';
      message.info._5_1_ = 0;
      message._6_2_ = 0;
      message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
      message.in.status = '\0';
      message.in._5_1_ = 0;
      message.in.group_id = 0;
      uStack_74 = zcl_packet_to_message(&offset,arg,0x80);
      if (uStack_74 == 0) {
        message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,uVar3);
        message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT22(uVar5,message.in.header._0_2_);
        uVar8 = 0x10;
        goto _L0;
      }
    }
  }
  else {
    uStack_74 = 0x81;
  }
  iVar6 = zcl_packet_setup_default_response(auStack_48,arg,uStack_74);
  if (iVar6 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
_L0:
  return (ezb_zcl_status_t)iVar6;
}

