/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> convert_to_esp_zb_zcl_cmd_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_esp_zb_zcl_cmd_info(esp_zb_zcl_cmd_info_t *dst,ezb_zcl_cmd_hdr_t *src)

{
  byte bVar1;
  
  (dst->src_address).addr_type = (src->src_addr).addr_mode;
  memcpy(&(dst->src_address).u,&(src->src_addr).u,8);
  dst->src_endpoint = src->src_ep;
  dst->dst_endpoint = src->dst_ep;
  dst->cluster = src->cluster_id;
  dst->profile = src->profile_id;
  bVar1 = src->fc;
  (dst->header).fc = bVar1;
  (dst->header).manuf_code = src->manuf_code;
  (dst->header).tsn = src->tsn;
  (dst->header).rssi = src->rssi;
  (dst->command).id = src->cmd_id;
  (dst->command).direction = bVar1 >> 3 & 1;
  (dst->command).is_common = (bVar1 & 3) == 0;
  return;
}

