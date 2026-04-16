/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_alarm(uint8_t ep_id,uint8_t alarm_code)

{
  int iVar1;
  undefined4 uStack_2c;
  ezb_zcl_alarms_alarm_cmd_t cmd;
  
  iVar1 = af_get_ep_desc();
  if ((iVar1 != 0) && (iVar1 = af_endpoint_get_cluster_desc(9,1), iVar1 != 0)) {
    uStack_2c = 0;
    cmd.cmd_ctrl.dst_addr._0_4_ = 0;
    cmd.cmd_ctrl._8_4_ = 0;
    cmd.cmd_ctrl.dis_default_rsp = false;
    cmd.cmd_ctrl._13_3_ = 0;
    cmd.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    cmd.cmd_ctrl.dst_addr.u._2_4_ = (uint)ep_id << 0x18;
    cmd.cmd_ctrl.cnf_ctx.user_ctx = (void *)CONCAT22(1,CONCAT11(0,alarm_code));
    ezb_zcl_alarms_alarm_cmd_req(&uStack_2c);
  }
  return;
}

