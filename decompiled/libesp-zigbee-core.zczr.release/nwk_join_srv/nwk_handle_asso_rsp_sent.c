/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_asso_rsp_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_asso_rsp_sent(int param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 10) != '\x03') {
    param_1 = __assert_func(0,0,0,0);
  }
  uVar1 = 0;
  if (*(byte *)(param_1 + 0x16) != 0) {
    uVar1 = *(byte *)(param_1 + 0x16) | 0x100;
  }
  nwk_accept_child_done(uVar1,param_1 + 0xc,0);
  return;
}

