/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_reset_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void touchlink_reset_commissioning(void)

{
  int iVar1;
  void *__s;
  
  iVar1 = touchlink_commissioning_get();
  milli_timer_stop(iVar1 + 0x40);
  iVar1 = touchlink_commissioning_get();
  milli_timer_stop(iVar1 + 0x10);
  iVar1 = touchlink_commissioning_get();
  milli_timer_stop(iVar1 + 0x24);
  __s = (void *)touchlink_commissioning_get();
  memset(__s,0,0x54);
  return;
}

