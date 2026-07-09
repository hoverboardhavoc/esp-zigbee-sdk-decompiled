/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_call_user_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_secur_call_user_cb(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xd0c) != 0) {
    iVar1 = core_globals_get();
    pcVar2 = *(code **)(iVar1 + 0xd0c);
    iVar1 = core_globals_get();
    (*pcVar2)(param_1,*(undefined4 *)(iVar1 + 0xd10));
  }
  return;
}

