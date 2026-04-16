/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_init(zcl_packet_t *packet,_Bool is_manuf)

{
  zcl_status_t zVar1;
  zcl_packet_payload_t *pzVar2;
  undefined3 in_register_0000202d;
  
  if (packet == (zcl_packet_t *)0x0) {
    zVar1 = 0x87;
  }
  else {
    memset(packet,0,0x22);
    if (CONCAT31(in_register_0000202d,is_manuf) != 0) {
      (packet->header).fc = '\x04';
    }
    (packet->header).tsn = 0xff;
    pzVar2 = (zcl_packet_payload_t *)zmsg_alloc(0x34);
    packet->payload = pzVar2;
    if (pzVar2 == (zcl_packet_payload_t *)0x0) {
      zVar1 = 0x89;
    }
    else {
      zVar1 = '\0';
    }
  }
  return zVar1;
}

