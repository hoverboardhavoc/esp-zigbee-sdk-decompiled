/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_esp_custom_cmd_to_ezb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_esp_custom_cmd_to_ezb(ezb_zcl_custom_cmd_t *dst,esp_zb_zcl_custom_cluster_cmd_t *src)

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
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  
  p_Var10 = get_zcl_send_status_cb_handle();
  (dst->cmd_ctrl).cnf_ctx.cb = p_Var10;
  (dst->cmd_ctrl).cnf_ctx.user_ctx = (void *)0x0;
  uVar12._0_1_ = src->field_4;
  uVar12._1_1_ = src->field_0x11;
  uVar12._2_2_ = src->manuf_code;
  (dst->cmd_ctrl).fc =
       (anon_struct_1_3_9083e743_for_fc)
       ((byte)((uVar12 >> 2 & 1) << 1) | (byte)(dst->cmd_ctrl).fc & 0xfd);
  uVar13._0_1_ = src->field_4;
  uVar13._1_1_ = src->field_0x11;
  uVar13._2_2_ = src->manuf_code;
  aVar1 = (dst->cmd_ctrl).fc;
  bVar9 = (byte)((uVar13 >> 3 & 1) << 2);
  (dst->cmd_ctrl).fc = (anon_struct_1_3_9083e743_for_fc)(bVar9 | (byte)aVar1 & 0xfb);
  uVar11._0_1_ = src->field_4;
  uVar11._1_1_ = src->field_0x11;
  uVar11._2_2_ = src->manuf_code;
  (dst->cmd_ctrl).fc =
       (anon_struct_1_3_9083e743_for_fc)(bVar9 | (byte)aVar1 & 0xfa | (byte)uVar11 & 1);
  (dst->cmd_ctrl).manuf_code = src->manuf_code;
  (dst->cmd_ctrl).dst_addr.addr_mode = src->address_mode;
  (dst->cmd_ctrl).dst_ep = (src->zcl_basic_cmd).dst_endpoint;
  (dst->cmd_ctrl).src_ep = (src->zcl_basic_cmd).src_endpoint;
  (dst->cmd_ctrl).cluster_id = src->cluster_id;
  uVar2 = (src->zcl_basic_cmd).dst_addr_u.addr_long[1];
  uVar3 = (src->zcl_basic_cmd).dst_addr_u.addr_long[2];
  uVar4 = (src->zcl_basic_cmd).dst_addr_u.addr_long[3];
  uVar5 = (src->zcl_basic_cmd).dst_addr_u.addr_long[4];
  uVar6 = (src->zcl_basic_cmd).dst_addr_u.addr_long[5];
  uVar7 = (src->zcl_basic_cmd).dst_addr_u.addr_long[6];
  uVar8 = (src->zcl_basic_cmd).dst_addr_u.addr_long[7];
  *(uint8_t *)&(dst->cmd_ctrl).dst_addr.u = (src->zcl_basic_cmd).dst_addr_u.addr_long[0];
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 1) = uVar2;
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 2) = uVar3;
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 3) = uVar4;
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 4) = uVar5;
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 5) = uVar6;
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 6) = uVar7;
  *(uint8_t *)((int)&(dst->cmd_ctrl).dst_addr.u + 7) = uVar8;
  dst->cmd_id = (uint8_t)src->custom_cmd_id;
  dst->data_length = (src->data).size;
  dst->data = (uint8_t *)(src->data).value;
  return;
}

