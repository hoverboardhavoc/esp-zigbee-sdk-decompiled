/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_permit_joining
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_permit_joining(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  
  iVar1 = nwk_is_router_started();
  if (iVar1 == 0) {
    uVar2 = 0x2c2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(byte *)(iVar1 + 0xb07) != param_1) {
      nwk_set_mac_permit_joining(param_1 != 0);
      memset(&uStack_17,0,7);
      uStack_18 = 1;
      uStack_16 = (char)param_1;
      nwk_nlme_event_indication(&uStack_18);
      iVar1 = core_globals_get();
      *(char *)(iVar1 + 0xb07) = (char)param_1;
    }
    uVar2 = 0;
  }
  return uVar2;
}

