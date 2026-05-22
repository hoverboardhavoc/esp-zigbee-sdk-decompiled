/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_move
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_packet_move(zdo_packet_t *dst,zdo_packet_t *src)

{
  if ((src != (zdo_packet_t *)0x0) && (dst != (zdo_packet_t *)0x0)) {
    memcpy(dst,src,0x18);
    memset(src,0,0x18);
    return 0;
  }
  return 2;
}

