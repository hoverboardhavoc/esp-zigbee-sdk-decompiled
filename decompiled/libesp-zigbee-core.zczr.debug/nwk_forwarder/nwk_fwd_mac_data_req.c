/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_mac_data_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_mac_data_req(undefined4 param_1,undefined4 param_2,undefined2 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_38 = 2;
  uStack_3c = param_1;
  iVar2 = core_globals_get();
  uStack_38 = CONCAT22(*(undefined2 *)(iVar2 + 0x9e2),(undefined2)uStack_38);
  uStack_30._0_3_ = CONCAT12(2,(undefined2)uStack_30);
  uStack_2c = CONCAT22(uStack_2c._2_2_,param_3);
  iVar2 = core_globals_get();
  uVar1 = (uint)uStack_24 >> 0x10;
  uStack_24._0_3_ =
       CONCAT12((byte)uVar1 & 0xfd | (byte)((param_4 & 1) << 1),*(undefined2 *)(iVar2 + 0x9e4));
  iVar2 = nwk_process_transmit_security(param_2,param_1);
  if ((iVar2 != 0) || (iVar2 = nwk_mm_data_request(param_2,&uStack_3c), iVar2 != 0)) {
    nwk_fwd_finish_tx(param_1,iVar2);
  }
  return;
}

