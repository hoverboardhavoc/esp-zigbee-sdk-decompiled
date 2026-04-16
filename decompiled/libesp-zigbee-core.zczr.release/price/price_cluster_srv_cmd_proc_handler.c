/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> price_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t price_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  anon_struct_1_1_6971b95b_for_out aVar2;
  int iVar3;
  uint16_t uVar4;
  undefined2 extraout_var;
  uint uVar5;
  ezb_zcl_cmd_hdr_t *peVar6;
  undefined2 extraout_var_00;
  ezb_err_t eVar7;
  uint uVar8;
  uint16_t uStack_72;
  undefined4 uStack_70;
  uint16_t offset;
  ezb_zcl_cmd_cnf_ctx_t cnf_ctx;
  ezb_zcl_price_get_current_price_message_t message;
  undefined4 uStack_50;
  ezb_af_user_cnf_callback_t p_Stack_4c;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  memset(auStack_48,0,0x28);
  uStack_70 = 0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if (((arg == (void *)0x0) || ((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0)) ||
     (iVar3 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar3 != 0)) {
    iVar3 = 1;
    goto _L0;
  }
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 2) {
    memset(&cnf_ctx.user_ctx,0,0x20);
    uStack_72 = 0;
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint32_t *)&message.in);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint32_t *)&message.in.cmd_opts);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint32_t *)&message.out);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&uStack_50);
    uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar5 = 0x80;
    if ((uStack_72 <= uVar8) &&
       (uVar5 = zcl_packet_to_message(&cnf_ctx.user_ctx,arg,0x80), uVar5 == 0)) {
      p_Stack_4c = (ezb_af_user_cnf_callback_t)CONCAT31(p_Stack_4c._1_3_,0xfe);
      message._4_4_ = arg;
      zcl_core_action_schedule(0x4d,&cnf_ctx.user_ctx,0);
      if (((uint)p_Stack_4c & 0xff) != 0xfe) {
        uVar5 = (uint)p_Stack_4c & 0xff;
      }
    }
_L0:
    iVar3 = zcl_packet_setup_default_response(auStack_48,arg,uVar5);
    if (iVar3 != 0) {
      zcl_packet_free(auStack_48);
      goto _L0;
    }
  }
  else {
    if (2 < bVar1) {
      if (bVar1 == 10) {
        memset(&cnf_ctx.user_ctx,0,0x20);
        uStack_72 = 0;
        uVar4 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint32_t *)&message.in);
        uVar5 = 0x80;
        if ((CONCAT22(extraout_var_00,uVar4) == 4) &&
           (uVar5 = zcl_packet_to_message(&cnf_ctx.user_ctx,arg,0x80), uVar5 == 0)) {
          message.in.cmd_opts = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x4c,&cnf_ctx.user_ctx,0);
          uVar5 = message.in._4_4_ & 0xff;
          if (uVar5 == 0xfe) {
_L0:
            uVar5 = 0x8b;
          }
          else if (uVar5 == 0) {
            uStack_70 = uStack_50;
            cnf_ctx.cb = p_Stack_4c;
            if (message._16_4_ == 0) goto _L0;
            eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,*(uint32_t *)message._16_4_);
            if (((((eVar7 == 0) &&
                  (eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,*(uint32_t *)(message._16_4_ + 4)),
                  eVar7 == 0)) &&
                 (eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,*(uint32_t *)(message._16_4_ + 8)),
                 eVar7 == 0)) &&
                ((eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message._16_4_ + 0xc)),
                 eVar7 == 0 &&
                 (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message._16_4_ + 0xd)),
                 eVar7 == 0)))) &&
               (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message._16_4_ + 0xe)),
               eVar7 == 0)) {
              uVar5 = (uint)*(byte *)(message._16_4_ + 0xe);
              if ((uVar5 == 0) || (uVar5 = 0, *(int *)(message._16_4_ + 0x10) != 0)) {
                for (; uVar5 < *(byte *)(message._16_4_ + 0xe); uVar5 = uVar5 + 1 & 0xff) {
                  eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,
                                         *(uint8_t *)(*(int *)(message._16_4_ + 0x10) + uVar5 * 0xe)
                                        );
                  if ((eVar7 != 0) ||
                     (iVar3 = *(int *)(message._16_4_ + 0x10) + uVar5 * 0xe,
                     iVar3 = zmsg_append_bytes(rsp._32_4_,*(byte *)(iVar3 + 1) + 1,iVar3 + 1),
                     iVar3 != 0)) goto _L0;
                }
                uVar5 = zcl_packet_setup_response(auStack_48,arg,8);
                goto _L0;
              }
              uVar5 = 1;
            }
            else {
_L0:
              uVar5 = 0x89;
            }
          }
        }
      }
      else {
        uVar5 = 0x81;
      }
      goto _L0;
    }
    if (bVar1 != 0) {
      memset(&cnf_ctx.user_ctx,0,0x18);
      uStack_72 = 0;
      af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint32_t *)&message.in);
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,&message.in.cmd_opts);
      uVar5 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      if (uVar5 < uStack_72) {
        uVar5 = 0x80;
      }
      else {
        if ((message.in.header == (ezb_zcl_cmd_hdr_t *)0x0) &&
           (peVar6 = (ezb_zcl_cmd_hdr_t *)zcl_time_get_utc_time(*(undefined1 *)((int)arg + 0x15)),
           peVar6 != (ezb_zcl_cmd_hdr_t *)0xffffffff)) {
          message.in.header = peVar6;
        }
        uVar5 = zcl_packet_to_message(&cnf_ctx.user_ctx,arg);
        if (uVar5 == 0) {
          message.out.result = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x4b,&cnf_ctx.user_ctx,0);
          aVar2.result = message.out.result;
          goto _L0;
        }
      }
      goto _L0;
    }
    cnf_ctx.user_ctx = (void *)0x0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message.info.cluster_role = '\0';
    message.info._5_1_ = 0;
    message._6_2_ = 0;
    message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
    message.in.cmd_opts = '\0';
    message.in._5_3_ = 0;
    uStack_72 = 0;
    uVar4 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_72,(uint8_t *)&message.in);
    uVar5 = 0x80;
    if ((CONCAT22(extraout_var,uVar4) == 0) ||
       (uVar5 = zcl_packet_to_message(&cnf_ctx.user_ctx,arg,0x80), uVar5 != 0)) goto _L0;
    message.in.cmd_opts = 0xfe;
    message._4_4_ = arg;
    zcl_core_action_schedule(0x4a,&cnf_ctx.user_ctx,0);
    aVar2.result = message.in.cmd_opts;
_L0:
    uVar5 = (uint)aVar2.result;
    if (uVar5 == 0xfe) goto _L0;
_L0:
    if (uVar5 != 0) goto _L0;
  }
  zcl_packet_send(auStack_48,&stack0xffffff90);
  iVar3 = 0;
_L0:
  return (ezb_zcl_status_t)iVar3;
}

