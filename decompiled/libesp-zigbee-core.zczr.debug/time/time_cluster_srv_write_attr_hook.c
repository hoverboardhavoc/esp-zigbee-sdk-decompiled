/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> time_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void time_cluster_srv_write_attr_hook(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = time_server_get_attr_desc(8);
    if ((iVar1 != 0) && (*(undefined4 **)(iVar1 + 8) != (undefined4 *)0x0)) {
      **(undefined4 **)(iVar1 + 8) = *param_3;
    }
    iVar1 = time_server_get_interface(param_1);
    if (*(code **)(iVar1 + 4) == (code *)0x0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/time.c",0x116,
                    "time_cluster_srv_write_attr_hook","interface->set_utc_time != ((void *)0)");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    (**(code **)(iVar1 + 4))(*param_3);
  }
  return;
}

