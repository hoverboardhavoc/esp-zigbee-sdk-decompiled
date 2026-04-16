/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_packet_req_handler(zdo_packet_t *packet)

{
  ushort uVar1;
  zdp_status_t zVar2;
  
  if (packet == (zdo_packet_t *)0x0) {
    zVar2 = 0x80;
  }
  else {
    uVar1 = packet->cluster_id;
    if (uVar1 < 0x20) {
      zVar2 = zdo_device_service_discovery_req_handler();
      return zVar2;
    }
    if (uVar1 < 0x30) {
      zVar2 = zdo_bind_mgmt_req_handler();
      return zVar2;
    }
    zVar2 = 0x84;
    if (uVar1 < 0x40) {
      zVar2 = zdo_nwk_mgmt_req_handler();
      return zVar2;
    }
  }
  return zVar2;
}

