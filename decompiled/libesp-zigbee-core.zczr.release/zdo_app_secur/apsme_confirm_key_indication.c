/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_secur.o -> apsme_confirm_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_confirm_key_indication(apsme_confirm_key_ind_t *ind)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (ind->key_type != '\x04') {
    return;
  }
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xd5c) != '\x03') {
    return;
  }
  nwk_pim_stop_fast_poll();
  uVar2 = 0;
  if (ind->status != 0) {
    uVar2 = ind->status | 0x300;
  }
  iVar1 = core_globals_get();
  milli_timer_stop(iVar1 + 0xd60);
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd5c) = 0;
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xd70) == 0) {
    return;
  }
  iVar1 = core_globals_get();
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xd70);
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001006c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2,*(undefined4 *)(iVar1 + 0xd74),UNRECOVERED_JUMPTABLE);
  return;
}

