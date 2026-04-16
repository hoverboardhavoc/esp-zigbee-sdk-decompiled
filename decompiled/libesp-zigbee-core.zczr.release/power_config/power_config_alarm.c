/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> power_config.o -> power_config_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_alarm(uint8_t ep_id,uint8_t alarm_code)

{
  int iVar1;
  undefined1 auStack_2c [4];
  ezb_zcl_alarms_alarm_cmd_t cmd;
  
  iVar1 = af_get_ep_desc();
  if ((iVar1 != 0) && (iVar1 = af_endpoint_get_cluster_desc(9,1), iVar1 != 0)) {
    memset(auStack_2c,0,0x1a);
    cmd.cmd_ctrl.cnf_ctx.user_ctx._2_2_ = 1;
    cmd.cmd_ctrl.dst_addr.u._5_1_ = ep_id;
    cmd.cmd_ctrl.cnf_ctx.user_ctx._0_1_ = alarm_code;
    ezb_zcl_alarms_alarm_cmd_req(auStack_2c);
  }
  return;
}

