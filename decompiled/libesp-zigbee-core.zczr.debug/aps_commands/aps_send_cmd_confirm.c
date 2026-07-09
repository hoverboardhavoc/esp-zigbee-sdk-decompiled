/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_send_cmd_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_cmd_confirm(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char acStack_11 [5];
  
  acStack_11[0] = '\0';
  uVar1 = zmsg_get_offset();
  zmsg_read_bytes(param_1,uVar1,1,acStack_11);
  if (acStack_11[0] == '\x05') {
    aps_cmd_handle_transport_key_sent(param_1,param_2);
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

