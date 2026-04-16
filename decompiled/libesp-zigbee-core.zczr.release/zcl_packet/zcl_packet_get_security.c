/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_get_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zcl_packet_get_security(zcl_packet_t *packet)

{
  ushort uVar1;
  uint8_t uVar2;
  
  if (packet == (zcl_packet_t *)0x0) {
    uVar2 = '\0';
  }
  else {
    uVar2 = '\0';
    if (packet->payload != (zcl_packet_payload_t *)0x0) {
      uVar1 = packet->payload->flags;
      uVar2 = '\x01';
      if ((uVar1 & 2) == 0) {
        return (byte)(uVar1 >> 1) & 2;
      }
    }
  }
  return uVar2;
}

