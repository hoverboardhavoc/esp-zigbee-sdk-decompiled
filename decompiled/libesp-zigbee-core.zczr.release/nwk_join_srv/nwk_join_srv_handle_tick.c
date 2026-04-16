/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_join_srv_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_join_srv_handle_tick(void)

{
  int iVar1;
  undefined1 uStack_18;
  undefined1 auStack_17 [3];
  nwk_nlme_event_ind_t ind;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xb07) != '\0') {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xb07) != -1) {
      iVar1 = core_globals_get();
      *(char *)(iVar1 + 0xb07) = *(char *)(iVar1 + 0xb07) + -1;
      iVar1 = core_globals_get();
      if (*(char *)(iVar1 + 0xb07) == '\0') {
        nwk_set_mac_permit_joining(false);
        memset(auStack_17,0,7);
        uStack_18 = 1;
        nwk_nlme_event_indication(&uStack_18);
      }
    }
  }
  return;
}

