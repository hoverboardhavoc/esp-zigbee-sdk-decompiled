/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
      puVar1[3] = *(undefined4 *)(iVar2 + 0xca4);
      *(undefined4 **)(iVar2 + 0xca4) = puVar1 + 3;
      eVar3 = 0;
    }
  }
  return eVar3;
}

