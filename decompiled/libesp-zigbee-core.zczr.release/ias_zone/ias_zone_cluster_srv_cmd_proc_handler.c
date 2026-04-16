/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_zone_cluster_srv_cmd_proc_handler(void *arg)

{
  char cVar1;
  int iVar2;
  _Bool _Var3;
  uint uVar4;
  ias_zone_srv_zone_ctx_t *piVar5;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar6;
  uint uVar7;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint8_t *puVar8;
  uint16_t uStack_66;
  uint uStack_64;
  uint16_t offset_1;
  uint16_t offset;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined4 uStack_5c;
  ezb_zcl_ias_zone_enroll_rsp_message_t message;
  zcl_packet_t rsp;
  
  memset(&message.out,0,0x28);
  if (arg == (void *)0x0) {
    iVar2 = 1;
    goto _L0;
  }
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar2 = zcl_packet_init(&message.out,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  cVar1 = *(char *)((int)arg + 0x20);
  if (cVar1 == '\x01') {
    uStack_64 = 0;
    _offset = 0;
    piVar5 = ias_zone_srv_get_zone_ctx(*(uint8_t *)((int)arg + 0x15));
    if ((piVar5->cie_ieee_addr_is_set == false) ||
       (_Var3 = validate_cie_authorization
                          (*(uint8_t *)((int)arg + 0x15),*(uint16_t *)((int)arg + 2)),
       CONCAT31(extraout_var_00,_Var3) == 0)) {
_L0:
      uVar7 = 0x7e;
    }
    else {
      uVar7 = zcl_packet_to_message(&stack0xffffff9c,arg);
      if (uVar7 == 0) {
        _offset = CONCAT12(0xfe,offset);
        zcl_core_action_schedule(0x2f,&stack0xffffff9c);
        uVar7 = _offset >> 0x10 & 0xff;
        if (uVar7 == 0xfe) {
_L0:
          uVar7 = 1;
        }
        else {
          piVar5 = ias_zone_srv_get_zone_ctx(*(uint8_t *)((int)arg + 0x15));
          iVar2 = milli_timer_is_running(&piVar5->restore_normal_mode_timer);
          if (iVar2 != 0) {
            milli_timer_stop(&piVar5->restore_normal_mode_timer);
          }
          pzVar6 = ias_zone_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),0x13);
          if (pzVar6 == (zcl_attr_desc_t *)0x0) goto _L85;
_L0:
          if (piVar5->is_prev_sensitivity_level_set != false) {
            *(uint8_t *)pzVar6->data_p = piVar5->prev_sensitivity_level;
            piVar5->is_prev_sensitivity_level_set = false;
          }
        }
      }
    }
  }
  else if (cVar1 == '\x02') {
    uStack_66 = 0;
    uStack_5c = 0;
    message.info.status = '\0';
    message.info.dst_ep = '\0';
    message.info.cluster_id = 0;
    message._4_4_ = message._4_4_ & 0xffff0000;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,(uint8_t *)&message.info.cluster_id);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_66,
                (uint8_t *)((int)&message.info.cluster_id + 1));
    uVar7 = 0x80;
    uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uStack_66 <= uVar4) {
      piVar5 = ias_zone_srv_get_zone_ctx(*(uint8_t *)((int)arg + 0x15));
      if ((piVar5->cie_ieee_addr_is_set == false) ||
         (_Var3 = validate_cie_authorization
                            (*(uint8_t *)((int)arg + 0x15),*(uint16_t *)((int)arg + 2)),
         CONCAT31(extraout_var_01,_Var3) == 0)) goto _L0;
      piVar5 = ias_zone_srv_get_zone_ctx(*(uint8_t *)((int)arg + 0x15));
      pzVar6 = ias_zone_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),0x13);
      if (pzVar6 == (zcl_attr_desc_t *)0x0) {
_L85:
        pzVar6 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
        goto _L0;
      }
      puVar8 = (uint8_t *)pzVar6->data_p;
      piVar5->prev_sensitivity_level = *puVar8;
      *puVar8 = message.info.cluster_id._1_1_;
      uVar7 = zcl_packet_to_message(&uStack_5c,arg);
      if (uVar7 == 0) {
        message.info.cluster_role = 0xfe;
        zcl_core_action_schedule(0x2e,&uStack_5c);
        uVar7 = message._4_4_ & 0xff;
        if (uVar7 == 0xfe) {
          *(uint8_t *)pzVar6->data_p = piVar5->prev_sensitivity_level;
          goto _L0;
        }
        if (uVar7 == 0) {
          piVar5->is_prev_sensitivity_level_set = true;
          milli_timer_init(ias_zone_restore_normal_operation_mode,*(undefined1 *)((int)arg + 0x15));
          milli_timer_start(&piVar5->restore_normal_mode_timer,
                            ((uint)message.info._0_4_ >> 0x10 & 0xff) * 1000);
        }
      }
    }
  }
  else {
    uVar7 = 0x81;
    if (cVar1 == '\0') {
      uStack_64 = uStack_64 & 0xffff0000;
      uStack_5c = 0;
      message.info.status = '\0';
      message.info.dst_ep = '\0';
      message.info.cluster_id = 0;
      message.info.cluster_role = '\0';
      message.info._5_1_ = 0;
      message._6_2_ = 0;
      message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
      message.in.payload.enroll_rsp_code = '\0';
      message.in.payload.zone_id = '\0';
      message.in._6_2_ = 0;
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)&stack0xffffff9c,(uint8_t *)&message.in)
      ;
      af_read_le8(*(zmsg_t **)((int)arg + 0x24),(uint16_t *)&stack0xffffff9c,
                  (uint8_t *)((int)&message.in.header + 1));
      uVar4 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar7 = 0x80;
      if ((uStack_64 & 0xffff) <= uVar4) {
        if (((uint)message.in.header & 0xff) == 0) {
          piVar5 = ias_zone_srv_get_zone_ctx(*(uint8_t *)((int)arg + 0x15));
          if ((piVar5->cie_ieee_addr_is_set == false) ||
             (_Var3 = validate_cie_authorization
                                (*(uint8_t *)((int)arg + 0x15),*(uint16_t *)((int)arg + 2)),
             CONCAT31(extraout_var,_Var3) == 0)) {
            uVar7 = 0x7e;
            goto _L0;
          }
          pzVar6 = ias_zone_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),0x11);
          *(undefined1 *)pzVar6->data_p = message.in.header._1_1_;
          pzVar6 = ias_zone_srv_get_attr_desc(*(uint8_t *)((int)arg + 0x15),0);
          *(undefined1 *)pzVar6->data_p = 1;
        }
        uVar7 = zcl_packet_to_message(&uStack_5c,arg);
        if (uVar7 == 0) {
          message.in.payload.enroll_rsp_code = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x31,&uStack_5c,0);
          if ((message.in._4_4_ & 0xff) != 0xfe) {
            uVar7 = message.in._4_4_ & 0xff;
          }
        }
      }
    }
  }
_L0:
  iVar2 = zcl_packet_setup_default_response(&message.out,arg,uVar7);
  if (iVar2 == 0) {
    zcl_packet_send(&message.out,0);
  }
  else {
    zcl_packet_free(&message.out);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

