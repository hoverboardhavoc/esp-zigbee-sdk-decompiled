/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_join_srv_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_srv_handle_tick(void)

{
  int iVar1;
  undefined1 uStack_18;
  undefined1 auStack_17 [15];
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xb07) != '\0') {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xb07) != -1) {
      iVar1 = core_globals_get();
      *(char *)(iVar1 + 0xb07) = *(char *)(iVar1 + 0xb07) + -1;
      iVar1 = core_globals_get();
      if (*(char *)(iVar1 + 0xb07) == '\0') {
        nwk_set_mac_permit_joining(0);
        memset(auStack_17,0,7);
        uStack_18 = 1;
        nwk_nlme_event_indication(&uStack_18);
      }
    }
  }
  return;
}

