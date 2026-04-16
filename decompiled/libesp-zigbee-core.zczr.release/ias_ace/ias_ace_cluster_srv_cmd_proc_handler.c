/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ias_ace_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  uint8_t val;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  int iVar4;
  undefined3 extraout_var;
  uint uVar5;
  ezb_err_t eVar6;
  undefined2 extraout_var_01;
  ias_ace_zone_table_t *zone_table;
  ezb_zcl_ias_ace_zone_table_ent_t *peVar7;
  undefined3 extraout_var_00;
  int iVar8;
  uint uVar9;
  int *piVar10;
  ezb_err_t eVar11;
  int iVar12;
  uint extraout_a1;
  undefined4 uVar13;
  ushort *puVar14;
  byte *pbVar15;
  uint8_t *puVar16;
  int in_a6;
  int in_a7;
  zcl_packet_payload_t **__s;
  char cVar17;
  uint uStack_94;
  uint16_t uStack_84;
  uint16_t uStack_82;
  uint16_t offset_1;
  uint16_t offset;
  ezb_zcl_cmd_cnf_ctx_t cnf_ctx;
  zcl_packet_t rsp;
  ezb_zcl_ias_ace_arm_message_t message;
  ezb_af_user_cnf_callback_t p_Stack_30;
  byte *pbStack_2c;
  ezb_zcl_status_t eStack_28;
  uint8_t uStack_27;
  undefined2 uStack_26;
  ezb_af_user_cnf_callback_t p_Stack_24;
  
  memset(&cnf_ctx.user_ctx,0,0x28);
  offset_1._0_1_ = '\0';
  offset_1._1_1_ = '\0';
  offset = 0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if (arg == (void *)0x0) {
    iVar8 = 1;
    goto _L0;
  }
  iVar8 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar4 = zcl_packet_init(&cnf_ctx.user_ctx,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar8 = iVar4,
     iVar4 != 0)) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 5) {
    __s = &rsp.payload;
    memset(__s,0,0x20);
    piVar10 = (int *)ezb_zcl_ias_ace_get_zone_table(*(uint8_t *)((int)arg + 0x15));
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)0x0;
      iVar8 = 0;
      uVar9 = __assert_func(0);
      uVar5 = extraout_a1;
      goto _L0;
    }
    uVar9 = (uint)*(byte *)(piVar10 + 1);
    in_a6 = 0x1e;
    uVar5 = 0xffff;
    in_a7 = 1;
    for (iVar8 = 0; iVar8 < (int)uVar9; iVar8 = iVar8 + 1) {
_L0:
      pbVar15 = (byte *)(*piVar10 + iVar8 * in_a6);
      if (*(ushort *)(pbVar15 + 2) != uVar5) {
        bVar1 = *pbVar15;
        puVar14 = (ushort *)((uint)(bVar1 >> 4) * 2 + (int)__s);
        *puVar14 = (ushort)(in_a7 << (bVar1 & 0xf)) | *puVar14;
      }
    }
    do {
      uStack_82 = *(uint16_t *)__s;
      iVar8 = zmsg_append_bytes(rsp._32_4_,2,&uStack_82);
      if (iVar8 != 0) goto _L0;
      __s = (zcl_packet_payload_t **)((int)__s + 2);
    } while ((zcl_packet_payload_t **)&p_Stack_30 != __s);
    uVar13 = 1;
