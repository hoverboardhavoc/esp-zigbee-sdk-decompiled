/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_fragment_is_supported
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zcl_packet_fragment_is_supported(zcl_packet_t *packet)

{
  undefined1 uVar1;
  
  if (packet == (zcl_packet_t *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = zcl_cluster_fragment_is_supported((packet->header).cluster_id);
  }
  return (_Bool)uVar1;
}

