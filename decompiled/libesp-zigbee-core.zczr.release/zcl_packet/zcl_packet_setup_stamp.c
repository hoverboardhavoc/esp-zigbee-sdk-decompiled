/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_stamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_packet_setup_stamp
               (zcl_packet_t *packet,uint8_t src_ep,uint8_t dst_ep,uint16_t cluster_id,
               uint16_t profile_id,uint8_t addr_mode,uint8_t *addr)

{
  uint8_t *extraout_a1;
  
  if (addr == (uint8_t *)0x0) {
    cluster_id = 0;
    dst_ep = '\0';
    packet = (zcl_packet_t *)__assert_func(0,0);
    addr = extraout_a1;
  }
  (packet->header).dst_ep = dst_ep;
  (packet->header).src_ep = src_ep;
  (packet->header).cluster_id = cluster_id;
  (packet->header).profile_id = profile_id;
  (packet->header).dst_addr.addr_mode = addr_mode;
  memcpy(&(packet->header).dst_addr.u,addr,8);
  return;
}

