/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_handle_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_handle_cmd(aps_header_t *aps_hdr,zmsg_t *msg)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((aps_hdr->fcf & 0xc) != 0xc) {
    bVar1 = aps_hdr->cmd_id;
    if (bVar1 == 9) {
      aps_cmd_handle_switch_key(aps_hdr,msg);
      return;
    }
    if (bVar1 < 10) {
      if (bVar1 == 7) {
        aps_cmd_handle_remove_device(aps_hdr,msg);
        return;
      }
      if (bVar1 < 8) {
        if (bVar1 == 5) {
          aps_cmd_handle_transport_key(aps_hdr,msg);
          return;
        }
        if (bVar1 == 6) {
          aps_cmd_handle_update_device(aps_hdr,msg);
          return;
        }
      }
      else if (bVar1 == 8) {
        aps_cmd_handle_request_key(aps_hdr,msg);
        return;
      }
    }
    else {
      if (bVar1 == 0x10) {
        aps_cmd_handle_confirm_key(aps_hdr,msg);
        return;
      }
      if (bVar1 < 0x11) {
        if (bVar1 == 0xe) {
          aps_cmd_handle_tunnel(aps_hdr,msg);
          return;
        }
        if (bVar1 == 0xf) {
          aps_cmd_handle_verify_key(aps_hdr,msg);
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
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

