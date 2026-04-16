/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> af_read_le16
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t af_read_le16(zmsg_t *payload,uint16_t *offset,uint16_t *value)

{
  int iVar1;
  uint16_t uVar2;
  
  iVar1 = zmsg_read_bytes(*offset,2,value);
  if (iVar1 == 0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = *offset + (uint16_t)iVar1;
  }
  *offset = uVar2;
  return (uint16_t)iVar1;
}

