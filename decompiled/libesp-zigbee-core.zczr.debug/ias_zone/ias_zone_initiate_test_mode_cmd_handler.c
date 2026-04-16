/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_initiate_test_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_zone_initiate_test_mode_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  uint uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ias_zone_srv_zone_ctx_t *piVar4;
  zcl_attr_desc_t *pzVar5;
  undefined4 uStack_2c;
  ezb_zcl_ias_zone_initiate_test_mode_message_t message;
  uint16_t offset;
  
  message.in.payload.duration = '\0';
  message.in.payload.current_zone_sensitivity_level = '\0';
  uStack_2c = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xea,
                  "ias_zone_initiate_test_mode_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,(uint16_t *)&message.in,(uint8_t *)&message.info.cluster_id);
    af_read_le8(packet->payload,(uint16_t *)&message.in,
                (uint8_t *)((int)&message.info.cluster_id + 1));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < (ushort)message.in.payload) {
      uVar3 = 0x80;
      goto _L0;
    }
  }
  _Var2 = validate_cie_establishment((packet->header).dst_ep);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    uVar3 = 0x7e;
  }
  else {
    _Var2 = validate_cie_authorization
                      ((packet->header).dst_ep,(packet->header).src_addr.u.short_addr);
    if (CONCAT31(extraout_var_00,_Var2) == 0) {
      uVar3 = 0x7e;
    }
    else {
      piVar4 = ias_zone_srv_get_zone_ctx((packet->header).dst_ep);
      pzVar5 = ias_zone_srv_get_attr_desc((packet->header).dst_ep,0x13);
      if (pzVar5 == (zcl_attr_desc_t *)0x0) {
        __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xf4,
                      "ias_zone_initiate_test_mode_cmd_handler","attr_desc");
      }
      else {
                    /* WARNING: Load size is inaccurate */
        piVar4->prev_sensitivity_level = *pzVar5->data_p;
        *(undefined1 *)pzVar5->data_p = message.info.cluster_id._1_1_;
        uVar3 = zcl_packet_to_message(&uStack_2c,packet);
        if (uVar3 != 0) goto _L0;
        message.info.cluster_role = 0xfe;
        zcl_core_action_schedule(0x2e,&uStack_2c);
        uVar3 = (uint)message.info.cluster_role;
        if (uVar3 != 0xfe) {
          if (uVar3 == 0) {
            piVar4->is_prev_sensitivity_level_set = true;
            milli_timer_init(&piVar4->restore_normal_mode_timer,
                             ias_zone_restore_normal_operation_mode,(packet->header).dst_ep);
            milli_timer_start(&piVar4->restore_normal_mode_timer,
                              ((uint)message.info._0_4_ >> 0x10 & 0xff) * 1000);
          }
          goto _L0;
        }
      }
      *(uint8_t *)pzVar5->data_p = piVar4->prev_sensitivity_level;
      uVar3 = 1;
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

