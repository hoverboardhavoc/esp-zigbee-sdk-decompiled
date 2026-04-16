/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_raise_address_conflict
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_raise_address_conflict(ezb_shortaddr_t offending_addr)

{
  undefined1 uStack_14;
  ezb_shortaddr_t eStack_13;
  undefined1 uStack_11;
  nwk_network_status_cmd_t cmd;
  
  uStack_14 = 0xd;
  uStack_11 = 0;
  eStack_13 = offending_addr;
  nwk_send_status(0xfffd,&uStack_14);
  nwk_handle_network_status_local(&uStack_14);
  return;
}

