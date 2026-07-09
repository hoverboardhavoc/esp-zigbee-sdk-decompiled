/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_secur_request_tclk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_secur_request_tclk(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  iVar1 = core_globals_get();
  if ((*(char *)(iVar1 + 0xcf8) == '\0') && (iVar1 = nwk_secur_is_authenticated(), iVar1 != 0)) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0x9b8) = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_2c = 4;
    puVar2 = (undefined4 *)aps_secur_get_tc_address();
    uStack_34 = *puVar2;
    uStack_30 = puVar2[1];
    iVar1 = apsme_request_key_request(&uStack_34);
    if (iVar1 == 0) {
      iVar3 = core_globals_get();
      *(undefined4 *)(iVar3 + 0xd0c) = param_1;
      iVar3 = core_globals_get();
      *(undefined4 *)(iVar3 + 0xd10) = param_2;
      iVar3 = core_globals_get();
      *(undefined1 *)(iVar3 + 0xcf8) = 2;
      iVar3 = core_globals_get();
      iVar4 = core_globals_get();
      milli_timer_start(iVar3 + 0xcfc,(*(ushort *)(iVar4 + 0x9ba) & 0x1f) * 1000);
      nwk_pim_start_fast_poll(0);
    }
  }
  else {
    iVar1 = 3;
  }
  return iVar1;
}

