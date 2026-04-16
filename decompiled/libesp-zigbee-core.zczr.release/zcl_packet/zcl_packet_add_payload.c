/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_add_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_packet_add_payload(zcl_packet_t *packet,uint16_t length,uint8_t *payload)

{
  undefined2 in_register_0000202e;
  
  if (((packet != (zcl_packet_t *)0x0) && (CONCAT22(in_register_0000202e,length) != 0)) &&
     (payload != (uint8_t *)0x0)) {
    zmsg_append_bytes(packet->payload);
    return;
  }
  return;
}

