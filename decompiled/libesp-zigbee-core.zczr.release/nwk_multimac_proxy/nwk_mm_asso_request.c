/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_asso_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mm_asso_request(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_1 == 0xff) {
    iVar1 = 2;
  }
  else {
    iVar2 = nwk_mm_iface_is_enabled();
    iVar1 = 3;
    if (iVar2 != 0) {
      iVar1 = core_globals_get();
      pcVar3 = *(code **)(*(int *)(*(int *)(iVar1 + param_1 * 0xc + 0xc84) + 4) + 0x20);
      iVar1 = core_globals_get();
      iVar1 = (*pcVar3)(*(undefined4 *)(iVar1 + param_1 * 0xc + 0xc84),param_2);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","mlme_asso_request",param_1,iVar1);
  return iVar1;
}

