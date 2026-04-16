/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_to_ezb_general_cmd_ctrl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_ezb_general_cmd_ctrl(ezb_zcl_cmd_ctrl_t *dst,esp_zb_zcl_general_cmd_header_t *src)

{
  anon_struct_1_3_9083e743_for_fc aVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  uint8_t uVar8;
  byte bVar9;
  ezb_af_user_cnf_callback_t p_Var10;
  
  memset(dst,0,0x1c);
  p_Var10 = get_zcl_send_status_cb_handle();
  (dst->cnf_ctx).cb = p_Var10;
  dst->fc = (anon_struct_1_3_9083e743_for_fc)
            ((byte)((*(ushort *)&src->field_3 >> 2 & 1) << 1) | (byte)dst->fc & 0xfd);
  aVar1 = dst->fc;
  bVar9 = (byte)((*(ushort *)&src->field_3 >> 3 & 1) << 2);
  dst->fc = (anon_struct_1_3_9083e743_for_fc)(bVar9 | (byte)aVar1 & 0xfb);
  dst->fc = (anon_struct_1_3_9083e743_for_fc)
            (bVar9 | (byte)aVar1 & 0xfa | (byte)*(undefined2 *)&src->field_3 & 1);
  dst->manuf_code = src->manuf_code;
  (dst->dst_addr).addr_mode = src->address_mode;
  dst->dst_ep = (src->zcl_basic_cmd).dst_endpoint;
  dst->src_ep = (src->zcl_basic_cmd).src_endpoint;
  dst->cluster_id = src->clusterID;
  uVar2 = (src->zcl_basic_cmd).dst_addr_u.addr_long[1];
  uVar3 = (src->zcl_basic_cmd).dst_addr_u.addr_long[2];
  uVar4 = (src->zcl_basic_cmd).dst_addr_u.addr_long[3];
  uVar5 = (src->zcl_basic_cmd).dst_addr_u.addr_long[4];
  uVar6 = (src->zcl_basic_cmd).dst_addr_u.addr_long[5];
  uVar7 = (src->zcl_basic_cmd).dst_addr_u.addr_long[6];
  uVar8 = (src->zcl_basic_cmd).dst_addr_u.addr_long[7];
  *(uint8_t *)&(dst->dst_addr).u = (src->zcl_basic_cmd).dst_addr_u.addr_long[0];
  *(uint8_t *)((int)&(dst->dst_addr).u + 1) = uVar2;
  *(uint8_t *)((int)&(dst->dst_addr).u + 2) = uVar3;
  *(uint8_t *)((int)&(dst->dst_addr).u + 3) = uVar4;
  *(uint8_t *)((int)&(dst->dst_addr).u + 4) = uVar5;
  *(uint8_t *)((int)&(dst->dst_addr).u + 5) = uVar6;
  *(uint8_t *)((int)&(dst->dst_addr).u + 6) = uVar7;
  *(uint8_t *)((int)&(dst->dst_addr).u + 7) = uVar8;
  return;
}

