/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ias_ace_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  anon_struct_8_2_ba86eea7_for_in *value;
  anon_struct_8_2_ba86eea7_for_in *paVar3;
  ezb_zcl_status_t eVar4;
  uint16_t uVar5;
  undefined2 extraout_var_01;
  undefined4 uVar6;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  uint uVar7;
  uint uStack_84;
  uint16_t uStack_72;
  uint16_t uStack_70;
  uint16_t offset_3;
  uint16_t offset;
  undefined1 auStack_68 [4];
  zcl_packet_t rsp;
  ezb_zcl_ias_ace_arm_rsp_message_t message;
  uint8_t auStack_28 [12];
  byte bStack_1c;
  byte abStack_14 [4];
  
  iVar2 = 1;
  memset(auStack_68,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar2 = zcl_packet_init(auStack_68,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 4) {
    _uStack_70 = (uint)offset_3 << 0x10;
    rsp.payload = (zcl_packet_payload_t *)0x0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.arm_notif = '\0';
    message.in._5_3_ = 0;
    uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint8_t *)&message.in);
    if ((((CONCAT22(extraout_var_06,uVar5) == 0) ||
         (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                              (uint8_t *)((int)&message.in.header + 1)),
         CONCAT22(extraout_var_07,uVar5) == 0)) ||
        (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                             (uint8_t *)((int)&message.in.header + 2)),
        CONCAT22(extraout_var_08,uVar5) == 0)) ||
       ((uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                             (uint8_t *)((int)&message.in.header + 3)),
        CONCAT22(extraout_var_09,uVar5) == 0 ||
        (uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar7 < (_uStack_70 & 0xffff))))
       ) goto _L0;
    uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
    if (uStack_84 == 0) {
      message.in.arm_notif = 0xfe;
      uVar6 = 0x27;
_L0:
      message._4_4_ = arg;
      zcl_core_action_schedule(uVar6,&rsp.payload,uStack_84);
      uVar7 = message.in._4_4_ & 0xff;
_L0:
      if (uVar7 != 0xfe) {
        uStack_84 = uVar7;
      }
    }
  }
  else if (bVar1 < 5) {
    if (bVar1 == 2) {
      _uStack_70 = 0;
      offset._0_1_ = '\0';
      stack0xffffff95 = 0;
      uStack_72 = 0;
      memset(&rsp.payload,0,0x30);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&message.in);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                   (uint16_t *)((int)&message.in.header + 2));
      uVar5 = uStack_72;
      iVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uStack_72,8,&stack0xffffff90);
      if (iVar2 == 0) {
        uStack_72 = 0xffff;
      }
      else {
        uStack_72 = uVar5 + (short)iVar2;
      }
      message.in._4_4_ = _uStack_70;
      message.out.result = offset._0_1_;
      message._17_3_ = stack0xffffff95;
      eVar4 = read_zcl_string(*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_72,auStack_28,
                              '\x11');
      if ((CONCAT31(extraout_var,eVar4) == 0) &&
         (uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uStack_72 <= uVar7)) {
        uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_84 == 0) {
          uVar6 = 0x25;
_L0:
          abStack_14[0] = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(uVar6,&rsp.payload,uStack_84);
          uVar7 = (uint)abStack_14[0];
          goto _L0;
        }
      }
      else {
_L0:
        uStack_84 = 0x80;
      }
    }
    else if (bVar1 == 3) {
      _uStack_70 = (uint)offset_3 << 0x10;
      memset(&rsp.payload,0,0x28);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint8_t *)&message.in);
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                   (uint16_t *)((int)&message.in.header + 2));
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,&message.in.arm_notif);
      eVar4 = read_zcl_string(*(zcl_packet_payload_t **)((int)arg + 0x24),&stack0xffffff90,
                              &message.in.field_0x5,'\x11');
      if ((CONCAT31(extraout_var_00,eVar4) != 0) ||
         (uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar7 < (_uStack_70 & 0xffff)))
      goto _L0;
      uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
      if (uStack_84 == 0) {
        bStack_1c = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x26,&rsp.payload,0);
        uVar7 = (uint)bStack_1c;
        goto _L0;
      }
    }
    else if (bVar1 == 0) {
      _uStack_70 = _uStack_70 & 0xffff0000;
      rsp.payload = (zcl_packet_payload_t *)0x0;
      message.info.status = '\0';
      message.info.dst_ep = '\0';
      message.info.cluster_id = 0;
      message.info.cluster_role = '\0';
      message.info._5_1_ = 0;
      message._6_2_ = 0;
      message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
      message.in.arm_notif = '\0';
      message.in._5_3_ = 0;
      uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint8_t *)&message.in);
      uStack_84 = 0x80;
      if ((CONCAT22(extraout_var_01,uVar5) == 1) &&
         (uStack_84 = zcl_packet_to_message(&rsp.payload,arg,0x80), uStack_84 == 0)) {
        message.in.arm_notif = 0xfe;
        uVar6 = 0x23;
        goto _L0;
      }
    }
    else {
      _uStack_70 = (uint)offset_3 << 0x10;
      memset(&rsp.payload,0,0x30);
      uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uStack_84 = 0x80;
      if (0x1f < uVar7) {
        value = &message.in;
        do {
          paVar3 = (anon_struct_8_2_ba86eea7_for_in *)((int)&value->header + 2);
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint16_t *)value);
          value = paVar3;
        } while ((anon_struct_8_2_ba86eea7_for_in *)abStack_14 != paVar3);
        uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_84 == 0) {
          uVar6 = 0x24;
          goto _L0;
        }
      }
    }
  }
  else if (bVar1 == 7) {
    _uStack_70 = (uint)offset_3 << 0x10;
    memset(&rsp.payload,0,0x18);
    uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint8_t *)&message.in);
    if (CONCAT22(extraout_var_11,uVar5) == 1) {
      uVar7 = (uint)message.in.header & 0xff;
      uStack_84 = 0x87;
      if (uVar7 != 0) {
        message.in._4_4_ = calloc(1,uVar7);
        uStack_84 = 0x89;
        if ((uint8_t *)message.in._4_4_ != (uint8_t *)0x0) {
          af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint16_t)uVar7,
                        (uint8_t *)message.in._4_4_);
          uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
          if (uVar7 < (_uStack_70 & 0xffff)) goto _L0;
          uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
          if (uStack_84 == 0) {
            message.out.result = 0xfe;
            uVar6 = 0x2a;
            goto _L0;
          }
        }
      }
      goto _L0;
    }
