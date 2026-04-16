/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_to_ezb_specific_cmd_ctrl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_ezb_specific_cmd_ctrl
               (ezb_zcl_cluster_cmd_ctrl_t *dst,esp_zb_zcl_specific_cmd_header_t *src)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  ezb_af_user_cnf_callback_t p_Var8;
  
  memset(dst,0,0x18);
  p_Var8 = get_zcl_send_status_cb_handle();
  (dst->cnf_ctx).cb = p_Var8;
  (dst->dst_addr).addr_mode = src->address_mode;
  dst->dst_ep = (src->zcl_basic_cmd).dst_endpoint;
  dst->src_ep = (src->zcl_basic_cmd).src_endpoint;
  uVar1 = (src->zcl_basic_cmd).dst_addr_u.addr_long[1];
  uVar2 = (src->zcl_basic_cmd).dst_addr_u.addr_long[2];
  uVar3 = (src->zcl_basic_cmd).dst_addr_u.addr_long[3];
  uVar4 = (src->zcl_basic_cmd).dst_addr_u.addr_long[4];
  uVar5 = (src->zcl_basic_cmd).dst_addr_u.addr_long[5];
  uVar6 = (src->zcl_basic_cmd).dst_addr_u.addr_long[6];
  uVar7 = (src->zcl_basic_cmd).dst_addr_u.addr_long[7];
  *(uint8_t *)&(dst->dst_addr).u = (src->zcl_basic_cmd).dst_addr_u.addr_long[0];
  *(uint8_t *)((int)&(dst->dst_addr).u + 1) = uVar1;
  *(uint8_t *)((int)&(dst->dst_addr).u + 2) = uVar2;
  *(uint8_t *)((int)&(dst->dst_addr).u + 3) = uVar3;
  *(uint8_t *)((int)&(dst->dst_addr).u + 4) = uVar4;
  *(uint8_t *)((int)&(dst->dst_addr).u + 5) = uVar5;
  *(uint8_t *)((int)&(dst->dst_addr).u + 6) = uVar6;
  *(uint8_t *)((int)&(dst->dst_addr).u + 7) = uVar7;
  return;
}

