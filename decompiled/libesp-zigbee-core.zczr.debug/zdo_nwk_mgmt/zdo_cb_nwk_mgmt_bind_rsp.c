/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_cb_nwk_mgmt_bind_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_cb_nwk_mgmt_bind_rsp(zdp_nwk_mgmt_bind_rsp_field_t *rsp,zdo_packet_ctx_t *ctx)

{
  zdp_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  zdp_nwk_mgmt_bind_rsp_field_t azStack_28 [2];
  
  if ((rsp != (zdp_nwk_mgmt_bind_rsp_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0)) {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x3f2,
                        "zdo_cb_nwk_mgmt_bind_rsp","rsp && ctx");
  azStack_28[0].status = '\0';
  azStack_28[0].binding_table_entries = '\0';
  azStack_28[0].start_index = '\0';
  azStack_28[0].binding_table_list_count = '\0';
  azStack_28[0].binding_table_list = (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0;
  if (iVar2 == 0) {
    zVar1 = 0xfe;
  }
  else if (*(zdo_packet_payload_t **)(iVar2 + 0x14) == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_nwk_mgmt_bind_rsp(*(zdo_packet_payload_t **)(iVar2 + 0x14),azStack_28,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      zVar1 = zdo_cb_nwk_mgmt_bind_rsp(azStack_28,(zdo_packet_ctx_t *)(iVar2 + 8));
    }
    else {
      zVar1 = 0xfe;
    }
  }
  if (azStack_28[0].binding_table_list != (ezb_zdp_nwk_mgmt_bind_table_entry_t *)0x0) {
    mm_free();
  }
  return zVar1;
}

