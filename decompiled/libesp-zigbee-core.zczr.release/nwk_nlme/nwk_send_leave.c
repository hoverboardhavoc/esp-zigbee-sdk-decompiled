/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_send_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_send_leave(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = zmsg_alloc(0x2f);
  if (iVar1 == 0) {
    iVar1 = __assert_func(0,0,0);
  }
  nwk_build_leave(param_1,param_2);
  nwk_fwd_send_msg_delayed(iVar1,0);
  return;
}

