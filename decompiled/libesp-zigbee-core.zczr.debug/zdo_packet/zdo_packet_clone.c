/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdo_packet_t * zdo_packet_clone(zdo_packet_t *src)

{
  zdo_packet_t *__dest;
  zdo_packet_payload_t *pzVar1;
  
  if (src == (zdo_packet_t *)0x0) {
    __dest = (zdo_packet_t *)0x0;
  }
  else {
    __dest = (zdo_packet_t *)calloc(1,0x18);
    if (__dest != (zdo_packet_t *)0x0) {
      memcpy(__dest,src,0x18);
      pzVar1 = (zdo_packet_payload_t *)zmsg_clone(src->payload);
      __dest->payload = pzVar1;
      if (pzVar1 == (zdo_packet_payload_t *)0x0) {
        mm_free(__dest);
        __dest = (zdo_packet_t *)0x0;
      }
    }
  }
  return __dest;
}