_L0:
    uStack_94 = zcl_packet_setup_response(&cnf_ctx.user_ctx,arg,uVar13);
    if (uStack_94 != 0) goto _L0;
  }
  else {
    if (bVar1 < 6) {
      if (bVar1 == 2) {
        rsp.payload = (zcl_packet_payload_t *)0x0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        uStack_94 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_94 == 0) {
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,0xfe);
          uVar13 = 0x1e;
          goto _L0;
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          uStack_82 = 0;
          memset(&rsp.payload,0,0x1c);
          af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_82,(uint8_t *)&message.in);
          eVar2 = read_zcl_string(*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_82,
                                  (uint8_t *)((int)&message.in.header + 1),'\t');
          if (CONCAT31(extraout_var,eVar2) == 0) {
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_82,
                        message.in.payload.arm_disarm_code + 5);
            uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
            if (uStack_82 <= uVar5) {
              if ((3 < (byte)message.in.header) || (message.in.payload.arm_disarm_code[5] == 0xff))
              goto _L0;
              uStack_94 = zcl_packet_to_message(&rsp.payload,arg);
              if (uStack_94 == 0) {
                message.in.payload.arm_disarm_code[7] = 0xfe;
                message._4_4_ = arg;
                zcl_core_action_schedule(0x1c,&rsp.payload,0);
                uStack_94 = message.in._12_4_ & 0xff;
                if (uStack_94 == 0xfe) goto _L0;
                if (uStack_94 == 0) {
                  eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,message.in.payload.arm_disarm_code[8])
                  ;
                  uStack_94 = 0x89;
                  if (eVar6 == 0) {
                    uVar13 = 0;
                    goto _L0;
                  }
                }
              }
              goto _L0;
            }
          }
          goto _L0;
        }
        uStack_82 = 0;
        memset(&rsp.payload,0,0x30);
        af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_82,(uint8_t *)&message.in);
        uVar5 = (uint)message.in.header & 0xff;
        uStack_94 = 0x87;
        if (uVar5 != 0) {
          message.in.payload._0_4_ = calloc(1,uVar5);
          if ((uint8_t *)message.in.payload._0_4_ == (uint8_t *)0x0) {
_L0:
            uStack_94 = 0x89;
          }
          else {
            uStack_94 = 0x80;
            af_read_bytes(*(zmsg_t **)((int)arg + 0x24),&uStack_82,(uint16_t)uVar5,
                          (uint8_t *)message.in.payload._0_4_);
            eVar2 = read_zcl_string(*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_82,
                                    message.in.payload.arm_disarm_code + 3,'\t');
            if ((CONCAT31(extraout_var_00,eVar2) == 0) &&
               (uStack_94 = zcl_packet_to_message(&rsp.payload,arg), uStack_94 == 0)) {
              p_Stack_30 = (ezb_af_user_cnf_callback_t)CONCAT31(p_Stack_30._1_3_,0xfe);
              message._4_4_ = arg;
              zcl_core_action_schedule(0x1d,&rsp.payload);
              uStack_94 = (uint)p_Stack_30 & 0xff;
              uVar13 = _offset_1;
              if (uStack_94 == 0xfe) {
_L0:
                _offset_1 = uVar13;
                uStack_94 = 1;
              }
              else if (uStack_94 == 0) {
                uVar13._0_2_ = _eStack_28;
                uVar13._2_2_ = uStack_26;
                offset_1._0_1_ = eStack_28;
                offset_1._1_1_ = uStack_27;
                offset = uStack_26;
                cnf_ctx.cb = p_Stack_24;
                if (((pbStack_2c == (byte *)0x0) ||
                    (uVar13 = _offset_1, ((uint)message.in.header & 0xff) != (uint)*pbStack_2c)) ||
                   (*(int *)(pbStack_2c + 4) == 0)) goto _L0;
                eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,(byte)message.in.header);
                if ((eVar6 != 0) ||
                   (iVar8 = zmsg_append_bytes(rsp._32_4_,*pbStack_2c,*(undefined4 *)(pbStack_2c + 4)
                                             ), iVar8 != 0)) goto _L0;
                uStack_94 = zcl_packet_setup_response(&cnf_ctx.user_ctx,arg,7);
              }
            }
          }
        }
        if (message.in.payload._0_4_ != 0) {
          mm_free();
        }
        if (uStack_94 == 0) goto _L0;
      }
      else if (bVar1 == 3) {
        rsp.payload = (zcl_packet_payload_t *)0x0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        uStack_94 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_94 == 0) {
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,0xfe);
          uVar13 = 0x1f;
