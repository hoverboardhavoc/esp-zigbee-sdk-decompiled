/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cluster_srv_set_attr_val_post_proc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ias_zone_cluster_srv_set_attr_val_post_proc
               (zcl_packet_header_t *header,uint16_t attr_id,void *new_value)

{
  undefined2 in_register_0000202e;
  
  if (CONCAT22(in_register_0000202e,attr_id) == 0x10) {
    ias_zone_cie_address_attr_write_handler
              (header->dst_ep,header->src_ep,(header->src_addr).u.short_addr,new_value);
  }
  return;
}

