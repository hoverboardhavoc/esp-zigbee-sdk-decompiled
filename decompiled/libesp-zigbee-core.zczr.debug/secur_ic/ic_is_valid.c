/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> ic_is_valid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool ic_is_valid(uint8_t ic_type,uint8_t *ic)

{
  uint8_t uVar1;
  ushort uVar2;
  undefined3 extraout_var;
  uint16_t crc;
  
  uVar1 = ic_crc_offset(ic_type);
  uVar2 = crc16_next(0xffff,ic,CONCAT31(extraout_var,uVar1));
  return (ushort)~uVar2 == *(ushort *)(ic + CONCAT31(extraout_var,uVar1));
}