_L0:
          message._4_4_ = arg;
          zcl_core_action_schedule(uVar13,&rsp.payload,uStack_94);
          if (((uint)message.in.header & 0xff) != 0xfe) {
            uStack_94 = (uint)message.in.header & 0xff;
          }
        }
      }
      else {
        rsp.payload = (zcl_packet_payload_t *)0x0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        uStack_94 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_94 == 0) {
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,0xfe);
          uVar13 = 0x20;
          goto _L0;
        }
      }
    }
    else if (bVar1 == 8) {
      piVar10 = (int *)ezb_zcl_ias_ace_get_zone_table(*(uint8_t *)((int)arg + 0x15));
      if (piVar10 != (int *)0x0) {
        cVar17 = '\0';
        eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
        if (eVar6 != 0) goto _L0;
        for (; eVar6 < (int)(uint)*(byte *)(piVar10 + 1); eVar6 = eVar6 + 1) {
          puVar16 = (uint8_t *)(*piVar10 + eVar6 * 0x1e);
          if ((puVar16[0xc] & 1) != 0) {
            cVar17 = cVar17 + '\x01';
            eVar11 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*puVar16);
            if (eVar11 != 0) goto _L0;
          }
        }
        rsp.payload = (zcl_packet_payload_t *)CONCAT31(rsp.payload._1_3_,cVar17);
        zmsg_write_bytes(0,1,&rsp.payload);
        uVar13 = 6;
        goto _L0;
      }
_L0:
      uStack_94 = 0x8b;
    }
    else if (bVar1 < 9) {
      if (bVar1 == 6) {
        uStack_82 = 0;
        uStack_84 = uStack_84 & 0xff00;
        uVar3 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_82,(uint8_t *)&uStack_84);
        if (CONCAT22(extraout_var_01,uVar3) == 1) {
          if ((uint8_t)uStack_84 == -1) {
_L0:
            uStack_94 = 0x87;
            goto _L0;
          }
          zone_table = (ias_ace_zone_table_t *)
                       ezb_zcl_ias_ace_get_zone_table(*(uint8_t *)((int)arg + 0x15));
          if (zone_table != (ias_ace_zone_table_t *)0x0) {
            val = (uint8_t)uStack_84;
            peVar7 = ias_ace_zone_table_get_zone(zone_table,(uint8_t)uStack_84);
            eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,val);
            if (eVar6 == 0) {
              if (peVar7 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) {
                uVar3 = 0xffff;
              }
              else {
                uVar3 = peVar7->zone_type;
              }
              rsp.payload = (zcl_packet_payload_t *)CONCAT22(rsp.payload._2_2_,uVar3);
              iVar8 = zmsg_append_bytes(rsp._32_4_,2,&rsp.payload);
              if (iVar8 == 0) {
                if (peVar7 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) {
                  rsp.payload = (zcl_packet_payload_t *)0xffffffff;
                  message.info.status = 0xff;
                  message.info.dst_ep = 0xff;
                  message.info.cluster_id = 0xffff;
                }
                else {
                  rsp.payload = *(zcl_packet_payload_t **)&(peVar7->zone_address).field_0;
                  message.info._0_4_ = *(undefined4 *)((int)&(peVar7->zone_address).field_0 + 4);
                }
                iVar8 = zmsg_append_bytes(rsp._32_4_,8,&rsp.payload);
                if (iVar8 == 0) {
                  if ((peVar7 == (ezb_zcl_ias_ace_zone_table_ent_t *)0x0) ||
                     (peVar7->zone_label[0] == 0)) {
                    iVar8 = zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
                  }
                  else {
                    iVar8 = zmsg_append_bytes(peVar7->zone_label[0] + 1,peVar7->zone_label);
                  }
                  uVar13 = 2;
joined_r0x00010f40:
                  if (iVar8 == 0) goto _L0;
                }
              }
            }
            goto _L0;
          }
        }
