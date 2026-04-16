/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> convert_to_ezb_general_cmd_ctrl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_ezb_general_cmd_ctrl(ezb_zcl_cmd_ctrl_t *dst,esp_zb_zcl_general_cmd_header_t *src)

{
  ushort uVar1;
  ezb_af_user_cnf_callback_t p_Var2;
  
  memset(dst,0,0x1c);
  p_Var2 = get_zcl_send_status_cb_handle();
  uVar1 = *(ushort *)&src->field_3;
  (dst->cnf_ctx).cb = p_Var2;
  dst->fc = (anon_struct_1_3_9083e743_for_fc)
            ((byte)(uVar1 >> 1) & 2 | (byte)uVar1 & 1 | (byte)(uVar1 >> 1) & 4 |
            (byte)dst->fc & 0xf8);
  dst->manuf_code = src->manuf_code;
  (dst->dst_addr).addr_mode = src->address_mode;
  dst->dst_ep = (src->zcl_basic_cmd).dst_endpoint;
  dst->src_ep = (src->zcl_basic_cmd).src_endpoint;
  dst->cluster_id = src->clusterID;
  memcpy(&(dst->dst_addr).u,src,8);
  return;
}

