/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_relay_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_relay_cmd(zmsg_t *msg,ezb_extaddr_t *dst_addr)

{
  ezb_err_t eVar1;
  zmsg_t *pzStack_1c;
  nwk_nlde_data_req_t nlde_req;
  
  pzStack_1c = (zmsg_t *)0x0;
  nlde_req.nsdu = (zmsg_t *)0x0;
  nlde_req.dst_addr = 0;
  nlde_req.radius = '\0';
  nlde_req.alias_seq_num = '\0';
  eVar1 = nwk_address_short_by_extended(dst_addr,&nlde_req);
  if (eVar1 == 0) {
    nlde_req._4_4_ = nlde_req._4_4_ & 0xfffeffff | 0x20000;
    pzStack_1c = msg;
    eVar1 = nwk_nlde_data_request(&pzStack_1c);
  }
  return eVar1;
}