_L0:
        uStack_94 = 0x80;
      }
      else {
        rsp.payload = (zcl_packet_payload_t *)0x0;
        message.info.status = '\0';
        message.info.dst_ep = '\0';
        message.info.cluster_id = 0;
        message.info.cluster_role = '\0';
        message.info._5_1_ = 0;
        message._6_2_ = 0;
        message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message.in.payload.arm_mode = '\0';
        message.in.payload.arm_disarm_code[0] = '\0';
        message.in.payload.arm_disarm_code[1] = '\0';
        message.in.payload.arm_disarm_code[2] = '\0';
        uStack_94 = zcl_packet_to_message(&rsp.payload,arg);
        if (uStack_94 == 0) {
          message.in.header = (ezb_zcl_cmd_hdr_t *)CONCAT31(message.in.header._1_3_,0xfe);
          message._4_4_ = arg;
          zcl_core_action_schedule(0x21,&rsp.payload,0);
          uStack_94 = (uint)message.in.header & 0xff;
          if (uStack_94 == 0xfe) goto _L0;
          if (uStack_94 == 0) {
            eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,message.in.header._1_1_);
            if (eVar6 == 0) {
              eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,message.in.header._2_1_);
              if (eVar6 == 0) {
                eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,message.in.header._3_1_);
                if (eVar6 == 0) {
                  iVar8 = zmsg_append_u8((zmsg_t *)rsp._32_4_,message.in.payload.arm_mode);
                  uVar13 = 5;
                  goto joined_r0x00010f40;
                }
              }
            }
            goto _L0;
          }
        }
      }
    }
    else if (bVar1 == 9) {
      uStack_84 = 0;
      memset(&rsp.payload,0,0x24);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_84,(uint8_t *)&message.in);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_84,(uint8_t *)((int)&message.in.header + 1))
      ;
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_84,(uint8_t *)((int)&message.in.header + 2))
      ;
      af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_84,(uint16_t *)&message.in.payload);
      uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uStack_94 = 0x80;
      if (((uStack_84 <= uVar5) &&
          (uStack_94 = zcl_packet_to_message(&rsp.payload,arg,0x80), uStack_94 == 0)) &&
         (uStack_94 = 0x87,
         ((uint)message.in.header & 0xff) + ((uint)message.in.header >> 8 & 0xff) < 0xff)) {
        message.in.payload.arm_disarm_code[3] = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x22,&rsp.payload,0x87);
        uStack_94 = (uint)message.in.payload.arm_disarm_code[3];
        if (uStack_94 == 0xfe) goto _L0;
        if (uStack_94 == 0) {
          offset_1._0_1_ = message.out.result;
          offset_1._1_1_ = message.out.arm_notif;
          offset = message._26_2_;
          cnf_ctx.cb = p_Stack_30;
          if (message.in._12_4_ == 0) {
_L0:
            uStack_94 = 1;
          }
          else {
            eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)message.in._12_4_);
            if (eVar6 == 0) {
              bVar1 = *(byte *)(message.in._12_4_ + 1);
              if (message.in.header._1_1_ < *(byte *)(message.in._12_4_ + 1)) {
                bVar1 = message.in.header._1_1_;
              }
              eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,bVar1);
              if (eVar6 == 0) {
                iVar8 = 0;
                if ((bVar1 == 0) || (*(int *)(message.in._12_4_ + 4) != 0)) {
                  for (; iVar8 < (int)(uint)bVar1; iVar8 = iVar8 + 1) {
                    eVar6 = zmsg_append_u8((zmsg_t *)rsp._32_4_,
                                           *(uint8_t *)(*(int *)(message.in._12_4_ + 4) + iVar8 * 4)
                                          );
                    if (eVar6 != 0) goto _L0;
                    uStack_82 = *(ushort *)(*(int *)(message.in._12_4_ + 4) + iVar8 * 4 + 2);
                    iVar12 = zmsg_append_bytes(rsp._32_4_,2,&uStack_82);
                    if (iVar12 != 0) goto _L0;
                  }
                  uVar13 = 8;
                  goto _L0;
                }
                goto _L0;
              }
            }
_L0:
            uStack_94 = 0x89;
          }
        }
      }
    }
    else {
      uStack_94 = 0x81;
    }
_L0:
    iVar8 = zcl_packet_setup_default_response(&cnf_ctx.user_ctx,arg,uStack_94);
    if (iVar8 != 0) {
      zcl_packet_free(&cnf_ctx.user_ctx);
      goto _L0;
    }
  }
_L0:
  zcl_packet_send(&cnf_ctx.user_ctx,&offset_1);
  iVar8 = iVar4;
_L0:
  return (ezb_zcl_status_t)iVar8;
}

