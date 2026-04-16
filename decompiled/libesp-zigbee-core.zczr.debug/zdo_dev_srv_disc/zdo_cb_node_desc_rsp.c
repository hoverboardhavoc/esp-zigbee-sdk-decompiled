/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_cb_node_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_cb_node_desc_rsp(zdp_node_desc_rsp_field_t *rsp,zdo_packet_ctx_t *ctx)

{
  zdp_status_t zVar1;
  int iVar2;
  undefined3 extraout_var;
  zdp_node_desc_rsp_field_t zStack_34;
  
  if ((rsp != (zdp_node_desc_rsp_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0)) {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  iVar2 = __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x5a9,
                        "zdo_cb_node_desc_rsp","rsp && ctx");
  zStack_34.status = '\0';
  zStack_34._1_1_ = 0;
  zStack_34.nwk_addr_of_interest = 0;
  zStack_34.node_desc.node_flags = 0;
  zStack_34.node_desc.mac_capability_flags = '\0';
  zStack_34.node_desc._3_1_ = 0;
  zStack_34.node_desc.manufacturer_code = 0;
  zStack_34.node_desc.max_buf_size = '\0';
  zStack_34.node_desc._7_1_ = 0;
  zStack_34.node_desc.max_incoming_transfer_size = 0;
  zStack_34.node_desc.server_mask = 0;
  zStack_34.node_desc.max_outgoing_transfer_size = 0;
  zStack_34.node_desc.desc_capability_field = '\0';
  zStack_34.node_desc._15_1_ = 0;
  if (iVar2 == 0) {
    zVar1 = 0xfe;
  }
  else if (*(zdo_packet_payload_t **)(iVar2 + 0x14) == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    zVar1 = zdo_op_node_desc_rsp(*(zdo_packet_payload_t **)(iVar2 + 0x14),&zStack_34,false);
    if (CONCAT31(extraout_var,zVar1) == 0) {
      zVar1 = zdo_cb_node_desc_rsp(&zStack_34,(zdo_packet_ctx_t *)(iVar2 + 8));
    }
    else {
      zVar1 = 0xfe;
    }
  }
  return zVar1;
}

