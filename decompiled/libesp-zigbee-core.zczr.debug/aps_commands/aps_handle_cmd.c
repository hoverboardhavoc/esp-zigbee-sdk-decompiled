/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_handle_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_handle_cmd(int param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_1 + 0xc) & 0xc) != 0xc) {
    bVar1 = *(byte *)(param_1 + 0xe);
    if (bVar1 == 9) {
      aps_cmd_handle_switch_key();
      return;
    }
    if (bVar1 < 10) {
      if (bVar1 == 7) {
        aps_cmd_handle_remove_device();
        return;
      }
      if (bVar1 < 8) {
        if (bVar1 == 5) {
          aps_cmd_handle_transport_key();
          return;
        }
        if (bVar1 == 6) {
          aps_cmd_handle_update_device();
          return;
        }
      }
      else if (bVar1 == 8) {
        aps_cmd_handle_request_key();
        return;
      }
    }
    else {
      if (bVar1 == 0x10) {
        aps_cmd_handle_confirm_key();
        return;
      }
      if (bVar1 < 0x11) {
        if (bVar1 == 0xe) {
          aps_cmd_handle_tunnel();
          return;
        }
        if (bVar1 == 0xf) {
          aps_cmd_handle_verify_key();
          return;
        }
      }
      else if ((byte)(bVar1 - 0x11) < 2) {
        uVar2 = aps_frame_cmd_str(bVar1);
        log_write(2,"aps_commands.c","APS %s Command not supported",uVar2);
        return;
      }
    }
  }
  if (param_2 != 0) {
    zmsg_free(param_2);
  }
  return;
}

