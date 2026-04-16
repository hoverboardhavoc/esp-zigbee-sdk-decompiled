/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement.o -> electrical_measurement_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t electrical_measurement_cluster_srv_cmd_proc_handler(void *arg)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort uStack_7e;
  undefined4 uStack_7c;
  uint16_t offset;
  void *pvStack_78;
  ezb_zcl_cmd_cnf_ctx_t cnf_ctx;
  zcl_packet_t rsp;
  ezb_zcl_electrical_measurement_get_prof_info_message_t message;
  ezb_af_user_cnf_callback_t p_Stack_24;
  
  memset(&cnf_ctx.user_ctx,0,0x28);
  pvStack_78 = (void *)0x0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  iVar3 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar3 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar3 = zcl_packet_init(&cnf_ctx.user_ctx,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar3 != 0))
  goto _L0;
  if (*(char *)((int)arg + 0x20) == '\0') {
    memset(&rsp.payload,0,0x20);
    uVar6 = zcl_packet_to_message(&rsp.payload,arg);
    if (uVar6 != 0) goto _L0;
    message.in.header._0_1_ = 0xfe;
    message._4_4_ = arg;
    zcl_core_action_schedule(0x3e,&rsp.payload);
    uVar6 = (uint)(byte)message.in.header;
    if (uVar6 == 0xfe) {
_L0:
      uVar6 = 1;
      goto _L0;
    }
    if (uVar6 != 0) goto _L0;
    if ((message.out._0_4_ == 0) ||
       (((byte)message.out.payload != 0 && (*(int *)(message.out._0_4_ + 4) == 0)))) goto _L0;
    uStack_7c = CONCAT31(uStack_7c._1_3_,*(undefined1 *)message.out._0_4_);
    iVar4 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff84);
    if (iVar4 != 0) {
_L0:
      uVar6 = 0x89;
      goto _L0;
    }
    uStack_7c = CONCAT31(uStack_7c._1_3_,*(undefined1 *)(message.out._0_4_ + 1));
    iVar4 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff84);
    if (iVar4 != 0) goto _L0;
    uStack_7c = CONCAT31(uStack_7c._1_3_,*(undefined1 *)(message.out._0_4_ + 2));
    iVar4 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff84);
    uVar6 = 0;
    if (iVar4 != 0) goto _L0;
    for (; uVar6 < (byte)message.out.payload; uVar6 = uVar6 + 1 & 0xff) {
      uStack_7c = CONCAT22(offset,*(undefined2 *)(*(int *)(message.out._0_4_ + 4) + uVar6 * 2));
      iVar4 = zmsg_append_bytes(rsp._32_4_,2,&stack0xffffff84);
      if (iVar4 != 0) goto _L0;
    }
    pvStack_78 = (void *)message.out._8_4_;
    cnf_ctx.cb = message.out.cnf_ctx.cb;
    uVar6 = zcl_packet_setup_response(&cnf_ctx.user_ctx,arg,0);
    if (uVar6 != 0) goto _L0;
  }
  else {
    if (*(char *)((int)arg + 0x20) == '\x01') {
      memset(&rsp.payload,0,0x28);
      iVar4 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&message.in);
      if (iVar4 == 0) {
        iVar4 = 0xffff;
      }
      iVar5 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),iVar4,4,&message.out);
      if (iVar5 == 0) {
        uStack_7e = 0xffff;
      }
      else {
        uStack_7e = (short)iVar4 + (short)iVar5;
      }
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,(uint8_t *)&message.out.payload);
      uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      if (uVar6 < uStack_7e) {
        uVar6 = 0x80;
      }
      else {
        uVar6 = zcl_packet_to_message(&rsp.payload,arg);
        if (uVar6 == 0) {
          message.out.num_of_attr_being_profiled = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x3f,&rsp.payload);
          uVar2 = message.out._8_4_ & 0xff;
          uVar1 = 1;
          uVar6 = uVar1;
          if ((((uVar2 != 0xfe) && (uVar6 = uVar2, uVar2 == 0)) &&
              (uVar6 = uVar1, message.out.cnf_ctx.cb != (ezb_af_user_cnf_callback_t)0x0)) &&
             ((message.out.cnf_ctx.cb[6] == (_func_void_ezb_af_user_cnf_t_ptr_void_ptr)0x0 ||
              (*(int *)(message.out.cnf_ctx.cb + 0xc) != 0)))) {
            uStack_7c = *(undefined4 *)message.out.cnf_ctx.cb;
            iVar4 = zmsg_append_bytes(rsp._32_4_,4,&stack0xffffff84);
            if (iVar4 == 0) {
              uStack_7c = CONCAT31(uStack_7c._1_3_,message.out.cnf_ctx.cb[4]);
              iVar4 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff84);
              if (iVar4 == 0) {
                uStack_7c = CONCAT31(uStack_7c._1_3_,message.out.cnf_ctx.cb[5]);
                iVar4 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff84);
                if (iVar4 == 0) {
                  uStack_7c = CONCAT31(uStack_7c._1_3_,message.out.cnf_ctx.cb[6]);
                  iVar4 = zmsg_append_bytes(rsp._32_4_,1,&stack0xffffff84);
                  if (iVar4 == 0) {
                    uStack_7c = CONCAT22(offset,*(undefined2 *)(message.out.cnf_ctx.cb + 8));
                    iVar4 = zmsg_append_bytes(rsp._32_4_,2,&stack0xffffff84);
                    if (iVar4 == 0) {
                      iVar4 = ezb_zcl_get_attr_desc
                                        (*(undefined1 *)((int)arg + 0x15),0xb04,1,
                                         *(undefined2 *)(message.out.cnf_ctx.cb + 8),0);
                      uVar6 = 0;
                      if (iVar4 == 0) {
                        uVar6 = 0x8b;
                      }
                      else {
                        for (; uVar6 < (byte)message.out.cnf_ctx.cb[6]; uVar6 = uVar6 + 1 & 0xff) {
                          iVar5 = zcl_packet_append_variable_attr_value
                                            (rsp._32_4_,*(undefined1 *)(iVar4 + 2),
                                             *(int *)(message.out.cnf_ctx.cb + 0xc) + uVar6);
                          if (iVar5 != 0) goto _L0;
                        }
                        pvStack_78 = message.out.cnf_ctx.user_ctx;
                        cnf_ctx.cb = p_Stack_24;
                        uVar6 = zcl_packet_setup_response(&cnf_ctx.user_ctx,arg,1);
                        if (uVar6 == 0) goto _L0;
                      }
                      goto _L0;
                    }
                  }
                }
              }
            }
_L0:
            uVar6 = 0x89;
          }
        }
      }
    }
    else {
      uVar6 = 0x81;
    }
_L0:
    iVar4 = zcl_packet_setup_default_response(&cnf_ctx.user_ctx,arg,uVar6);
    if (iVar4 != 0) {
      zcl_packet_free(&cnf_ctx.user_ctx);
      iVar3 = iVar4;
      goto _L0;
    }
  }
_L0:
  zcl_packet_send(&cnf_ctx.user_ctx,&pvStack_78);
_L0:
  return (ezb_zcl_status_t)iVar3;
}

