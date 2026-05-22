/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_call_user_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_secur_call_user_cb(ezb_err_t error)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xd0c) != 0) {
    iVar1 = core_globals_get();
    pcVar2 = *(code **)(iVar1 + 0xd0c);
    iVar1 = core_globals_get();
    (*pcVar2)(error,*(undefined4 *)(iVar1 + 0xd10));
  }
  return;
}

