/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_purge_tx_queue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mm_purge_tx_queue(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 != 0xff) {
    iVar1 = core_globals_get();
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar1 + param_1 * 0xc + 0xc84) + 4) + 8);
    iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x000102ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)
                      (*(undefined4 *)(iVar1 + param_1 * 0xc + 0xc84),param_2,UNRECOVERED_JUMPTABLE)
    ;
    return iVar1;
  }
  iVar2 = nwk_mm_iface_is_valid(0);
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar2 = core_globals_get();
    UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(iVar2 + 0xc84) + 4) + 8);
    iVar2 = core_globals_get();
    iVar2 = (*UNRECOVERED_JUMPTABLE)(*(undefined4 *)(iVar2 + 0xc84),param_2);
    if (iVar2 != 0) {
      log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","purge_tx_queue",0,iVar2);
      iVar1 = iVar2;
    }
  }
  return iVar1;
}

