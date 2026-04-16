/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_to_esp_zb_zcl_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_to_esp_zb_zcl_reporting_info
               (esp_zb_zcl_reporting_info_t *dst,ezb_zcl_reporting_info_temp_t *src)

{
  *(undefined1 *)&(dst->dst).short_addr = 0;
  *(undefined1 *)((int)&(dst->dst).short_addr + 1) = 0;
  (dst->dst).endpoint = '\0';
  (dst->dst).field_0x3 = 0;
  *(undefined1 *)&(dst->dst).profile_id = 0;
  *(undefined1 *)((int)&(dst->dst).profile_id + 1) = 0;
  dst->direction = src->direction;
  dst->ep = src->ep_id;
  dst->cluster_id = src->cluster_id;
  dst->cluster_role = src->cluster_role;
  dst->attr_id = src->attr_id;
  dst->manuf_code = src->manuf_code;
  dst->flags = (byte)((*(uint *)&src->cluster_role >> 0xc & 0xf) << 4) |
               (byte)(*(uint *)&src->cluster_role >> 8) & 0xf;
  memcpy(&dst->u,&src->u,0x20);
  dst->info = src;
  return;
}

