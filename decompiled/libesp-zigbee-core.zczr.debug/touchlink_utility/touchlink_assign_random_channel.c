/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_assign_random_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_assign_random_channel(void)

{
  uint8_t uVar1;
  uint uVar2;
  _Bool _Var3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint8_t local_20 [4];
  uint8_t secondary_channels [12];
  uint8_t primary_channels [4];
  
  builtin_memcpy(secondary_channels + 8,"\v\x0f\x14\x19",4);
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = secondary_channels[uVar2 + 8];
    _Var3 = touchlink_channel_is_valid(uVar1);
    if (CONCAT31(extraout_var,_Var3) != 0) {
      return uVar1;
    }
  }
  builtin_memcpy(local_20,"\f\r\x0e\x10",4);
  builtin_memcpy(secondary_channels,"\x11\x12\x13\x15\x16\x17\x18\x1a",8);
  uVar2 = 0;
  while( true ) {
    if (0xb < uVar2) {
      return '\v';
    }
    uVar1 = secondary_channels[uVar2 - 4];
    _Var3 = touchlink_channel_is_valid(uVar1);
    if (CONCAT31(extraout_var_00,_Var3) != 0) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return uVar1;
}

