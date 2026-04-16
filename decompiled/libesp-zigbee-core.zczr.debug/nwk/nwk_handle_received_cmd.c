/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_handle_received_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: cmd_id */
/* WARNING: Unknown calling convention */

void nwk_handle_received_cmd(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ushort uVar1;
  ezb_shortaddr_t eVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  uint8_t uStack_15;
  nwk_network_status_cmd_t cmd;
  uint8_t cmd_id;
  
  cmd.command_id = '\0';
  uVar3 = zmsg_get_offset();
  zmsg_read_bytes(msg,uVar3,1,&cmd.command_id);
  if (cmd.command_id == '\a') {
    nwk_handle_rejoin_rsp(msg,rx_info);
    msg = (zmsg_t *)0x0;
    goto _L0;
  }
  if (cmd.command_id < 8) {
    if (cmd.command_id == '\x04') {
      nwk_handle_leave(msg,rx_info);
      msg = (zmsg_t *)0x0;
      goto _L0;
    }
    if (cmd.command_id < 5) {
      if (cmd.command_id == '\x02') {
        nwk_mesh_handle_rrep(msg,rx_info);
        msg = (zmsg_t *)0x0;
        goto _L0;
      }
      if (cmd.command_id == '\x03') {
        nwk_handle_network_status(msg,rx_info);
        msg = (zmsg_t *)0x0;
        goto _L0;
      }
      if (cmd.command_id == '\x01') {
        nwk_mesh_handle_rreq(msg,rx_info);
        msg = (zmsg_t *)0x0;
        goto _L0;
      }
    }
    else {
      if (cmd.command_id == '\x05') {
        nwk_mesh_handle_rrec(msg,rx_info);
        msg = (zmsg_t *)0x0;
        goto _L0;
      }
      if (cmd.command_id == '\x06') {
        nwk_handle_rejoin_req(msg,rx_info);
        msg = (zmsg_t *)0x0;
        goto _L0;
      }
    }
    goto _L0;
  }
  if (cmd.command_id == '\f') {
    nwk_ed_handle_ed_tmo_rsp(msg,rx_info);
    msg = (zmsg_t *)0x0;
    goto _L0;
  }
  if (cmd.command_id < 0xd) {
    if (10 < cmd.command_id) {
      if (cmd.command_id == '\v') {
        nwk_ed_mngr_handle_ed_tmo_req(msg,rx_info);
        msg = (zmsg_t *)0x0;
        goto _L0;
      }
      goto _L0;
    }
    if (cmd.command_id < 9) {
      if (cmd.command_id == '\b') {
        nwk_link_mngr_handle_link_status(msg,rx_info);
        goto _L0;
      }
      goto _L0;
    }
_L0:
    uVar3 = nwk_frame_cmd_str(cmd.command_id);
    log_write(2,"nwk.c","Receive unsupported command: %s",uVar3);
  }
  else {
    if (cmd.command_id == '\x0e') {
      nwk_handle_network_comm_req(msg,rx_info);
      msg = (zmsg_t *)0x0;
      goto _L0;
    }
    if (cmd.command_id == '\x0f') {
      nwk_handle_network_comm_rsp(msg,rx_info);
      msg = (zmsg_t *)0x0;
      goto _L0;
    }
    if (cmd.command_id == '\r') goto _L0;
_L0:
    log_write(1,"nwk.c","Receive invalid command: %d");
  }
  uVar1 = rx_info->nwk_dst_addr;
  eVar2 = nwk_get_short_address();
  if ((uint)uVar1 == CONCAT22(extraout_var,eVar2)) {
    uStack_18 = 0x13;
    uStack_17 = (undefined1)rx_info->nwk_src_addr;
    uStack_16 = (undefined1)(rx_info->nwk_src_addr >> 8);
    uStack_15 = cmd.command_id;
    nwk_send_status(&uStack_18);
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

