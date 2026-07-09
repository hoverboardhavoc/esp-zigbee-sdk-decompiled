/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac_proxy.o -> nwk_mm_get_pib_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mm_get_pib_attr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if (param_1 == 0xff) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_multimac_proxy.c",99,
                  "nwk_mm_get_pib_attr","iface_id != 0xFF");
  }
  else if (param_1 == 0xff) {
    iVar3 = 0;
    bVar1 = false;
    while (!bVar1) {
      iVar2 = nwk_mm_iface_is_valid(0);
      if (iVar2 != 0) {
        iVar2 = core_globals_get();
        pcVar4 = *(code **)(*(int *)(*(int *)(iVar2 + 0xc84) + 4) + 0x10);
        iVar2 = core_globals_get();
        iVar2 = (*pcVar4)(*(undefined4 *)(iVar2 + 0xc84),param_2,param_3,param_4);
        if (iVar2 != 0) {
          log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","get_pib_attr",0,iVar2);
          iVar3 = iVar2;
        }
      }
      bVar1 = true;
    }
    return iVar3;
  }
  iVar3 = core_globals_get();
  pcVar4 = *(code **)(*(int *)(*(int *)(iVar3 + param_1 * 0xc + 0xc84) + 4) + 0x10);
  iVar3 = core_globals_get();
  iVar3 = (*pcVar4)(*(undefined4 *)(iVar3 + param_1 * 0xc + 0xc84),param_2,param_3,param_4);
  return iVar3;
}

