/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_handle_datagram
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_handle_datagram(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = aps_frame_need_ack();
  if (((iVar1 == 0) || (iVar1 = aps_send_ack(param_1,param_2,0,0xff), iVar1 == 0)) &&
     (iVar1 = aps_check_duplicates(param_1), iVar1 == 0)) {
    bVar2 = *(byte *)(param_1 + 0xc) & 3;
    if (bVar2 == 1) {
      aps_handle_cmd(param_1,param_2);
      return;
    }
    if (bVar2 == 2) {
      aps_retrans_handle_ack(param_1,param_2);
      return;
    }
    if ((*(byte *)(param_1 + 0xc) & 3) == 0) {
      aps_handle_data(param_1,param_2);
      return;
    }
  }
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  return;
}

