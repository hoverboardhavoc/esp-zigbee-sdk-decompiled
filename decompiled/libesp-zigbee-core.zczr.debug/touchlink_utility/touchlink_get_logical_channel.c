/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_logical_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_get_logical_channel(void)

{
  _Bool _Var1;
  uint8_t uVar2;
  int iVar3;
  undefined3 extraout_var;
  
  iVar3 = touchlink_device_info_get();
  _Var1 = touchlink_channel_is_valid(*(uint8_t *)(iVar3 + 1));
  if (CONCAT31(extraout_var,_Var1) == 0) {
    uVar2 = touchlink_assign_random_channel();
  }
  else {
    iVar3 = touchlink_device_info_get();
    uVar2 = *(uint8_t *)(iVar3 + 1);
  }
  return uVar2;
}

