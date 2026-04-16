/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_beacon_set_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t mac_beacon_set_payload(mac_beacon_t *beacon,uint8_t *buf,uint8_t len)

{
  size_t __n;
  undefined3 in_register_00002031;
  
  __n = CONCAT31(in_register_00002031,len);
  if (buf == (uint8_t *)0x0) {
    __n = 0;
  }
  else if (__n != 0) {
    memcpy(beacon + 1,buf,__n);
  }
  return (uint8_t)__n;
}

