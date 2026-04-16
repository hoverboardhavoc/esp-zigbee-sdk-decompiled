/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_add_cnf_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ezb_err_t af_data_add_cnf_cb(zmsg_t *msg,af_user_cnf_ctx_t cnf_ctx)

{
  undefined4 *puVar1;
  int iVar2;
  ezb_err_t eVar3;
  int in_a1;
  undefined4 in_a2;
  af_user_cnf_ctx_t cnf_ctx_local;
  
  if (in_a1 == 0) {
    eVar3 = 0;
  }
  else {
    puVar1 = (undefined4 *)calloc(1,0x10);
    if (puVar1 == (undefined4 *)0x0) {
      eVar3 = 1;
    }
    else {
      puVar1[1] = in_a1;
      puVar1[2] = in_a2;
      *puVar1 = msg;
      puVar1[3] = puVar1 + 3;
      iVar2 = core_globals_get();
      puVar1[3] = *(undefined4 *)(iVar2 + 0xd08);
      *(undefined4 **)(iVar2 + 0xd08) = puVar1 + 3;
      eVar3 = 0;
    }
  }
  return eVar3;
}