_L0:
    uStack_84 = 0x80;
_L0:
    if (message.in._4_4_ != 0) {
      mm_free();
    }
  }
  else if (bVar1 < 8) {
    if (bVar1 != 5) {
      _uStack_70 = (uint)offset_3 << 0x10;
      memset(&rsp.payload,0,0x18);
      uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint8_t *)&message.in);
      if (CONCAT22(extraout_var_10,uVar5) == 1) {
        uVar7 = (uint)message.in.header & 0xff;
        if (uVar7 != 0) {
          message.in._4_4_ = calloc(1,uVar7);
          uStack_84 = 0x89;
          if ((uint8_t *)message.in._4_4_ == (uint8_t *)0x0) goto _L0;
          af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint16_t)uVar7,
                        (uint8_t *)message.in._4_4_);
        }
        uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if ((_uStack_70 & 0xffff) <= uVar7) {
          uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
          if (uStack_84 == 0) {
            message.out.result = 0xfe;
            uVar6 = 0x29;
_L0:
            message._4_4_ = arg;
            zcl_core_action_schedule(uVar6,&rsp.payload);
            if ((message._16_4_ & 0xff) != 0xfe) {
              uStack_84 = message._16_4_ & 0xff;
            }
          }
          goto _L0;
        }
      }
      goto _L0;
    }
    _uStack_70 = (uint)offset_3 << 0x10;
    rsp.payload = (zcl_packet_payload_t *)0x0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.arm_notif = '\0';
    message.in._5_3_ = 0;
    uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,(uint8_t *)&message.in);
    if (((CONCAT22(extraout_var_02,uVar5) == 0) ||
        (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                             (uint8_t *)((int)&message.in.header + 1)),
        CONCAT22(extraout_var_03,uVar5) == 0)) ||
       ((uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                             (uint8_t *)((int)&message.in.header + 2)),
        CONCAT22(extraout_var_04,uVar5) == 0 ||
        ((uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&stack0xffffff90,
                              (uint8_t *)((int)&message.in.header + 3)),
         CONCAT22(extraout_var_05,uVar5) == 0 ||
         (uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar7 < (_uStack_70 & 0xffff)))
        )))) goto _L0;
    uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
    if (uStack_84 == 0) {
      message.in.arm_notif = 0xfe;
      uVar6 = 0x28;
      goto _L0;
    }
  }
  else {
    if (bVar1 == 8) {
      uStack_72 = 0;
      memset(&rsp.payload,0,0x18);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&message.in);
      uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                          (uint8_t *)((int)&message.in.header + 1));
      if (CONCAT22(extraout_var_12,uVar5) != 1) goto _L0;
      uStack_84 = 0x89;
      message.in._4_4_ = calloc(1,((uint)message.in.header >> 8 & 0xff) << 2);
      if ((void *)message.in._4_4_ != (void *)0x0) {
        for (iVar2 = 0; iVar2 < (int)((uint)message.in.header >> 8 & 0xff); iVar2 = iVar2 + 1) {
          _uStack_70 = _uStack_70 & 0xffff0000;
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,
                      (uint8_t *)(message.in._4_4_ + iVar2 * 4));
          af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&stack0xffffff90);
          *(uint16_t *)(message.in._4_4_ + iVar2 * 4 + 2) = uStack_70;
        }
        uVar7 = zmsg_get_length();
        if (uVar7 < uStack_72) goto _L0;
        uStack_84 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_84 == 0) {
          message.out.result = 0xfe;
          uVar6 = 0x2b;
          goto _L0;
        }
      }
      goto _L0;
    }
    uStack_84 = 0x81;
  }
  iVar2 = zcl_packet_setup_default_response(auStack_68,arg,uStack_84);
  if (iVar2 == 0) {
    zcl_packet_send(auStack_68,0);
  }
  else {
    zcl_packet_free(auStack_68);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

