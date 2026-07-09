/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> time_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void time_cluster_srv_write_attr_hook(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 == 0) {
    iVar1 = time_server_get_attr_desc(8);
    if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 8) != (undefined4 *)0x0)) {
      **(undefined4 **)(iVar1 + 8) = *param_3;
    }
    iVar1 = time_server_get_interface(param_1);
    UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 4);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      __assert_func(0,0,0,0);
    }
                    /* WARNING: Could not recover jumptable at 0x00010240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*param_3);
    return;
  }
  return;
}

