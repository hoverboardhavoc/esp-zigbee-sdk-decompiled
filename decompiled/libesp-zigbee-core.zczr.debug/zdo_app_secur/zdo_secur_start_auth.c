/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_start_auth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_secur_start_auth(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  if ((*(char *)(iVar1 + 0xcf8) == '\0') && (iVar1 = nwk_secur_is_authenticated(), iVar1 == 0)) {
    aps_secur_get_tc_address();
    iVar1 = aps_secur_key_pair_find_or_create();
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = aps_secur_joiner_setup_key_pair();
      if (iVar1 == 0) {
        iVar2 = core_globals_get();
        *(undefined4 *)(iVar2 + 0xd0c) = param_1;
        iVar2 = core_globals_get();
        *(undefined4 *)(iVar2 + 0xd10) = param_2;
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xcf8) = 1;
        iVar2 = core_globals_get();
        iVar3 = core_globals_get();
        milli_timer_start(iVar2 + 0xcfc,(uint)*(byte *)(iVar3 + 0x9b4) * 1000);
        iVar2 = nwk_is_device_zed();
        if (iVar2 != 0) {
          iVar2 = core_globals_get();
          if (*(char *)(iVar2 + 0x9ee) == '\0') {
            nwk_pim_start_poll();
          }
        }
        nwk_pim_start_fast_poll(0);
      }
    }
  }
  else {
    iVar1 = 3;
  }
  return iVar1;
}

