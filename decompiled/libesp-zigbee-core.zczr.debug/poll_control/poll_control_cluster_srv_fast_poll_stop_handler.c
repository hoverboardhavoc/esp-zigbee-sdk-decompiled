/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_fast_poll_stop_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_srv_fast_poll_stop_handler(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar2 = 0xfe;
  }
  else {
    iVar1 = poll_control_source_is_exist_in_bind_table
                      (*(undefined1 *)(param_1 + 0x14),*(undefined2 *)(param_1 + 2));
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = nwk_pim_is_fast_poll_running();
      if (iVar1 == 0) {
        uVar2 = 1;
      }
      else {
        nwk_pim_stop_fast_poll();
        iVar1 = nwk_pim_is_fast_poll_running();
        if (iVar1 == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

