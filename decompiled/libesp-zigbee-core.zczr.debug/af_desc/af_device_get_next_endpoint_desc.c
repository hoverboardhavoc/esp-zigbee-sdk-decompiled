/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_get_next_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010c66) */
/* WARNING: Removing unreachable block (ram,0x00010c78) */
/* WARNING: Removing unreachable block (ram,0x00010c8c) */
/* WARNING: Removing unreachable block (ram,0x00010c5e) */

undefined4 af_device_get_next_endpoint_desc(int param_1)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == 0) {
    bVar1 = false;
    while (!bVar1) {
      iVar2 = core_globals_get();
      if ((*(int *)(iVar2 + 0xca0) != 0) &&
         (iVar2 = core_globals_get(), **(int **)(iVar2 + 0xca0) != 0)) {
        iVar2 = core_globals_get();
        return **(undefined4 **)(iVar2 + 0xca0);
      }
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
    while (!bVar1) {
      iVar2 = core_globals_get();
      if ((*(int *)(iVar2 + 0xca0) != 0) &&
         (iVar2 = core_globals_get(), **(int **)(iVar2 + 0xca0) != 0)) {
        iVar2 = core_globals_get();
        for (iVar2 = **(int **)(iVar2 + 0xca0); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
          if (iVar2 == param_1) {
            return *(undefined4 *)(iVar2 + 0x1c);
          }
        }
      }
      bVar1 = true;
    }
  }
  return 0;
}

