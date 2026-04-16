/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_ace_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined1 local_40 [4];
  ezb_zcl_cmd_cnf_ctx_t cnf_ctx;
  zcl_packet_t rsp;
  
  cnf_ctx.user_ctx = (void *)0x0;
  local_40 = (undefined1  [4])0x0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if (arg == (void *)0x0) {
    iVar2 = 1;
    goto _L0;
  }
  if ((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) {
    iVar2 = 1;
    goto _L0;
  }
  iVar2 = zcl_packet_init(&cnf_ctx.user_ctx,*(byte *)((int)arg + 0x1a) >> 2 & 1);
  if (iVar2 != 0) goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 5) {
    eVar3 = ias_ace_cluster_get_zone_id_map_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
    iVar2 = CONCAT31(extraout_var_06,eVar3);
  }
  else if (bVar1 < 6) {
    if (bVar1 == 2) {
      eVar3 = ias_ace_cluster_emergency_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
      iVar2 = CONCAT31(extraout_var_04,eVar3);
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        eVar3 = ias_ace_cluster_arm_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
        iVar2 = CONCAT31(extraout_var_03,eVar3);
      }
      else {
        if (bVar1 != 1) goto _L0;
        eVar3 = ias_ace_cluster_bypass_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx,
                           (ezb_zcl_cmd_cnf_ctx_t *)local_40);
        iVar2 = CONCAT31(extraout_var,eVar3);
      }
    }
    else if (bVar1 == 3) {
      eVar3 = ias_ace_cluster_fire_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
      iVar2 = CONCAT31(extraout_var_05,eVar3);
    }
    else {
      if (bVar1 != 4) goto _L0;
      eVar3 = ias_ace_cluster_panic_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
      iVar2 = CONCAT31(extraout_var_00,eVar3);
    }
  }
  else if (bVar1 == 8) {
    eVar3 = ias_ace_cluster_get_bypassed_zone_list_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
    iVar2 = CONCAT31(extraout_var_08,eVar3);
  }
  else if (bVar1 < 9) {
    if (bVar1 == 6) {
      eVar3 = ias_ace_cluster_get_zone_information_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
      iVar2 = CONCAT31(extraout_var_07,eVar3);
    }
    else {
      if (bVar1 != 7) goto _L0;
      eVar3 = ias_ace_cluster_get_panel_status_cmd_handler
                        ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx);
      iVar2 = CONCAT31(extraout_var_01,eVar3);
    }
  }
  else if (bVar1 == 9) {
    eVar3 = ias_ace_cluster_get_zone_status_cmd_handler
                      ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx,
                       (ezb_zcl_cmd_cnf_ctx_t *)local_40);
    iVar2 = CONCAT31(extraout_var_02,eVar3);
  }
  else {
_L0:
    iVar2 = zcl_packet_setup_default_response(&cnf_ctx.user_ctx,arg,0x81);
  }
  if (iVar2 == 0) {
    zcl_packet_send(&cnf_ctx.user_ctx,local_40);
  }
  else {
    zcl_packet_free(&cnf_ctx.user_ctx);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

