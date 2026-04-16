/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_raise_source_route_failure
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_raise_source_route_failure(ezb_shortaddr_t src_addr,ezb_shortaddr_t dst_addr)

{
  undefined2 in_register_0000202a;
  undefined4 uStack_14;
  nwk_network_status_cmd_t cmd;
  
  uStack_14 = (uint)CONCAT21(dst_addr,0xb);
  nwk_send_status(CONCAT22(in_register_0000202a,src_addr),&uStack_14);
  nwk_handle_network_status_local(&uStack_14);
  return;
}

