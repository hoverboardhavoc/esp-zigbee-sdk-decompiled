/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_md_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_md_start(int *param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 != (int *)0x0) {
    if (param_2 == 1) {
      UNRECOVERED_JUMPTABLE = crypto_aes_mmo_hash_start;
      pcVar2 = crypto_aes_mmo_hash_update;
      pcVar3 = crypto_aes_mmo_hash_finish;
    }
    else {
      if (param_2 != 2) goto _L0;
      UNRECOVERED_JUMPTABLE = crypto_sha256_hash_start;
      pcVar2 = crypto_sha256_hash_update;
      pcVar3 = crypto_sha256_hash_finish;
    }
    param_1[1] = (int)UNRECOVERED_JUMPTABLE;
    param_1[2] = (int)pcVar2;
    param_1[3] = (int)pcVar3;
    *param_1 = param_2;
                    /* WARNING: Could not recover jumptable at 0x0001042e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1 + 4);
    return;
  }
_L0:
  iVar1 = __assert_func(0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x00010462. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 8))(iVar1 + 0x10,*(code **)(iVar1 + 8));
  return;
}

