/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_report_attr_now
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_report_attr_now(zcl_reporting_info_t *info)

{
  uint16_t uVar1;
  int iVar2;
  undefined4 local_30;
  zcl_report_attr_cmd_t cmd_req;
  
  if (info != (zcl_reporting_info_t *)0x0) {
    local_30 = 0;
    cmd_req.cmd_ctrl.dst_addr._0_4_ = 0;
    cmd_req.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
    cmd_req.cmd_ctrl.dst_addr.u._2_4_ = (uint)info->ep_id << 0x18;
    uVar1 = info->manuf_code;
    cmd_req.cmd_ctrl.dst_ep = (char)uVar1;
    cmd_req.cmd_ctrl.src_ep = (char)(uVar1 >> 8);
    cmd_req.cmd_ctrl.dst_addr.u._6_2_ = info->cluster_id;
    cmd_req.cmd_ctrl._13_3_ = 0;
    cmd_req.cmd_ctrl.cluster_id._0_1_ = uVar1 != 0 | (info->cluster_role == '\x01') << 1;
    cmd_req.cmd_ctrl._16_4_ = zcl_reporting_packet_confirm_handler;
    cmd_req.cmd_ctrl.cnf_ctx.user_ctx = (void *)(uint)info->attr_id;
    iVar2 = zdo_dev_joined();
    if ((iVar2 == 0) || (iVar2 = zcl_report_attr_cmd_req(&local_30), iVar2 != 0)) {
      info->field_0x9 = info->field_0x9 & 0xf0 | 1;
      process_attr_report(info);
    }
  }
  return;
}

