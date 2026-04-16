/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> af_read_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t af_read_bytes(zmsg_t *payload,uint16_t *offset,uint16_t length,uint8_t *value)

{
  uint16_t uVar1;
  int iVar2;
  undefined2 in_register_00002032;
  
  iVar2 = zmsg_read_bytes(*offset);
  if ((iVar2 == 0) && (CONCAT22(in_register_00002032,length) != 0)) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = (short)iVar2 + *offset;
  }
  *offset = uVar1;
  return uVar1;
}

