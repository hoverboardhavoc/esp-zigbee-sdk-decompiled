/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_off_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void on_off_cluster_off_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  int extraout_a1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    on_off_process_transition(*(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x20),0,0,0)
    ;
    zcl_packet_setup_default_response(param_2,param_1,0);
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x156,
                        "on_off_cluster_off_cmd_handler","packet && rsp");
  if ((iVar1 != 0) && (extraout_a1 != 0)) {
    on_off_process_transition(*(undefined1 *)(iVar1 + 0x15),*(undefined1 *)(iVar1 + 0x20),1,0,0);
    zcl_packet_setup_default_response(extraout_a1,iVar1,0);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x165,
                "on_off_cluster_on_cmd_handler","packet && rsp");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

