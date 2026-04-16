/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_send_cmd_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_send_cmd_confirm(zmsg_t *msg,ezb_err_t error)

{
  undefined4 uVar1;
  char acStack_11 [4];
  aps_cmd_id_t cmd_id;
  
  acStack_11[0] = '\0';
  uVar1 = zmsg_get_offset();
  zmsg_read_bytes(msg,uVar1,1,acStack_11);
  if (acStack_11[0] == '\x05') {
    aps_cmd_handle_transport_key_sent(msg,error);
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

