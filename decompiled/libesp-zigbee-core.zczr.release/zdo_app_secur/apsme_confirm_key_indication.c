/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  if (*(char *)(iVar1 + 0xcf8) != '\x03') {
    return;
  }
  nwk_pim_stop_fast_poll();
  uVar2 = 0;
  if (ind->status != 0) {
    uVar2 = ind->status | 0x300;
  }
  iVar1 = core_globals_get();
  milli_timer_stop(iVar1 + 0xcfc);
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xcf8) = 0;
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xd0c) == 0) {
    return;
  }
  iVar1 = core_globals_get();
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xd0c);
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001006c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2,*(undefined4 *)(iVar1 + 0xd10),UNRECOVERED_JUMPTABLE);
  return;
}

