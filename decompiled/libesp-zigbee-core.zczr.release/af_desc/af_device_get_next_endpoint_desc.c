/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_device_get_next_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_device_get_next_endpoint_desc(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0xca0) != 0) &&
       (iVar3 = core_globals_get(), **(int **)(iVar3 + 0xca0) != 0)) {
      iVar3 = core_globals_get();
      return **(int **)(iVar3 + 0xca0);
    }
  }
  else {
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0xca0) != 0) &&
       (iVar3 = core_globals_get(), **(int **)(iVar3 + 0xca0) != 0)) {
      iVar3 = core_globals_get();
      iVar3 = **(int **)(iVar3 + 0xca0);
      while (iVar3 != 0) {
        piVar2 = (int *)(iVar3 + 0x1c);
        bVar1 = iVar3 == param_1;
        iVar3 = *piVar2;
        if (bVar1) {
          return *piVar2;
        }
      }
    }
  }
  return 0;
}

