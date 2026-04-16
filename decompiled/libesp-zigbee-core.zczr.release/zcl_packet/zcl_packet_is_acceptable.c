/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_is_acceptable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_is_acceptable(zcl_packet_t *packet)

{
  int iVar1;
  
  if (packet == (zcl_packet_t *)0x0) {
    return 0xfe;
  }
  iVar1 = af_endpoint_is_gateway((packet->header).dst_ep);
  if (iVar1 == 0) {
    iVar1 = af_get_ep_desc((packet->header).dst_ep);
    if (iVar1 == 0) {
      return 0x81;
    }
    if (*(uint16_t *)(iVar1 + 2) != (packet->header).profile_id) {
      return 0x81;
    }
    iVar1 = zcl_get_cluster_desc
                      ((packet->header).dst_ep,(packet->header).cluster_id,
                       (((packet->header).fc & 8) != 0) + '\x01');
    if (iVar1 == 0) {
      return 0xc3;
    }
  }
  return '\0';
}

