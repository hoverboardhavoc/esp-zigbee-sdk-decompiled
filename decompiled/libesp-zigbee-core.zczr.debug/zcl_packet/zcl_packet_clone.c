/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_clone(zcl_packet_t *dst,zcl_packet_t *src)

{
  zcl_status_t zVar1;
  zcl_packet_payload_t *pzVar2;
  
  if (dst == (zcl_packet_t *)0x0) {
    zVar1 = 0x87;
  }
  else if (src == (zcl_packet_t *)0x0) {
    zVar1 = 0x87;
  }
  else {
    memcpy(dst,src,0x22);
    pzVar2 = (zcl_packet_payload_t *)zmsg_clone(src->payload);
    dst->payload = pzVar2;
    zVar1 = '\0';
  }
  return zVar1;
}

