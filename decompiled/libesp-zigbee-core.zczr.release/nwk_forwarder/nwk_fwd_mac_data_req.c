/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_mac_data_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_mac_data_req(undefined4 param_1,undefined4 param_2,undefined2 param_3,uint param_4)

{
  int iVar1;
  undefined4 uStack_3c;
  undefined1 auStack_38 [2];
  undefined2 uStack_36;
  undefined1 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_24;
  byte bStack_22;
  
  memset(auStack_38,0,0x18);
  auStack_38[0] = 2;
  uStack_3c = param_1;
  iVar1 = core_globals_get();
  uStack_36 = *(undefined2 *)(iVar1 + 0x9e2);
  uStack_2e = 2;
  uStack_2c = param_3;
  iVar1 = core_globals_get();
  uStack_24 = *(undefined2 *)(iVar1 + 0x9e4);
  bStack_22 = bStack_22 & 0xfd | (byte)((param_4 & 1) << 1);
  iVar1 = nwk_process_transmit_security(param_2,param_1);
  if ((iVar1 != 0) || (iVar1 = nwk_mm_data_request(param_2,&uStack_3c), iVar1 != 0)) {
    nwk_fwd_finish_tx(param_1,iVar1);
  }
  return;
}

