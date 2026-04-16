/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> electrical_measurement.o -> electrical_measurement_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t electrical_measurement_cluster_srv_cmd_proc_handler(void *arg)

{
  int iVar1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 local_40 [4];
  ezb_zcl_cmd_cnf_ctx_t cnf_ctx;
  zcl_packet_t rsp;
  
  cnf_ctx.user_ctx = (void *)0x0;
  local_40 = (undefined1  [4])0x0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  if (arg == (void *)0x0) {
    iVar1 = 1;
  }
  else if ((*(byte *)((int)arg + 0x1a) >> 3 & 1) == 0) {
    iVar1 = zcl_packet_init(&cnf_ctx.user_ctx,*(byte *)((int)arg + 0x1a) >> 2 & 1);
    if (iVar1 == 0) {
      if (*(char *)((int)arg + 0x20) == '\0') {
        eVar2 = electrical_measurement_cluster_get_prof_info_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx,
                           (ezb_zcl_cmd_cnf_ctx_t *)local_40);
        iVar1 = CONCAT31(extraout_var,eVar2);
      }
      else if (*(char *)((int)arg + 0x20) == '\x01') {
        eVar2 = electrical_measurement_cluster_get_meas_prof_cmd_handler
                          ((zcl_packet_t *)arg,(zcl_packet_t *)&cnf_ctx.user_ctx,
                           (ezb_zcl_cmd_cnf_ctx_t *)local_40);
        iVar1 = CONCAT31(extraout_var_00,eVar2);
      }
      else {
        iVar1 = zcl_packet_setup_default_response(&cnf_ctx.user_ctx,arg,0x81);
      }
      if (iVar1 == 0) {
        zcl_packet_send(&cnf_ctx.user_ctx,local_40);
      }
      else {
        zcl_packet_free(&cnf_ctx.user_ctx);
      }
    }
  }
  else {
    iVar1 = 1;
  }
  return (ezb_zcl_status_t)iVar1;
}

