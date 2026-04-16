/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> convert_to_ezb_specific_cmd_ctrl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_ezb_specific_cmd_ctrl
               (ezb_zcl_cluster_cmd_ctrl_t *dst,esp_zb_zcl_specific_cmd_header_t *src)

{
  ezb_af_user_cnf_callback_t p_Var1;
  
  memset(dst,0,0x18);
  p_Var1 = get_zcl_send_status_cb_handle();
  (dst->cnf_ctx).cb = p_Var1;
  (dst->dst_addr).addr_mode = src->address_mode;
  dst->dst_ep = (src->zcl_basic_cmd).dst_endpoint;
  dst->src_ep = (src->zcl_basic_cmd).src_endpoint;
  memcpy(&(dst->dst_addr).u,src,8);
  return;
}

