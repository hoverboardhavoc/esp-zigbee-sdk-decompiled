/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_sync_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_time_server_sync_callback(ezb_zdo_match_desc_req_result_t *rsp,void *user_ctx)

{
  uint unaff_s0;
  ezb_zdp_match_desc_rsp_field_t *in_a5;
  ezb_zdp_match_desc_rsp_field_t *peVar1;
  int iStack_38;
  ezb_zcl_read_attr_cmd_t cmd;
  
  if (rsp != (ezb_zdo_match_desc_req_result_t *)0x0) {
    peVar1 = rsp->rsp;
    if (((peVar1 != (ezb_zdp_match_desc_rsp_field_t *)0x0) && (peVar1->status == '\0')) &&
       (peVar1->match_length != '\0')) {
      cmd.cmd_ctrl.dst_addr._0_4_ = 0;
      cmd.cmd_ctrl.cluster_id = 0;
      cmd.cmd_ctrl.manuf_code = 0;
      cmd.cmd_ctrl.fc = (anon_struct_1_3_9083e743_for_fc)0x0;
      cmd.cmd_ctrl._17_3_ = 0;
      cmd.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
      iStack_38 = (uint)rsp->rsp->nwk_addr_of_interest << 0x10;
      iStack_38 = CONCAT31(iStack_38._1_3_,2);
      cmd.cmd_ctrl.dst_addr.u._2_4_ = (int)user_ctx << 0x18;
      cmd.cmd_ctrl._8_4_ = 10;
      cmd.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x2;
      cmd.payload.attr_field._0_2_ = 0;
      cmd.payload.attr_field._2_2_ = 1;
      cmd.payload._0_4_ = &cmd.payload.attr_field;
      for (unaff_s0 = 0; in_a5 = rsp->rsp, unaff_s0 < in_a5->match_length;
          unaff_s0 = unaff_s0 + 1 & 0xff) {
_L0:
        cmd.cmd_ctrl.dst_addr.u._4_1_ = in_a5->match_list[unaff_s0];
        ezb_zcl_read_attr_cmd_req(&iStack_38);
      }
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/time.c",0x99,
                "zcl_time_server_sync_callback",&_LC5);
  goto _L0;
}

