/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_set_role
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_set_role(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = touchlink_commissioning_get();
  *(undefined1 *)(iVar1 + 1) = param_1;
  iVar1 = touchlink_commissioning_get();
  *(undefined4 *)(iVar1 + 0x38) = param_2;
  return;
}

