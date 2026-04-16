/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_report_attr_now
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_report_attr_now(zcl_reporting_info_t *info)

{
  int iVar1;
  undefined1 auStack_30 [4];
  zcl_report_attr_cmd_t cmd_req;
  
  if (info == (zcl_reporting_info_t *)0x0) {
    return;
  }
  memset(auStack_30,0,0x20);
  cmd_req.cmd_ctrl.dst_addr.u._5_1_ = info->ep_id;
  cmd_req.cmd_ctrl._10_2_ = info->manuf_code;
  cmd_req.cmd_ctrl.dst_addr.u._6_2_ = info->cluster_id;
  cmd_req.cmd_ctrl.cluster_id._0_1_ =
       cmd_req.cmd_ctrl._10_2_ != 0 | (info->cluster_role == '\x01') << 1;
  cmd_req.cmd_ctrl._16_4_ = zcl_reporting_packet_confirm_handler;
  cmd_req.cmd_ctrl.cnf_ctx.user_ctx._0_2_ = info->attr_id;
  iVar1 = zdo_dev_joined();
  if ((iVar1 == 0) || (iVar1 = zcl_report_attr_cmd_req(auStack_30), iVar1 != 0)) {
    info->field_0x9 = info->field_0x9 & 0xf0 | 1;
    process_attr_report(info);
  }
  return;
}

