/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_command(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = **(byte **)(param_2 + 0x24);
  if (bVar1 == 4) {
    mac_handle_data_req();
  }
  else if (bVar1 < 5) {
    if (bVar1 == 1) {
      if ((*(byte *)(param_1 + 0x2a) & 1) != 0) {
        mac_handle_association_req();
      }
    }
    else if (((bVar1 == 2) && ((*(uint *)(param_1 + 0x2c) & 0xffff00) == 0x60200)) &&
            (*(char *)(param_2 + 4) != '\0')) {
      mac_stop_timer();
      mac_finish_op(param_1);
      mac_handle_association_rsp(param_1,param_2);
      mac_perform_next_op(param_1);
    }
  }
  else if ((bVar1 == 7) && (iVar2 = mac_should_send_beacon(), iVar2 != 0)) {
    mac_start_op(param_1,7);
  }
  return;
}

