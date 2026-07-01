/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_cb_nwk_mgmt_lqi_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_cb_nwk_mgmt_lqi_rsp(zdp_nwk_mgmt_lqi_rsp_field_t *rsp,zdo_packet_ctx_t *ctx)

{
  zdp_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  int extraout_a1;
  zdp_nwk_mgmt_rtg_rsp_field_t azStack_38 [2];
  
  if ((rsp != (zdp_nwk_mgmt_lqi_rsp_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0)) {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x29c,
                        "zdo_cb_nwk_mgmt_lqi_rsp","rsp && ctx");
  if ((iVar2 != 0) && (extraout_a1 != 0)) {
    zdo_packet_notify_result(extraout_a1,0);
    return '\0';
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x312,
                        "zdo_cb_nwk_mgmt_rtg_rsp","rsp && ctx");
  azStack_38[0].status = '\0';
  azStack_38[0].routing_table_entries = '\0';
  azStack_38[0].start_index = '\0';
  azStack_38[0].routing_table_list_count = '\0';
  azStack_38[0].routing_table_list = (ezb_zdp_nwk_mgmt_routing_table_entry_t *)0x0;
  if (iVar2 == 0) {
    zVar1 = 0xfe;
  }
  else if (*(zdo_packet_payload_t **)(iVar2 + 0x14) == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_nwk_mgmt_rtg_rsp(*(zdo_packet_payload_t **)(iVar2 + 0x14),azStack_38,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      zVar1 = zdo_cb_nwk_mgmt_rtg_rsp(azStack_38,(zdo_packet_ctx_t *)(iVar2 + 8));
    }
    else {
      zVar1 = 0xfe;
    }
  }
  if (azStack_38[0].routing_table_list != (ezb_zdp_nwk_mgmt_routing_table_entry_t *)0x0) {
    mm_free();
  }
  return zVar1;
}

