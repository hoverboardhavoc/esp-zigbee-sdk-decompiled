/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_packet_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  int iVar2;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar1 = 0x87;
  }
  else {
    iVar2 = zcl_packet_is_general();
    if (iVar2 == 0) {
      iVar2 = zcl_packet_is_manuf_spec(packet);
      if (iVar2 == 0) {
        zVar1 = zcl_cluster_cmd_handler(packet);
      }
      else {
        zVar1 = zcl_message_notify_manuf_spec_cmd(packet);
      }
    }
    else {
      zVar1 = zcl_general_cmd_handler(packet);
    }
  }
  return zVar1;
}

