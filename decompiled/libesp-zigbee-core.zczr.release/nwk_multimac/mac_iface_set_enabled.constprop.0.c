/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> mac_iface_set_enabled.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_iface_set_enabled_constprop_0(undefined4 param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  iVar1 = core_globals_get();
  UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(*(int *)(iVar1 + 0xc84) + 4);
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001003a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(iVar1 + 0xc84),param_1,UNRECOVERED_JUMPTABLE);
  return;
}

