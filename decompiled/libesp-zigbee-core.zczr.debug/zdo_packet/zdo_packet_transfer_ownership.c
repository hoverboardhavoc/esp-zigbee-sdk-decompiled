/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_transfer_ownership
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zmsg_t * zdo_packet_transfer_ownership(zdo_packet_t *packet)

{
  zmsg_t *pzVar1;
  
  if (packet != (zdo_packet_t *)0x0) {
    pzVar1 = packet->payload;
    packet->payload = (zdo_packet_payload_t *)0x0;
    return pzVar1;
  }
  return (zmsg_t *)0x0;
}

