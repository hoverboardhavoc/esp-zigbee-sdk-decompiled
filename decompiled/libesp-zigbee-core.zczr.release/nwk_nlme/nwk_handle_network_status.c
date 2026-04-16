/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_network_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_status(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  short sVar1;
  int iVar2;
  nwk_network_status_cmd_t nStack_14;
  nwk_network_status_cmd_t cmd;
  
  iVar2 = nwk_is_joined();
  if (iVar2 == 0) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    iVar2 = nwk_secur_get_seclevel();
    if ((ushort)(iVar2 != 0) == (msg->flags >> 1 & 1)) {
      nStack_14.status_code = '\0';
      nStack_14.target_addr = 0;
      nStack_14.command_id = '\0';
      sVar1 = zmsg_get_offset(msg);
      zmsg_read_bytes(msg,sVar1 + 1,4,&nStack_14);
      if ((((uint)nStack_14 & 0xff) < 0x14) && ((0x83807U >> ((uint)nStack_14 & 0x1f) & 1) != 0)) {
        nwk_handle_network_status_local(&nStack_14);
      }
    }
  }
  zmsg_free(msg);
  return;
}

