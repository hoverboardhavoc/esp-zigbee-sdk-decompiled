/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_core_compat.o -> convert_to_esp_zb_zcl_cmd_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_esp_zb_zcl_cmd_info(esp_zb_zcl_cmd_info_t *dst,ezb_zcl_cmd_hdr_t *src)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  
  (dst->src_address).addr_type = (src->src_addr).addr_mode;
  uVar1 = *(uint8_t *)((int)&(src->src_addr).u + 1);
  uVar2 = *(uint8_t *)((int)&(src->src_addr).u + 2);
  uVar3 = *(uint8_t *)((int)&(src->src_addr).u + 3);
  uVar4 = *(uint8_t *)((int)&(src->src_addr).u + 4);
  uVar5 = *(uint8_t *)((int)&(src->src_addr).u + 5);
  uVar6 = *(uint8_t *)((int)&(src->src_addr).u + 6);
  uVar7 = *(uint8_t *)((int)&(src->src_addr).u + 7);
  (dst->src_address).u.ieee_addr[0] = *(uint8_t *)&(src->src_addr).u;
  (dst->src_address).u.ieee_addr[1] = uVar1;
  (dst->src_address).u.ieee_addr[2] = uVar2;
  (dst->src_address).u.ieee_addr[3] = uVar3;
  (dst->src_address).u.ieee_addr[4] = uVar4;
  (dst->src_address).u.ieee_addr[5] = uVar5;
  (dst->src_address).u.ieee_addr[6] = uVar6;
  (dst->src_address).u.ieee_addr[7] = uVar7;
  dst->src_endpoint = src->src_ep;
  dst->dst_endpoint = src->dst_ep;
  dst->cluster = src->cluster_id;
  dst->profile = src->profile_id;
  (dst->header).fc = src->fc;
  (dst->header).manuf_code = src->manuf_code;
  (dst->header).tsn = src->tsn;
  (dst->header).rssi = src->rssi;
  (dst->command).id = src->cmd_id;
  (dst->command).direction = src->fc >> 3 & 1;
  (dst->command).is_common = (src->fc & 3) == 0;
  return;
}

