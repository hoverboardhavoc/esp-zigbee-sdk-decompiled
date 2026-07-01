/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_move
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_packet_move(zcl_packet_t *dst,zcl_packet_t *src)

{
  if ((src != (zcl_packet_t *)0x0) && (dst != (zcl_packet_t *)0x0)) {
    memcpy(dst,src,0x28);
    memset(src,0,0x28);
    return '\0';
  }
  return 0x87;
}

