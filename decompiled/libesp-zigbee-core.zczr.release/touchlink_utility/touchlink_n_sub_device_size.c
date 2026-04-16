/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_n_sub_device_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_n_sub_device_size(void)

{
  uint8_t uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = '\0'; (iVar2 = af_get_next_simple_desc(iVar2), iVar2 != 0 && (uVar1 != '\b'));
      uVar1 = uVar1 + '\x01') {
  }
  return uVar1;
}

