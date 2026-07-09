/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_info_add(char *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_1 == (char *)0x0) {
    uVar3 = 2;
  }
  else {
    iVar1 = af_get_ep_desc(param_1[1]);
    if (iVar1 == 0) {
      uVar3 = 5;
    }
    else {
      piVar2 = (int *)calloc(1,8);
      if (piVar2 == (int *)0x0) {
        uVar3 = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar1 + 8);
        *(char **)(iVar1 + 8) = param_1;
        *piVar2 = (int)param_1;
        if (*param_1 == '\0') {
          param_1[9] = (byte)((*(uint *)(param_1 + 8) >> 0xc & 0xf | 1) << 4) | param_1[9] & 0xfU;
          *(byte *)(*piVar2 + 9) = *(byte *)(*piVar2 + 9) & 0xf0 | 1;
        }
        piVar2[1] = (int)(piVar2 + 1);
        iVar1 = core_globals_get();
        piVar2[1] = *(int *)(iVar1 + 0xd34);
        *(int **)(iVar1 + 0xd34) = piVar2 + 1;
        uVar3 = zcl_reporting_store_reporting_info(*piVar2);
      }
    }
  }
  return uVar3;
}

