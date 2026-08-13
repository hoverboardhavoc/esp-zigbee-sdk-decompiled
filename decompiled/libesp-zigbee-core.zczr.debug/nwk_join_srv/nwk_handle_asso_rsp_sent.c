/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_asso_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_asso_rsp_sent(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 10) == '\x03') {
    iVar2 = param_1 + 0xc;
    if (*(byte *)(param_1 + 0x16) != 0) {
      uVar1 = *(byte *)(param_1 + 0x16) | 0x100;
      goto _L0;
    }
  }
  else {
    iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x1b4,
                          "nwk_handle_asso_rsp_sent",
                          "ind->addresses.destination.addr_mode == EZB_ADDR_MODE_EXT");
  }
  uVar1 = 0;
_L0:
  nwk_accept_child_done(uVar1,iVar2,0);
  return;
}

