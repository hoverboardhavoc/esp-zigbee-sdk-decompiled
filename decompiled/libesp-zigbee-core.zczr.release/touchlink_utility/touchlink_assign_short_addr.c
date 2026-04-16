/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_assign_short_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_shortaddr_t touchlink_assign_short_addr(void)

{
  ezb_shortaddr_t eVar1;
  int iVar2;
  
  iVar2 = nwk_check_assigned_shortaddr(0xffff);
  if (iVar2 == 0) {
    eVar1 = nwk_assign_shortaddr();
    return eVar1;
  }
  return 0xffff;
}

