/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_common.o -> zcl_packet_to_message
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_to_message(zcl_message_info_t *info,zcl_packet_t *packet)

{
  if ((info != (zcl_message_info_t *)0x0) && (packet != (zcl_packet_t *)0x0)) {
    info->status = '\0';
    info->dst_ep = (packet->header).dst_ep;
    info->cluster_id = (packet->header).cluster_id;
    info->cluster_role = (((packet->header).fc & 8) != 0) + '\x01';
    return '\0';
  }
  return 0x87;
}

