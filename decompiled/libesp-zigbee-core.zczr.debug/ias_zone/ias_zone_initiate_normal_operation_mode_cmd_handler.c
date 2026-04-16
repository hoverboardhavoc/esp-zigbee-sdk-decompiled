/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_initiate_normal_operation_mode_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_zone_initiate_normal_operation_mode_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ias_zone_srv_zone_ctx_t *piVar3;
  int iVar4;
  zcl_attr_desc_t *pzVar5;
  uint uVar6;
  undefined4 uStack_28;
  ezb_zcl_ias_zone_initiate_normal_mode_message_t message;
  
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xcc,
                  "ias_zone_initiate_normal_operation_mode_cmd_handler","packet && rsp");
  }
  else {
    _Var1 = validate_cie_establishment((packet->header).dst_ep);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      uVar6 = 0x7e;
      goto _L0;
    }
  }
  _Var1 = validate_cie_authorization((packet->header).dst_ep,(packet->header).src_addr.u.short_addr)
  ;
  if (CONCAT31(extraout_var_00,_Var1) == 0) {
    uVar6 = 0x7e;
  }
  else {
    uVar6 = zcl_packet_to_message(&uStack_28,packet);
    if (uVar6 == 0) {
      message.info.cluster_id._0_1_ = 0xfe;
      zcl_core_action_schedule(0x2f,&uStack_28);
      uVar6 = (uint)message.info._0_4_ >> 0x10 & 0xff;
      if (uVar6 != 0xfe) {
        piVar3 = ias_zone_srv_get_zone_ctx((packet->header).dst_ep);
        iVar4 = milli_timer_is_running(&piVar3->restore_normal_mode_timer);
        if (iVar4 != 0) {
          milli_timer_stop(&piVar3->restore_normal_mode_timer);
        }
        pzVar5 = ias_zone_srv_get_attr_desc((packet->header).dst_ep,0x13);
        if (pzVar5 != (zcl_attr_desc_t *)0x0) {
          if (piVar3->is_prev_sensitivity_level_set != false) {
            *(uint8_t *)pzVar5->data_p = piVar3->prev_sensitivity_level;
            piVar3->is_prev_sensitivity_level_set = false;
          }
          goto _L0;
        }
        __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xd9,
                      "ias_zone_initiate_normal_operation_mode_cmd_handler","attr_desc");
      }
      uVar6 = 1;
    }
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar6);
  return eVar2;
}

